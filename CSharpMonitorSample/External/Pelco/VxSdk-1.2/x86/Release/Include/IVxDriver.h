#ifndef IVxDriver_h__
#define IVxDriver_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    struct IVxDataStorage;

    /// <summary>
    /// Represents a device communication driver.
    /// </summary>
    struct IVxDriver {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDataStorage"/> that hosts this driver.
        /// </summary>
        /// <param name="dataStorage">The host <see cref="IVxDataStorage"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataStorage(IVxDataStorage*& dataStorage) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;

    public:
        /// <summary>
        /// The friendly name of the driver.
        /// </summary>
        char name[64];
        /// <summary>
        /// The driver type identifier.
        /// </summary>
        char type[64];
        /// <summary>
        /// The name of the vendor that manufactured the device that the driver is for.
        /// </summary>
        char vendor[64];
        /// <summary>
        /// The driver version number.
        /// </summary>
        char version[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->name);
            VxZeroArray(this->type);
            VxZeroArray(this->vendor);
            VxZeroArray(this->version);
        }
    };
}

#endif // IVxDriver_h__
