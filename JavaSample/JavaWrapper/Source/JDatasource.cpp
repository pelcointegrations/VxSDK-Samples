#include "stdafx.h"
#include "JDatasource.h"
#include "JClip.h"
#include "JDataInterface.h"
#include "JPTZController.h"
#include "Logger.h"

using namespace CPPJni;

/// <summary>
/// Returns the VxSDK datasource pointer stored in Java DataSource
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="dataSourceObj">JDataSource Java class instance</param>
VxSdk::IVxDataSource* GetDataSourceObject(JNIEnv *env, jobject dataSourceObj) {
    jclass datasourceClass = env->GetObjectClass(dataSourceObj);
    jfieldID datasourcePointerId = env->GetFieldID(datasourceClass, "vxDataSource", "J");
    return (VxSdk::IVxDataSource*)env->GetLongField(dataSourceObj, datasourcePointerId);
}

/// <summary>
/// Create a JNI wrapper type for JPTZControl java class
/// </summary>
/// <param name="env">Jni environment pointer</param>
Jni_PTZController* CreateJniClassForPTZControl(JNIEnv * env) {
    Jni_PTZController * jniPTZControl = new Jni_PTZController;
    jniPTZControl->cls = env->FindClass("javasample/JPTZController");

    if (jniPTZControl->cls == nullptr) {
        LOGGER->Log("Failed to create class JPTZController");
        return nullptr;
    }

    jniPTZControl->constructortorID = env->GetMethodID(jniPTZControl->cls, kInit, "()V");
    if (jniPTZControl->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JPTZController class");
        return nullptr;
    }

    jniPTZControl->ptzControlPointer = env->GetFieldID(jniPTZControl->cls, "vxPTZController", "J");
    return jniPTZControl;
}

/// <summary>
/// Create a JNI wrapper type for JClip java class
/// </summary>
/// <param name="env">Jni environment pointer</param>
Jni_Clip* CreateJniClassForClip(JNIEnv * env) {
    Jni_Clip * jniClp = new Jni_Clip;
    jniClp->cls = env->FindClass("javasample/JClip");

    if (jniClp->cls == nullptr) {
        LOGGER->Log("Failed to create class JClip");
        return nullptr;
    }

    jniClp->constructortorID = env->GetMethodID(jniClp->cls, kInit, "()V");
    if (jniClp->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JClip class");
        return nullptr;
    }

    jniClp->type = env->GetFieldID(jniClp->cls, "recordType", "I");
    jniClp->startTime = env->GetFieldID(jniClp->cls, "startTime", kJavaLangString);
    jniClp->endTime = env->GetFieldID(jniClp->cls, "endTime", kJavaLangString);
    jniClp->dataSourceID = env->GetFieldID(jniClp->cls, "dataSourceID", kJavaLangString);
    jniClp->clipPointer = env->GetFieldID(jniClp->cls, "vxClip", "J");
    return jniClp;
}

/// <summary>
/// Assign to properties of Java JClip class object reading from JNI wrapper and VxSDK clip data
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="clpObj">Jni clip wrapper filled with JClip data types</param>
/// <param name="jClpObj">Java JClip object to be updated</param>
/// <param name="vxClip">Actual vxSDK clip pointer from data to be read</param>
void SetClipDetailsToJniObject(JNIEnv * env, Jni_Clip* clpObj, jobject jClpObj, VxSdk::IVxClip* vxClip) {
    env->SetIntField(jClpObj, clpObj->type, vxClip->recordingType);
    env->SetObjectField(jClpObj, clpObj->startTime, env->NewStringUTF(vxClip->startTime));
    env->SetObjectField(jClpObj, clpObj->endTime, env->NewStringUTF(vxClip->endTime));
    env->SetObjectField(jClpObj, clpObj->dataSourceID, env->NewStringUTF(vxClip->dataSourceId));
    env->SetLongField(jClpObj, clpObj->clipPointer, (long)vxClip);
}

