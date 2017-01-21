#include "stdafx.h"
#include <direct.h>
#include <curl.h>

#include "DownloadExport.h"
#include "Utility.h"
#include "Constants.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

// Downloads an export from the current system and saves as a file.
Plugin* CppSamples::Exports::DownloadExport::Run(DataModel* dataModel) {
    Download(dataModel->VxSystem);

    cout << "\n\n";
    // Pause for user input before going back to parent menu.
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

// Prints the given collection of exports to the screen.
void CppSamples::Exports::DownloadExport::DisplayExportDetailsOnScreen(VxCollection<IVxExport**> exportCollection) {
    cout << exportCollection.collectionSize << " exports found.";
    if (exportCollection.collectionSize == 0)
        return;

    // Header Line
    cout << "\n-----------------------------------------------------------------";
    for (int i = 0; i < exportCollection.collectionSize; i++) {
        IVxExport* vxExport = exportCollection.collection[i];

        // Status to string value
        VxExportStatus::Value expStatus = vxExport->status;
        string expStatusInString = "U";
        switch (expStatus) {
        case VxExportStatus::Value::kExporting:
            expStatusInString = "E";
            break;
        case VxExportStatus::Value::kSuccessful:
            expStatusInString = "S";
            break;
        case VxExportStatus::Value::kFailed:
            expStatusInString = "F";
            break;
        case VxExportStatus::Value::kPending:
            expStatusInString = "P";
            break;
        case VxExportStatus::Value::kUnknown:
        default:
            break;
        }

        // Print details of single export
        cout << "\n\t" << (i + 1) << "\t" << vxExport->name << "\t" << expStatusInString;
    }

    // Footer
    cout << "\n-----------------------------------------------------------------";
    cout << "\n  Status: E-Exporting  S-Successful  F-Failed  P-Pending  U-Unknown\n";
}

// Downloads an export from the current system and saves as a file.
void CppSamples::Exports::DownloadExport::Download(IVxSystem* vxSystem) const {
    // Get a collection of exports from the system
    VxCollection<IVxExport**> exports = GetExports(vxSystem);
    // Display the details of exports in the collection on screen.
    DisplayExportDetailsOnScreen(exports);

    if (exports.collectionSize <= 0)
        return;
    // User selects an export
    int exportIndex;
    cout << "\n" << "Enter index of export to download [1-" << exports.collectionSize << "] : ";
    cin >> exportIndex;

    // Validate user input
    if (exportIndex < 1 || exportIndex >= exports.collectionSize)
        return;

    // Print details of selected export to delete
    IVxExport* vxExport = exports.collection[exportIndex - 1];
    ShowExportDetails(vxExport);
    
    // File Location
    cout << "\n" << "Enter path to save export file(eg: C:\\ExportFolder): ";
    string pathToSave = "";
    cin >> pathToSave;

    // File Name
    cout << "\n" << "Enter name to save export file: ";
    string fileToSave = "";
    cin >> fileToSave;

    // Set extention based of export format
    string fullPath;
    if (vxExport->format == VxExportFormat::kMp4) {
        fullPath = pathToSave + "\\" + fileToSave + ".mp4";
    }
    else {
        fullPath = pathToSave + "\\" + fileToSave + ".zip";
    }

    // Make directory if doesn't exists
    _mkdir(pathToSave.c_str());

    // Initialize CURL
    int actualFileSize = vxExport->fileSizeKb;
    CURL *curl = curl_easy_init();
    FILE *fp;

    if (curl) {
        // Open File for Writing
        fopen_s(&fp, fullPath.c_str(), "wb");
        if (fp == nullptr) {
            char buff[256];
            strerror_s(buff, 100, errno);
            printf("Error opening file for writing:  %s\n", buff);
            return;
        }

        // Create Header structure with user name and password
        struct curl_slist *headers = nullptr;
        string userNameHeader = "X-Serenity-User: " + Utility::Encode(Constants::kUserName);
        string passwordHeader = "X-Serenity-Password: " + Utility::Encode(Constants::kPassword);
        headers = curl_slist_append(headers, userNameHeader.c_str());
        headers = curl_slist_append(headers, passwordHeader.c_str());

        // Set options to CURL
        curl_easy_setopt(curl, CURLOPT_URL, vxExport->dataUri);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressFunc);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &actualFileSize);

        // Start Downloading
        cout << "\n" << "Exporting to " << fullPath << "\n\n";
        curl_easy_perform(curl);
        // Cleanup the CURL
        curl_easy_cleanup(curl);
        fclose(fp);
        cout << "\n\n";
    }

    // Remove the memory allocated to the collection.
    delete[] exports.collection;
}

