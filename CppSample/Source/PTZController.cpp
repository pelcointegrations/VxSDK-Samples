#include "stdafx.h"
#include "PTZController.h"

CPPConsole::PTZController::PTZController(VxSdk::IVxPtzController* ptzController) : _presetsList(nullptr), _patternsList(nullptr) {
    _ptzController = ptzController;
}

bool CPPConsole::PTZController::ContinuousMove(int speedX, int speedY, ZoomDirection zoomDirection) {
    VxSdk::VxResult::Value res = _ptzController->ContinuousMove(speedX, speedY, static_cast<VxSdk::VxZoomDirection::Value>(zoomDirection));
    if (res == VxSdk::VxResult::Value::kOK)
        return true;

    return false;
}

std::list<CPPConsole::Preset*>* CPPConsole::PTZController::GetPresets() {
    if (_presetsList != nullptr) {
        for (std::list<Preset*>::const_iterator iterator = _presetsList->begin(), end = _presetsList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _presetsList;
    }
    
    _presetsList = new std::list<Preset*>();

    VxSdk::VxCollection<VxSdk::IVxPreset**> presets;
    VxSdk::VxResult::Value result = _ptzController->GetPresets(presets);

    if (result == VxSdk::VxResult::kInsufficientSize) {
        presets.collection = new VxSdk::IVxPreset*[presets.collectionSize];
        result = _ptzController->GetPresets(presets);
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < presets.collectionSize; i++) {
                _presetsList->push_back(new Preset(presets.collection[i]));
            }
        }
        delete[] presets.collection;
    }
    return _presetsList;
}

std::list<CPPConsole::Pattern*>* CPPConsole::PTZController::GetPatterns() {
    if (_patternsList != nullptr) {
        for (std::list<Pattern*>::const_iterator iterator = _patternsList->begin(), end = _patternsList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _patternsList;
    }

    _patternsList = new std::list<Pattern*>();

    VxSdk::VxCollection<VxSdk::IVxPattern**> patterns;
    VxSdk::VxResult::Value result = _ptzController->GetPatterns(patterns);

    if (result == VxSdk::VxResult::kInsufficientSize) {
        patterns.collection = new VxSdk::IVxPattern*[patterns.collectionSize];
        result = _ptzController->GetPatterns(patterns);
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < patterns.collectionSize; i++) {
                _patternsList->push_back(new Pattern(patterns.collection[i]));
            }
        }
        delete[] patterns.collection;
    }
    return _patternsList;
}

bool CPPConsole::PTZController::TriggerPattern(Pattern* pattern) {
    VxSdk::VxResult::Value result = _ptzController->TriggerPattern(*pattern->Self());
    return result == VxSdk::VxResult::kOK;
}

bool CPPConsole::PTZController::TriggerPreset(Preset* preset) {
    VxSdk::VxResult::Value result = _ptzController->TriggerPreset(*preset->Self());
    return result == VxSdk::VxResult::kOK;
}

void CPPConsole::PTZController::PtzStop() {
    _ptzController->PtzStop();
}

CPPConsole::PTZController::~PTZController() {
    if (_presetsList != nullptr) {
        for (std::list<Preset*>::const_iterator iterator = _presetsList->begin(), end = _presetsList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _presetsList;
    }

    if (_patternsList != nullptr) {
        for (std::list<Pattern*>::const_iterator iterator = _patternsList->begin(), end = _patternsList->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete _patternsList;
    }

    _ptzController->Delete();
    _ptzController = nullptr;
}
