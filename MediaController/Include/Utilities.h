#ifndef Utilities_h__
#define Utilities_h__

namespace MediaController {

    /// <summary>
    /// Provides commonly used methods.
    /// </summary>
    namespace Utilities {

        /// <summary>
        /// Convert a unix timestamp to an RFC 3339 formatted string.
        /// </summary>
        /// <param name="unixTime">The unix timestamp.</param>
        /// <returns>An RFC 3339 formatted string.</returns>
        std::string UnixTimeToRfc3339(unsigned int unixTime);

        /// <summary>
        /// Get the current time as a unix timestamp.
        /// </summary>
        /// <returns>The current time as a unix timestamp.</returns>
        unsigned int CurrentUnixTime();
    }
}
#endif // Utilities_h__
