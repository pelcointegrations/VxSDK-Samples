#include "stdafx.h"
#include "MergeTag.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Merge two tags in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Tags::MergeTag::Run(DataModel* dataModel) {
    system("cls");

    // Get a collection of tags
    VxCollection<IVxTag**> tags = GetTags(dataModel->VxSystem);
    PrintTags(tags);

    if (tags.collectionSize > 0) {
        int firstIndex = SelectTagIndex(tags, -1);
        int secondIndex = SelectTagIndex(tags, firstIndex);
        IVxTag* firstTag = tags.collection[firstIndex];
        IVxTag* secondTag = tags.collection[secondIndex];
        VxResult::Value result = firstTag->Merge(*secondTag);
        if (result == VxResult::kOK)
            cout << "\n" << "Tag merged succesfully.\n";
        else
            cout << "\n" << "Failed to merge tag!!\n";
    }

    // Remove the memory allocated to the collection.
    delete[] tags.collection;
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of tags from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of tags.</returns>
VxCollection<IVxTag**> CppSamples::Tags::MergeTag::GetTags(IVxSystem* vxSystem) {
    VxCollection<IVxTag**> tags;
    VxResult::Value result = vxSystem->GetTags(tags);
    if (result == VxResult::kInsufficientSize) {
        tags.collection = new IVxTag*[tags.collectionSize];
        vxSystem->GetTags(tags);
    }
    return tags;
}

/// <summary>
/// Prints the given collection of tags to the screen.
/// </summary>
/// <param name="tagCollection">Collection of tags.</param>
void CppSamples::Tags::MergeTag::PrintTags(VxCollection<IVxTag**> tagCollection) {

    cout << tagCollection.collectionSize << " tags found." << "\n";
    if (tagCollection.collectionSize == 0)
        return;

    cout << "---------------------------------------------------------------------------------------------";
    for (int i = 0; i < tagCollection.collectionSize; i++) {
        IVxTag* tag = tagCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << tag->id;
        cout << "\t" << tag->name;
    }
    cout << "\n---------------------------------------------------------------------------------------------\n";
}

/// <summary>
/// Select a tag from the given collection by user input.
/// </summary>
/// <param name="tags">Collection of tag.</param>
/// <param name="firstIndex">Provide -1 to select first index.</param>
/// <returns>Index of the selected tag in the given collection.</returns>
int CppSamples::Tags::MergeTag::SelectTagIndex(VxCollection<IVxTag**> &tags, int firstIndex) {
    while (true) {
        int index = 0;
        if (firstIndex < 0)
            cout << "\n" << "Enter first tag number [1-" << tags.collectionSize << "] : ";
        else
            cout << "\n" << "Enter second tag number [1-" << tags.collectionSize << "] : ";
        cin >> index;
        if (index == 0)
            break;
        if (index > 0 && index <= tags.collectionSize) {
            if (index - 1 == firstIndex)
                cout << "\n" << "First and second tags must be different.";
            else
                return index - 1;
        }
        else
            cout << "\n" << "Invalid Option !!!";

        cout << "\n" << "Enter 0 to go back.";
    }

    return -1;
}
