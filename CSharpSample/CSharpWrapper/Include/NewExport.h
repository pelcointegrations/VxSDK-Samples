// Declares the  new export class.
#ifndef NewExport_h__
#define NewExport_h__

#include "NewExportClip.h"

namespace CPPCli {

    /// <summary>
    /// The NewExport class represents a new export.
    /// </summary>
    public ref class NewExport {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewExport() {
            _newExport = new VxSdk::VxNewExport();
            _clips = gcnew System::Collections::Generic::List<CPPCli::NewExportClip^>();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewExport">The new export.</param>
        NewExport(VxSdk::VxNewExport* vxNewExport);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~NewExport() {
            this->!NewExport();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !NewExport();

        /// <summary>
        /// Gets the clips that shall be included in this export when triggered.
        /// </summary>
        /// <value>A <c>List</c> of clips included in the export.</value>
        property System::Collections::Generic::List<NewExportClip^>^ Clips {
        public:
            System::Collections::Generic::List<NewExportClip^>^ get() { return _clips; }
        }

        /// <summary>
        /// Gets or sets the export format to use.
        /// </summary>
        /// <value>The export <see cref="Export::Formats">Format</see>.</value>
        property Export::Formats Format {
        public:
            Export::Formats get() { return (Export::Formats)_newExport->format; }
            void set(Export::Formats value) { _newExport->format = (VxSdk::VxExportFormat::Value)value; }
        }

        /// <summary>
        /// Gets or sets the friendly name of the export.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_newExport->name); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newExport->name, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the password for the Export. If set, the export data will be signed and encrypted. This password
        /// will be required to decrypt the export data. If not set, the export data will not be signed or encrypted.
        /// </summary>
        /// <value>The password.</value>
        property System::String^ Password {
        public:
            System::String^ get() { return gcnew System::String(_newExport->password); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newExport->password, Utils::ConvertSysString(value)); }
        }

    internal:
        VxSdk::VxNewExport* _newExport;
        System::Collections::Generic::List<NewExportClip^>^ _clips;
    };
}
#endif // NewExport_h__
