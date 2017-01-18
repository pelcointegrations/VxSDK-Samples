#ifndef VxUtilities_h__
#define VxUtilities_h__

namespace VxSdk {
    /// <summary>
    /// Provides commonly used methods.
    /// </summary>
    namespace Utilities {
        /// <summary>
        /// Performs a safe string copy.
        /// </summary>
        /// <param name="dst">The destination.</param>
        /// <param name="src">The source.</param>
        template <size_t dstSize>
        static void StrCopySafe(char(&dst)[dstSize], const char* src) {
            if (src) {
                strncpy_s(dst, dstSize, src, dstSize - 1);
                dst[dstSize - 1] = 0;
            }
        }

        /// <summary>
        /// Performs a safe string copy.
        /// </summary>
        /// <param name="dst">The destination.</param>
        /// <param name="src">The source.</param>
        /// <param name="dstSize">The size of <paramref name="dst"/>.</param>
        static void StrCopySafe(char* dst, const char* src, int dstSize) {
            if (dst && src && dstSize > 0) {
                strncpy_s(dst, dstSize, src, dstSize - 1);
                dst[dstSize - 1] = 0;
            }
        }
    }
}

#endif // VxUtilities_h__
