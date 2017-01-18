/// <summary>
/// Implements the preset class.
/// </summary>
#include "Preset.h"

CPPCli::Preset::Preset(VxSdk::IVxPreset* vxPreset) {
    _preset = vxPreset;
}

CPPCli::Preset::!Preset() {
    _preset->Delete();
    _preset = nullptr;
}
