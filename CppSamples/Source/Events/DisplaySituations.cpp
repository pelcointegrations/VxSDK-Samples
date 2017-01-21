#include "stdafx.h"
#include "DisplaySituations.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

Plugin* CppSamples::Events::DisplaySituations::Run(DataModel* dataModel) {

    Display(dataModel->VxSystem);

    // Pause for user input before going back to parent menu.
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Menu function for displaying situations available in a system
/// </summary>
/// <param name="vxSystem">system pointer</param>
void CppSamples::Events::DisplaySituations::Display(IVxSystem* vxSystem) {

    cout << "\n\n" << "Fetching situations from system..Please wait..\n";
    VxCollection<IVxSituation**> situations = GetSituations(vxSystem);
    DisplaySituationDetailsOnScreen(situations);

    // Remove the memory allocated to the collection.
    delete[] situations.collection;
}

// Get a collection of situations from the given VideoExpert system.
VxCollection<IVxSituation**> CppSamples::Events::DisplaySituations::GetSituations(IVxSystem* vxSystem) {

    // Read the size of collection from system.
    VxCollection<IVxSituation**> situations;
    VxResult::Value result = vxSystem->GetSituations(situations);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        situations.collection = new IVxSituation*[situations.collectionSize];
        // Read the collection from system.
        result = vxSystem->GetSituations(situations);
    }

    return situations;
}

/// <summary>
/// Method for displaying situation details
/// </summary>
/// <param name="situations">Situations list to iterate</param>
void CppSamples::Events::DisplaySituations::DisplaySituationDetailsOnScreen(VxCollection<IVxSituation**> situations) {

    if (situations.collectionSize > 0) {
        cout << situations.collectionSize << " situations found.\n";

        // Print Heading
        cout << "\n\n";
        cout << setfill(' ') << "  INDEX         " << setw(60) << left << "  TYPE" << "\n";
        cout << "\n--------------------------------------------------\n";

        // Print Situation Details
        int index = 0;
        for (int i = 0; i < situations.collectionSize;i++) {
            IVxSituation* situation = situations.collection[i];
            cout << setfill(' ') << "\n\t" << index + 1 << "\t" << left << setw(60) << left << situation->type;
            index++;
        }
        // Print Footer
        cout << "\n--------------------------------------------------\n";
    }
    else
        cout << "No situations found!!\n";
}
