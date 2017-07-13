// Declares the tag class.
#ifndef Tag_h__
#define Tag_h__

#include "VxSdk.h"
#include "Utils.h"
#include "DataSource.h"

namespace CPPCli {
    ref class User;

    /// <summary>
    /// The Tag class represents a non-hierarchical identifier typically associated with one or
    /// more resources (i.e. device or data source). A tag helps to describe a resource and allows it
    /// to be found more efficiently.
    /// </summary>
    public ref class Tag {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxTag">The vx tag.</param>
        Tag(VxSdk::IVxTag* vxTag);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Tag() {
            this->!Tag();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Tag();

        /// <summary>
        /// Associate data sources with this tag. If the data source is deleted, the association with
        /// this tag shall also be removed.
        /// </summary>
        /// <param name="dataSources">A <c>List</c> containing the data sources to be added.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the data sources.</returns>
        CPPCli::Results::Value Link(System::Collections::Generic::List<CPPCli::DataSource^>^ dataSources);

        /// <summary>
        /// Associate devices with this tag. If the device is deleted, the association with this tag
        /// shall also be removed.
        /// </summary>
        /// <param name="devices">A <c>List</c> containing the devices to be added.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the devices.</returns>
        CPPCli::Results::Value Link(System::Collections::Generic::List<CPPCli::Device^>^ devices);

        /// <summary>
        /// Merge this tag into the given tag. All links associated with this tag will be re-associated
        /// with the given tag; this tag will then be deleted.
        /// </summary>
        /// <param name="tag">The tag to merge into.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of merging the tag.</returns>
        CPPCli::Results::Value Merge(CPPCli::Tag^ tag);

        /// <summary>
        /// Update this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Remove data source associations from this tag.
        /// </summary>
        /// <param name="dataSources">A <c>List</c> containing the data sources to be removed.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the data sources.</returns>
        CPPCli::Results::Value Unlink(System::Collections::Generic::List<CPPCli::DataSource^>^ dataSources);

        /// <summary>
        /// Remove device associations from this tag.
        /// </summary>
        /// <param name="devices">A <c>List</c> containing the devices to be removed.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of removing the devices.</returns>
        CPPCli::Results::Value Unlink(System::Collections::Generic::List<CPPCli::Device^>^ devices);

        /// <summary>
        /// Gets the unique identifier for this tag.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_tag->id); }
        }

        /// <summary>
        /// Gets the data sources associated with this tag.
        /// </summary>
        /// <value>A list of data sources.</value>
        property System::Collections::Generic::List<DataSource^>^ LinkedDataSources {
        public:
            System::Collections::Generic::List<DataSource^>^ get() { return _GetLinkedDataSources(); }
        }

        /// <summary>
        /// Gets the devices associated with this tag.
        /// </summary>
        /// <value>A list of devices.</value>
        property System::Collections::Generic::List<Device^>^ LinkedDevices {
        public:
            System::Collections::Generic::List<Device^>^ get() { return _GetLinkedDevices(); }
        }

        /// <summary>
        /// Gets or sets the friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_tag->name); }
            void set(System::String^ value) {
                char name[64];
                VxSdk::Utilities::StrCopySafe(name, Utils::ConvertSysStringNonConst(value));
                _tag->SetName(name);
            }
        }

        /// <summary>
        /// Gets the user that owns this tag.
        /// </summary>
        /// <value>The user that owns this tag.</value>
        property User^ Owner {
        public:
            User^ get() { return _GetOwner(); }
        }

        /// <summary>
        /// Gets the name of the user that owns this tag.
        /// </summary>
        /// <value>The name of the user that owns this tag.</value>
        property System::String^ OwnerName {
        public:
            System::String^ get() { return gcnew System::String(_tag->owner); }
        }

    internal:
        VxSdk::IVxTag* _tag;
        System::Collections::Generic::List<DataSource^>^ _GetLinkedDataSources();
        System::Collections::Generic::List<Device^>^ _GetLinkedDevices();
        User^ _GetOwner();
    };
}
#endif // Tag_h__
