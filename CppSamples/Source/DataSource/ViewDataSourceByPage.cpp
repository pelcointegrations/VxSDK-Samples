#include "stdafx.h"
#include "ViewDataSourceByPage.h"
#ifdef WIN32
#include <conio.h>
#else
#include <curses.h>
#endif
#include "Paging.h"
#include "Utility.h"

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
    cout << "\n" << "Enter number of items per page: ";
    int numberOfItemsPerPage = Utility::ReadInt();
    if (numberOfItemsPerPage < 1) {
        cout << "\n" << "number of items per page: " << numberOfItemsPerPage;
        return;
    }

    // Initialize instance of Paging class
    Paging paging(collection.collectionSize, numberOfItemsPerPage);

    while (true) {
        // Print header of a page on screen
        Utility::ClearScreen();
        cout << "========================================================";
        cout << "\n" << "Number\tData Source Name";
        cout << "\n" << "========================================================\n";

        // Print content of a page
        for (int i = paging.GetStartIndex(); i <= paging.GetEndIndex(); i++)
            PrintDataSource(i + 1, collection.collection[i]);

        // Print footer
        cout << "========================================================";
        cout << "\n\n" << "Page " << paging.GetCurrentPage() << " of " << paging.GetPageCount();

#ifndef WIN32
        // Get user inputs in Linux
        cout << "\n\n" << "Press 'Enter' key to move next";

        int key = 77;
        if (paging.GetCurrentPage() == paging.GetPageCount()) {
            key = 27;
        }

        std::cin.clear();
        fseek(stdin, 0, SEEK_END);
        fflush(stdin);
        while (std::cin.get() != '\n');
#else
        // Get user inputs in Windows
        cout << "\n\n" << "Press arrow keys to traverse. Esc key to quit...";
        int key = _getch();
#endif

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

    Utility::Pause();
}
