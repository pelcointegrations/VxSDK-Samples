// Declares the license class.
#ifndef License_h__
#define License_h__

#include "VxSdk.h"
#include "LicenseFeature.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The License class represents license information for the resource that owns this resource.
    /// </summary>
    public ref class License {
    public:

        /// <summary>
        /// Values that represent the types of system licenses.
        /// </summary>
        enum class SystemLicenseTypes {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>Enterprise system license.</summary>
            Enterprise,

            /// <summary>Ultimate system license.</summary>
            Ultimate,

            /// <summary>Unlicensed system.</summary>
            Unlicensed
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxLicense">The vx license.</param>
        License(VxSdk::IVxLicense* vxLicense);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~License() {
            this->!License();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !License();

        /// <summary>
        /// Gets the friendly name of the owning company/organization.
        /// </summary>
        /// <value>The friendly name of the owning company/organization.</value>
        property System::String^ CompanyName {
        public:
            System::String^ get() { return gcnew System::String(_license->companyName); }
        }

        /// <summary>
        /// Gets the features this license contains.
        /// </summary>
        /// <value>A <c>List</c> of license features.</value>
        property System::Collections::Generic::List<LicenseFeature^>^ LicenseFeatures {
        public:
            System::Collections::Generic::List<LicenseFeature^>^ get() { return _GetLicenseFeatures(); }
        }

        /// <summary>
        /// Gets the type of system that this license is applied to.
        /// </summary>
        /// <value>The system license <see cref="SystemLicenseTypes">Type</see>.</value>
        property SystemLicenseTypes SystemLicenseType {
        public:
            SystemLicenseTypes get() { return (SystemLicenseTypes)_license->systemLicenseType; }
        }

    internal:
        VxSdk::IVxLicense* _license;
        System::Collections::Generic::List<LicenseFeature^>^ _GetLicenseFeatures();
    };
}
#endif // License_h__
