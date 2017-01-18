// Declares the MonitorCell class.
#ifndef MonitorCell_h__
#define MonitorCell_h__

#include "VxSdk.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The MonitorCell class represents a single viewport, hosted on a monitor, that can play media from a data source.
    /// </summary>
    public ref class MonitorCell {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxMonitorCell">The monitor cell.</param>
        MonitorCell(VxSdk::IVxMonitorCell* vxMonitorCell);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~MonitorCell() {
            this->!MonitorCell();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !MonitorCell();

        /// <summary>
        /// Removes the active data source from this cell.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the active data source.</returns>
        Results::Value Disconnect();

        /// <summary>
        /// Sets the position of the display data to live.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of going to live.</returns>
        Results::Value GoToLive();

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Gets or sets the unique identifier of the data source that this cell shall display.
        /// </summary>
        /// <value>The unique identifier of the data source.</value>
        property System::String^ DataSourceId {
        public:
            System::String^ get() { return gcnew System::String(_monitorCell->dataSourceId); }
            void set(System::String^ value) {
                char id[64];
                strncpy_s(id, Utils::ConvertSysStringNonConst(value), sizeof(id));
                _monitorCell->SetDataSource(id);
            }
        }

        /// <summary>
        /// Gets the unique index of this cell based on its position within the current layout.
        /// </summary>
        /// <value>The index.</value>
        property int Index {
        public:
            int get() { return _monitorCell->index; }
        }

        /// <summary>
        /// Gets or sets the play speed of the display data.
        /// </summary>
        /// <value>The speed.</value>
        property float Speed {
        public:
            float get() { return _monitorCell->speed; }
            void set(float value) { _monitorCell->SetSpeed(value); }
        }

        /// <summary>
        /// Gets or sets the time at which the data should seek to (does not track time as the data plays).
        /// </summary>
        /// <value>The seek time.</value>
        property System::DateTime Time {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_monitorCell->time); }
            void set(System::DateTime value) {
                char temp[64];
                VxSdk::Utilities::StrCopySafe(temp, Utils::ConvertDateTimeToChar(value));
                _monitorCell->SetTime(temp);
            }
        }

        /// <summary>
        /// Gets the wall clock time at which the data playback should begin.
        /// </summary>
        /// <value>The time.</value>
        property System::DateTime TimeAnchor {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_monitorCell->timeAnchor); }
        }

    internal:
        VxSdk::IVxMonitorCell* _monitorCell;
    };
}
#endif // MonitorCell_h__
