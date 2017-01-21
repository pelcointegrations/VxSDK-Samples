#include "stdafx.h"
#include "ViewDataSourceByPage.h"
#include <conio.h>
#include "Paging.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

// Print all available data sources in the current system page by page.
Plugin* CppSamples::DataSource::ViewDataSourceByPage::Run(DataModel* dataModel) {
    cout << "\n\n";
    // Get all data sources from the system
    VxCollection<IVxDataSource**> dataSources = GetDataSources(dataModel->VxSystem);

    // Print all available data sources in the current system page by page.
    PrintDataSourceCollection(dataSources);

    // Remove the memory allocated to the collection.
    delete[] dataSources.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

// Get a collection of data source from the given VideoExpert system.
VxCollection<IVxDataSource**> CppSamples::DataSource::ViewDataSourceByPage::GetDataSources(IVxSystem* vxSystem) {
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

// Print details of a single data source on screen
void CppSamples::DataSource::ViewDataSourceByPage::PrintDataSource(int number, IVxDataSource* dataSource) {
    cout << number << "\t" << dataSource->name << "\n";
}

// Print the given collection of data source to the screen.
void CppSamples::DataSource::ViewDataSourceByPage::PrintDataSourceCollection(VxCollection<IVxDataSource**> collection) {

    // Read number of items per page from user.
    int numberOfItemsPerPage = 0;
    cout << "\n" << "Enter number of items per page: ";
    cin >> numberOfItemsPerPage;

    // Initialize instance of Paging class
    Paging paging(collection.collectionSize, numberOfItemsPerPage);

    while (true) {
        // Print header of a page on screen
        system("cls");
        cout << "========================================================";
        cout << "\n" << "Number\tData Source Name";
        cout << "\n" << "========================================================\n";

        // Print content of a page
        for (int i = paging.GetStartIndex(); i <= paging.GetEndIndex(); i++)
            PrintDataSource(i + 1, collection.collection[i]);

        // Print footer
        cout << "========================================================";
        cout << "\n\n" << "Page " << paging.GetCurrentPage() << " of " << paging.GetPageCount();

        // Get user inputs
        cout << "\n\n" << "Press arrow keys to traverse. Esc key to quit...";
        int key = _getch();
        
        // Convert the user inputs into commands
        // Top or Left   => Previous Page
        // Right or Down => Next page
        // Esc           => Break
        if (key == 72 || key == 75)
            paging.PreviousPage();
        else if (key == 77 || key == 80)
            paging.NextPage();
        else if (key == 27)
            break;
    }

    cout << "\n\n" << "Press any key to continue...";
    getchar();
}
