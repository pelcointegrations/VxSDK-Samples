#ifndef MediaRequest_h__
#define MediaRequest_h__

#include "VxSdk.h"

namespace MediaController {

    /// <summary>
    /// Contains the information needed to start a new media stream.
    /// </summary>
    struct MediaRequest {

        MediaRequest() {
            dataSource = nullptr;
            audioDataSource = nullptr;
        }

        /// <summary>
        /// The data source to use to create the new video stream.
        /// </summary>
        VxSdk::IVxDataSource* dataSource;

        /// <summary>
        /// The protocol to use for the new video stream.
        /// </summary>
        VxSdk::IVxDataInterface dataInterface;

        /// <summary>
        /// The data source to use to create the new audio stream.
        /// </summary>
        VxSdk::IVxDataSource* audioDataSource;

        /// <summary>
        /// The protocol to use for the new audio stream.
        /// </summary>
        VxSdk::IVxDataInterface audioDataInterface;
    };
}
#endif // MediaRequest_h__
