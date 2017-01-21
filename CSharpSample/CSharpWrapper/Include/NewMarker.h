// Declares the new Marker class.
#ifndef NewMarker_h__
#define NewMarker_h__

#include "Marker.h"

namespace CPPCli {

    /// <summary>
    /// The NewMarker class represents a new Marker.
    /// </summary>
    public ref class NewMarker {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewMarker() {
            _newMarker = new VxSdk::VxNewMarker();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewMarker">The new marker.</param>
        NewMarker(VxSdk::VxNewMarker* vxNewMarker) {
            _newMarker = vxNewMarker;
        }

        /// <summary>
        /// Gets or sets the data source id to associate with the marker.
        /// </summary>
        /// <value>The data source id.</value>
        property System::String^ AssociatedDataSourceId {
        public:
            System::String^ get() { return gcnew System::String(_newMarker->associatedDataSourceId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newMarker->associatedDataSourceId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the angular coordinate indicating the direction, if any, that the marker is
        /// facing on a polar grid(e.g.: 0 (right), 90 (up), 180 (left), 270 (down)).
        /// </summary>
        /// <value>The angular direction.</value>
        property float Direction {
        public:
            float get() { return _newMarker->direction; }
            void set(float value) { _newMarker->direction = value; }
        }

        /// <summary>
        /// Gets or sets the friendly name of the marker.
        /// </summary>
        /// <value>The friendly name of the marker.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_newMarker->name); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newMarker->name, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the X coordinate.
        /// </summary>
        /// <value>The X coordinate.</value>
        property float X {
        public:
            float get() { return _newMarker->x; }
            void set(float value) { _newMarker->x = value; }
        }

        /// <summary>
        /// Gets or sets the Y coordinate.
        /// </summary>
        /// <value>The Y coordinate.</value>
        property float Y {
        public:
            float get() { return _newMarker->y; }
            void set(float value) { _newMarker->y = value; }
        }

    internal:
        VxSdk::VxNewMarker* _newMarker;
    };
}
#endif // NewMarker_h__
