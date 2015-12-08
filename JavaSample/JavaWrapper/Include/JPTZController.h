#include "javasample_JPTZController.h"

namespace CPPJni{
    typedef struct Jni_PTZController{
        jclass cls;
        jmethodID constructortorID;
        jfieldID ptzControlPointer;

    } Jni_PTZController;

    typedef struct Jni_Preset{
        jclass cls;
        jmethodID constructortorID;

        jfieldID name;
        jfieldID description;
        jfieldID presetPointer;

    } Jni_Preset;

    typedef struct Jni_Pattern{
        jclass cls;
        jmethodID constructortorID;

        jfieldID name;
        jfieldID description;
        jfieldID patternPointer;

    } Jni_Pattern;

}