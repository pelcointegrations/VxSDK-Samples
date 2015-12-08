#include "VxSdk.h"
#pragma once

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxClip
    /// </summary>
    class Clip {
    public:

        /// <summary>
        /// Constructor - copies the VxSDK clip pointer
        /// </summary>
        /// <param name="vxClip">The clip pointer</param>
        Clip(VxSdk::IVxClip* vxClip);

        /// <summary>
        /// Destructor
        /// </summary>
        ~Clip();

        /// <summary>
        /// Returns the datasource name for this clip
        /// </summary>
        const char* GetClipName() { return _clip->dataSourceName; }

        /// <summary>
        /// Returns the id of datasource for this clip
        /// </summary>
        const char* GetClipId() { return _clip->dataSourceId; }

        /// <summary>
        /// Returns the clip' start time
        /// </summary>
        const char* GetStartTime() { return _clip->startTime; }

        /// <summary>
        /// Returns the clip' end time
        /// </summary>
        const char* GetEndTime() { return _clip->endTime; }

    private:
        VxSdk::IVxClip* _clip;
    };
}
