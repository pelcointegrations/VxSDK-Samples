#include "javasample_JEvent.h"

namespace CPPJni {
    typedef struct Jni_Event{
        jclass cls;
        jmethodID constructortorID;

        jfieldID generatorDeviceId;
        jfieldID id;
        jfieldID time;

        jfieldID situationType;
        jfieldID sourceDeviceId;
        jfieldID sourceUserName;

        jfieldID severity;
        jfieldID ackState;
    } Jni_Event;
}