// Declares the new tag class.
#ifndef NewTag_h__
#define NewTag_h__

#include "Tag.h"

namespace CPPCli {

    /// <summary>
    /// The NewTag class represents a new tag.
    /// </summary>
    public ref class NewTag {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewTag() {
            _newTag = new VxSdk::VxNewTag();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewTag">The new tag.</param>
        NewTag(VxSdk::VxNewTag* vxNewTag) {
            _newTag = vxNewTag;
        }

        /// <summary>
        /// Gets or sets whether the new tag will not be owned (public) or will be owned by the user
        /// submitting the request (private).
        /// </summary>
        /// <value><c>true</c> if the tag will be public, <c>false</c> if private.</value>
        property bool IsPublic {
        public:
            bool get() { return _newTag->isPublic; }
            void set(bool value) { _newTag->isPublic = value; }
        }

        /// <summary>
        /// Gets or sets the unique tag friendly name.
        /// </summary>
        /// <remarks>Note: Commas are invalid characters for this field and MUST NOT be used.</remarks>
        /// <value>The unique friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_newTag->name); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newTag->name, Utils::ConvertSysString(value)); }
        }

    internal:
        VxSdk::VxNewTag* _newTag;
    };
}
#endif // NewTag_h__
