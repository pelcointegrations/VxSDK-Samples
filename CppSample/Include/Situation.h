#include "VxSdk.h"
#pragma once

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxSituation
    /// </summary>
    class Situation {
    public:

        /// <summary>
        /// Constructor - copies the VxSDK situation pointer
        /// </summary>
        /// <param name="vxSituation">The situation pointer</param>
        Situation(VxSdk::IVxSituation* vxSituation);

        /// <summary>
        /// Returns the situation name
        /// </summary>
        const char* GetSituationName() { return _situation->name; }

        /// <summary>
        /// Returns the situation type
        /// </summary>
        const char* GetSituationType() { return _situation->type; }

        /// <summary>
        /// Returns the VxSDK situation pointer
        /// </summary>
        VxSdk::IVxSituation* Self() { return _situation; }

        /// <summary>
        /// Destructor
        /// </summary>
        ~Situation();

    private:
        VxSdk::IVxSituation* _situation;
    };
}
