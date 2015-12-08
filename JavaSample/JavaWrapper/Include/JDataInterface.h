#include "javasample_JDevice.h"

namespace CPPJni{
    typedef struct Jni_DataInterface{
        jclass cls;
        jmethodID constructortorID;
        
        jfieldID streamProtocol;
        jfieldID dataInterfacePointer;

    } Jni_DataInterface;

}