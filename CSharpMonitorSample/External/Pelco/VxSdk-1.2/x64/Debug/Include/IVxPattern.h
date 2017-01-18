#ifndef IVxPattern_h__
#define IVxPattern_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a predefined sequence of movement that a PTZ device can perform when triggered. A running pattern will be
    /// halted upon any other PTZ request.
    /// </summary>
    struct IVxPattern {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;

    public:
        /// <summary>
        /// The friendly description of the pattern.
        /// </summary>
        char description[64];
        /// <summary>
        /// The friendly name of the pattern.
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

#endif // IVxPattern_h__
