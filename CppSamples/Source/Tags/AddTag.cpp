#include "stdafx.h"
#include "AddTag.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Adds a tag to the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Tags::AddTag::Run(DataModel* dataModel) {

    // Read name from input
    cout << "\n\n" << "Enter tag name: ";
    string name = "";
    cin >> name;

    // Add Tag
    VxNewTag tag;
    Utilities::StrCopySafe(tag.name, name.c_str());
    tag.isPublic = true;

    // Make the call to add the tag into VideoXpert
    VxResult::Value result = dataModel->VxSystem->AddTag(tag);
    if (result == VxResult::kOK)
        cout << "\n" << "Tag added succesfully.\n";
    else
        cout << "\n" << "Failed to add tag.\n";

    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}
