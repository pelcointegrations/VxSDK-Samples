#include "javasample_JSituation.h"

namespace CPPJni{

    typedef struct Jni_Situation{
        jclass cls;
        jmethodID constructortorID;

        jfieldID situationType;
        jfieldID sourceDeviceId;
        jfieldID severity;

        jfieldID notificationIds;
        jfieldID snoozeIntervals;
        jfieldID audiblePlayCount;

        jfieldID audibleLoopDelay;
        jfieldID autoAcknowledge;
        jfieldID audibleNotify;

        jfieldID ackNeeded;
        jfieldID expandBanner;
        jfieldID log;

        jfieldID notify;
        jfieldID name;
        jfieldID situationPointer;

    } Jni_Situation;
}