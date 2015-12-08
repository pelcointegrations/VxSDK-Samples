#include "javasample_JDevice.h"
#include "VxSdk.h"

namespace CPPJni{
    typedef struct Jni_Device{
        jclass cls;
        jmethodID constructortorID;

        jfieldID deviceName;
        jfieldID deviceIP;
        jfieldID deviceModel;
        jfieldID deviceVersion;
        jfieldID deviceID;
        jfieldID deviceCommissioned;
        jfieldID deviceLicenseRequired;
        jfieldID devicePassword;
        jfieldID devicePelcoHardware;
        jfieldID deviceSerial;
        jfieldID deviceUsername;
        jfieldID deviceVendor;
        jfieldID deviceVirtualIp;
        jfieldID deviceState;
        jfieldID deviceType;

        jfieldID devicePointer;
    } Jni_Device;
}