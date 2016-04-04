#ifndef MediaRequest_h__
#define MediaRequest_h__

#include "VxSdk.h"

namespace MediaController {

    /// <summary>
    /// Contains the information needed to start a new media stream.
    /// </summary>
    struct MediaRequest {

        /// <summary>
        /// The data source to use to create the new stream.
        /// </summary>
        VxSdk::IVxDataSource* dataSource;

        /// <summary>
        /// The protocol to use for the new stream.
        /// </summary>
        VxSdk::IVxDataInterface dataInterface;
    };
}
#endif // MediaRequest_h__
