#include "stdafx.h"
#include "ViewQuickReport.h"

#include <ctime>
#ifdef VxSdkInLinux
#include <unistd.h>
#endif
#include <curl.h>
#include "Utility.h"
#include "Constants.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Print a quick report on screen.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Reports::ViewQuickReport::Run(DataModel* dataModel) {

    // Create a VxQuickReportFilter object
    VxNewQuickReport vxQuickReportFilter;
    vxQuickReportFilter.contentsSize = 2;
    vxQuickReportFilter.contents = new VxReportContent::Value[2];
    vxQuickReportFilter.contents[0] = VxReportContent::kCameraConfig;
    vxQuickReportFilter.contents[1] = VxReportContent::kEventHistory;

    // End Time: Now
    const time_t now = time(0);
    struct tm tmEndTime;
    localtime_s(&tmEndTime, &now);
    std::string endTime = Utility::ConvertLocalTimetoUTC(tmEndTime);
    Utilities::StrCopySafe(vxQuickReportFilter.endTime, endTime.c_str());

    // Start time: One hour ago
    const time_t oneHourAgo = now - 60*60;
    struct tm tmStartTime;
    localtime_s(&tmStartTime, &oneHourAgo);
    string startTime = Utility::ConvertLocalTimetoUTC(tmStartTime);
    Utilities::StrCopySafe(vxQuickReportFilter.startTime, startTime.c_str());

    // Read Report
    string reportUrl = ReadReportUrl(dataModel->VxSystem, vxQuickReportFilter);
    if (reportUrl.empty())
    {
        system("pause");
        return GetParent();
    }

    // Show Report on default browser
#ifdef VxSdkInLinux
    string stemp = "firefox ";
    stemp.append(reportUrl);
    system(stemp.c_str());
#else
    wstring stemp = wstring(reportUrl.begin(), reportUrl.end());
    ShellExecute(0, 0, (LPCWSTR)stemp.c_str(), 0, 0, SW_SHOW);
#endif

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Read the end point of the report.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <param name="vxQuickReportFilter">Instance of VxNewQuickReport.</param>
/// <returns>End point of the report.</returns>
string CppSamples::Reports::ViewQuickReport::ReadReportUrl(IVxSystem* vxSystem, VxNewQuickReport vxQuickReportFilter) {

    cout << "\n" << "Reading report endpoint...";

    IVxQuickReport* quickReport;
    // Attempt to create the quick report
    string report = "";
    VxResult::Value result = vxSystem->CreateQuickReport(vxQuickReportFilter, quickReport);
    if (result == VxResult::kOK) {
        VxReportCreationStatus::Value status;
        quickReport->GetStatus(status);
        while (status == VxReportCreationStatus::kInProgress) {
#ifdef VxSdkInLinux
            sleep(1);
#else
            Sleep(1000);
#endif
            quickReport->GetStatus(status);
        }

        // If the quick report endpoint is not available on the system the result will return VxResult::kActionUnavailable,
        // otherwise VxResult::kInsufficientSize
        char* reportEndpoint = nullptr;
        int size = 0;
        result = quickReport->GetQuickReportEndpoint(reportEndpoint, size);
        while (result == VxResult::kActionUnavailable) {
#ifdef VxSdkInLinux
            sleep(1);
#else
            Sleep(1000);
#endif
            result = quickReport->GetQuickReportEndpoint(reportEndpoint, size);
        }

        if (result == VxResult::kInsufficientSize) {
            // Allocate enough space for reportEndpoint
            reportEndpoint = new char[size];
            // The result should now be kOK since we have allocated enough space
            result = quickReport->GetQuickReportEndpoint(reportEndpoint, size);
        }

        if (result == VxResult::kOK) {
            cout << "DONE\n";
            return string(reportEndpoint);
        }
    }

    if (result == VxResult::kActionUnavailable)
        cout << "\nUnable to create quick report (action unavailable)\n";
    else
        cout << "\nError\n";

    return "";
}

/// <summary>
/// Read a web page content from the given URL.
/// </summary>
/// <param name="reportUrl">URL of report.</param>
/// <returns>Report content.</returns>
string CppSamples::Reports::ViewQuickReport::ReadWebPageConent(string reportUrl) {

    string reportContent;

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        CURL *curl_handle;
        curl_global_init(CURL_GLOBAL_ALL);
        curl_handle = curl_easy_init();
        curl_easy_setopt(curl_handle, CURLOPT_URL, reportUrl.c_str());
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, ViewQuickReport::AppendDataCurlCallback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &reportContent); // Pointer to reportContent will be passed to AppendDataCurlCallback.

        curl_easy_perform(curl_handle);
        curl_easy_cleanup(curl_handle);

        res = curl_easy_perform(curl);

        // always cleanup
        curl_easy_cleanup(curl);
    }

    return reportContent;
}

/// <summary>
/// This callback function gets called by libcurl as soon as there is data received that needs to be saved.
/// It will append the data from the page to given variable at CURLOPT_WRITEDATA.
/// </summary>
/// <param name="pageContent">This pointer points to the delivered data.</param>
/// <param name="sz">The size of that data is sz multiplied with nmemb.</param>
/// <param name="nmemb">The size of that data is sz multiplied with nmemb.</param>
/// <param name="reportContentPtr">Pointer to the variable given at CURLOPT_WRITEDATA.</param>
/// <returns>The size of the string.</returns>
size_t CppSamples::Reports::ViewQuickReport::AppendDataCurlCallback(void *pageContent, size_t sz, size_t nmemb, void *reportContentPtr) {
    string *reportContent = (string*)reportContentPtr;
    reportContent->append((char*)pageContent, sz * nmemb);
    return sz * nmemb;
}
