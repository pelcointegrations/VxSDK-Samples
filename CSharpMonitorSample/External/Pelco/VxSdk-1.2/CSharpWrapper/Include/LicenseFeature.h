// Declares the license feature class.
#ifndef LicenseFeature_h__
#define LicenseFeature_h__

#include "Device.h"

namespace CPPCli {

    /// <summary>
    /// The LicenseFeature class represents device functionality that is enabled with a valid license.
    /// </summary>
    public ref class LicenseFeature {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxLicenseFeature">The vx license feature.</param>
        LicenseFeature(VxSdk::IVxLicenseFeature* vxLicenseFeature);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~LicenseFeature() {
            this->!LicenseFeature();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !LicenseFeature();

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Gets the activation identifier.
        /// </summary>
        /// <value>The activation identifier.</value>
        property System::String^ ActivationId {
        public:
            System::String^ get() { return gcnew System::String(_licenseFeature->activationId); }
        }

        /// <summary>
        /// Gets the devices that have been commissioned for this feature.
        /// </summary>
        /// <value>A <c>List</c> of devices that have been commissioned for this feature.</value>
        property System::Collections::Generic::List<Device^>^ CommissionedDevices {
        public:
            System::Collections::Generic::List<Device^>^ get() { return _GetCommissionedDevices(); }
        }

        /// <summary>
        /// Gets the allowable commisions count.
        /// </summary>
        /// <value>The allowable commisions count.</value>
        property int Count {
        public:
            int get() { return _licenseFeature->count; }
        }

        /// <summary>
        /// Gets the date and time at which the feature will expire.
        /// </summary>
        /// <value>The date and time at which the feature will expire.</value>
        property System::DateTime Expiration {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_licenseFeature->expiration); }
        }

        /// <summary>
        /// Gets the unique identifier of the feature.
        /// </summary>
        /// <value>The unique identifier of the feature.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_licenseFeature->id); }
        }

        /// <summary>
        /// Gets the date and time at which the feature was installed on the host.
        /// </summary>
        /// <value>The date and time at which the feature was installed on the host.</value>
        property System::DateTime Installation {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_licenseFeature->installation); }
        }

        /// <summary>
        /// Gets a value indicating whether this is a "pending" feature, which does not enable any device
        /// functionality, or a normal feature that does.
        /// </summary>
        /// <value><c>true</c> if this is a "pending" feature, <c>false</c> if a normal feature.</value>
        property bool IsPending {
        public:
            bool get() { return _licenseFeature->isPending; }
        }

        /// <summary>
        /// Gets the name of the feature.
        /// </summary>
        /// <value>The name of the feature.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_licenseFeature->name); }
        }

        /// <summary>
        /// Gets the amount of the allowable count that is currently used by commissions.
        /// </summary>
        /// <value>The amount of the allowable count that is currently used by commissions.</value>
        property int Used {
        public:
            int get() { return _licenseFeature->used; }
        }

        /// <summary>
        /// Gets the feature version.
        /// </summary>
        /// <value>The feature version.</value>
        property System::String^ Version {
        public:
            System::String^ get() { return gcnew System::String(_licenseFeature->version); }
        }

    internal:
        VxSdk::IVxLicenseFeature* _licenseFeature;
        System::Collections::Generic::List<Device^>^ _GetCommissionedDevices();
    };
}
#endif // LicenseFeature_h__
