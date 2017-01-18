#ifndef IVxLicenseFeature_h__
#define IVxLicenseFeature_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDevice.h"

namespace VxSdk {
    /// <summary>
    /// Represents device functionality that is enabled with a valid license.
    /// </summary>
    struct IVxLicenseFeature {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the devices that have been commissioned for this feature.
        /// <para>Available filters: kAllTags, kCommissioned, kId, kIp, kModel, kModifiedSince, kName, kSerial, kState, kType, kVendor, kVersion.</para>
        /// </summary>
        /// <param name="deviceCollection">A <see cref="VxCollection"/> of the devices that have been commissioned for this feature.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetCommissionedDevices(VxCollection<IVxDevice**>& deviceCollection) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;

    public:
        /// <summary>
        /// Indicates whether this is a "pending" feature, which does not enable any device functionality, or
        /// a normal feature that does.
        /// </summary>
        bool isPending;
        /// <summary>
        /// The activation identifier.
        /// </summary>
        char activationId[64];
        /// <summary>
        /// The date and time at which the feature will expire.
        /// </summary>
        char expiration[64];
        /// <summary>
        /// The unique identifier of the feature.
        /// </summary>
        char id[64];
        /// <summary>
        /// The date and time at which the feature was installed on the host.
        /// </summary>
        char installation[64];
        /// <summary>
        /// The name of the feature.
        /// </summary>
        char name[64];
        /// <summary>
        /// The feature version.
        /// </summary>
        char version[64];
        /// <summary>
        /// The allowable commisions count.
        /// </summary>
        int count;
        /// <summary>
        /// The amount of the allowable count that is currently used by commissions.
        /// </summary>
        int used;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            isPending = false;
            VxZeroArray(this->activationId);
            VxZeroArray(this->expiration);
            VxZeroArray(this->id);
            VxZeroArray(this->installation);
            VxZeroArray(this->name);
            VxZeroArray(this->version);
            count = 0;
            used = 0;
        }
    };
}
#endif // IVxLicenseFeature_h__