/// <summary>
/// Convert the value of export format to string.
/// </summary>
string CppSamples::Exports::DownloadExport::GetExportFormatInString(VxExportFormat::Value expFormat) {
    string expFormatInString = "Unknown";
    if (expFormat == VxExportFormat::kMkvZip) {
        expFormatInString = "MkvZip";
    }
    else if (expFormat == VxExportFormat::kMp4) {
        expFormatInString = "Mp4";
    }

    return expFormatInString;
}

// Get a collection of exports from the given VideoExpert system.
VxCollection<IVxExport**> CppSamples::Exports::DownloadExport::GetExports(IVxSystem* vxSystem) {
    cout << "\n\n" << "Fetching exports from system. Please wait...\n";
    // Read the size of collection from system.
    VxCollection<IVxExport**> exports;
    VxResult::Value result = vxSystem->GetExports(exports);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        exports.collection = new IVxExport*[exports.collectionSize];
        // Read the collection from system.
        vxSystem->GetExports(exports);
    }

    return exports;
}

/// <summary>
/// Returns the status of the export in string
/// </summary>
string CppSamples::Exports::DownloadExport::GetExportStatusInString(VxExportStatus::Value expStatus, bool shortStr) {
    string expStatusInString = "U";
    if (expStatus == VxExportStatus::kExporting) {
        if (shortStr)
            expStatusInString = "E";
        else
            expStatusInString = "Exporting";
    }
    else if (expStatus == VxExportStatus::kSuccessful) {
        if (shortStr)
            expStatusInString = "S";
        else
            expStatusInString = "Successful";
    }
    else if (expStatus == VxExportStatus::kFailed) {
        if (shortStr)
            expStatusInString = "F";
        else
            expStatusInString = "Failed";
    }
    else if (expStatus == VxExportStatus::kPending) {
        if (shortStr)
            expStatusInString = "P";
        else
            expStatusInString = "Pending";
    }

    return expStatusInString;
}

/// <summary>
/// Callback method to get the download progress
/// </summary>
/// <param name="ptr">Custom data assigned to curl.</param>
/// <param name="dltotal">Total bytes to be downloaded (not used).</param>
/// <param name="dlnow">Number of bytes downloaded.</param>
int CppSamples::Exports::DownloadExport::ProgressFunc(void* ptr, double dltotal, double dlnow) {
    // Get the value in the given pointer.
    int actualSize = *static_cast<int*>(ptr);
    // Downloaded in bytes, so convert to Kb
    Utility::ShowProgress("Downloading", static_cast<int>(dlnow) / 1000, actualSize, 50);
    return 0;
}

// Print the details of given export.
void CppSamples::Exports::DownloadExport::ShowExportDetails(IVxExport* vxExport) {
    cout << "\n" << "  Export you selected: " << "\n";
    cout << "\n" << "-------------------------------------------------------------------";
    cout << "\n" << "  Name: " << vxExport->name;
    cout << "\n" << "  Size (In Kb): " << vxExport->fileSizeKb;
    cout << "\n" << "  Status: " << GetExportStatusInString(vxExport->status, false);
    cout << "\n" << "  Format: " << GetExportFormatInString(vxExport->format) << "\n";
    cout << "\n" << "-------------------------------------------------------------------";
}

/// <summary>
/// Callback method for writing export data to file
/// </summary>
/// <param name="ptr">stream data</param>
/// <param name="size">size of the data</param>
/// <param name="nmemb">count of the data</param>
/// <param name="stream">file pointer to which data is being written</param>
size_t CppSamples::Exports::DownloadExport::WriteData(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
