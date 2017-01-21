#pragma once

#include "VxSdk.h"
#include <Rpc.h>

namespace CppSamples {
    namespace Common {
        class Utility {
        public:
            Utility() {}
            ~Utility() {}

            /// <summary>
            /// Initialize the SDK.
            /// </summary>
            static bool Init();

            /// <summary>
            /// Login to the VideoExpert system.
            /// </summary>
            /// <param name=""></param>
            static VxSdk::IVxSystem* Login();

            /// <summary>
            /// Converts the local time to UTC format
            /// </summary>
            /// <param name="t">Time struct to convert</param>
            static std::string ConvertLocalTimetoUTC(struct tm t);

            /// <summary>
            /// Converts the UTC time to local time format
            /// </summary>
            /// <param name="t">Time struct to convert</param>
            static std::string ConvertUTCtoLocalTime(struct tm t);

            /// <summary>
            /// Encode given std::string using Base64
            /// </summary>
            /// <param name="toEncode">String to encode</param>
            static std::string Encode(const std::string& toEncode);

            /// <summary>
            /// Get the date and time input from user and returns in struct format
            /// </summary>
            static struct tm GetDateAndTimeFromUser();

            /// <summary>
            /// Parse a date time string and return in struct format
            /// </summary>
            static struct tm ParseDateTime(char* dateTime);

            /// <summary>
            /// Show progress indicator in console
            /// </summary>
            /// <param name="statusMsg">Message to display</param>
            /// <param name="x">progress value</param>
            /// <param name="n">actual size</param>
            /// <param name="w">width of bar</param>
            static void ShowProgress(std::string statusMsg, unsigned int x, unsigned int n, int w = 50);

            /// <summary>
            /// Initializes a new instance of the System.Guid structure and returns equivalent std::string.
            /// </summary>
            /// <returns>String value of new Guid.</returns>
            static std::string GetNewGuid();

            /// <summary>
            /// Get the time zone offset in seconds
            /// </summary>
            static int TzOffset();
        };
    }
}
