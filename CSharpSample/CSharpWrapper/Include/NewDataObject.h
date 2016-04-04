// Declares the new data object class.
#ifndef NewDataObject_h__
#define NewDataObject_h__

#include "DataObject.h"

namespace CPPCli {

    /// <summary>
    /// The NewDataObject class represents a new data object.
    /// </summary>
    public ref class NewDataObject {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewDataObject() {
            _newDataObject = new VxSdk::VxNewDataObject();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewDataObject">The new data object.</param>
        NewDataObject(VxSdk::VxNewDataObject* vxNewDataObject) {
            _newDataObject = vxNewDataObject;
        }

        /// <summary>
        /// Gets or sets the client identifier. Recommend using the Java package naming convention: com.&gt;company&lt;.&gt;project&lt;.&gt;client_name&lt;.
        /// </summary>
        /// <value>The unique friendly name.</value>
        property System::String^ ClientType {
        public:
            System::String^ get() { return gcnew System::String(_newDataObject->clientType); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newDataObject->clientType, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the serialized data (e.g.: JSON, XML, CSV, etc). The maximum allowable size of this field is 1MB.
        /// </summary>
        /// <value>The serialized data.</value>
        property System::String^ Data {
        public:
            System::String^ get() { return gcnew System::String(_newDataObject->data); }
            void set(System::String^ value) { _newDataObject->data = Utils::ConvertSysStringNonConst(value); }
        }

        /// <summary>
        /// Gets or sets whether the new data object will not be owned (public) or will be owned by the user
        /// submitting the request (private).
        /// </summary>
        /// <value><c>true</c> if the data object will be public, <c>false</c> if private.</value>
        property bool IsPrivate {
        public:
            bool get() { return _newDataObject->isPrivate; }
            void set(bool value) { _newDataObject->isPrivate = value; }
        }

    internal:
        VxSdk::VxNewDataObject* _newDataObject;
    };
}
#endif // NewDataObject_h__
