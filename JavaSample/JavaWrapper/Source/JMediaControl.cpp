#include "stdafx.h"
#include "JMediaControl.h"
#include "VxSdk.h"
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include "Logger.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace CPPJni;

//Global variables
//static JavaVM *g_jvm;
//static jobject g_mediaControlObj = nullptr;

/// <summary>
// Returns the MediaController pointer stored in Java JMediaControl class
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
MediaController::IController* GetMediaControllerObj(JNIEnv *env, jobject mediaControlObj) {
    jclass mediaControlClass = env->GetObjectClass(mediaControlObj);
    jfieldID mediaControlPointerId = env->GetFieldID(mediaControlClass, CPPJni::kMediaControlHandle, "J");

    return (MediaController::IController*)env->GetLongField(mediaControlObj, mediaControlPointerId);
}

/// <summary>
// Timestamp callback received at JNI side which will then fired to Java VM
/// </summary>
/// <param name="timeEvent">Timestamp event information from MediaController</param>
void TimestampCallback(MediaController::TimestampEvent* timeEvent) {

    JNIEnv *env;

    Jni_JMediaControl* mediaControJniObj = (Jni_JMediaControl*)timeEvent->eventData;
    if (nullptr == mediaControJniObj){
        LOGGER->Log("Event callback received, but mediaControJniObj received as null.");
        return;
    }

    mediaControJniObj->jvm->AttachCurrentThread((void **)&env, nullptr);

    jobject mediaControlObj = mediaControJniObj->mediaControlJavObj;
    jclass mediaControlClass = env->GetObjectClass(mediaControlObj);

    if (nullptr == mediaControlClass){
        LOGGER->Log("Event callback: Failed to recreate Java JMediaControl class.");
        return;
    }

    //Using the object of JMediaControl, invoke the TimeStampCallback method defined in mediaControlObj with time event data
    jmethodID mid = env->GetMethodID(mediaControlClass, "TimeStampCallback", "(Ljava/lang/String;)V");
    if (mid == nullptr) {
        LOGGER->Log("Event callback: Failed to create call Java method from JNI.");
        return;
    }

    time_t timestamp = timeEvent->unixTime;
    struct tm timeinfo;
    stringstream fmt;

    localtime_s(&timeinfo, &timestamp);
    fmt << (timeinfo.tm_year + 1900) << "-"
        << std::setfill('0') << std::setw(2) << (timeinfo.tm_mon + 1) << "-"
        << std::setfill('0') << std::setw(2) << timeinfo.tm_mday << " "
        << std::setfill('0') << std::setw(2) << timeinfo.tm_hour << ":"
        << std::setfill('0') << std::setw(2) << timeinfo.tm_min << ":"
        << std::setfill('0') << std::setw(2) << timeinfo.tm_sec;

    jstring callBackData = env->NewStringUTF(fmt.str().c_str());
    env->CallVoidMethod(mediaControlObj, mid, callBackData);
}

/// <summary>
// This is the first call to made to initialize MediaController, store the jvm and caller MediaController object
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
/// <param name="dataSourceObj">JDataSource Java class instance. VxSDK datasource pointer inside this class will be used
/// for invoking MediaController library</param>
/// <param name="streamProtocol">Stream protocol enum value. Can be RTSP or MJPEG</param>
JNIEXPORT jboolean JNICALL Java_javasample_JMediaControl_InvokeMediaController
(JNIEnv *env, jobject mediaControlObj, jobject dataSourceObj, jint streamProtocol) {
    jclass mediaControlClass = env->GetObjectClass(mediaControlObj);

    jclass datasourceClass = env->GetObjectClass(dataSourceObj);
    jfieldID datasourcePointerId = env->GetFieldID(datasourceClass, CPPJni::kVxDataSource, "J");
    VxSdk::IVxDataSource* vxDatasource = (VxSdk::IVxDataSource*)env->GetLongField(dataSourceObj, datasourcePointerId);

    if (vxDatasource == nullptr) {
        LOGGER->Log(CPPJni::kDataSourceFailed);
        return false;
    }

    MediaController::MediaRequest request;
    request.dataSource = vxDatasource;
    request.dataInterface = *vxDatasource->dataInterfaces[0];

    MediaController::IController* control = nullptr;
    MediaController::GetController(&request, &control); //Initializing the MediaController library

    //Store the media control pointer in Java instance for later use
    jfieldID mediaControlPointer = env->GetFieldID(mediaControlClass, CPPJni::kMediaControlHandle, "J");
    env->SetLongField(mediaControlObj, mediaControlPointer, (long)control);

    jfieldID mediaControlJNIPointer = env->GetFieldID(mediaControlClass, CPPJni::kMediaControlJNIHandle, "J");
    Jni_JMediaControl* mediaControlJni = new Jni_JMediaControl;
    mediaControlJni->mediaControlJavObj = env->NewGlobalRef(mediaControlObj);
    mediaControlJni->callBackMethod = TimestampCallback;
    env->GetJavaVM(&mediaControlJni->jvm);

    env->SetLongField(mediaControlObj, mediaControlJNIPointer, (long)mediaControlJni);

    return true;
}

