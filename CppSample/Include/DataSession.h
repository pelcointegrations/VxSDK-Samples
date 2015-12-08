#include "VxSdk.h"

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxDataSession
    /// </summary>
    class DataSession {
    public:

        /// <summary>
        /// Constructor - copies the VxSDK data session pointer
        /// </summary>
        /// <param name="vxDataSession">The datasession pointer</param>
        DataSession(VxSdk::IVxDataSession* vxDataSession) { _dataSession = vxDataSession; }

        /// <summary>
        /// Destructor
        /// </summary>
        ~DataSession() {
            _dataSession->Delete();
            _dataSession = nullptr;
        }

        /// <summary>
        /// Returns the jpeguri that can be used for starting MJPEG streaming
        /// </summary>
        const char* GetJpegUri() { return _dataSession->jpegUri; }

    private:
        VxSdk::IVxDataSession* _dataSession;
    };
}