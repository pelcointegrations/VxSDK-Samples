#include "stdafx.h"
#include "DeleteDrawing.h"
#include "Utility.h"

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

/// <summary>
/// Delete a selected drawing from the current system.
/// </summary>
/// <param name="dataModel">Instance of data model.</param>
Plugin* CppSamples::Drawings::DeleteDrawing::Run(DataModel* dataModel) {
    Utility::ClearScreen();

    VxCollection<IVxDrawing**> drawings = GetDrawings(dataModel->VxSystem);
    PrintDrawings(drawings);

    if (drawings.collectionSize > 0) {
        int index = SelectDrawingIndex(drawings);
        if (index >= 0) {
            IVxDrawing* drawing = drawings.collection[index];
            VxResult::Value result = drawing->DeleteDrawing();
            if (result == VxResult::kOK)
                cout << "\n" << "Drawing deleted succesfully.\n";
            else
                cout << "\n" << "Failed to delete drawing!!\n";
        }
    }

    // Remove the memory allocated to the collection.
    delete[] drawings.collection;
    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Get a collection of drawings from the given VideoExpert system.
/// </summary>
/// <param name="vxSystem">Pointer to the VideoExpert system.</param>
/// <returns>A collection of drawings.</returns>
VxCollection<IVxDrawing**> CppSamples::Drawings::DeleteDrawing::GetDrawings(IVxSystem* vxSystem) {
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
void CppSamples::Drawings::DeleteDrawing::PrintDrawings(VxCollection<IVxDrawing**> drawingCollection) {

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

/// <summary>
/// Select a drawing from the given collection by user input.
/// </summary>
/// <param name="drawings">Collection of drawing.</param>
/// <returns>Index of the selected drawing in the given collection.</returns>
int CppSamples::Drawings::DeleteDrawing::SelectDrawingIndex(VxCollection<IVxDrawing**> &drawings) {
    while (true) {
        cout << "\n" << "Enter drawing number [1-" << drawings.collectionSize << "] : ";
        int index = Utility::ReadInt();
        if (index == 0)
            break;
        if (index > 0 && index <= drawings.collectionSize)
            return index - 1;
        else
            cout << "\n" << "Invalid Option !!!";

        cout << "\n" << "Enter 0 to go back.";
    }

    return -1;
}
