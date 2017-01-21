#include "stdafx.h"
#include "AddBookmark.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Adds a bookmark to the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Bookmarks::AddBookmark::Run(DataModel* dataModel) {

    AddNew(dataModel->VxSystem);

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Add a new bookmark to server.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
void CppSamples::Bookmarks::AddBookmark::AddNew(IVxSystem* vxSystem) {

    // Data Source ID
    VxCollection<IVxDataSource**> dataSources = GetDataSources(vxSystem);
    int dataSourceIndex = SelectDataSourceIndex(dataSources);
    if (dataSourceIndex < 0)
        return;

    string dataSourceId = dataSources.collection[dataSourceIndex]->id;

    // Description
    cout << "\n\n" << "Enter description for bookmark: ";
    cin.ignore();
    string description = "";
    getline(cin, description);

    // Time
    cout << "\n" << "Enter time (yyyy-mm-dd hh:mm:ss): ";
    struct tm strtTime = Utility::GetDateAndTimeFromUser();
    string time = Utility::ConvertLocalTimetoUTC(strtTime);

    VxNewBookmark bookmark;
    Utilities::StrCopySafe(bookmark.dataSourceId, dataSourceId.c_str());
    Utilities::StrCopySafe(bookmark.description, description.c_str());
    Utilities::StrCopySafe(bookmark.time, time.c_str());

    VxResult::Value result = vxSystem->AddBookmark(bookmark);
    if (result == VxResult::kOK)
        cout << "\n" << "Bookmark added succesfully.\n";
    else
        cout << "\n" << "Failed to add bookmark.\n";

    // Pause for user input before going back to parent menu.
    system("pause");
}

/// <summary>
/// Get a collection of data source from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of data source.</returns>
VxCollection<IVxDataSource**> CppSamples::Bookmarks::AddBookmark::GetDataSources(IVxSystem* vxSystem) {
    cout << "\nFetching datasources from system, Please wait...\n";
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

/// <summary>
/// Select a data source from the given collection by user input.
/// </summary>
/// <param name="dataSources">Collection of data source.</param>
/// <returns>Index of the selected data source in the given collection.</returns>
int CppSamples::Bookmarks::AddBookmark::SelectDataSourceIndex(VxCollection<IVxDataSource**> &dataSources) {
    while (true) {
        // Select a Data source
        int dataSourceNumber = 0;
        cout << "\n" << "Enter data source number [1-" << dataSources.collectionSize << "] : ";
        cin >> dataSourceNumber;
        if (dataSourceNumber == 0)
            break;
        // Verify input
        if (dataSourceNumber > 0 && dataSourceNumber <= dataSources.collectionSize)
            return dataSourceNumber - 1;
        else
            cout << "\n" << "Invalid Option !!!";

        cout << "\n" << "Enter 0 to go back.";
    }

    return -1;
}
