#ifndef IVxMonitor_h__
#define IVxMonitor_h__

#include "VxPrimitives.h"
#include "VxMacros.h"
#include "VxCollection.h"
#include "VxUtilities.h"

#include "IVxMonitorCell.h"

namespace VxSdk {
    struct IVxDevice;
    struct IVxMonitorLock;

    /// <summary>
    /// Represents a display for view data (typically video).
    /// </summary>
    struct IVxMonitor {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the layouts available for this monitor.
        /// </summary>
        /// <param name="layoutCollection">A <see cref="VxCollection"/> of the available layouts.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAvailableLayouts(VxCollection<VxCellLayout::Value*>& layoutCollection) const = 0;
        /// <summary>
        /// Gets the host device of this monitor.
        /// </summary>
        /// <param name="hostDevice">The host <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Gets the cells currently active on this monitor.
        /// </summary>
        /// <param name="cellCollection">A <see cref="VxCollection"/> of the active monitor cells.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMonitorCells(VxCollection<IVxMonitorCell**>& cellCollection) = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Deletes this monitor from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the monitor.</returns>
        virtual VxResult::Value RemoveMonitor() const = 0;
        /// <summary>
        /// Sets the layout property.
        /// </summary>
        /// <param name="layout">The new layout value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetLayout(VxCellLayout::Value layout) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the number property.
        /// </summary>
        /// <param name="number">The new number value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetNumber(int number) = 0;

    public:
        /// <summary>
        /// The unique identifier of the monitor.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of this monitor.
        /// </summary>
        char name[64];
        /// <summary>
        /// The number used to designate the monitor.
        /// </summary>
        int number;
        /// <summary>
        /// The cell grid layout.
        /// </summary>
        VxCellLayout::Value layout;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->number = 0;
            this->layout = VxCellLayout::Value::k1x1;
        }
    };
}

#endif // IVxMonitor_h__
