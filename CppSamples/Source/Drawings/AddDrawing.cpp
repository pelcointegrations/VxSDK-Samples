#include "stdafx.h"
#include "AddDrawing.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Adds a drawing to the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Drawings::AddDrawing::Run(DataModel* dataModel) {

    // Read name from input
    cout << "\n\n" << "Enter drawing name: ";
    string name = Utility::ReadString();

    // Add Drawing
    VxNewDrawing drawing;
    Utilities::StrCopySafe(drawing.name, name.c_str());

    // Make the call to add the drawing into VideoXpert
    VxResult::Value result = dataModel->VxSystem->AddDrawing(drawing);
    if (result == VxResult::kOK)
        cout << "\n" << "Drawing added succesfully.\n";
    else
        cout << "\n" << "Failed to add drawing.\n";

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}
