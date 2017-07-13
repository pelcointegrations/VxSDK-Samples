// Declares the new bookmark class.
#ifndef NewBookmark_h__
#define NewBookmark_h__

#include "Bookmark.h"

namespace CPPCli {

    /// <summary>
    /// The NewBookmark class represents a new bookmark.
    /// </summary>
    public ref class NewBookmark {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewBookmark() {
            _newBookmark = new VxSdk::VxNewBookmark();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewBookmark">The new bookmark.</param>
        NewBookmark(VxSdk::VxNewBookmark* vxNewBookmark) {
            _newBookmark = vxNewBookmark;
        }

        /// <summary>
        /// Gets or sets the unique identifier of the data source.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ DataSourceId {
        public:
            System::String^ get() { return gcnew System::String(_newBookmark->dataSourceId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newBookmark->dataSourceId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the description of the bookmark.
        /// </summary>
        /// <value>The bookmark description.</value>
        property System::String^ Description {
        public:
            System::String^ get() { return gcnew System::String(_newBookmark->description); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newBookmark->description, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the friendly name of the bookmark.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_newBookmark->name); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newBookmark->name, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the time at which the point of interest occurred.
        /// </summary>
        /// <value>The time at which the point of interest occurred.</value>
        property System::DateTime Time {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_newBookmark->time); }
            void set(System::DateTime value) { VxSdk::Utilities::StrCopySafe(_newBookmark->time, Utils::ConvertDateTimeToChar(value)); }
        }

    internal:
        VxSdk::VxNewBookmark* _newBookmark;
    };
}
#endif // NewBookmark_h__