/// <summary>
/// Create a JNI wrapper type for JDataInterface java class
/// </summary>
Jni_DataInterface* CreateJniClassForDataInterface(JNIEnv * env) {
    Jni_DataInterface * jniDataInterface = new Jni_DataInterface;
    jniDataInterface->cls = env->FindClass("javasample/JDataInterface");

    if (jniDataInterface->cls == nullptr) {
        LOGGER->Log("Failed to create class JDataInterface");
        return nullptr;
    }

    jniDataInterface->constructortorID = env->GetMethodID(jniDataInterface->cls, kInit, "()V");
    if (jniDataInterface->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JDataInterface class");
        return nullptr;
    }

    jniDataInterface->streamProtocol = env->GetFieldID(jniDataInterface->cls, "streamProtocol", "I");
    jniDataInterface->dataInterfacePointer = env->GetFieldID(jniDataInterface->cls, "vxDataInterface", "J");
    return jniDataInterface;
}

/// <summary>
/// Assign to properties of Java JDataInterface class object reading from JNI wrapper and VxSDK datainterface data
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="dataIntrfce">Jni clip wrapper filled with JDataInterface data types</param>
/// <param name="jDataInterfaceObj">Java JDataInterface object to be updated</param>
/// <param name="vxDataInterface">Actual vxSDK datainterface pointer from data to be read</param>
void SetDataInterfaceDetailsToJniObject(JNIEnv * env, Jni_DataInterface* dataIntrfce, jobject jDataInterfaceObj, VxSdk::IVxDataInterface* vxDataInterface) {
    env->SetIntField(jDataInterfaceObj, dataIntrfce->streamProtocol, vxDataInterface->protocol);
    env->SetLongField(jDataInterfaceObj, dataIntrfce->dataInterfacePointer, (long)vxDataInterface);
}

/// <summary>
/// Check whether PTZ capability is available for this datasource
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="dataSourceObj">JDataSource Java class instance</param>
JNIEXPORT jboolean JNICALL Java_javasample_JDataSource_IsPTZEnabled
(JNIEnv *env, jobject dataSourceObj) {
    bool result = false;
    VxSdk::IVxDataSource* vxDatasource = GetDataSourceObject(env, dataSourceObj);
    if (vxDatasource == nullptr) {
        LOGGER->Log(kJDataSourceFailed);
        return false;
    }

    vxDatasource->CanPtz(result);
    return result;
}

/// <summary>
/// Returns the PTZController class associated with this datasource
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="dataSourceObj">JDataSource Java class instance</param>
JNIEXPORT jobject JNICALL Java_javasample_JDataSource_GetPTZController
(JNIEnv *env, jobject dataSourceObj) {
    VxSdk::IVxDataSource* vxDatasource = GetDataSourceObject(env, dataSourceObj);

    if (vxDatasource == nullptr) {
        LOGGER->Log(kJDataSourceFailed);
        return nullptr;
    }

    Jni_PTZController * jniPTZController = CreateJniClassForPTZControl(env);
    jobject jPtzControlObj = env->NewObject(jniPTZController->cls, jniPTZController->constructortorID);

    VxSdk::IVxPtzController* ptzController;
    VxSdk::VxResult::Value result = vxDatasource->GetPtzController(ptzController);
    if (result == VxSdk::VxResult::kOK) {
        env->SetLongField(jPtzControlObj, jniPTZController->ptzControlPointer, (long)ptzController);
        return jPtzControlObj;
    }

    return nullptr;
}

