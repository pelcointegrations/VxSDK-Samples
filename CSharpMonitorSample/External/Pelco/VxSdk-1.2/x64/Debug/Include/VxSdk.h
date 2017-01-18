#ifndef _VxSdk_h_
#define _VxSdk_h_

#include "VxMacros.h"
#include "VxPrimitives.h"
#include "VxUtilities.h"

#include "VxCollection.h"
#include "VxCollectionFilter.h"
#include "VxKvObject.h"
#include "VxLoginInfo.h"
#include "VxNewBookmark.h"
#include "VxNewDevice.h"
#include "VxNewDataObject.h"
#include "VxNewDrawing.h"
#include "VxNewDeviceAssignment.h"
#include "VxNewEvent.h"
#include "VxNewExport.h"
#include "VxNewExportClip.h"
#include "VxNewMarker.h"
#include "VxNewMonitor.h"
#include "VxNewNotification.h"
#include "VxNewQuickReport.h"
#include "VxNewPrivilege.h"
#include "VxNewSchedule.h"
#include "VxNewScheduleTrigger.h"
#include "VxNewSituation.h"
#include "VxNewTag.h"
#include "VxNewUser.h"
#include "VxSnapshotFilter.h"

#include "IVxBookmark.h"
#include "IVxClip.h"
#include "IVxDataInterface.h"
#include "IVxDataObject.h"
#include "IVxDataSession.h"
#include "IVxDataSource.h"
#include "IVxDataStorage.h"
#include "IVxDevice.h"
#include "IVxDeviceAssignment.h"
#include "IVxDrawing.h"
#include "IVxDriver.h"
#include "IVxEvent.h"
#include "IVxExport.h"
#include "IVxExportClip.h"
#include "IVxLicense.h"
#include "IVxLicenseFeature.h"
#include "IVxMarker.h"
#include "IVxMonitor.h"
#include "IVxMonitorCell.h"
#include "IVxNotification.h"
#include "IVxQuickReport.h"
#include "IVxPattern.h"
#include "IVxPreset.h"
#include "IVxPtzController.h"
#include "IVxPtzLock.h"
#include "IVxResourceLock.h"
#include "IVxRole.h"
#include "IVxSchedule.h"
#include "IVxScheduleTrigger.h"
#include "IVxSituation.h"
#include "IVxSystem.h"
#include "IVxTag.h"
#include "IVxUser.h"

namespace VxSdk {
    /// <summary>
    /// Initializes the SDK.
    /// </summary>
    /// <param name="key">The integration key.</param>
    /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
    EXTERN_C VXAPI VxResult::Value VxInit(const char* key);
    /// <summary>
    /// Logs in to the VideoXpert system.
    /// </summary>
    /// <param name="loginInfo">The information to connect and log in with.</param>
    /// <param name="system"><c>nullptr</c> if login fails, else the new <see cref="IVxSystem"/>.</param>
    /// <returns>The <see cref="VxResult::Value">Result</see> of the login.</returns>
    EXTERN_C VXAPI VxResult::Value VxSystemLogin(const VxLoginInfo& loginInfo, IVxSystem*& system);
    /// <summary>
    /// Checks whether the system at the specified IP address is supported by this SDK.
    /// </summary>
    /// <param name="ipAddress">The IP address of the system we want to check.</param>
    /// <param name="port">The port of the system we want to check.</param>
    /// <param name="isSupported"><c>true</c> if system is supported, otherwise <c>false</c>.</param>
    /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
    EXTERN_C VXAPI VxResult::Value IsSupportedSystem(const char* ipAddress, int port, bool& isSupported);
    /// <summary>
    /// Sets the minimum severity level of messages to log.
    /// </summary>
    /// <param name="logLevel">The logging severity <see cref="VxLogLevel::Value">level</see>.</param>
    /// <returns>The <see cref="VxResult::Value">Result</see> of setting the configuration.</returns>
    EXTERN_C VXAPI VxResult::Value VxSetLogLevel(VxLogLevel::Value logLevel);
    /// <summary>
    /// Sets the output path for log files.
    /// </summary>
    /// <param name="logPath">The directory to store the generated log files.</param>
    /// <returns>The <see cref="VxResult::Value">Result</see> of setting the configuration.</returns>
    EXTERN_C VXAPI VxResult::Value VxSetLogPath(const char* logPath);
}

#endif // !_VxSdk_h_
