#ifndef Constants_H__
#define Constants_H__
#pragma once

namespace CPPJni {
    static const int kSslPort = 443;
    static const char* kSdkKey = "ReplaceWithGeneratedKey";

    static const char* kInit = "<init>";
    static const char* kJavaLangString = "Ljava/lang/String;";
    static const char* kAckNeeded = "ackNeeded";
    static const char* kAudibleLoopDelay = "audibleLoopDelay";
    static const char* kAudibleNotify = "audibleNotify";
    static const char* kAudiblePlayCount = "audiblePlayCount";
    static const char* kAutoAcknowledge = "autoAcknowledge";
    static const char* kEventsCallBack = "EventsCallBack";
    static const char* kExpandBanner = "expandBanner";
    static const char* kNotify = "notify";
    static const char* kSeverity = "severity";
    static const char* kSituationType = "situationType";
    static const char* kSnoozeIntervals = "snoozeIntervals";
    static const char* kSourceDeviceId = "sourceDeviceId";
    static const char* kDescription = "description";
    static const char* kMediaControlHandle = "mediaControlHandle";
    static const char* kMediaControlJNIHandle = "mediaControJniHandle";
    static const char* kVxDataSource = "vxDataSource";
    static const char* kVxExport = "vxExport";
    static const char* kVxPreset = "vxPreset";
    static const char* kVxPattern = "vxPattern";
    static const char* kVxSituation = "vxSituation";
    static const char* kDataSourceFailed = "Failed to get datasource pointer.";
    static const char* kJDataSourceFailed = "Failed to get JDatasource object";
    static const char* kExportPointerFailed = "Failed to get vxExport pointer object";
    static const char* kPtzControllerFailed = "Failed to get ptzcontrol pointer.";
    static const char* kClassInitFailed = "Unable to initialize class in JNI layer.";
    static const char* kStringFormat = "%s = %s \n";
    static const char* kGeneratorDeviceId = "generatorDeviceId";
    static const char* kId = "id";
    static const char* kTime = "time";
    static const char* kSourceUserName = "sourceUserName";
    static const char* kAckState = "ackState";
}
#endif // Constants_H__
