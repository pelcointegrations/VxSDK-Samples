// Declares the alarm input class.
#ifndef AlarmInput_h__
#define AlarmInput_h__

#include "VxSdk.h"
#include "Utils.h"

namespace CPPCli {
    ref class Device;

    /// <summary>
    /// The AlarmInput class represents a physical alarm input.
    /// </summary>
    public ref class AlarmInput {
    public:

        /// <summary>
        /// Values that represent the state of an alarm input.
        /// </summary>
        enum class AlarmStates {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>The alarm input is active.</summary>
            Active,

            /// <summary>The alarm input is inactive.</summary>
            Inactive
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxAlarmInput">The vx alarm input.</param>
        AlarmInput(VxSdk::IVxAlarmInput* vxAlarmInput);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~AlarmInput() {
            this->!AlarmInput();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !AlarmInput();

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Gets or sets the friendly description of the alarm input.
        /// </summary>
        /// <value>The friendly description.</value>
        property System::String^ Description {
        public:
            System::String^ get() { return gcnew System::String(_alarmInput->description); }
            void set(System::String^ value) {
                char description[64];
                VxSdk::Utilities::StrCopySafe(description, Utils::ConvertSysStringNonConst(value));
                _alarmInput->SetDescription(description);
            }
        }

        /// <summary>
        /// Gets the device that hosts this alarm input.
        /// </summary>
        /// <value>The host device.</value>
        property CPPCli::Device^ HostDevice {
        public:
            CPPCli::Device^ get() { return _GetHostDevice(); }
        }

        /// <summary>
        /// Gets the unique alarm input identifier.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_alarmInput->id); }
        }

        /// <summary>
        /// Gets or sets the friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_alarmInput->name); }
            void set(System::String^ value) {
                char name[64];
                VxSdk::Utilities::StrCopySafe(name, Utils::ConvertSysStringNonConst(value));
                _alarmInput->SetName(name);
            }
        }

        /// <summary>
        /// Gets the current state of this alarm input.
        /// </summary>
        /// <value>The alarm input state.</value>
        property AlarmStates State {
        public:
            AlarmStates get() { return AlarmStates(_alarmInput->state); }
        }

    internal:
        VxSdk::IVxAlarmInput* _alarmInput;
        CPPCli::Device^ _GetHostDevice();
    };
}
#endif // AlarmInput_h__
