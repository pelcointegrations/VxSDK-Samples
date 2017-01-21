/// <summary>
/// Implements the clip class.
/// </summary>
#include "QuickReport.h"

CPPCli::QuickReport::QuickReport(VxSdk::IVxQuickReport* vxQuickReport) {
    _report = vxQuickReport;
}

CPPCli::QuickReport::!QuickReport() {
    _report->Delete();
    _report = nullptr;
}

System::String^ CPPCli::QuickReport::_GetQuickReportEndpoint() {
    char* reportEndpoint = nullptr;
    int size = 0;

    // If the quick report endpoint is not available on the system the result will return VxSdk::VxResult::kActionUnavailable,
    // otherwise VxSdk::VxResult::kInsufficientSize
    VxSdk::VxResult::Value result = _report->GetQuickReportEndpoint(reportEndpoint, size);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for reportEndpoint
        reportEndpoint = new char[size];
        // The result should now be kOK since we have allocated enough space
        _report->GetQuickReportEndpoint(reportEndpoint, size);
    }
    return gcnew System::String(reportEndpoint);
}

CPPCli::QuickReport::ReportCreationStatus CPPCli::QuickReport::_GetStatus() {
    // Get the status of the report
    VxSdk::VxReportCreationStatus::Value status;
    VxSdk::VxResult::Value result = _report->GetStatus(status);
    // Return the status if GetStatus was successful
    if (result == VxSdk::VxResult::kOK)
        return (CPPCli::QuickReport::ReportCreationStatus)status;

    return CPPCli::QuickReport::ReportCreationStatus::Unknown;
}
