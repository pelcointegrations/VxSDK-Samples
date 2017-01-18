#ifndef IVxDataObject_h__
#define IVxDataObject_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    struct IVxUser;

    /// <summary>
    /// Represents a custom serialized data object submitted by a client and stored on the server.  The data is completely opaque to
    /// the server and other types of clients.
    /// </summary>
    struct IVxDataObject {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this data object from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the data object.</returns>
        virtual VxResult::Value DeleteDataObject() const = 0;
        /// <summary>
        /// Gets the serialized data.
        /// </summary>
        /// <param name="data">The serialized data.</param>
        /// <param name="size">The size of <paramref name="data"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetData(char* data, int& size) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxUser"/> that owns this data object, if any.
        /// </summary>
        /// <param name="user">The <see cref="IVxUser"/> that owns this data object.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetOwner(IVxUser*& user) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the serialized data value.
        /// </summary>
        /// <param name="data">The serialized data.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the data.</returns>
        virtual VxResult::Value SetData(char* data) = 0;

    public:
        /// <summary>
        /// The data object client identifier.
        /// </summary>
        char clientType[64];
        /// <summary>
        /// The unique identifier of the data object.
        /// </summary>
        char id[64];
        /// <summary>
        /// If present, indicates that this resource is owned by a user (it is private); this is their username. If not present, indicates
        /// that this resource is not owned (it is public).  If this data object has an owner, only the owner and users with appropriate
        /// permissions will be able to read it.
        /// </summary>
        char owner[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->clientType);
            VxZeroArray(this->id);
            VxZeroArray(this->owner);
        }
    };
}
#endif // IVxDataObject_h__
