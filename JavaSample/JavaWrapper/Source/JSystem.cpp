#include "stdafx.h"
#include "string.h"
#include "javasample_JSystem.h"
#include "JSystem.h"
#include "JDevice.h"
#include "JExport.h"
#include "JSituation.h"
#include "JClip.h"
#include "JEvent.h"
#include "Logger.h"

using namespace std;
using namespace CPPJni;

static JavaVM *jvm;
static jobject _eventControlObj = nullptr;

/// <summary>
/// Create a JNI wrapper type for JDevice java class
/// </summary>
/// <param name="env">Jni environment pointer</param>
Jni_Device* CreateJniClassForDevice(JNIEnv * env) {
    Jni_Device * jniDev = nullptr;
    jniDev = new Jni_Device;
    jniDev->cls = env->FindClass("javasample/JDevice");
    if (jniDev->cls == nullptr) {
        LOGGER->Log("Failed to create class JDevice");
        return false;
    }
    jniDev->constructortorID = env->GetMethodID(jniDev->cls, kInit, "()V");
    if (jniDev->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JDevice class");
        return false;
    }
    jniDev->deviceName = env->GetFieldID(jniDev->cls, "deviceName", kJavaLangString);
    jniDev->deviceIP = env->GetFieldID(jniDev->cls, "deviceIP", kJavaLangString);
    jniDev->deviceModel = env->GetFieldID(jniDev->cls, "deviceModel", kJavaLangString);
    jniDev->deviceVersion = env->GetFieldID(jniDev->cls, "deviceVersion", kJavaLangString);
    jniDev->deviceID = env->GetFieldID(jniDev->cls, "deviceID", kJavaLangString);
    jniDev->deviceCommissioned = env->GetFieldID(jniDev->cls, "deviceCommissioned", "Z");
    jniDev->deviceLicenseRequired = env->GetFieldID(jniDev->cls, "deviceLicenseRequired", "Z");
    jniDev->devicePassword = env->GetFieldID(jniDev->cls, "devicePassword", kJavaLangString);
    jniDev->devicePelcoHardware = env->GetFieldID(jniDev->cls, "devicePelcoHardware", "Z");
    jniDev->deviceSerial = env->GetFieldID(jniDev->cls, "deviceSerial", kJavaLangString);
    jniDev->deviceUsername = env->GetFieldID(jniDev->cls, "deviceUsername", kJavaLangString);
    jniDev->deviceVendor = env->GetFieldID(jniDev->cls, "deviceVendor", kJavaLangString);
    jniDev->deviceVirtualIp = env->GetFieldID(jniDev->cls, "deviceVirtualIp", kJavaLangString);
    jniDev->deviceState = env->GetFieldID(jniDev->cls, "deviceState", "I");
    jniDev->deviceType = env->GetFieldID(jniDev->cls, "deviceType", "I");
    jniDev->devicePointer = env->GetFieldID(jniDev->cls, "vxDevice", "J");
    return jniDev;
}

/// <summary>
/// Create a JNI wrapper type for JExport java class
/// </summary>
/// <param name="env">Jni environment pointer</param>
Jni_Export* CreateJniClassForExport(JNIEnv * env) {
    Jni_Export * jniExp = nullptr;
    jniExp = new Jni_Export;
    jniExp->cls = env->FindClass("javasample/JExport");
    if (jniExp->cls == nullptr) {
        LOGGER->Log("Failed to create class JExport");
        return false;
    }
    jniExp->constructortorID = env->GetMethodID(jniExp->cls, kInit, "()V");
    if (jniExp->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JExport class");
        return false;
    }
    jniExp->exportCompleted = env->GetFieldID(jniExp->cls, "completed", kJavaLangString);
    jniExp->exportId = env->GetFieldID(jniExp->cls, "id", kJavaLangString);
    jniExp->exportInitiated = env->GetFieldID(jniExp->cls, "initiated", kJavaLangString);
    jniExp->exportName = env->GetFieldID(jniExp->cls, "name", kJavaLangString);
    jniExp->exportOwner = env->GetFieldID(jniExp->cls, "owner", kJavaLangString);
    jniExp->exportDataUri = env->GetFieldID(jniExp->cls, "datauri", kJavaLangString);
    jniExp->exportPercentComplete = env->GetFieldID(jniExp->cls, "percentComplete", "F");
    jniExp->exportIsProtected = env->GetFieldID(jniExp->cls, "isProtected", "Z");
    jniExp->exportClipSize = env->GetFieldID(jniExp->cls, "exportClipSize", "I");
    jniExp->exportSecondsRemaining = env->GetFieldID(jniExp->cls, "secondsRemaining", "I");
    jniExp->exportFileSizeKb = env->GetFieldID(jniExp->cls, "fileSizeKb", "I");
    jniExp->exportFormat = env->GetFieldID(jniExp->cls, "format", "I");
    jniExp->exportStatus = env->GetFieldID(jniExp->cls, "status", "I");
    jniExp->exportPointer = env->GetFieldID(jniExp->cls, kVxExport, "J");
    return jniExp;
}

