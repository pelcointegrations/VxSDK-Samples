#include "javasample_JExport.h"

namespace CPPJni{

    typedef struct Jni_Export{
        jclass cls;
        jmethodID constructortorID;

        jfieldID exportCompleted;
        jfieldID exportId;
        jfieldID exportInitiated;
        jfieldID exportName;
        jfieldID exportOwner;
        jfieldID exportDataUri;
        jfieldID exportPercentComplete;
        jfieldID exportIsProtected;
        jfieldID exportClipSize;
        jfieldID exportSecondsRemaining;
        jfieldID exportFileSizeKb;
        jfieldID exportFormat;
        jfieldID exportStatus;
        jfieldID exportPointer;

    } Jni_Export;
}