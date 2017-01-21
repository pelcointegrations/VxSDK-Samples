// Declares the preset class.
#ifndef Preset_h__
#define Preset_h__

#include "VxSdk.h"

namespace CPPCli {

    /// <summary>
    /// The Preset class represents a predefined point that a PTZ device can PTZ to when triggered.
    /// </summary>
    public ref class Preset {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxPreset">The vx preset.</param>
        Preset(VxSdk::IVxPreset* vxPreset);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Preset() {
            this->!Preset();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Preset();

        /// <summary>
        /// Gets the friendly description of the preset.
        /// </summary>
        /// <value>The friendly description.</value>
        property System::String^ Description {
        public:
            System::String^ get() { return gcnew System::String(_preset->description); }
        }

        /// <summary>
        /// Gets the friendly name of the preset.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_preset->name); }
        }

    internal:
        VxSdk::IVxPreset* _preset;
    };
}
#endif // Preset_h__