/// <summary>
/// Create a JNI wrapper type for JSituation java class
/// </summary>
/// <param name="env">Jni environment pointer</param>
Jni_Situation* CreateJniClassForSituation(JNIEnv * env) {
    Jni_Situation * jniSituation = nullptr;
    jniSituation = new Jni_Situation;
    jniSituation->cls = env->FindClass("javasample/JSituation");
    if (jniSituation->cls == nullptr) {
        LOGGER->Log("Failed to create class JSituation");
        return false;
    }
    jniSituation->constructortorID = env->GetMethodID(jniSituation->cls, kInit, "()V");
    if (jniSituation->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JSituation class");
        return false;
    }
    jniSituation->situationType = env->GetFieldID(jniSituation->cls, kSituationType, kJavaLangString);
    jniSituation->sourceDeviceId = env->GetFieldID(jniSituation->cls, kSourceDeviceId, kJavaLangString);
    jniSituation->severity = env->GetFieldID(jniSituation->cls, kSeverity, "I");
    jniSituation->notificationIds = env->GetFieldID(jniSituation->cls, "notificationIds", "[Ljava/lang/String;");
    jniSituation->snoozeIntervals = env->GetFieldID(jniSituation->cls, kSnoozeIntervals, "[I");
    jniSituation->audiblePlayCount = env->GetFieldID(jniSituation->cls, kAudiblePlayCount, "I");
    jniSituation->audibleLoopDelay = env->GetFieldID(jniSituation->cls, kAudibleLoopDelay, "I");
    jniSituation->autoAcknowledge = env->GetFieldID(jniSituation->cls, kAutoAcknowledge, "I");
    jniSituation->audibleNotify = env->GetFieldID(jniSituation->cls, kAudibleNotify, "Z");
    jniSituation->ackNeeded = env->GetFieldID(jniSituation->cls, kAckNeeded, "Z");
    jniSituation->expandBanner = env->GetFieldID(jniSituation->cls, kExpandBanner, "Z");
    jniSituation->log = env->GetFieldID(jniSituation->cls, "log", "Z");
    jniSituation->notify = env->GetFieldID(jniSituation->cls, kNotify, "Z");
    jniSituation->name = env->GetFieldID(jniSituation->cls, "name", kJavaLangString);
    jniSituation->situationPointer = env->GetFieldID(jniSituation->cls, kVxSituation, "J");

    return jniSituation;
}

/// <summary>
// Create a JNI wrapper type for JEvent java class
/// </summary>
/// <param name="env">Jni environment pointer</param>
Jni_Event* CreateJniClassForEvent(JNIEnv * env) {
    Jni_Event* jniEvent = nullptr;
    jniEvent = new Jni_Event;
    jniEvent->cls = env->FindClass("javasample/JEvent");
    if (jniEvent->cls == nullptr) {
        LOGGER->Log("Failed to create class JEvent");
        return false;
    }
    jniEvent->constructortorID = env->GetMethodID(jniEvent->cls, kInit, "()V");
    if (jniEvent->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JEvent class");
        return false;
    }
    jniEvent->generatorDeviceId = env->GetFieldID(jniEvent->cls, kGeneratorDeviceId, kJavaLangString);
    jniEvent->id = env->GetFieldID(jniEvent->cls, kId, kJavaLangString);
    jniEvent->time = env->GetFieldID(jniEvent->cls, kTime, kJavaLangString);
    jniEvent->situationType = env->GetFieldID(jniEvent->cls, kSituationType, kJavaLangString);
    jniEvent->sourceDeviceId = env->GetFieldID(jniEvent->cls, kSourceDeviceId, kJavaLangString);
    jniEvent->sourceUserName = env->GetFieldID(jniEvent->cls, kSourceUserName, kJavaLangString);
    jniEvent->severity = env->GetFieldID(jniEvent->cls, kSeverity, "I");
    jniEvent->ackState = env->GetFieldID(jniEvent->cls, kAckState, "I");

    return jniEvent;
}

