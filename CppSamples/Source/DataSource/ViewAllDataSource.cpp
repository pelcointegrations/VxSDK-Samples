#include "stdafx.h"
#include "ViewAllDataSource.h"
#include "Utility.h"
#ifndef WIN32
#include <unistd.h>
#endif

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

// Print all available data sources in the current system.
Plugin* CppSamples::DataSource::ViewAllDataSource::Run(DataModel* dataModel) {
    cout << "\n\n";
    // Get all data sources from the system
    VxCollection<IVxDataSource**> dataSources = GetDataSources(dataModel->VxSystem);

    // Print the collection on console screen
    PrintDataSourceCollection(dataSources);

    // Remove the memory allocated to the collection.
    delete[] dataSources.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

// Get a collection of data source from the given VideoExpert system.
VxCollection<IVxDataSource**> CppSamples::DataSource::ViewAllDataSource::GetDataSources(IVxSystem* vxSystem) {
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
void CppSamples::DataSource::ViewAllDataSource::PrintDataSourceCollection(VxCollection<IVxDataSource**> collection) {
    Utility::ClearScreen();

    // Print details of all data sources on screen
    for (int i = 0; i < collection.collectionSize; i++)
        PrintDataSource(i + 1, collection.collection[i]);

    // Wait for user response before going back to parent menu.
    Utility::Pause();
}

// Print the details of the given data source to the screen.
void CppSamples::DataSource::ViewAllDataSource::PrintDataSource(int number, IVxDataSource* dataSource) {
    // Print details of a single data source on screen
    cout << number << "\t" << dataSource->name << "\n";
}
