#include "stdafx.h"
#include "JPTZController.h"
#include "VxSdk.h"
#include "Logger.h"

using namespace CPPJni;

/// <summary>
// Returns the VxSDK ptz controller pointer stored in Java PTZController
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
VxSdk::IVxPtzController* GetPTZControllerObj(JNIEnv *env, jobject ptzControlObj) {
    jclass ptzControlClass = env->GetObjectClass(ptzControlObj);
    jfieldID ptzControlPointer = env->GetFieldID(ptzControlClass, "vxPTZController", "J");

    return (VxSdk::IVxPtzController*)env->GetLongField(ptzControlObj, ptzControlPointer);
}

/// <summary>
// Returns the VxSDK preset pointer stored in Java Preset class
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="presetObj">JPreset Java class instance</param>
VxSdk::IVxPreset* GetPresetObj(JNIEnv *env, jobject presetObj) {
    jclass presetClass = env->GetObjectClass(presetObj);
    jfieldID presetPointer = env->GetFieldID(presetClass, kVxPreset, "J");

    return (VxSdk::IVxPreset*)env->GetLongField(presetObj, presetPointer);
}

/// <summary>
// Returns the VxSDK pattern pointer stored in Java Pattern class
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="patternObj">JPattern Java class instance</param>
VxSdk::IVxPattern* GetPatternObj(JNIEnv *env, jobject patternObj) {
    jclass patternClass = env->GetObjectClass(patternObj);
    jfieldID patternPointer = env->GetFieldID(patternClass, kVxPattern, "J");

    return (VxSdk::IVxPattern*)env->GetLongField(patternObj, patternPointer);
}

/// <summary>
// Create and return JNI type wrapper for Java JPreset object
/// </summary>
/// <param name="env">Jni environment pointer</param>
Jni_Preset* CreateJniClassForPreset(JNIEnv * env) {
    Jni_Preset * jniPreset = nullptr;
    jniPreset = new Jni_Preset;
    jniPreset->cls = env->FindClass("javasample/JPreset");

    if (jniPreset->cls == nullptr)
    {
        LOGGER->Log("Failed to create class JPreset");
        return nullptr;
    }

    jniPreset->constructortorID = env->GetMethodID(jniPreset->cls, kInit, "()V");
    if (jniPreset->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JPreset class");
        return nullptr;
    }

    jniPreset->name = env->GetFieldID(jniPreset->cls, "name", kJavaLangString);
    jniPreset->description = env->GetFieldID(jniPreset->cls, kDescription, kJavaLangString);
    jniPreset->presetPointer = env->GetFieldID(jniPreset->cls, kVxPreset, "J");

    return jniPreset;
}

/// <summary>
// Create and return JNI type wrapper for Java JPattern object
/// </summary>
/// <param name="env">Jni environment pointer</param>
Jni_Pattern* CreateJniClassForPattern(JNIEnv * env) {
    Jni_Pattern * jniPattern = nullptr;
    jniPattern = new Jni_Pattern;
    jniPattern->cls = env->FindClass("javasample/JPattern");

    if (jniPattern->cls == nullptr)
    {
        LOGGER->Log("Failed to create class JPattern");
        return nullptr;
    }

    jniPattern->constructortorID = env->GetMethodID(jniPattern->cls, kInit, "()V");
    if (jniPattern->constructortorID == nullptr) {
        LOGGER->Log("Failed to create constructor id for JPattern class");
        return nullptr;
    }

    jniPattern->name = env->GetFieldID(jniPattern->cls, "name", kJavaLangString);
    jniPattern->description = env->GetFieldID(jniPattern->cls, kDescription, kJavaLangString);
    jniPattern->patternPointer = env->GetFieldID(jniPattern->cls, kVxPattern, "J");

    return jniPattern;
}

/// <summary>
// Assign to properties of Java JPreset class object reading from JNI wrapper and VxSDK preset data
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="presetObj">Jni preset wrapper filled with JPreset types</param>
/// <param name="jPresetObj">Java preset object to be updated</param>
/// <param name=kVxPreset>Actual vxSDK preset pointer from data to be read</param>
void SetPresetDetailsToJniObject(JNIEnv * env, Jni_Preset* presetObj, jobject jPresetObj, VxSdk::IVxPreset* vxPreset) {
    env->SetObjectField(jPresetObj, presetObj->name, env->NewStringUTF(vxPreset->name));
    env->SetObjectField(jPresetObj, presetObj->description, env->NewStringUTF(vxPreset->description));
    env->SetLongField(jPresetObj, presetObj->presetPointer, (long)vxPreset);
}

