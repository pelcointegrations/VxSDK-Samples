/// <summary>
/// Implements the quick log class.
/// </summary>
#include "QuickLog.h"

CPPCli::QuickLog::QuickLog(VxSdk::IVxQuickLog* vxQuickLog) {
    _log = vxQuickLog;
}

CPPCli::QuickLog::!QuickLog() {
    _log->Delete();
    _log = nullptr;
}

System::String^ CPPCli::QuickLog::_GetQuickLogEndpoint() {
    char* logEndpoint = nullptr;
    int size = 0;

    // If the quick log endpoint is not available on the system the result will return VxSdk::VxResult::kActionUnavailable,
    // otherwise VxSdk::VxResult::kInsufficientSize
    VxSdk::VxResult::Value result = _log->GetQuickLogEndpoint(logEndpoint, size);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for logEndpoint
        logEndpoint = new char[size];
        // The result should now be kOK since we have allocated enough space
        _log->GetQuickLogEndpoint(logEndpoint, size);
    }
    return gcnew System::String(logEndpoint);
}

CPPCli::QuickLog::LogCreationStatus CPPCli::QuickLog::_GetStatus() {
    // Get the status of the log
    VxSdk::VxLogCreationStatus::Value status;
    VxSdk::VxResult::Value result = _log->GetStatus(status);
    // Return the status if GetStatus was successful
    if (result == VxSdk::VxResult::kOK)
        return (CPPCli::QuickLog::LogCreationStatus)status;

    return CPPCli::QuickLog::LogCreationStatus::Unknown;
}
