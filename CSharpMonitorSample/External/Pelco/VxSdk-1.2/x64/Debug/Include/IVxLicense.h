#ifndef IVxLicense_h__
#define IVxLicense_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxLicenseFeature.h"

namespace VxSdk {
    /// <summary>
    /// Represents license information for the resource that owns this resource.
    /// </summary>
    struct IVxLicense {
    public:
        /// <summary>
        /// Commissions a device for use within the VideoXpert system.
        /// </summary>
        /// <param name="device">The device to commission.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CommissionDevice(IVxDevice& device) const = 0;
        /// <summary>
        /// Decommissions a device on the VideoXpert system.
        /// </summary>
        /// <param name="device">The device to decommission.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value DecommissionDevice(IVxDevice& device) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the features this license contains.
        /// </summary>
        /// <param name="licenseFeatureCollection">A <see cref="VxCollection"/> of the features this license contains.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLicenseFeatures(VxCollection<IVxLicenseFeature**>& licenseFeatureCollection) const = 0;

    public:
        /// <summary>
        /// The friendly name of the owning company/organization.
        /// </summary>
        char companyName[64];
        /// <summary>
        /// The type of system that this license is applied to.
        /// </summary>
        VxSystemLicenseType::Value systemLicenseType;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->companyName);
            systemLicenseType = VxSystemLicenseType::kUnknown;
        }
    };
}
#endif // IVxLicense_h__