/// <summary>
// Assign to properties of Java JDevice class object reading from JNI wrapper and VxSDK device data
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="deviceObj">Jni device wrapper filled with JDevice data types</param>
/// <param name="jDevObj">Java JDevice object to be updated</param>
/// <param name="vxDevice">Actual vxSDK device pointer from data to be read</param>
void SetDeviceDetailsToJniObject(JNIEnv * env, Jni_Device* deviceObj, jobject jDevObj, VxSdk::IVxDevice* vxDevice) {
    env->SetObjectField(jDevObj, deviceObj->deviceName, env->NewStringUTF(vxDevice->name));
    env->SetObjectField(jDevObj, deviceObj->deviceIP, env->NewStringUTF(vxDevice->ip));
    env->SetObjectField(jDevObj, deviceObj->deviceModel, env->NewStringUTF(vxDevice->model));
    env->SetObjectField(jDevObj, deviceObj->deviceVersion, env->NewStringUTF(vxDevice->version));
    env->SetObjectField(jDevObj, deviceObj->deviceID, env->NewStringUTF(vxDevice->id));
    env->SetBooleanField(jDevObj, deviceObj->deviceCommissioned, vxDevice->isCommissioned);
    env->SetBooleanField(jDevObj, deviceObj->deviceLicenseRequired, vxDevice->isLicenseRequired);
    env->SetBooleanField(jDevObj, deviceObj->devicePelcoHardware, vxDevice->isPelcoHardware);
    env->SetObjectField(jDevObj, deviceObj->deviceSerial, env->NewStringUTF(vxDevice->serial));
    env->SetObjectField(jDevObj, deviceObj->deviceUsername, env->NewStringUTF(vxDevice->username));
    env->SetObjectField(jDevObj, deviceObj->deviceVendor, env->NewStringUTF(vxDevice->vendor));
    env->SetObjectField(jDevObj, deviceObj->deviceVirtualIp, env->NewStringUTF(vxDevice->virtualIp));
    env->SetIntField(jDevObj, deviceObj->deviceState, vxDevice->state);
    env->SetIntField(jDevObj, deviceObj->deviceType, vxDevice->type);
    env->SetLongField(jDevObj, deviceObj->devicePointer, (long)vxDevice);
}

/// <summary>
/// Assign to properties of Java JExport class object reading from JNI wrapper and VxSDK export data
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="expObj">Jni export wrapper filled with JExport data types</param>
/// <param name="jExpObj">Java JExport object to be updated</param>
/// <param name="vxExport">Actual vxSDK export pointer from data to be read</param>
void SetExportDetailsToJniObject(JNIEnv * env, Jni_Export* expObj, jobject jExpObj, VxSdk::IVxExport* vxExport) {
    env->SetObjectField(jExpObj, expObj->exportCompleted, env->NewStringUTF(vxExport->name));
    env->SetObjectField(jExpObj, expObj->exportId, env->NewStringUTF(vxExport->id));
    env->SetObjectField(jExpObj, expObj->exportInitiated, env->NewStringUTF(vxExport->initiatedTime));
    env->SetObjectField(jExpObj, expObj->exportName, env->NewStringUTF(vxExport->name));
    env->SetObjectField(jExpObj, expObj->exportOwner, env->NewStringUTF(vxExport->owner));
    env->SetObjectField(jExpObj, expObj->exportDataUri, env->NewStringUTF(vxExport->dataUri));
    env->SetFloatField(jExpObj, expObj->exportPercentComplete, vxExport->percentComplete);
    env->SetBooleanField(jExpObj, expObj->exportIsProtected, vxExport->isProtected);
    env->SetIntField(jExpObj, expObj->exportClipSize, vxExport->exportClipSize);
    env->SetIntField(jExpObj, expObj->exportSecondsRemaining, vxExport->secondsRemaining);
    env->SetIntField(jExpObj, expObj->exportFileSizeKb, vxExport->fileSizeKb);
    env->SetIntField(jExpObj, expObj->exportFormat, vxExport->format);
    env->SetIntField(jExpObj, expObj->exportStatus, vxExport->status);
    env->SetLongField(jExpObj, expObj->exportPointer, (long)vxExport);
}

/// <summary>
/// Assign to properties of Java JSituation class object reading from JNI wrapper and VxSDK situation data
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="stnObj">Jni situation wrapper filled with JSituation data types</param>
/// <param name="jStnObj">Java JSituation object to be updated</param>
/// <param name="vxSituation">Actual vxSDK situation pointer from data to be read</param>
void SetSituationDetailsToJniObject(JNIEnv * env, Jni_Situation* stnObj, jobject jStnObj, VxSdk::IVxSituation* vxSituation) {
    env->SetObjectField(jStnObj, stnObj->situationType, env->NewStringUTF(vxSituation->type));
    env->SetObjectField(jStnObj, stnObj->sourceDeviceId, env->NewStringUTF(vxSituation->sourceDeviceId));
    env->SetIntField(jStnObj, stnObj->severity, vxSituation->severity);
    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray notificationArray = env->NewObjectArray(vxSituation->notificationIdSize, stringClass, 0);
    for (int i = 0; i < vxSituation->notificationIdSize; i++) {
        string s = vxSituation->notificationIds[i];
        jstring javaString = env->NewStringUTF(s.c_str());
        env->SetObjectArrayElement(notificationArray, i, javaString);
    }
    env->SetObjectField(jStnObj, stnObj->notificationIds, notificationArray);
    jintArray snoozeArray = env->NewIntArray(vxSituation->snoozeIntervalSize);
    int *interval = new int[vxSituation->snoozeIntervalSize];
    for (int i = 0; i < vxSituation->snoozeIntervalSize; i++) {
        interval[i] = vxSituation->snoozeIntervals[i];
        env->SetIntArrayRegion(snoozeArray, 0, vxSituation->snoozeIntervalSize, (jint*)interval);
    }
    env->SetObjectField(jStnObj, stnObj->snoozeIntervals, snoozeArray);
    env->SetIntField(jStnObj, stnObj->audiblePlayCount, vxSituation->audiblePlayCount);
    env->SetIntField(jStnObj, stnObj->audibleLoopDelay, vxSituation->audibleLoopDelay);
    env->SetIntField(jStnObj, stnObj->autoAcknowledge, vxSituation->autoAcknowledgeTime);
    env->SetBooleanField(jStnObj, stnObj->audibleNotify, vxSituation->shouldAudiblyNotify);
    env->SetBooleanField(jStnObj, stnObj->ackNeeded, vxSituation->isAckNeeded);
    env->SetBooleanField(jStnObj, stnObj->expandBanner, vxSituation->shouldExpandBanner);
    env->SetBooleanField(jStnObj, stnObj->log, vxSituation->shouldLog);
    env->SetBooleanField(jStnObj, stnObj->notify, vxSituation->shouldNotify);
    env->SetObjectField(jStnObj, stnObj->name, env->NewStringUTF(vxSituation->name));
    env->SetLongField(jStnObj, stnObj->situationPointer, (long)vxSituation);
}

