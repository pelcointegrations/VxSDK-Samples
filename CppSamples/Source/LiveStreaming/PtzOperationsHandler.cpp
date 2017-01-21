#include "stdafx.h"
#include "PtzOperationsHandler.h"

using namespace std;
using namespace VxSdk;

bool CppSamples::LiveStreaming::PtzOperationsHandler::DoOperation(char keyCode) {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return false;

    // This will be false for non PTZ commands
    bool isPtzCommandProcessed = true;
    VxResult::Value ptzRes = VxResult::kUnknownError;
    // Used to make exceptional cases for presets and patterns
    _showResult = true;

    // 7 => Up Left
    // 8 => Up
    // 9 => UpRight
    // 4 => Left
    // 6 => Right
    // 1 => Down Left
    // 2 => Down
    // 3 => Down Right
    // + => Zoom In
    // - => Zoom Out
    // 0 => Show Presets
    // . => Show Patterns
    // P => Toggle between PAUSE and PLAY
    // Keycode functions mentioned in CPPConsole::Utils::DisplayPlayerOptionsToConsole.
    switch (keyCode) {
        case '7':
            ptzRes = MoveUpLeft();
            break;
        case '8':
            ptzRes = MoveUp();
            break;
        case '9':
            ptzRes = MoveUpRight();
            break;
        case '4':
            ptzRes = MoveLeft();
            break;
        case '6':
            ptzRes = MoveRight();
            break;
        case '1':
            ptzRes = MoveDownLeft();
            break;
        case '2':
            ptzRes = MoveDown();
            break;
        case '3':
            ptzRes = MoveDownRight();
            break;
        case '+':
            ptzRes = ZoomIn();
            break;
        case '-':
            ptzRes = ZoomOut();
            break;
        case '0':
            TriggerPreset();
            break;
        case '.':
            TriggerPattern();
            break;
        default:
            // Not received a PTZ command keycode
            isPtzCommandProcessed = false;
            break;
    }

    // Show message if command processed.
    if (isPtzCommandProcessed && _showResult) {
        if (ptzRes)
            cout << "\n" << "PTZ command sent succefully.\n ";
        else {
            cout << "\n" << "PTZ command failed!!\n";
        }
    }

    return isPtzCommandProcessed;
}

// Get collection of patterns from the PTZ control
VxCollection<IVxPattern**> CppSamples::LiveStreaming::PtzOperationsHandler::GetPatterns() const {
    VxCollection<IVxPattern**> patterns;
    // Read the size of collection from system.
    VxResult::Value result = _ptzControl->GetPatterns(patterns);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        patterns.collection = new IVxPattern*[patterns.collectionSize];
        // Read the collection from system.
        _ptzControl->GetPatterns(patterns);
    }

    return patterns;
}

// Get collection of presets from the PTZ control
VxCollection<IVxPreset**> CppSamples::LiveStreaming::PtzOperationsHandler::GetPresets() const {
    VxCollection<IVxPreset**> presets;
    // Read the size of collection from system.
    VxResult::Value result = _ptzControl->GetPresets(presets);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        presets.collection = new IVxPreset*[presets.collectionSize];
        // Read the collection from system.
        _ptzControl->GetPresets(presets);
    }

    return presets;
}

// Move the camera down
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::MoveDown() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    // Send PTZ Command : Down
    cout << "\nSending PTZ Command:Down.";
    return _ptzControl->ContinuousMove(0, -10, VxZoomDirection::kNone);
}

// Move the camera diagonally towards down left
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::MoveDownLeft() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    // Send PTZ Command : Down Left
    cout << "\nSending PTZ Command:DownLeft.";
    return _ptzControl->ContinuousMove(-10, -10, VxZoomDirection::kNone);
}

// Move the camera diagonally towards down right
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::MoveDownRight() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    // Send PTZ Command : Down Right
    cout << "\nSending PTZ Command:DownRight.";
    return _ptzControl->ContinuousMove(10, -10, VxZoomDirection::kNone);
}

// Move the camera left
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::MoveLeft() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    // Send PTZ Command : Left
    cout << "\nSending PTZ Command:Left.";
    return _ptzControl->ContinuousMove(-10, 0, VxZoomDirection::kNone);
}