/// <summary>
// Assign to properties of Java JPattern class object reading from JNI wrapper and VxSDK pattern data
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="patternObj">Jni pattern wrapper filled with JPreset types</param>
/// <param name="jPatternObj">Java pattern object to be updated</param>
/// <param name=kVxPattern>Actual vxSDK pattern pointer from data to be read</param>
void SetPatternDetailsToJniObject(JNIEnv * env, Jni_Pattern* patternObj, jobject jPatternObj, VxSdk::IVxPattern* vxPattern) {
    env->SetObjectField(jPatternObj, patternObj->name, env->NewStringUTF(vxPattern->name));
    env->SetObjectField(jPatternObj, patternObj->description, env->NewStringUTF(vxPattern->description));
    env->SetLongField(jPatternObj, patternObj->patternPointer, (long)vxPattern);
}

/// <summary>
// Method used for invoking Move function in VxSDK
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="speedX">Negative values pan left, Positive values pan right</param>
/// <param name="speedY">Negative values tilt downward, Positive values tilt upward</param>
/// <param name="zoomDirection">Zoom Direction enum value</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_ContinuousMove
(JNIEnv *env, jobject ptzControlObj, jint speedX, jint speedY, jint zoomDirection) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value res = vxPtzControl->ContinuousMove(speedX, speedY, VxSdk::VxZoomDirection::Value(zoomDirection));
    
    if (res == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Method used for triggering a preset on datasource
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="presetObj">JPreset Java class object</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_TriggerPreset
(JNIEnv *env, jobject ptzControlObj, jobject presetObj) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }

    VxSdk::IVxPreset* vxPresetObj = GetPresetObj(env, presetObj);
    if (vxPresetObj == nullptr) {
        LOGGER->Log("Failed to get preset pointer.");
        return false;
    }
    VxSdk::VxResult::Value res = vxPtzControl->TriggerPreset(*vxPresetObj);

    if (res == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Method used for triggering a pattern on datasource
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="patternObj">JPattern Java class object</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_TriggerPattrn
(JNIEnv *env, jobject ptzControlObj, jobject patternObj) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }

    VxSdk::IVxPattern* vxPatternObj = GetPatternObj(env, patternObj);
    if (vxPatternObj == nullptr) {
        LOGGER->Log("Failed to get pattern pointer.");
        return false;
    }
    VxSdk::VxResult::Value res = vxPtzControl->TriggerPattern(*vxPatternObj);

    if (res == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Method used for stoping the current PTZ movement associated with this PTZController
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
JNIEXPORT void JNICALL Java_javasample_JPTZController_PTZStop
(JNIEnv *env, jobject ptzControlObj) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return;
    }
    vxPtzControl->PtzStop();
}

/// <summary>
// Returns the presets available for the datasource associated with the PTZController instance
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
JNIEXPORT jobjectArray JNICALL Java_javasample_JPTZController_GetPresets
(JNIEnv *env, jobject ptzControlObj) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return nullptr;
    }

    jobjectArray presetsList = nullptr;
    int presetsCount = 0;
    Jni_Preset * jniPreset = CreateJniClassForPreset(env);


    VxSdk::VxCollection<VxSdk::IVxPreset**> presets;
    VxSdk::VxResult::Value result = vxPtzControl->GetPresets(presets);

    if (result == VxSdk::VxResult::kInsufficientSize) {
        presets.collection = new VxSdk::IVxPreset*[presets.collectionSize];
        result = vxPtzControl->GetPresets(presets);
        if (result == VxSdk::VxResult::kOK) {
            presetsCount = presets.collectionSize;
            presetsList = env->NewObjectArray(presets.collectionSize, jniPreset->cls, nullptr);
            for (int i = 0; i < presets.collectionSize; i++) {
                jobject jPresetObj = env->NewObject(jniPreset->cls, jniPreset->constructortorID);
                SetPresetDetailsToJniObject(env, jniPreset, jPresetObj, presets.collection[i]);
                env->SetObjectArrayElement(presetsList, i, jPresetObj);
            }
        }
        delete[] presets.collection;
    }
    delete jniPreset;

    if (presetsList != nullptr) {
        LOGGER->Log(std::to_string(presetsCount) + " presets found.");
    }
    return presetsList;
}