/// <summary>
// Assign to properties of Java JEvent class object reading from JNI wrapper and VxSDK device data
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="evObj">Jni device wrapper filled with JEvent data types</param>
/// <param name="jevObj">Java JEvent object to be updated</param>
/// <param name="vxEvent">Actual vxSDK event pointer from data to be read</param>
void SetEventDetailsToJniObject(JNIEnv * env, Jni_Event* evObj, jobject jevObj, VxSdk::IVxEvent* vxEvent) {
    env->SetObjectField(jevObj, evObj->generatorDeviceId, env->NewStringUTF(vxEvent->generatorDeviceId));
    env->SetObjectField(jevObj, evObj->id, env->NewStringUTF(vxEvent->id));
    env->SetObjectField(jevObj, evObj->time, env->NewStringUTF(vxEvent->time));
    env->SetObjectField(jevObj, evObj->situationType, env->NewStringUTF(vxEvent->situationType));
    env->SetObjectField(jevObj, evObj->sourceDeviceId, env->NewStringUTF(vxEvent->sourceDeviceId));
    env->SetObjectField(jevObj, evObj->sourceUserName, env->NewStringUTF(vxEvent->sourceUserName));
    env->SetIntField(jevObj, evObj->severity, vxEvent->severity);
    env->SetIntField(jevObj, evObj->ackState, vxEvent->ackState);
}

/// <summary>
// Connect to a VxSDK system using given ip, username and password
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="obj">JSystem Java class instance</param>
/// <param name="usrName">Username</param>
/// <param name="passwd">Password</param>
/// <param name="ip">IP of Vx system to connect</param>
JNIEXPORT jboolean JNICALL Java_javasample_JSystem_Connect(JNIEnv *env, jobject obj, jstring usrName, jstring passwd, jstring ip) {
    //Convert to C++ strings
    const char *userName_native = env->GetStringUTFChars(usrName, JNI_FALSE);
    const char *password_native = env->GetStringUTFChars(passwd, JNI_FALSE);
    const char *ip_native = env->GetStringUTFChars(ip, JNI_FALSE);

    LOGGER->Log("Connecting to " + std::string(ip_native));

    //Try VxSDK cpp calls to connect to system. If connected, keep the system pointer
    VxSdk::VxLoginInfo loginInfo;
    loginInfo.port = kSslPort;
    loginInfo.useSsl = true;
    VxSdk::Utilities::StrCopySafe(loginInfo.ipAddress, ip_native);
    VxSdk::Utilities::StrCopySafe(loginInfo.username, userName_native);
    VxSdk::Utilities::StrCopySafe(loginInfo.password, password_native);
    VxSdk::IVxSystem* system = nullptr;
    VxSystemLogin(loginInfo, system);
    _system = system; //keep the system pointer for later use. This should be deleted in Disconnect JNI call

    //C++ strings are no longer requried, so releasing
    env->ReleaseStringUTFChars(usrName, userName_native);
    env->ReleaseStringUTFChars(passwd, password_native);
    env->ReleaseStringUTFChars(ip, ip_native);
    if (system != nullptr) {
        LOGGER->Log("Connected to " + std::string(ip_native));
        return true;
    }

    LOGGER->Log("Failed to connect to system");
    return false;
}

/// <summary>
/// Logout from the system
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="obj">JSystem Java class instance</param>
JNIEXPORT jboolean JNICALL Java_javasample_JSystem_Disconnect(JNIEnv *env, jobject obj) {
    if (_system != nullptr) {
        _system->Delete();
        _system = nullptr;
    }
    return true;
}

