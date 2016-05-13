#include "VxSdk.h"
#pragma once

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxDataInterface
    /// </summary>
    class DataInterface {
    public:

        /// <summary>
        /// Defines the stream protocol
        /// </summary>
        enum class StreamProtocol {
            kStreamProtocolUnknown,
            kStreamProtocolMjpegPull,
            kStreamProtocolRtspRtp
        };

        /// <summary>
        /// Constructor - copies the VxSDK data interface pointer
        /// </summary>
        /// <param name="vxDataInterface">The datainterface pointer</param>
        DataInterface(VxSdk::IVxDataInterface* vxDataInterface);
        
        /// <summary>
        /// Returns the protocol used in the datainterface
        /// </summary>
        StreamProtocol GetProtocol() { return StreamProtocol(_dataInterface->protocol); }

        /// <summary>
        /// Destructor
        /// </summary>
        ~DataInterface() { }

    public:
        VxSdk::IVxDataInterface* _dataInterface;
    };
}
