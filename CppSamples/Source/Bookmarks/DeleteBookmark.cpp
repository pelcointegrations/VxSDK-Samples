#include "stdafx.h"
#include "DeleteBookmark.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Delete a selected bookmark from the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Bookmarks::DeleteBookmark::Run(DataModel* dataModel) {
    system("cls");

    // Read book marks from current system
    VxCollection<IVxBookmark**> bookmarks = GetBookmarks(dataModel->VxSystem);
    PrintBookmarks(bookmarks);

    if (bookmarks.collectionSize > 0) {
        // Select the book mark to delete
        int index = SelectBookmarkIndex(bookmarks);
        if (index >= 0) {
            IVxBookmark* bookmark = bookmarks.collection[index];
            VxResult::Value result = bookmark->DeleteBookmark();
            if (result == VxResult::kOK)
                cout << "\n" << "Bookmark deleted succesfully.\n";
            else
                cout << "\n" << "Failed to delete bookmark!!\n";
        }
    }

    // Remove the memory allocated to the collection.
    delete[] bookmarks.collection;
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of bookmarks from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of bookmarks.</returns>
VxCollection<IVxBookmark**> CppSamples::Bookmarks::DeleteBookmark::GetBookmarks(IVxSystem* vxSystem) {
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
void CppSamples::Bookmarks::DeleteBookmark::PrintBookmarks(VxCollection<IVxBookmark**> bookmarkCollection) {

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

/// <summary>
/// Select a bookmark from the given collection by user input.
/// </summary>
/// <param name="bookmarks">Collection of bookmark.</param>
/// <returns>Index of the selected bookmark in the given collection.</returns>
int CppSamples::Bookmarks::DeleteBookmark::SelectBookmarkIndex(VxCollection<IVxBookmark**> &bookmarks) {
    while (true) {
        int index = 0;
        cout << "\n" << "Enter bookmark number [1-" << bookmarks.collectionSize << "] : ";
        cin >> index;
        if (index == 0)
            break;
        if (index > 0 && index <= bookmarks.collectionSize)
            return index - 1;
        else
            cout << "\n" << "Invalid Option !!!";

        cout << "\n" << "Enter 0 to go back.";
    }

    return -1;
}
