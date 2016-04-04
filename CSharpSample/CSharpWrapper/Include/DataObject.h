// Declares the data object class.
#ifndef DataObject_h__
#define DataObject_h__

#include "VxSdk.h"
#include "Utils.h"
#include "DataObject.h"

namespace CPPCli {

    /// <summary>
    /// The DataObject class represents an object that contains a custom serialized data object submitted by a
    /// client and stored on the server. The data is completely opaque to the server and other types of clients.
    /// </summary>
    public ref class DataObject {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxDataObject">The vx data object.</param>
        DataObject(VxSdk::IVxDataObject* vxDataObject);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~DataObject() {
            this->!DataObject();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !DataObject();

        /// <summary>
        /// Gets the serialized data.
        /// </summary>
        /// <value>The serialized data.</value>
        property System::String^ Data {
        public:
            System::String^ get() { return _GetData(); }
        }

        /// <summary>
        /// Gets the client identifier.
        /// </summary>
        /// <value>The client identifier.</value>
        property System::String^ ClientType {
        public:
            System::String^ get() { return gcnew System::String(_dataObject->clientType); }
        }

        /// <summary>
        /// Gets the unique identifier for this data object.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_dataObject->id); }
        }

        /// <summary>
        /// Gets the owner.
        /// </summary>
        /// <value>The owner.</value>
        property System::String^ Owner {
        public:
            System::String^ get() { return gcnew System::String(_dataObject->owner); }
        }

    internal:
        VxSdk::IVxDataObject* _dataObject;
        System::String^ _GetData();
    };
}
#endif // DataObject_h__
