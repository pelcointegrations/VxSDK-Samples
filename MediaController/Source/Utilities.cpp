#include "stdafx.h"
#include "Utilities.h"

using namespace std;

namespace MediaController {
    namespace Utilities {
        string UnixTimeToRfc3339(unsigned int unixTime) {
            time_t unixTimeValue = unixTime;
            tm tmTime;
            gmtime_s(&tmTime, &unixTimeValue);
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
