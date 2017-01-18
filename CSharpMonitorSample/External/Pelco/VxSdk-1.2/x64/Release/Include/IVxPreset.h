#ifndef IVxPreset_h__
#define IVxPreset_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a predefined point that a PTZ device can PTZ to when triggered.
    /// </summary>
    struct IVxPreset {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;

    public:
        /// <summary>
        /// The friendly description of the preset.
        /// </summary>
        char description[64];
        /// <summary>
        /// The friendly name of the preset.
        /// </summary>
        char name[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->description);
            VxZeroArray(this->name);
        }
    };
}

#endif // IVxPreset_h__