/// <summary>
/// Get the devices connected to this system
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="obj">JSystem Java class instance</param>
JNIEXPORT jobjectArray JNICALL Java_javasample_JSystem_GetDevices(JNIEnv * env, jobject obj) {
    LOGGER->Log("Fetching devices..");
    jobjectArray jDevicesList = nullptr; //This array will contain objects of JDevice filled with vxDevice details
    int deviceCount = 0;

    Jni_Device * jniDev = CreateJniClassForDevice(env); //Create a c++ wrapper pointer for JDevice java class
    if (nullptr == jniDev) {
        LOGGER->Log(kClassInitFailed);
        return nullptr;
    }

    VxSdk::VxCollection<VxSdk::IVxDevice**> devices;
    VxSdk::VxResult::Value result = _system->GetDevices(devices);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        devices.collection = new VxSdk::IVxDevice*[devices.collectionSize];
        result = _system->GetDevices(devices);
        if (result == VxSdk::VxResult::kOK) {
            deviceCount = devices.collectionSize;
            jDevicesList = env->NewObjectArray(devices.collectionSize, jniDev->cls, nullptr);
            for (int i = 0; i < devices.collectionSize; i++) {
                jobject jDevObj = env->NewObject(jniDev->cls, jniDev->constructortorID);
                //Set the device details in JNI wrapper to JDevice java object
                SetDeviceDetailsToJniObject(env, jniDev, jDevObj, devices.collection[i]);
                env->SetObjectArrayElement(jDevicesList, i, jDevObj);
            }
        }
        delete[] devices.collection;
    }
    delete jniDev;

    if (jDevicesList != nullptr) {
        LOGGER->Log(std::to_string(deviceCount) + " devices found.");
    }
    return jDevicesList;
}

/// <summary>
/// Get the exports available in this sytem
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="obj">JSystem Java class instance</param>
JNIEXPORT jobjectArray JNICALL Java_javasample_JSystem_GetExports(JNIEnv * env, jobject obj) {
    LOGGER->Log("Fetching Exports..");
    jobjectArray jExportsList = nullptr;
    int exportsCount = 0;

    Jni_Export * jniExp = CreateJniClassForExport(env);
    if (nullptr == jniExp) {
        LOGGER->Log(kClassInitFailed);
        return nullptr;
    }
    VxSdk::VxCollection<VxSdk::IVxExport**> exports;
    VxSdk::VxResult::Value result = _system->GetExports(exports);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        exports.collection = new VxSdk::IVxExport*[exports.collectionSize];
        result = _system->GetExports(exports);
        if (result == VxSdk::VxResult::kOK) {
            exportsCount = exports.collectionSize;
            jExportsList = env->NewObjectArray(exports.collectionSize, jniExp->cls, nullptr);
            for (int i = 0; i < exports.collectionSize; i++) {
                jobject jExpObj = env->NewObject(jniExp->cls, jniExp->constructortorID);
                SetExportDetailsToJniObject(env, jniExp, jExpObj, exports.collection[i]);
                env->SetObjectArrayElement(jExportsList, i, jExpObj);
            }
        }
        delete[] exports.collection;
    }
    delete jniExp;
    if (jExportsList != nullptr) {
        LOGGER->Log(std::to_string(exportsCount) + " exports found.");
    }
    return jExportsList;
}


/// <summary>
/// Create a new export in this sytem
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="obj">JSystem Java class instance</param>
/// <param name="clips">Clips to be added in the export</param>
/// <param name="format">Format of export</param>
/// <param name="name">Name of export</param>
/// <param name="password">Password of exportt</param>
JNIEXPORT void JNICALL Java_javasample_JSystem_CreateExport
(JNIEnv *env, jobject obj, jobjectArray clips, jstring format, jstring name, jstring password) {
    LOGGER->Log(" Java_javasample_JSystem_CreateExport");
    const char *name_native = env->GetStringUTFChars(name, JNI_FALSE);
    const char *password_native = env->GetStringUTFChars(password, JNI_FALSE);

    VxSdk::IVxExport* exportItem = nullptr;
    int size = env->GetArrayLength(clips);
    LOGGER->Log(" Java_javasample_JSystem_CreateExport size %d", size);
    VxSdk::VxNewExport vxExport;
    vxExport.clips = new VxSdk::VxNewExportClip[size];
    vxExport.clipSize = size;
    vxExport.format = (VxSdk::VxExportFormat::Value)(1);
    VxSdk::Utilities::StrCopySafe(vxExport.name, name_native);
    VxSdk::Utilities::StrCopySafe(vxExport.password, password_native);
    for (int i = 0; i < size; i++) {
        VxSdk::VxNewExportClip clip;
        jobject obj = env->GetObjectArrayElement(clips, i);
        jclass jcClass = env->GetObjectClass(obj);
        jfieldID startId = env->GetFieldID(jcClass, "startTime", kJavaLangString);
        jfieldID endId = env->GetFieldID(jcClass, "endTime", kJavaLangString);
        jfieldID dataSourceId = env->GetFieldID(jcClass, "dataSourceID", kJavaLangString);
        jstring startTime =(jstring) env->GetObjectField(obj, startId);
        jstring endTime = (jstring)env->GetObjectField(obj, endId);
        jstring dataSrcID = (jstring)env->GetObjectField(obj, dataSourceId);
        VxSdk::Utilities::StrCopySafe(clip.dataSourceId, env->GetStringUTFChars(dataSrcID, JNI_FALSE));
        VxSdk::Utilities::StrCopySafe(clip.startTime, env->GetStringUTFChars(startTime, JNI_FALSE));
        VxSdk::Utilities::StrCopySafe(clip.endTime, env->GetStringUTFChars(endTime, JNI_FALSE));
        vxExport.clips[i] = clip;
        LOGGER->Log(" startTime %s", env->GetStringUTFChars(startTime, JNI_FALSE));
    }
    VxSdk::VxResult::Value result = _system->CreateExport(vxExport, exportItem);
    
    env->ReleaseStringUTFChars(name, name_native);
    env->ReleaseStringUTFChars(password, password_native);
}

