#include "VxSdk.h"

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxPattern
    /// </summary>
    class Pattern {
    public:

        /// <summary>
        /// Constructor - copies the VxSDK pattern pointer
        /// </summary>
        /// <param name="vxPattern">The pattern pointer</param>
        Pattern(VxSdk::IVxPattern* vxPattern) { _pattern = vxPattern; }

        /// <summary>
        /// Destructor
        /// </summary>
        ~Pattern() {
            _pattern->Delete();
            _pattern = nullptr;
        }
        /// <summary>
        /// Returns the VxSDK pattern pointer
        /// </summary>
        VxSdk::IVxPattern* Self() { return _pattern; }

        /// <summary>
        /// Returns the pattern name
        /// </summary>
        const char* GetPatternName() { return _pattern->name; }

        /// <summary>
        /// Returns the pattern description
        /// </summary>
        const char* GetPatternDescription() { return _pattern->description; }

    private:
        VxSdk::IVxPattern* _pattern;
    };
}