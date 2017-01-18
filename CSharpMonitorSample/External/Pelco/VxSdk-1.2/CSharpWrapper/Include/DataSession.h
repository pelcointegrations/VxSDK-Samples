// Declares the data session class.
#ifndef DataSession_h__
#define DataSession_h__

#include "VxSdk.h"

namespace CPPCli {

    /// <summary>
    /// The DataSession class represents a data session that is being transmitted
    /// by a data source, via a data interface, to a client.
    /// </summary>
    public ref class DataSession {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxDataSession">The vx data session.</param>
        DataSession(VxSdk::IVxDataSession* vxDataSession) {
            _dataSession = vxDataSession;
        }

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~DataSession() {
            this->!DataSession();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !DataSession() {
            _dataSession->Delete();
            _dataSession = nullptr;
        }

        /// <summary>
        /// Refreshes this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Update() { return (CPPCli::Results::Value)_dataSession->Update(); }

        /// <summary>
        /// Gets the vertical resolution of the data (Height).
        /// </summary>
        /// <value>The vertical resolution.</value>
        property int Height {
        public:
            int get() { return _dataSession->yResolution; }
        }

        /// <summary>
        /// Gets the unique identifier of the sessions data source.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_dataSession->id); }
        }

        /// <summary>
        /// Gets URI of the JPEG frame.
        /// </summary>
        /// <value>The JPEG URI.</value>
        property System::String^ JpegUri {
        public:
            System::String^ get() { return gcnew System::String(_dataSession->jpegUri); }
        }

        /// <summary>
        /// Gets the image quality of the data from 1 to 100. Smaller numbers have better quality than larger numbers.
        /// </summary>
        /// <value>The image quality value.</value>
        property int Quality {
        public:
            int get() { return _dataSession->quality; }
        }

        /// <summary>
        /// Gets the play speed of the data.
        /// </summary>
        /// <value>The play speed.</value>
        property float Speed {
        public:
            float get() { return _dataSession->speed; }
        }

        /// <summary>
        /// Gets the horizontal resolution of the data (Width).
        /// </summary>
        /// <value>The horizontal resolution.</value>
        property int Width {
        public:
            int get() { return _dataSession->xResolution; }
        }

    internal:
        VxSdk::IVxDataSession* _dataSession;
    };
}
#endif // DataSession_h__