/// <summary>
/// Returns the Clips available with this datasource
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="dataSourceObj">JDataSource Java class instance</param>
JNIEXPORT jobjectArray JNICALL Java_javasample_JDataSource_GetClips
(JNIEnv * env, jobject dataSourceObj) {
    VxSdk::IVxDataSource* vxDatasource = GetDataSourceObject(env, dataSourceObj);

    if (vxDatasource == nullptr) {
        LOGGER->Log(kJDataSourceFailed);
        return nullptr;
    }

    jobjectArray clipsList = nullptr;
    int clipsCount = 0;
    Jni_Clip * jniClp = CreateJniClassForClip(env);

    VxSdk::VxCollection<VxSdk::IVxClip**> clips;
    VxSdk::VxResult::Value result = vxDatasource->GetClips(clips);

    if (result == VxSdk::VxResult::kInsufficientSize) {
        clips.collection = new VxSdk::IVxClip*[clips.collectionSize];
        result = vxDatasource->GetClips(clips);
        if (result == VxSdk::VxResult::kOK) {
            clipsCount = clips.collectionSize;
            clipsList = env->NewObjectArray(clips.collectionSize, jniClp->cls, nullptr);
            for (int i = 0; i < clips.collectionSize; i++) {
                jobject jClpObj = env->NewObject(jniClp->cls, jniClp->constructortorID);
                SetClipDetailsToJniObject(env, jniClp, jClpObj, clips.collection[i]);
                env->SetObjectArrayElement(clipsList, i, jClpObj);
            }
        }
        delete[] clips.collection;
    }
    delete jniClp;

    if (clipsList != nullptr) {
        LOGGER->Log(std::to_string(clipsCount) + " clips found.");
    }

    return clipsList;
}

/// <summary>
/// Returns the data interfaces available with this datasource
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="dataSourceObj">JDataSource Java class instance</param>
JNIEXPORT jobjectArray JNICALL Java_javasample_JDataSource_GetDataInterfaces
(JNIEnv *env, jobject dataSourceObj) {
    jobjectArray dataInterfaceList = nullptr;
    VxSdk::IVxDataSource* vxDatasource = GetDataSourceObject(env, dataSourceObj);

    if (vxDatasource == nullptr) {
        LOGGER->Log(kJDataSourceFailed);
        return nullptr;
    }

    Jni_DataInterface * jniDataInterface = CreateJniClassForDataInterface(env);

    int size = vxDatasource->dataInterfaceSize;
    dataInterfaceList = env->NewObjectArray(vxDatasource->dataInterfaceSize, jniDataInterface->cls, nullptr);
    for (int i = 0; i < size; i++) {
        jobject jDataInterfaceObj = env->NewObject(jniDataInterface->cls, jniDataInterface->constructortorID);
        SetDataInterfaceDetailsToJniObject(env, jniDataInterface, jDataInterfaceObj, vxDatasource->dataInterfaces[i]);
        env->SetObjectArrayElement(dataInterfaceList, i, jDataInterfaceObj);
    }
    delete jniDataInterface;
    return dataInterfaceList;
}

/// <summary>
/// Returns the RTSP endpoint for this datasource
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="dataSourceObj">JDataSource Java class instance</param>
JNIEXPORT jstring JNICALL Java_javasample_JDataSource_GetRTSPEndpoint
(JNIEnv *env, jobject dataSourceObj) {
    char* rtspEndpoint = nullptr;
    int size = 0;
    jstring rtspUrl = nullptr;

    VxSdk::IVxDataSource* vxDatasource = GetDataSourceObject(env, dataSourceObj);

    if (vxDatasource == nullptr) {
        LOGGER->Log(kJDataSourceFailed);
        return nullptr;
    }

    VxSdk::VxResult::Value result = vxDatasource->GetRtspEndpoint(rtspEndpoint, size);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        rtspEndpoint = new char[size];
        vxDatasource->GetRtspEndpoint(rtspEndpoint, size);
    }

    if (rtspEndpoint != nullptr) {
        rtspUrl = env->NewStringUTF(rtspEndpoint);
        LOGGER->Log("Got RTSPEndpoint as:" + std::string(rtspEndpoint));
        delete[] rtspEndpoint;
    }
    else {
        LOGGER->Log("Failed to get RTSP endpoint url for datasource:" + std::string(vxDatasource->id));
    }

    return rtspUrl;
}

JNIEXPORT jobject JNICALL Java_javasample_JDataSource_CreateMJPEGSession
(JNIEnv *env, jobject dataSourceObj) {
    return nullptr;
}
