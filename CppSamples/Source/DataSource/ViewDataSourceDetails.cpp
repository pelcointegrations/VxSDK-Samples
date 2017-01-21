#include "stdafx.h"
#include "ViewDataSourceDetails.h"
#include <conio.h>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

// Print the details of a particular data source specified by user in the current system.
Plugin* CppSamples::DataSource::ViewDataSourceDetails::Run(DataModel* dataModel) {
    cout << "\n\n";
    // Get all data sources from the system
    VxCollection<IVxDataSource**> dataSources = GetDataSources(dataModel->VxSystem);

    // Print all available data sources in the current system.
    PrintDataSourceCollection(dataSources);

    // Remove the memory allocated to the collection.
    delete[] dataSources.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

// Get a collection of data source from the given VideoExpert system.
VxCollection<IVxDataSource**> CppSamples::DataSource::ViewDataSourceDetails::GetDataSources(IVxSystem* vxSystem) {
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

// Print the given collection of data source to the screen.
void CppSamples::DataSource::ViewDataSourceDetails::PrintDataSourceCollection(VxCollection<IVxDataSource**> collection) {
    // Repeating loop to help user to view multiple data source one by one.
    while (true) {
        // Read user input for data source number
        int dataSourceNumber = 0;
        cout << "\n" << "Enter number [1-" << collection.collectionSize << "] : ";
        cin >> dataSourceNumber;

        // 0 to break the loop ang go back to parent menu.
        if (dataSourceNumber == 0)
            break;

        // Validate the user input
        if (dataSourceNumber > 0 && dataSourceNumber <= collection.collectionSize)
            // Print the selected data source
            ShowDataSourceDetails(collection.collection[dataSourceNumber - 1]);
        else
            cout << "\n" << "Invalid Option !!!";

        cout << "\n" << "Enter 0 to go back.";
    }
}

// Print the details of the given data source to the screen.
void CppSamples::DataSource::ViewDataSourceDetails::ShowDataSourceDetails(IVxDataSource* dataSource) {
    // Read PTZ info
    bool canPtz;
    dataSource->CanPtz(canPtz);

    // Convert the state to its corresponding string
    string deviceState = "Unknown";
    if (dataSource->state == VxDeviceState::kOffline)
        deviceState = "Offline";
    else if (dataSource->state == VxDeviceState::kOnline)
        deviceState = "Online";

    // Print the details to the console screen.
    cout << "-----------------------------------------------------------------";
    cout << "\n" << "Name            : " << dataSource->name;
    cout << "\n" << "ID              : " << dataSource->id;
    cout << "\n" << "IP              : " << dataSource->ip;
    cout << "\n" << "PTZ             : " << (canPtz ? "Yes" : "No");
    cout << "\n" << "State           : " << deviceState;
    cout << "\n" << "Live Stream     : " << (dataSource->hasLive ? "Yes" : "No");
    cout << "\n" << "Playback Stream : " << (dataSource->hasRecorded ? "Yes" : "No");
    cout << "\n" << "Capturing       : " << (dataSource->isCapturing ? "Yes" : "No");
    cout << "\n" << "Recording       : " << (dataSource->isRecording ? "Yes" : "No");
    cout << "\n" << "DataInterfaces  : " << dataSource->dataInterfaceSize;
    cout << "\n-----------------------------------------------------------------";
}
