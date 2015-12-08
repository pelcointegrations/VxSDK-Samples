#include "javasample_JMediaControl.h"
#include "MediaController.h"

namespace CPPJni {
    typedef void(*TimeStampCallBack)(MediaController::TimestampEvent* linkedList);

    typedef struct Jni_JMediaControl {
        JavaVM * jvm;
        jobject mediaControlJavObj;
        TimeStampCallBack callBackMethod;
    } Jni_JMediaControl;
}
