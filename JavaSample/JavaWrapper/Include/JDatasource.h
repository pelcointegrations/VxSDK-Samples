#pragma once
#include "javasample_JDataSource.h"
#include "VxSdk.h"

namespace CPPJni{
    typedef struct Jni_Datasource{
        jclass cls;
        jmethodID constructortorID;
        jfieldID name;
        jfieldID ip;
        jfieldID id;
        jfieldID number;
        jfieldID live;
        jfieldID datasourcePointer;
    } Jni_Datasource;
}
