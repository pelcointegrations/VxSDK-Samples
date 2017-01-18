// Declares the new monitor class.
#ifndef NewMonitor_h__
#define NewMonitor_h__

#include "Utils.h"
#include "Monitor.h"
#include "VxNewMonitor.h"

namespace CPPCli {

    /// <summary>
    /// The NewMonitor class represents a new monitor to be created on the system.
    /// </summary>
    public ref class NewMonitor {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewMonitor() {
            _newMonitor = new VxSdk::VxNewMonitor();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewMonitor">The new monitor.</param>
        NewMonitor(VxSdk::VxNewMonitor* vxNewMonitor) {
            _newMonitor = vxNewMonitor;
        }

        /// <summary>
        /// Gets or sets the unique identifier of the monitor host device.
        /// </summary>
        /// <value>The unique host identifier.</value>
        property System::String^ HostDeviceId {
        public:
            System::String^ get() { return gcnew System::String(_newMonitor->hostDeviceId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newMonitor->hostDeviceId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the cell grid layout of the monitor.
        /// </summary>
        /// <value>The cell grid layout.</value>
        property Monitor::Layouts Layout {
        public:
            Monitor::Layouts get() { return (Monitor::Layouts)_newMonitor->layout; }
            void set(Monitor::Layouts value) { _newMonitor->layout = (VxSdk::VxCellLayout::Value)value; }
        }

        /// <summary>
        /// Gets or sets the friendly name of the monitor.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_newMonitor->name); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newMonitor->name, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the unique number of the monitor.
        /// </summary>
        /// <value>The monitor number.</value>
        property int Number {
        public:
            int get() { return _newMonitor->number; }
            void set(int value) { _newMonitor->number = value; }
        }

    internal:
        VxSdk::VxNewMonitor* _newMonitor;
    };
}
#endif // NewMonitor_h__