/// <summary>
// Returns the patterns available for the datasource associated with the PTZController instance
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
JNIEXPORT jobjectArray JNICALL Java_javasample_JPTZController_GetPatterns
(JNIEnv *env, jobject ptzControlObj) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return nullptr;
    }

    jobjectArray patternList = nullptr;
    int patternsCount = 0;
    Jni_Pattern * jniPattern = CreateJniClassForPattern(env);


    VxSdk::VxCollection<VxSdk::IVxPattern**> patterns;
    VxSdk::VxResult::Value result = vxPtzControl->GetPatterns(patterns);

    if (result == VxSdk::VxResult::kInsufficientSize) {
        patterns.collection = new VxSdk::IVxPattern*[patterns.collectionSize];
        result = vxPtzControl->GetPatterns(patterns);
        if (result == VxSdk::VxResult::kOK) {
            patternsCount = patterns.collectionSize;
            patternList = env->NewObjectArray(patterns.collectionSize, jniPattern->cls, nullptr);
            for (int i = 0; i < patterns.collectionSize; i++) {
                jobject jPatternObj = env->NewObject(jniPattern->cls, jniPattern->constructortorID);
                SetPatternDetailsToJniObject(env, jniPattern, jPatternObj, patterns.collection[i]);
                env->SetObjectArrayElement(patternList, i, jPatternObj);
            }
        }
        delete[] patterns.collection;
    }
    delete jniPattern;

    if (patternList != nullptr) {
        LOGGER->Log(std::to_string(patternsCount) + " patterns found.");
    }
    return patternList;
}

/// <summary>
// Send the focus command to camera associated with this PTZController.
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="focusDirection">Focus direction value</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_ContinuousFocus
(JNIEnv *env, jobject ptzControlObj, jint focusDirection) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->ContinuousFocus(VxSdk::VxFocusDirection::Value(focusDirection));

    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Send the iris command to camera associated with this PTZController.
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="irisDirection">Iris direction value</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_ContinuousIris
(JNIEnv *env, jobject ptzControlObj, jint irisDirection) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->ContinuousIris(VxSdk::VxIrisDirection::Value(irisDirection));

    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Send absolute pan position command to camera associated with this PTZController.
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="x">Pan position</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_AbsolutePan
(JNIEnv *env, jobject ptzControlObj, jint x) {
    LOGGER->Log("Java_javasample_JPTZController_AbsolutePan");
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->AbsolutePan(x);

    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Send absolute tilt position command to camera associated with this PTZController.
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="y">Tilt position</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_AbsoluteTilt
(JNIEnv *env, jobject ptzControlObj, jint y) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->AbsoluteTilt(y);

    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Send absolute zoom position command to camera associated with this PTZController.
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="z">Zoom position</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_AbsoluteZoom
(JNIEnv *env, jobject ptzControlObj, jint z) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->AbsoluteZoom(z);

    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Send absolute move command without z value to camera associated with this PTZController.
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="x">Pan position</param>
/// <param name="y">Tilt position</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_AbsoluteMove__II
(JNIEnv *env, jobject ptzControlObj, jint x, jint y) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->AbsoluteMove(x, y);

    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Send absolute move command with x,y and z value to camera associated with this PTZController.
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="x">Pan position</param>
/// <param name="y">Tilt position</param>
/// <param name="z">Zoom position</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_AbsoluteMove__III
(JNIEnv *env, jobject ptzControlObj, jint x, jint y, jint z) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->AbsoluteMove(x, y, z);

    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}

/// <summary>
// Get the current X Position of camera associated with this PTZController
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
JNIEXPORT jint JNICALL Java_javasample_JPTZController_GetX
(JNIEnv *env, jobject ptzControlObj) {
    int x, y, z;
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->GetPosition(x, y, z);

    if (result == VxSdk::VxResult::kOK)
        return x;

    return NULL;
}

/// <summary>
// Get the current y Position of camera associated with this PTZController
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
JNIEXPORT jint JNICALL Java_javasample_JPTZController_GetY
(JNIEnv *env, jobject ptzControlObj) {
    int x, y, z;
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->GetPosition(x, y, z);

    if (result == VxSdk::VxResult::kOK)
        return y;

    return NULL;
}

/// <summary>
// Get the current y Position of camera associated with this PTZController
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
JNIEXPORT jint JNICALL Java_javasample_JPTZController_GetZ
(JNIEnv *env, jobject ptzControlObj) {
    int x, y, z;
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->GetPosition(x, y, z);

    if (result == VxSdk::VxResult::kOK)
        return z;

    return NULL;
}

/// <summary>
// Send relative move command with x,y and z value to camera associated with this PTZController.
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="ptzControlObj">JPTZControl Java class instance</param>
/// <param name="x">Pan position</param>
/// <param name="y">Tilt position</param>
/// <param name="z">Zoom position</param>
JNIEXPORT jboolean JNICALL Java_javasample_JPTZController_RelativeMove
(JNIEnv *env, jobject ptzControlObj, jint x, jint y, jint z) {
    VxSdk::IVxPtzController* vxPtzControl = GetPTZControllerObj(env, ptzControlObj);
    if (vxPtzControl == nullptr) {
        LOGGER->Log(kPtzControllerFailed);
        return false;
    }
    VxSdk::VxResult::Value result = vxPtzControl->RelativeMove(x, y, z);

    if (result == VxSdk::VxResult::kOK)
        return true;

    return false;
}
