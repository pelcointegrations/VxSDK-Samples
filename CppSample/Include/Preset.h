#include "VxSdk.h"

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxPreset
    /// </summary>
    class Preset {
    public:

        /// <summary>
        /// Constructor - copies the VxSDK preset pointer
        /// </summary>
        /// <param name="vxPreset">The preset pointer</param>
        Preset(VxSdk::IVxPreset* vxPreset) { _preset = vxPreset; }

        /// <summary>
        /// Destructor
        /// </summary>
        ~Preset(){
            _preset->Delete();
            _preset = nullptr;
        }

        /// <summary>
        /// Returns the VxSDK preset pointer
        /// </summary>
        VxSdk::IVxPreset* Self() { return _preset; }

        /// <summary>
        /// Gets the preset name
        /// </summary>
        const char* GetPresetName() { return _preset->name; }

        /// <summary>
        /// Gets the preset description
        /// </summary>
        const char* GetPresetDescription() { return _preset->description; }

    private:
        VxSdk::IVxPreset* _preset;
    };
}