/// <summary>
/// Delete an export from this sytem
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="sysObj">JSystem Java class instance</param>
/// <param name="exportToDelete">JExport object to delete</param>
JNIEXPORT jboolean JNICALL Java_javasample_JSystem_DeleteExport(JNIEnv *env, jobject sysObj, jobject exportToDelete) {
    jclass exportClass = env->GetObjectClass(exportToDelete);
    jfieldID exportPointerId = env->GetFieldID(exportClass, kVxExport, "J");
    VxSdk::IVxExport* delExport = (VxSdk::IVxExport*)env->GetLongField(exportToDelete, exportPointerId);

    if (delExport == nullptr) {
        LOGGER->Log(kExportPointerFailed);
        return false;
    }

    VxSdk::VxResult::Value result = delExport->DeleteExport();
    if (result == VxSdk::VxResult::kOK) {
        return true;
    }
    return false;
}

/// <summary>
/// Get situations available in this system
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="sysObj">JSystem Java class instance</param>
JNIEXPORT jobjectArray JNICALL Java_javasample_JSystem_GetSituations(JNIEnv *env, jobject sysObj) {
    LOGGER->Log("Fetching Situations..");
    jobjectArray jSituationsList = nullptr;
    int situationsCount = 0;
    Jni_Situation * jniSituation = CreateJniClassForSituation(env);
    if (nullptr == jniSituation) {
        LOGGER->Log(kClassInitFailed);
        return nullptr;
    }
    VxSdk::VxCollection<VxSdk::IVxSituation**> situations;
    VxSdk::VxResult::Value result = _system->GetSituations(situations);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        situations.collection = new VxSdk::IVxSituation*[situations.collectionSize];
        result = _system->GetSituations(situations);
        if (result == VxSdk::VxResult::kOK) {
            situationsCount = situations.collectionSize;
            jSituationsList = env->NewObjectArray(situations.collectionSize, jniSituation->cls, nullptr);
            for (int i = 0; i < situations.collectionSize; i++)
            {
                jobject jStnObj = env->NewObject(jniSituation->cls, jniSituation->constructortorID);
                SetSituationDetailsToJniObject(env, jniSituation, jStnObj, situations.collection[i]);
                env->SetObjectArrayElement(jSituationsList, i, jStnObj);
            }
        }
        delete[] situations.collection;
    }
    delete jniSituation;
    if (jSituationsList != nullptr) {
        LOGGER->Log(std::to_string(situationsCount) + " situations found.");
    }
    return jSituationsList;
}

