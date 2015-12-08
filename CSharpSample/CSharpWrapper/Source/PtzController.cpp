/// <summary>
/// Implements the ptz controller class.
/// </summary>
#include "PtzController.h"

using namespace System::Collections::Generic;

CPPCli::PtzController::PtzController(VxSdk::IVxPtzController* ptzController) {
    _ptzController = ptzController;
}

CPPCli::PtzController::!PtzController() {
    _ptzController->Delete();
    _ptzController = nullptr;
}

List<CPPCli::Pattern^>^ CPPCli::PtzController::GetPatterns() {
    // Create a list of managed pattern objects
    List<Pattern^>^ mlist = gcnew List<Pattern^>();
    // Create a collection of unmanaged pattern objects
    VxSdk::VxCollection<VxSdk::IVxPattern**> patterns;

    // Make the GetPatterns call, which will return with the total pattern count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _ptzController->GetPatterns(patterns);
    // As long as the datasource has at least one pattern the GetPatterns call should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Fill the array of pointers to the proper size as determined by the previous GetPatterns call
        patterns.collection = new VxSdk::IVxPattern*[patterns.collectionSize];
        result = _ptzController->GetPatterns(patterns);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < patterns.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Pattern(patterns.collection[i]));
        }
        // Delete the memory allocated earlier
        delete[] patterns.collection;
    }
    return mlist;
}

List<CPPCli::Preset^>^ CPPCli::PtzController::GetPresets() {
    // Create a list of managed preset objects
    List<Preset^>^ mlist = gcnew List<Preset^>();
    // Create a collection of unmanaged preset objects
    VxSdk::VxCollection<VxSdk::IVxPreset**> presets;

    // Make the GetPresets call, which will return with the total preset count, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _ptzController->GetPresets(presets);
    // As long as the datasource has at least one preset the GetPresets call should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Fill the array of pointers to the proper size as determined by the previous GetPresets call
        presets.collection = new VxSdk::IVxPreset*[presets.collectionSize];
        result = _ptzController->GetPresets(presets);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < presets.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Preset(presets.collection[i]));
        }
        // Delete the memory allocated earlier
        delete[] presets.collection;
    }
    return mlist;
}

CPPCli::Results::Value CPPCli::PtzController::AbsoluteMove(int positionX, int positionY) {
    VxSdk::VxResult::Value result = _ptzController->AbsoluteMove(positionX, positionY);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::AbsoluteMove(int positionX, int positionY, int positionZ) {
    VxSdk::VxResult::Value result = _ptzController->AbsoluteMove(positionX, positionY, positionZ);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::AbsolutePan(int positionX) {
    VxSdk::VxResult::Value result = _ptzController->AbsolutePan(positionX);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::AbsoluteTilt(int positionY) {
    VxSdk::VxResult::Value result = _ptzController->AbsoluteTilt(positionY);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::AbsoluteZoom(int positionZ) {
    VxSdk::VxResult::Value result = _ptzController->AbsoluteZoom(positionZ);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::ContinuousMove(int speedX, int speedY, CPPCli::PtzController::ZoomDirections inOut){
    VxSdk::VxResult::Value result = _ptzController->ContinuousMove(speedX, speedY, (VxSdk::VxZoomDirection::Value)inOut);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::RelativeMove(int deltaX, int deltaY, int deltaZ){
    VxSdk::VxResult::Value result = _ptzController->RelativeMove(deltaX, deltaY, deltaZ);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::ContinuousIris(CPPCli::PtzController::IrisDirections openClose){
    VxSdk::VxResult::Value result = _ptzController->ContinuousIris((VxSdk::VxIrisDirection::Value)openClose);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::ContinuousFocus(CPPCli::PtzController::FocusDirections nearFar){
    VxSdk::VxResult::Value result = _ptzController->ContinuousFocus((VxSdk::VxFocusDirection::Value)nearFar);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::Stop() {
    VxSdk::VxResult::Value result = _ptzController->PtzStop();
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::TriggerPattern(Pattern^ pattern) {
    VxSdk::VxResult::Value result = _ptzController->TriggerPattern(*pattern->_pattern);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzController::TriggerPreset(Preset^ preset) {
    VxSdk::VxResult::Value result = _ptzController->TriggerPreset(*preset->_preset);
    return CPPCli::Results::Value(result);
}