/// <summary>
// Set a different datasource to already initialized MediaController instance
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
/// <param name="dataSourceObj">JDataSource class instance</param>
/// <param name="protocol">Protocol to set. Can be RTSP or MJPEG</param>
JNIEXPORT jboolean JNICALL Java_javasample_JMediaControl_SetDataSource
(JNIEnv *env, jobject mediaControlObj, jobject dataSourceObj, jint protocol) {
    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);

    jclass datasourceClass = env->GetObjectClass(dataSourceObj);
    jfieldID datasourcePointerId = env->GetFieldID(datasourceClass, CPPJni::kVxDataSource, "J");
    VxSdk::IVxDataSource* vxDatasource = (VxSdk::IVxDataSource*)env->GetLongField(dataSourceObj, datasourcePointerId);

    if (vxDatasource == nullptr) {
        LOGGER->Log(CPPJni::kDataSourceFailed);
        return false;
    }

    MediaController::MediaRequest request;
    request.dataSource = vxDatasource;
    request.dataInterface = *vxDatasource->dataInterfaces[0];
    control->NewRequest(request); //Set a new request with another datasource
    return true;
}

/// <summary>
// Set window handle to which video needs to be streamed from lower layer GStreamer in MediaController library
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
/// <param name="windowHandle">Window handle instance.</param>
JNIEXPORT void JNICALL Java_javasample_JMediaControl_SetVideoWindow
(JNIEnv *env, jobject mediaControlObj, jlong windowHandle) {
    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);
    control->SetWindow((void*)windowHandle);
}

/// <summary>
// Subscribe to timestamp events. A method written in JNI class(TimestampCallback) shall be used for subscribing.
// From TimestampCallback, JMediaControl Java class' TimestampCallback method will be invoked.
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
JNIEXPORT void JNICALL Java_javasample_JMediaControl_SubscribeTimeStampEvents
(JNIEnv *env, jobject mediaControlObj) {
    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);

    jclass mediaControlClass = env->GetObjectClass(mediaControlObj);
    jfieldID mediaControlJNIPointerId = env->GetFieldID(mediaControlClass, CPPJni::kMediaControlJNIHandle, "J");
    
    Jni_JMediaControl* mediaControlJni = (Jni_JMediaControl*)env->GetLongField(mediaControlObj, mediaControlJNIPointerId);
    control->AddEventData(mediaControlJni);
    control->AddObserver(mediaControlJni->callBackMethod);
}

/// <summary>
// Unsubsribe events. Inform MediaController not to send timestamp events any more
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
JNIEXPORT void JNICALL Java_javasample_JMediaControl_UnSubscribeTimeStampEvents
(JNIEnv *env, jobject mediaControlObj) {
    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);
    control->ClearObservers();
}

/// <summary>
// Send a Play request to MediaController object
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
/// <param name="speed">speed of playback stream</param>
JNIEXPORT void JNICALL Java_javasample_JMediaControl_Play
(JNIEnv *env, jobject mediaControlObj, jfloat speed) {
    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);
    control->Play(speed);
}

/// <summary>
// Send a Pause request to MediaController object
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
JNIEXPORT void JNICALL Java_javasample_JMediaControl_Pause
(JNIEnv *env, jobject mediaControlObj) {
    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);
    control->Pause();
}

/// <summary>
// Send a Stop request to MediaController object
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
JNIEXPORT void JNICALL Java_javasample_JMediaControl_Stop
(JNIEnv *env, jobject mediaControlObj) {
    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);
    control->Stop();
}

/// <summary>
// Send a GoToLive request to MediaController object
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
JNIEXPORT void JNICALL Java_javasample_JMediaControl_GotoLive
(JNIEnv *env, jobject mediaControlObj) {
    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);
    control->GoToLive();
}

/// <summary>
// Send a Seek request to MediaController object
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
/// <param name="time">seek time to start playbcak</param>
/// <param name="speed">Speed of playback streams</param>
JNIEXPORT void JNICALL Java_javasample_JMediaControl_Seek
(JNIEnv *env, jobject mediaControlObj, jint time, jfloat speed) {
    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);
    LOGGER->Log("Seek to:%d", time);
    control->Play(speed, time);
}

/// <summary>
// Finally delete the MediaCOntroller once it is no longer required
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="mediaControlObj">JMediaControl Java class instance</param>
JNIEXPORT void JNICALL Java_javasample_JMediaControl_Delete
(JNIEnv *env, jobject mediaControlObj){

    jclass mediaControlClass = env->GetObjectClass(mediaControlObj);
    jfieldID mediaControlJNIPointerId = env->GetFieldID(mediaControlClass, CPPJni::kMediaControlJNIHandle, "J");

    Jni_JMediaControl* mediaControlJni = (Jni_JMediaControl*)env->GetLongField(mediaControlObj, mediaControlJNIPointerId);
    env->DeleteGlobalRef(mediaControlJni->mediaControlJavObj);
    delete mediaControlJni;

    MediaController::IController* control = GetMediaControllerObj(env, mediaControlObj);
    delete control;
    
}
