// Declares the monitor class.
#ifndef Monitor_h__
#define Monitor_h__

#include "VxSdk.h"
#include "Utils.h"
#include "MonitorCell.h"

namespace CPPCli {
    ref class Device;

    /// <summary>
    /// The Monitor class represents a display for view data (typically video).
    /// </summary>
    public ref class Monitor {
    public:

        /// <summary>
        /// Values that represent the layouts of a monitor.
        /// </summary>
        enum class Layouts {
            /// <summary>A 1x1 monitor layout.</summary>
            CellLayout1x1,

            /// <summary>A 1x2 monitor layout.</summary>
            CellLayout1x2,

            /// <summary>A 2x1 monitor layout.</summary>
            CellLayout2x1,

            /// <summary>A 2x2 monitor layout.</summary>
            CellLayout2x2,

            /// <summary>A 2x3 monitor layout.</summary>
            CellLayout2x3,

            /// <summary>A 3x2 monitor layout.</summary>
            CellLayout3x2,

            /// <summary>A 3x3 monitor layout.</summary>
            CellLayout3x3,

            /// <summary>A 4x3 monitor layout.</summary>
            CellLayout4x3,

            /// <summary>A 4x4 monitor layout.</summary>
            CellLayout4x4,

            /// <summary>A 1 plus 12 monitor layout.</summary>
            CellLayout1plus12,

            /// <summary>A 2 plus 8 monitor layout.</summary>
            CellLayout2plus8,

            /// <summary>A 3 plus 4 monitor layout.</summary>
            CellLayout3plus4,

            /// <summary>A 1 plus 5 monitor layout.</summary>
            CellLayout1plus5,

            /// <summary>A 1 plus 7 monitor layout.</summary>
            CellLayout1plus7,

            /// <summary>A 12 plus 1 monitor layout.</summary>
            CellLayout12plus1,

            /// <summary>A 8 plus 2 monitor layout.</summary>
            CellLayout8plus2,

            /// <summary>A 1 plus 4 tall monitor layout.</summary>
            CellLayout1plus4tall,

            /// <summary>A 1 plus 4 wide monitor layout.</summary>
            CellLayout1plus4wide
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxMonitor">The vx monitor.</param>
        Monitor(VxSdk::IVxMonitor* vxMonitor);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Monitor() {
            this->!Monitor();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Monitor();

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Gets the layouts available for this monitor.
        /// </summary>
        /// <value>A <c>List</c> of the available layouts.</value>
        property System::Collections::Generic::List<CPPCli::Monitor::Layouts>^ AvailableLayouts {
        public:
            System::Collections::Generic::List<CPPCli::Monitor::Layouts>^ get() { return _GetAvailableLayouts(); }
        }

        /// <summary>
        /// Gets the device that hosts this monitor.
        /// </summary>
        /// <value>The host device.</value>
        property CPPCli::Device^ HostDevice {
        public:
            CPPCli::Device^ get() { return _GetHostDevice(); }
        }

        /// <summary>
        /// Gets the unique monitor identifier.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_monitor->id); }
        }

        /// <summary>
        /// Gets or sets the current layout for this monitor.
        /// </summary>
        /// <value>The cell layout.</value>
        property Layouts Layout {
        public:
            Layouts get() { return Layouts(_monitor->layout); }
            void set(Layouts value) { _monitor->SetLayout((VxSdk::VxCellLayout::Value)value); }
        }

        /// <summary>
        /// Gets the cells currently active on this monitor.
        /// </summary>
        /// <value>A <c>List</c> of the currently active cells.</value>
        property System::Collections::Generic::List<MonitorCell^>^ MonitorCells {
        public:
            System::Collections::Generic::List<MonitorCell^>^ get() { return _GetMonitorCells(); }
        }

        /// <summary>
        /// Gets or sets the friendly name of this monitor.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_monitor->name); }
            void set(System::String^ value) {
                strncpy_s(_monitor->name, Utils::ConvertSysStringNonConst(value), sizeof(_monitor->name));
            }
        }

        /// <summary>
        /// Gets or sets the number used to designate this monitor.
        /// </summary>
        /// <value>The monitor number.</value>
        property int Number {
        public:
            int get() { return _monitor->number; }
            void set(int value) { _monitor->number = value; }
        }

    internal:
        VxSdk::IVxMonitor* _monitor;
        System::Collections::Generic::List<MonitorCell^>^ _GetMonitorCells();
        System::Collections::Generic::List<CPPCli::Monitor::Layouts>^ _GetAvailableLayouts();
        CPPCli::Device^ _GetHostDevice();
    };
}
#endif // Monitor_h__
