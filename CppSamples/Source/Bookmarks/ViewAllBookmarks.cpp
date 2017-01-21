#include "stdafx.h"
#include "ViewAllBookmarks.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Print all bookmarks available in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Bookmarks::ViewAllBookmarks::Run(DataModel* dataModel) {
    system("cls");

    VxCollection<IVxBookmark**> bookmarks = GetBookmarks(dataModel->VxSystem);
    PrintBookmarks(bookmarks);

    system("pause");
    // Remove the memory allocated to the collection.
    delete[] bookmarks.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of bookmarks from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of bookmarks.</returns>
VxCollection<IVxBookmark**> CppSamples::Bookmarks::ViewAllBookmarks::GetBookmarks(IVxSystem* vxSystem) {
    VxCollection<IVxBookmark**> bookmarks;
    VxResult::Value result = vxSystem->GetBookmarks(bookmarks);
    if (result == VxResult::kInsufficientSize) {
        bookmarks.collection = new IVxBookmark*[bookmarks.collectionSize];
        vxSystem->GetBookmarks(bookmarks);
    }
    return bookmarks;
}

/// <summary>
/// Prints the given collection of bookmarks to the screen.
/// </summary>
/// <param name="bookmarkCollection">Collection of bookmarks.</param>
void CppSamples::Bookmarks::ViewAllBookmarks::PrintBookmarks(VxCollection<IVxBookmark**> bookmarkCollection) {

    cout << bookmarkCollection.collectionSize << " bookmarks found." << "\n";
    if (bookmarkCollection.collectionSize == 0)
        return;

    cout << "------------------------------------------------------------------------------------------";
    for (int i = 0; i < bookmarkCollection.collectionSize; i++) {
        IVxBookmark* bookmark = bookmarkCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << bookmark->id;
        cout << "\t" << bookmark->time;
        cout << "\t" << bookmark->description;
    }
    cout << "\n------------------------------------------------------------------------------------------\n";
}
