#include "stdafx.h"
#include <chrono>
#include <thread>
#include "CreateExport.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

// Creates an export and adds to the current system.
Plugin* CppSamples::Exports::CreateExport::Run(DataModel* dataModel) {
    cout << "\n\n";
    VxCollection<IVxDataSource**> dataSources = GetDataSources(dataModel->VxSystem);

    CreateNewExportOption(dataSources, dataModel->VxSystem);

    // Pause for user input before going back to parent menu.
    system("pause");
    // Remove the memory allocated to the collection.
    delete[] dataSources.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

// Creates an export using the given system.
void CppSamples::Exports::CreateExport::CreateNewExportOption(VxCollection<IVxDataSource**> dataSources, IVxSystem* vxSystem) const {
    // Select a Data source
    int camNum;
    cout << "\nEnter data source index [1-"<<dataSources.collectionSize<<"]: ";
    cin >> camNum;

    // Verify input
    if (camNum < 1 || camNum >= dataSources.collectionSize)
        return;

    // Print the details of selected data source
    IVxDataSource* dataSource = dataSources.collection[camNum - 1];
    cout << "\n" << "DataSource selected for export is : " << dataSource->name << "\n";

    // Read Clips from system
    VxCollection<IVxClip**> clips = GetClips(dataSource);
    string exportName;
    string exportPasswd;
    int fileFormatOption = 1;

    if (clips.collectionSize > 0) {
        cin.ignore();
        // Start time for export
        cout << "\n" << "Input start time for export clip(yyyy-mm-dd hh:mm:ss): ";
        struct tm startTime = Utility::GetDateAndTimeFromUser();
        string startTimeInUTC = Utility::ConvertLocalTimetoUTC(startTime);

        // End time for export
        cout << "\n" << "Input end time for export clip(yyyy-mm-dd hh:mm:ss): ";
        struct tm endTime = Utility::GetDateAndTimeFromUser();
        string endTimeInUTC = Utility::ConvertLocalTimetoUTC(endTime);

        // Read name of export
        cout << "\n" << "Enter name for your export: ";
        getline(cin, exportName);

        // File Format Option
        cout << "\n\t" << "1.MkvZip";
        cout << "\n\t" << "2.Mp4";
        cout << "\n" << "Choose a file format for your export from above options: ";
        cin >> fileFormatOption;

        // Create instance of export structure and assign user inputs.
        VxNewExport* newExport = new VxNewExport();
        if (fileFormatOption == 1) {
            newExport->format = VxExportFormat::kMkvZip;
        }
        else if (fileFormatOption == 2) {
            newExport->format = VxExportFormat::kMp4;
        }
        Utilities::StrCopySafe(newExport->name, exportName.c_str());

        // Create instance of Export Clip
        VxNewExportClip* exportClip = new VxNewExportClip();
        Utilities::StrCopySafe(exportClip->dataSourceId, dataSource->id);
        Utilities::StrCopySafe(exportClip->startTime, startTimeInUTC.c_str());
        Utilities::StrCopySafe(exportClip->endTime, endTimeInUTC.c_str());
        newExport->clips = new VxNewExportClip[1];
        newExport->clipSize = 1;
        newExport->clips[0] = *exportClip;

        IVxExport* exportItem = nullptr;
        vxSystem->CreateExport(*newExport, exportItem);
        // Remove the memory allocated to the collection.
        delete[] newExport->clips;

        if (exportItem != nullptr) {
            // Show progress info
            do {
                // Get an export from the system
                IVxExport* newExp = GetExport(vxSystem, exportItem->name, exportItem->id);

                // Show status on screen
                if (newExp->status == VxExportStatus::kExporting) {
                    Utility::ShowProgress("Exporting", static_cast<int>(newExp->percentComplete), 100, 50);
                }
                else if (newExp->status == VxExportStatus::kPending) {
                    Utility::ShowProgress("Pending", static_cast<int>(newExp->percentComplete), 100, 50);
                }
                else if (newExp->status == VxExportStatus::kFailed) {
                    cout << "\nExport failed!!\n";
                    break;
                }
                else if (newExp->status == VxExportStatus::kSuccessful) {
                    Utility::ShowProgress("Exporting", 100, 100, 50);
                    cout << "\nExport successfully created..\n";
                    break;
                }

                delete newExp;
                // Pause the thread for a while after each iteration.
                this_thread::sleep_for(chrono::seconds(1));
            } while (true);

            delete exportItem;
        }
        else {
            cout << "\nFailed to export!!.\n";
        }
        delete exportClip;
        delete newExport;
    }
    else {
        cout << "No clips available for selected camera!!\n";
    }

    // Remove the memory allocated to the collection.
    delete[] clips.collection;
}

// Get a collection of clips from the given VideoExpert system.
VxCollection<IVxClip**> CppSamples::Exports::CreateExport::GetClips(IVxDataSource* dataSource) {
    cout << "Searching for available clips..Please wait..\n";

    // Read the clips from data source only if it has atleast one data interface with RTSP stream.
    int size = dataSource->dataInterfaceSize;
    for (int i = 0; i < size; i++) {
        IVxDataInterface* dataInterface = dataSource->dataInterfaces[i];
        if (dataInterface->protocol == VxStreamProtocol::kRtspRtp) {
            // Read the size of clip collection from system.
            VxCollection<IVxClip**> clips;
            VxResult::Value result = dataSource->GetClips(clips);
            if (result == VxResult::kInsufficientSize) {
                // Allocate memory for the requried collection.
                clips.collection = new IVxClip*[clips.collectionSize];
                // Read the collection from system.
                dataSource->GetClips(clips);
            }

            if (clips.collectionSize > 0) {
                // Print the clip details on screen
                cout << "Total Number of clips available: " << clips.collectionSize << "\n";
                for (int i1 = 0; i1 < clips.collectionSize; i1++) {
                    IVxClip* clip = clips.collection[i1];
                    tm startTime = Utility::ParseDateTime(clip->startTime);
                    tm endTime = Utility::ParseDateTime(clip->endTime);
                    string startTimeStr = Utility::ConvertUTCtoLocalTime(startTime);
                    string endTimeStr = Utility::ConvertUTCtoLocalTime(endTime);
                    cout << (i1 + 1) << ". " << startTimeStr << "---" << endTimeStr << "\n";
                }
            }

            return clips;
        }
    }

    return VxCollection<IVxClip**>();
}

// Get a collection of data source from the given VideoExpert system.
VxCollection<IVxDataSource**> CppSamples::Exports::CreateExport::GetDataSources(IVxSystem* vxSystem) {
    cout << "Fetching datasources from system, Please wait...\n";
    // Read the size of collection from system.
    VxCollection<IVxDataSource**> dataSources;
    VxResult::Value result = vxSystem->GetDataSources(dataSources);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        dataSources.collection = new IVxDataSource*[dataSources.collectionSize];
        // Read the collection from system.
        vxSystem->GetDataSources(dataSources);
    }
    // Print the number of data source items read from the system.
    cout << dataSources.collectionSize << " datasources found.\n";
    return dataSources;
}

// Get an export from the VideoExpert system with given name and ID.
IVxExport* CppSamples::Exports::CreateExport::GetExport(IVxSystem* vxSystem, const char* expName, const char* id) const {
    // Create filter with given export name.
    VxCollection<IVxExport**> exports;
    exports.filterSize = 1;
    VxCollectionFilter filters[1];
    filters->key = VxCollectionFilterItem::kName;
    Utilities::StrCopySafe(filters->value, expName);
    exports.filters = filters;

    IVxExport* vxExport = nullptr;
    // Read the size of collection from system.
    VxResult::Value result = vxSystem->GetExports(exports);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        exports.collection = new IVxExport*[exports.collectionSize];
        // Read the collection from system.
        result = vxSystem->GetExports(exports);
        if (result == VxResult::kOK) {
            // Find the export with given ID from the result collection of exports.
            for (int i = 0; i < exports.collectionSize; i++) {
                IVxExport* exportObj = exports.collection[i];
                if (strcmp(exportObj->id, id) == 0) {
                    vxExport = exports.collection[i];
                    break;
                }
            }
        }

        // Remove the memory allocated to the collection.
        delete[] exports.collection;
    }

    return vxExport;
}
