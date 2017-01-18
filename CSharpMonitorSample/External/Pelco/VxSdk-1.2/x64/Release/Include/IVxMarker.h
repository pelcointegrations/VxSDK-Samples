#ifndef IVxMarker_h__
#define IVxMarker_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    struct IVxDataSource;

    /// <summary>
    /// Represents the location of a resource on a drawing. A marker is associated with exactly one
    /// drawing, though a drawing may have many markers. A marker may be associated with one resource,
    /// though a resource may have many markers.
    /// </summary>
    struct IVxMarker {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes any resource association with this marker.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the marker.</returns>
        virtual VxResult::Value DeleteAssociation() const = 0;
        /// <summary>
        /// Deletes this marker from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the marker.</returns>
        virtual VxResult::Value DeleteMarker() const = 0;
        /// <summary>
        /// Gets the data source associated with this marker.
        /// </summary>
        /// <param name="dataSource">The associated data source.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAssociation(IVxDataSource*& dataSource) const = 0;
        /// <summary>
        /// Gets the drawing that this marker belongs to.
        /// </summary>
        /// <param name="drawing">The drawing this marker belongs to.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDrawing(IVxDrawing*& drawing) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the data source associated with this marker.
        /// </summary>
        /// <param name="dataSource">The data source to associate with this marker.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAssociation(IVxDataSource& dataSource) = 0;
        /// <summary>
        /// Sets the angular coordinate indicating the direction that the marker is facing on a polar grid
        /// (e.g.: 0 (right), 90 (up), 180 (left), 270 (down)).
        /// </summary>
        /// <param name="direction">The direction.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the direction.</returns>
        virtual VxResult::Value SetDirection(float direction) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the location of the marker on the associated drawing.
        /// </summary>
        /// <param name="x">The X coordinate.</param>
        /// <param name="y">The Y coordinate.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the coordinates.</returns>
        virtual VxResult::Value SetCoordinates(float x, float y) = 0;

    public:
        /// <summary>
        /// The unique identifier of the marker.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the marker.
        /// </summary>
        char name[64];
        /// <summary>
        /// The the angular coordinate indicating the direction that the marker is facing.
        /// </summary>
        float direction;
        /// <summary>
        /// The X coordinate.
        /// </summary>
        float x;
        /// <summary>
        /// The Y coordinate.
        /// </summary>
        float y;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->direction = 0;
            this->x = 0;
            this->y = 0;
        }
    };
}
#endif // IVxMarker_h__