/// <summary>
/// Insert a new event to system
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="sysObj">JSystem Java class instance</param>
/// <param name="eventToInsert">JEvent Java class instance</param>
/// <param name="jHashtable">Event properties filled in</param>
JNIEXPORT jboolean JNICALL Java_javasample_JSystem_InsertNewEvent(JNIEnv *env, jobject sysObj, jobject eventToInsert, jobject jHashtable) {
    LOGGER->Log("Java_javasample_JSystem_InsertNewEvent");
    int size = 3;

    VxSdk::VxNewEvent newEvent;
    jclass jcClass = env->GetObjectClass(eventToInsert);
    jfieldID generatorDeviceId = env->GetFieldID(jcClass, "generatorDeviceId", kJavaLangString);
    jfieldID situationType = env->GetFieldID(jcClass, kSituationType, kJavaLangString);
    jfieldID sourceDeviceId = env->GetFieldID(jcClass, kSourceDeviceId, kJavaLangString);
    jfieldID eventTime = env->GetFieldID(jcClass, "eventTime", kJavaLangString);
    jstring str_generatorDeviceId = (jstring)env->GetObjectField(eventToInsert, generatorDeviceId);
    jstring str_situationType = (jstring)env->GetObjectField(eventToInsert, situationType);
    jstring str_sourceDeviceId = (jstring)env->GetObjectField(eventToInsert, sourceDeviceId);
    jstring str_eventTime = (jstring)env->GetObjectField(eventToInsert, eventTime);
    jclass c_Object = env->FindClass( "java/lang/Object");
    jclass c_Hashtable = env->FindClass( "java/util/Hashtable");
    jclass c_Enumeration = env->FindClass( "java/util/Enumeration");
    jmethodID m_toString = env->GetMethodID( c_Object, "toString", "()Ljava/lang/String;");
    jmethodID m_keys = env->GetMethodID( c_Hashtable, "keys", "()Ljava/util/Enumeration;");
    jmethodID m_hasMoreElements = env->GetMethodID( c_Enumeration, "hasMoreElements", "()Z");
    jmethodID m_nextElement = env->GetMethodID( c_Enumeration, "nextElement", "()Ljava/lang/Object;");
    jmethodID m_get = env->GetMethodID( c_Hashtable, "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
    jboolean isCopy;  jobject jKey, jValue;
    jstring jKeyString, jValueString;
    jobject jKeys = env->CallObjectMethod( jHashtable, m_keys);

    VxSdk::VxKvObject *kvObj = new VxSdk::VxKvObject[size];
    newEvent.properties = kvObj;
    int i = 0;
    while (env->CallBooleanMethod( jKeys, m_hasMoreElements)) {
        const char* key = nullptr; const char* value = nullptr;
        jKey =env->CallObjectMethod( jKeys, m_nextElement);
        jKeyString = (jstring)env->CallObjectMethod(jKey, m_toString);
        jValue = env->CallObjectMethod( jHashtable, m_get, jKeyString);
        jValueString = (jstring)env->CallObjectMethod(jValue, m_toString);
        key = env->GetStringUTFChars( jKeyString, &isCopy);
        value =env->GetStringUTFChars( jValueString, &isCopy);
        VxSdk::Utilities::StrCopySafe(newEvent.properties[i].key, key);
        VxSdk::Utilities::StrCopySafe(newEvent.properties[i].value, value);
        i++;
    }

    VxSdk::Utilities::StrCopySafe(newEvent.generatorDeviceId, env->GetStringUTFChars(str_generatorDeviceId, JNI_FALSE));
    VxSdk::Utilities::StrCopySafe(newEvent.situationType, env->GetStringUTFChars(str_situationType, JNI_FALSE));
    VxSdk::Utilities::StrCopySafe(newEvent.sourceDeviceId, env->GetStringUTFChars(str_sourceDeviceId, JNI_FALSE));
    VxSdk::Utilities::StrCopySafe(newEvent.time, env->GetStringUTFChars(str_eventTime, JNI_FALSE));

    VxSdk::VxResult::Value result = _system->InsertEvent(newEvent);
    if (result == VxSdk::VxResult::kOK)
    {
        return true;
    }
    return false;
}

/// <summary>
/// Events callback method that will be regsisterd for revceiving notifications from VxSDK
/// </summary>
/// <param name="ev">Event data from VxSDK</param>
void EventsCallBack(VxSdk::IVxEvent* ev) {
    JNIEnv *env;
    jint rs = jvm->AttachCurrentThread((void **)&env, NULL);
    Jni_Event* jniEvent = CreateJniClassForEvent(env);
    if (nullptr == jniEvent) {
        LOGGER->Log(kClassInitFailed);
    }

    jclass eventControlClass = env->GetObjectClass(_eventControlObj);
    jmethodID mid = env->GetMethodID(eventControlClass, kEventsCallBack, "(Ljavasample/JEvent;)V");
    if (mid == NULL) {
        LOGGER->Log("Failed to create call Java method from JNI.");
        return;
    }

    jobject jEventObj = env->NewObject(jniEvent->cls, jniEvent->constructortorID);
    SetEventDetailsToJniObject(env, jniEvent, jEventObj, ev);
    env->CallVoidMethod(_eventControlObj, mid, jEventObj);
}

/// <summary>
/// Subscribe to event notifications
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="sysObj">JSystem Java class instance</param>
JNIEXPORT jboolean JNICALL Java_javasample_JSystem_SubscribeEvents(JNIEnv *env, jobject sysObj) {
    jint rs = env->GetJavaVM(&jvm);
    _eventControlObj = env->NewGlobalRef(sysObj);
    VxSdk::VxResult::Value result = _system->StartNotifications(EventsCallBack);
    return result == VxSdk::VxResult::kOK;
}

/// <summary>
/// Unsubscribe to event notifications
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="sysObj">JSystem Java class instance</param>
JNIEXPORT jboolean JNICALL Java_javasample_JSystem_UnsubscribeEvents(JNIEnv *env, jobject sysObj) {
    VxSdk::VxResult::Value result = _system->StopNotifications();
    return result == VxSdk::VxResult::kOK;
}

/// <summary>
/// Delete a situation from system
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="sysObj">JSystem Java class instance</param>
/// <param name="sitnToDelete">JSituation Java class instance</param>
JNIEXPORT jboolean JNICALL Java_javasample_JSystem_DeleteSituation(JNIEnv *env, jobject sysObj, jobject sitnToDelete) {
    LOGGER->Log("Java_javasample_JSystem_DeleteSituation");
    jclass situationClass = env->GetObjectClass(sitnToDelete);
    jfieldID situationPointerId = env->GetFieldID(situationClass, kVxSituation, "J");
    VxSdk::IVxSituation* delSituation = (VxSdk::IVxSituation*)env->GetLongField(sitnToDelete, situationPointerId);
    if (delSituation == nullptr) {
        LOGGER->Log(kExportPointerFailed);
        return false;
    }

    VxSdk::VxResult::Value result = delSituation->DeleteSituation();
    LOGGER->Log("Java_javasample_JSystem_DeleteSituation Result  %d", result);
    if (result == VxSdk::VxResult::kOK) {
        return true;
    }
    return false;
}

/// <summary>
/// Add a new situation to system
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="sysObj">JSystem Java class instance</param>
/// <param name="situationObj">JSituation Java class instance</param>
JNIEXPORT jboolean JNICALL Java_javasample_JSystem_AddSituation(JNIEnv *env, jobject sysObj, jobject situationObj) {
    VxSdk::VxNewSituation vxSituation;
    int size = 3; //For snooze intervals array. It will always be 3
    jclass jcClass = env->GetObjectClass(situationObj);
    jfieldID nameField = env->GetFieldID(jcClass, "name", kJavaLangString);
    jfieldID sourceDeviceIdField = env->GetFieldID(jcClass, kSourceDeviceId, kJavaLangString);
    jfieldID situationTypeField = env->GetFieldID(jcClass, kSituationType, kJavaLangString);
    jfieldID severityField = env->GetFieldID(jcClass, kSeverity, "I");
    jfieldID audiblePlayCountField = env->GetFieldID(jcClass, kAudiblePlayCount, "I");
    jfieldID audibleLoopDelayField = env->GetFieldID(jcClass, kAudibleLoopDelay, "I");
    jfieldID autoAcknowledgeField = env->GetFieldID(jcClass, kAutoAcknowledge, "I");
    jfieldID audibleNotifyField = env->GetFieldID(jcClass, kAudibleNotify, "Z");
    jfieldID ackNeededField = env->GetFieldID(jcClass, kAckNeeded, "Z");
    jfieldID expandBannerField = env->GetFieldID(jcClass, kExpandBanner, "Z");
    jfieldID logField = env->GetFieldID(jcClass, "log", "Z");
    jfieldID notifyField = env->GetFieldID(jcClass, kNotify, "Z");
    jfieldID snoozeIntervals = env->GetFieldID(jcClass, kSnoozeIntervals, "[I");
    jstring name = (jstring)env->GetObjectField(situationObj, nameField);
    jstring sourceDeviceId = (jstring)env->GetObjectField(situationObj, sourceDeviceIdField);
    jstring situationType = (jstring)env->GetObjectField(situationObj, situationTypeField);
    jint severity = env->GetIntField(situationObj, severityField);
    jint audiblePlayCount = env->GetIntField(situationObj, audiblePlayCountField);
    jint audibleLoopDelay = env->GetIntField(situationObj, audibleLoopDelayField);
    jint autoAcknowledge = env->GetIntField(situationObj, autoAcknowledgeField);
    jboolean audibleNotify = env->GetBooleanField(situationObj, audibleNotifyField);
    jboolean ackNeeded = env->GetBooleanField(situationObj, ackNeededField);
    jboolean expandBanner = env->GetBooleanField(situationObj, expandBannerField);
    jboolean log = env->GetBooleanField(situationObj, logField);
    jboolean notify = env->GetBooleanField(situationObj, notifyField);
    jobject intervalData = env->GetObjectField(jcClass, snoozeIntervals);
    jintArray * arr = reinterpret_cast<jintArray*>(&intervalData);
    jint *data = env->GetIntArrayElements(*arr, 0);
    int *intervals = new int[size];
    for (int i = 0; i < size; i++) {
        intervals[i] = data[i];
    }

    vxSituation.snoozeIntervals = intervals;
    vxSituation.isAckNeeded = ackNeeded;
    vxSituation.audibleLoopDelay = audibleLoopDelay;
    vxSituation.shouldAudiblyNotify = audibleNotify;
    vxSituation.audiblePlayCount = audiblePlayCount;
    vxSituation.autoAcknowledge = autoAcknowledge;
    vxSituation.shouldExpandBanner = expandBanner;
    vxSituation.shouldLog = log;
    VxSdk::Utilities::StrCopySafe(vxSituation.name, env->GetStringUTFChars(name, JNI_FALSE));
    vxSituation.shouldNotify = notify;
    vxSituation.severity = severity;
    VxSdk::Utilities::StrCopySafe(vxSituation.sourceDeviceId, env->GetStringUTFChars(sourceDeviceId, JNI_FALSE));
    VxSdk::Utilities::StrCopySafe(vxSituation.type, env->GetStringUTFChars(situationType, JNI_FALSE));

    VxSdk::VxResult::Value result = _system->AddSituation(vxSituation);
    if (result == VxSdk::VxResult::kOK) {
        LOGGER->Log("Succesfully added new Situation");
    }
    else{
        LOGGER->Log("Failed to add new Situation");
    }

    return result == VxSdk::VxResult::kOK;
}