// Move the camera up
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::MoveUp() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    // Send PTZ Command : Up
    cout << "\nSending PTZ Command:Up.";
    return _ptzControl->ContinuousMove(0, 10, VxZoomDirection::kNone);
}

// Move the camera diagonally towards up left
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::MoveUpLeft() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    // Send PTZ Command : Up Left
    cout << "\nSending PTZ Command:UpLeft.";
    return _ptzControl->ContinuousMove(-10, 10, VxZoomDirection::kNone);
}

// Move the camera diagonally towards up right
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::MoveUpRight() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    // Send PTZ Command : Up Right
    cout << "\nSending PTZ Command:UpRight.";
    return _ptzControl->ContinuousMove(10, 10, VxZoomDirection::kNone);
}

// Move the camera right
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::MoveRight() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    // Send PTZ Command : Right
    cout << "\nSending PTZ Command:Right.";
    return _ptzControl->ContinuousMove(10, 0, VxZoomDirection::kNone);
}

// Trigger using the selected pattern
void CppSamples::LiveStreaming::PtzOperationsHandler::TriggerPattern(){
    _showResult = false;
    // Verify the instance of PTZ controller.
    if (_ptzControl != nullptr) {
        cout << "\nFetching patterns...";
        // Get collection of patterns from the PTZ control
        VxCollection<IVxPattern**> patterns = GetPatterns();
        if (patterns.collectionSize > 0) {
            // Print the collection of patterns on screen.
            for (int i = 0; i < patterns.collectionSize; i++) {
                cout << "\n  " << i + 1 << ": " << patterns.collection[i]->name;
            }

            // User inputs a pattern index
            cout << "\nEnter the index of pattern to be triggered (0 to cancel): ";
            int ch;
            cin >> ch;
            // Verify the pattern index
            if (ch != 0) {
                // Select the pattern
                IVxPattern* pattern = patterns.collection[ch];
                // Trigger the control using selected pattern.
                if (_ptzControl->TriggerPattern(*pattern))
                    cout << "\nPattern triggered succesfully..\n";
                else
                    cout << "\nFailed to trigger pattern.\n";
            }
            else {
                cout << "\nCancelled..\n";
            }
        }
        else {
            cout << "\nNo patterns available for this LiveStreaming!\n";
        }

        // Remove the memory allocated to the collection.
        delete[] patterns.collection;
    }
}

// Trigger using the selected preset
void CppSamples::LiveStreaming::PtzOperationsHandler::TriggerPreset(){
    _showResult = false;
    // Verify the instance of PTZ controller.
    if (_ptzControl != nullptr) {
        cout << "\nFetching presets...";
        // Get collection of presets from the PTZ control
        VxCollection<IVxPreset**> presets = GetPresets();
        if (presets.collectionSize > 0) {
            // Print the collection of presets on screen.
            for (int i = 0; i < presets.collectionSize; i++) {
                cout << "\n  " << i + 1 << ": " << presets.collection[i]->name;
            }

            // User inputs a preset index
            cout << "\nEnter the index of preset to be triggered (0 to cancel): ";
            int ch;
            cin >> ch;
            // Verify the preset index
            if (ch != 0) {
                // Select the preset
                IVxPreset* preset = presets.collection[ch];
                // Trigger the control using selected preset.
                if (_ptzControl->TriggerPreset(*preset))
                    cout << "\nPreset triggered succesfully..\n";
                else
                    cout << "\nFailed to trigger preset.\n";
            }
            else {
                cout << "\nCancelled..\n";
            }
        }
        else {
            cout << "\nNo presets available for this LiveStreaming!\n";
        }

        // Remove the memory allocated to the collection.
        delete[] presets.collection;
    }
}

// Zoom in the camera
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::ZoomIn() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    cout << "\nSending PTZ Command:ZoomIn.";
    return _ptzControl->ContinuousMove(0, 0, VxZoomDirection::kIn);
}

// Zoom out the camera
VxResult::Value CppSamples::LiveStreaming::PtzOperationsHandler::ZoomOut() const {
    // Verify the instance of PTZ controller.
    if (_ptzControl == nullptr)
        return VxResult::kInvalidParameters;

    cout << "\nSending PTZ Command:ZoomOut.";
    return _ptzControl->ContinuousMove(0, 0, VxZoomDirection::kOut);
}
