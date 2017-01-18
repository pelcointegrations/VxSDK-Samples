#ifndef IVxMonitorCell_h__
#define IVxMonitorCell_h__

#include "VxMacros.h"

namespace VxSdk {
    struct IVxDevice;

    /// <summary>
    /// Represents a single viewport, hosted on a monitor, that can play media from a data source.
    /// </summary>
    struct IVxMonitorCell {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the data source that this cell shall display.  A value of <c>nullptr</c> will remove the current data source.
        /// </summary>
        /// <param name="dataSourceId">The ID of the data source to display, <c>nullptr</c> to remove the current data source.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDataSource(char dataSourceId[64]) = 0;
        /// <summary>
        /// Sets the play speed of the monitor data. Negative values indicate reverse speeds while positive values indicate
        /// forward speeds (1 is normal speed).  A value of 0 will pause the data playback.
        /// </summary>
        /// <param name="speed">The playback speed.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetSpeed(float speed) = 0;
        /// <summary>
        /// Sets the time to seek to on the monitor.  A value of <c>nullptr</c> will set the stream to live.  If no frame is available
        /// for the given time the stream will remain unchanged.
        /// </summary>
        /// <param name="time">The time to seek to, <c>nullptr</c> for live.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetTime(char time[64]) = 0;

    public:
        /// <summary>
        /// The unique identifier of the data source displayed in the cell.
        /// </summary>
        char dataSourceId[64];
        /// <summary>
        /// The unique index of the cell based on its position within the current layout.
        /// </summary>
        int index;
        /// <summary>
        /// The play speed of the display data.
        /// </summary>
        float speed;
        /// <summary>
        /// The time at which the data should initially seek to (does not track time as the data plays).
        /// </summary>
        char time[64];
        /// <summary>
        /// The wall clock time at which the data playback should begin.
        /// </summary>
        char timeAnchor[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            this->index = 0;
            this->speed = 0;
            VxZeroArray(this->time);
            VxZeroArray(this->timeAnchor);
        }
    };
}

#endif // IVxMonitorCell_h__
