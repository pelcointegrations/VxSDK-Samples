#include "javasample_JDevice.h"

namespace CPPJni{
    typedef struct Jni_Clip{
        jclass cls;
        jmethodID constructortorID;

        jfieldID type;
        jfieldID startTime;
        jfieldID endTime;
        jfieldID dataSourceID;
        jfieldID clipPointer;

    } Jni_Clip;

}