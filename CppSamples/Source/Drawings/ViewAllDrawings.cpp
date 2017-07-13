#include "stdafx.h"
#include "ViewAllDrawings.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Print all drawings available in the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Drawings::ViewAllDrawings::Run(DataModel* dataModel) {
    Utility::ClearScreen();

    VxCollection<IVxDrawing**> drawings = GetDrawings(dataModel->VxSystem);
    PrintDrawings(drawings);

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Remove the memory allocated to the collection.
    delete[] drawings.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of drawings from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of drawings.</returns>
VxCollection<IVxDrawing**> CppSamples::Drawings::ViewAllDrawings::GetDrawings(IVxSystem* vxSystem) {
    VxCollection<IVxDrawing**> drawings;
    VxResult::Value result = vxSystem->GetDrawings(drawings);
    if (result == VxResult::kInsufficientSize) {
        drawings.collection = new IVxDrawing*[drawings.collectionSize];
        vxSystem->GetDrawings(drawings);
    }
    return drawings;
}

/// <summary>
/// Prints the given collection of drawings to the screen.
/// </summary>
/// <param name="drawingCollection">Collection of drawings.</param>
void CppSamples::Drawings::ViewAllDrawings::PrintDrawings(VxCollection<IVxDrawing**> drawingCollection) {

    cout << drawingCollection.collectionSize << " drawings found." << "\n";
    if (drawingCollection.collectionSize == 0)
        return;

    cout << "---------------------------------------------------------------------------------------------";
    for (int i = 0; i < drawingCollection.collectionSize; i++) {
        IVxDrawing* drawing = drawingCollection.collection[i];

        cout << "\n" << (i + 1);
        cout << "\t" << drawing->id;
        cout << "\t" << drawing->name;
    }
    cout << "\n---------------------------------------------------------------------------------------------\n";
}
