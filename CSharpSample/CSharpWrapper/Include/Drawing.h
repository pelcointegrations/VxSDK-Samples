// Declares the Drawing class.
#ifndef Drawing_h__
#define Drawing_h__

#include "VxSdk.h"
#include "Utils.h"
#include "NewMarker.h"
#include "Marker.h"
#include "ResourceLock.h"

namespace CPPCli {

    /// <summary>
    /// The Drawing class represents a diagrammatic representation of an area. A drawing may
    /// contain any number of markers to represent points of interest within the area.
    /// </summary>
    public ref class Drawing {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxDrawing">The vx Drawing.</param>
        Drawing(VxSdk::IVxDrawing* vxDrawing);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Drawing() {
            this->!Drawing();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Drawing();

        /// <summary>
        /// Creates a new marker.
        /// </summary>
        /// <param name="newMarker">The new marker to be added.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the request.</returns>
        Results::Value AddMarker(NewMarker^ newMarker);

        /// <summary>
        /// Deletes the binary drawing image data.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the image.</returns>
        Results::Value DeleteImage();

        /// <summary>
        /// Deletes the resource lock, if any.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the lock.</returns>
        Results::Value DeleteLock();

        /// <summary>
        /// Deletes a marker.
        /// </summary>
        /// <param name="marker">The marker to be deleted.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the request.</returns>
        Results::Value DeleteMarker(Marker^ marker);

        /// <summary>
        /// Gets the image uri, if any.
        /// </summary>
        /// <returns>The the image uri.</returns>
        System::String^ GetImageUri();

        /// <summary>
        /// Gets the resource lock, if any.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of the request.</returns>
        ResourceLock^ GetLock();

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Sets the binary drawing image data. The maximum allowable size of the image is 128 MB.
        /// Supported file types are DWG, JPG and PNG.
        /// </summary>
        /// <param name="imagePath">The local path to the image file.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the request.</returns>
        Results::Value SetImage(System::String^ imagePath);

        /// <summary>
        /// Sets a resource lock on this drawing, owned by the current user.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of the request.</returns>
        Results::Value SetLock();

        /// <summary>
        /// Gets the unique drawing identifier.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_drawing->id); }
        }

        /// <summary>
        /// Gets the markers associated with this drawing.
        /// </summary>
        /// <value>A <c>List</c> of the associated markers.</value>
        property System::Collections::Generic::List<Marker^>^ Markers {
        public:
            System::Collections::Generic::List<Marker^>^ get() { return _GetMarkers(); }
        }

        /// <summary>
        /// Gets or sets the friendly name.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_drawing->name); }
            void set(System::String^ value) {
                char name[64];
                VxSdk::Utilities::StrCopySafe(name, Utils::ConvertSysStringNonConst(value));
                _drawing->SetName(name);
            }
        }

    internal:
        VxSdk::IVxDrawing* _drawing;
        System::Collections::Generic::List<Marker^>^ _GetMarkers();
    };
}
#endif // Drawing_h__
