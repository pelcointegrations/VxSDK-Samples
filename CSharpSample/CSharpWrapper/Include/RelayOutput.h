// Declares the relay output class.
#ifndef RelayOutput_h__
#define RelayOutput_h__

#include "VxSdk.h"
#include "Utils.h"

namespace CPPCli {
    ref class Device;

    /// <summary>
    /// The RelayOutput class represents a physical relay output.
    /// </summary>
    public ref class RelayOutput {
    public:

        /// <summary>
        /// Values that represent the state of a relay output.
        /// </summary>
        enum class RelayStates {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>The relay output is active.</summary>
            Active,

            /// <summary>The relay output is inactive.</summary>
            Inactive
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxRelayOutput">The vx relay output.</param>
        RelayOutput(VxSdk::IVxRelayOutput* vxRelayOutput);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~RelayOutput() {
            this->!RelayOutput();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !RelayOutput();

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Gets or sets the friendly description of the relay output.
        /// </summary>
        /// <value>The friendly description.</value>
        property System::String^ Description {
        public:
            System::String^ get() { return gcnew System::String(_relayOutput->description); }
            void set(System::String^ value) {
                char description[64];
                VxSdk::Utilities::StrCopySafe(description, Utils::ConvertSysStringNonConst(value));
                _relayOutput->SetDescription(description);
            }
        }

        /// <summary>
        /// Gets the device that hosts this relay output.
        /// </summary>
        /// <value>The host device.</value>
        property CPPCli::Device^ HostDevice {
        public:
            CPPCli::Device^ get() { return _GetHostDevice(); }
        }

        /// <summary>
        /// Gets the unique relay output identifier.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_relayOutput->id); }
        }

        /// <summary>
        /// Gets or sets the friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_relayOutput->name); }
            void set(System::String^ value) {
                char name[64];
                VxSdk::Utilities::StrCopySafe(name, Utils::ConvertSysStringNonConst(value));
                _relayOutput->SetName(name);
            }
        }

        /// <summary>
        /// Gets the current state of this relay output.
        /// </summary>
        /// <value>The relay output state.</value>
        property RelayStates State {
        public:
            RelayStates get() { return RelayStates(_relayOutput->state); }
            void set(RelayStates value) { _SetRelayState(value); }
        }

    internal:
        VxSdk::IVxRelayOutput* _relayOutput;
        CPPCli::Device^ _GetHostDevice();
        void _SetRelayState(RelayStates state);
    };
}
#endif // RelayOutput_h__
