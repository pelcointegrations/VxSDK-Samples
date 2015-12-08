#include "stdafx.h"
#include "JDevice.h"
#include "JDatasource.h"
#include "Logger.h"
#include <string.h>

using namespace CPPJni;

/// <summary>
// Create a JNI wrapper type for JDataSource java class
/// </summary>
/// <param name="env">Jni environment pointer</param>
Jni_Datasource* CreateJniClassForDatasource(JNIEnv * env) {

    Jni_Datasource * jniDatasource = nullptr;

    jniDatasource = new Jni_Datasource;
    jniDatasource->cls = env->FindClass("javasample/JDataSource");

    if (jniDatasource->cls == nullptr)
    {
        LOGGER->Log("Failed to create class JDatasource");
        return nullptr;
    }

    jniDatasource->constructortorID = env->GetMethodID(jniDatasource->cls, "<init>", "()V");
    if (jniDatasource->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JDatasource class");
        return nullptr;
    }

    jniDatasource->id = env->GetFieldID(jniDatasource->cls, "id", kJavaLangString);
    jniDatasource->ip = env->GetFieldID(jniDatasource->cls, "ip", kJavaLangString);
    jniDatasource->number = env->GetFieldID(jniDatasource->cls, "number", "I");
    jniDatasource->name = env->GetFieldID(jniDatasource->cls, "name", kJavaLangString);
    jniDatasource->datasourcePointer = env->GetFieldID(jniDatasource->cls, "vxDataSource", "J");

    return jniDatasource;
}

/// <summary>
// Assign to properties of Java JDataSource class object reading from JNI wrapper and VxSDK datasource data
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="dsObj">Jni datasource wrapper filled with JDataSource data types</param>
/// <param name="dataSourceObj">Java JDataSource object to be updated</param>
/// <param name="vxDataSource">Actual vxSDK datasource pointer from data to be read</param>
void SetDataSourceDetailsToJniObject(JNIEnv * env, Jni_Datasource* dsObj, jobject dataSourceObj, VxSdk::IVxDataSource* vxDataSource) {

    env->SetLongField(dataSourceObj, dsObj->datasourcePointer, (long)vxDataSource);
    env->SetObjectField(dataSourceObj, dsObj->name, env->NewStringUTF(vxDataSource->name));
    env->SetObjectField(dataSourceObj, dsObj->id, env->NewStringUTF(vxDataSource->id));
    env->SetObjectField(dataSourceObj, dsObj->ip, env->NewStringUTF(vxDataSource->ip));
    env->SetIntField(dataSourceObj, dsObj->number, vxDataSource->number);
}

/// <summary>
// Returns the datasources available for this device
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="deviceObj">JDevice Java class instance</param>
JNIEXPORT jobjectArray JNICALL Java_javasample_JDevice_GetDataSources
(JNIEnv *env, jobject deviceObj) {
    jclass deviceClass = env->GetObjectClass(deviceObj);
    jobjectArray dataSourceList = nullptr;

    if (deviceClass == nullptr) {
        LOGGER->Log("Failed to get JDevice object");
        return nullptr;
    }

    jfieldID devicePointerId = env->GetFieldID(deviceClass, "vxDevice", "J");
    VxSdk::IVxDevice* vxDevice = (VxSdk::IVxDevice*)env->GetLongField(deviceObj, devicePointerId);

    if (vxDevice == nullptr) {
        LOGGER->Log("Failed to get VxSDK::VxDevice object from Java");
        return nullptr;
    }
    int dataSourceCount = 0;
    Jni_Datasource * jniDs = CreateJniClassForDatasource(env);

    LOGGER->Log("Got VxDevice pointer with IP: " +  std::string(vxDevice->ip));

    VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources;
    VxSdk::VxResult::Value result = vxDevice->GetDataSources(dataSources);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        dataSources.collection = new VxSdk::IVxDataSource*[dataSources.collectionSize];
        result = vxDevice->GetDataSources(dataSources);
        if (result == VxSdk::VxResult::kOK) {
            dataSourceCount = dataSources.collectionSize;
            dataSourceList = env->NewObjectArray(dataSources.collectionSize, jniDs->cls, nullptr);
            for (int i = 0; i < dataSources.collectionSize; i++) {
                jobject jDataSourceObj = env->NewObject(jniDs->cls, jniDs->constructortorID);
                //Set the datasource details in JNI wrapper to JDataSource java object
                SetDataSourceDetailsToJniObject(env, jniDs, jDataSourceObj, dataSources.collection[i]);
                env->SetObjectArrayElement(dataSourceList, i, jDataSourceObj);
            }
        }
        delete[] dataSources.collection;
    }
    if (dataSourceList != nullptr) {
        LOGGER->Log(std::to_string(dataSourceCount) + " datasources found.");
    }
    delete jniDs;

    return dataSourceList;
}