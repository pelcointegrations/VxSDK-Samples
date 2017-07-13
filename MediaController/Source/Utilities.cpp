#include "stdafx.h"
#include "Utilities.h"

using namespace std;

namespace MediaController {
    namespace Utilities {
        string UnixTimeToRfc3339(unsigned int unixTime) {
            time_t unixTimeValue = unixTime;
            tm tmTime;
#ifndef WIN32
            gmtime_r(&unixTimeValue, &tmTime);
#else
            gmtime_s(&tmTime, &unixTimeValue);
#endif
            char date[Constants::kDateMaxSize];
            strftime(date, sizeof(date), "%Y%m%dT%H%M%S.000Z-", &tmTime);
            return string(date);
        }

        unsigned int CurrentUnixTime() {
            time_t currentTime;
            time(&currentTime);
            return static_cast<unsigned int>(currentTime);
        }
    }
}
