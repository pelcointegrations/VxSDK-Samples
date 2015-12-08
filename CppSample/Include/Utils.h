#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "Constants.h"

namespace CPPConsole {
    class Utils {
    public:

        /// <summary>
        /// Encode given string using Base64
        /// </summary>
        /// <param name="toEncode">string to encode</param>
        static std::string Encode(const std::string& toEncode) {
            std::string kBase64Chars =
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz"
                "0123456789+/";
            const char* data = toEncode.c_str();
            size_t size = toEncode.length();
            std::string ret;
            int i = 0;
            unsigned char char_array_3[3];
            unsigned char char_array_4[4];

            while (size--) {
                char_array_3[i++] = *(data++);
                if (i == 3) {
                    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                    char_array_4[3] = char_array_3[2] & 0x3f;

                    for (i = 0; i < 4; i++)
                        ret += kBase64Chars[char_array_4[i]];
                    i = 0;
                }
            }

            if (i) {
                int j = 0;
                for (j = i; j < 3; j++)
                    char_array_3[j] = '\0';

                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (j = 0; j < i + 1; j++)
                    ret += kBase64Chars[char_array_4[j]];

                while (i++ < 3)
                    ret += '=';
            }
            return ret;
        }

        /// <summary>
        /// Retruns the event log path (where events received from server will be added)
        /// </summary>
        static std::string GetEventLogFilePath() {
            char buffer[MAX_PATH];
            GetModuleFileNameA(nullptr, buffer, MAX_PATH);
            std::string::size_type pos = std::string(buffer).find_last_of("\\/");
            std::string exePath = std::string(buffer).substr(0, pos);
            return exePath + "\\EventPool.txt";
        }

        /// <summary>
        /// Get the date and time input from user and returns in struct format
        /// </summary>
        static struct tm GetDateAndTimeFromUser() {
            std::string dateAndTimeVal;

            getline(std::cin, dateAndTimeVal);

            std::stringstream dateStream(dateAndTimeVal);
            struct tm t;
            struct tm parseTime;
            //Here parse date and time string value to time structure
            dateStream >> std::get_time(&parseTime, "%Y-%m-%d %H:%M:%S");

            t.tm_mon = parseTime.tm_mon;
            t.tm_year = parseTime.tm_year;
            t.tm_mday = parseTime.tm_mday;

            t.tm_hour = parseTime.tm_hour;
            t.tm_min = parseTime.tm_min;
            t.tm_sec = parseTime.tm_sec;

            return t;
        }

        /// <summary>
        /// Converts the local time to UTC format
        /// </summary>
        /// <param name="t">time struct to convert</param>
        static std::string ConvertLocalTimetoUTC(struct tm t) {
            std::stringstream fmt;
            time_t epochTime = mktime(&t);
            struct tm timeinfo;
            gmtime_s(&timeinfo, &epochTime);

            fmt << (timeinfo.tm_year + 1900) << "-"
                << std::setfill('0') << std::setw(2) << (timeinfo.tm_mon + 1) << "-"
                << std::setfill('0') << std::setw(2) << timeinfo.tm_mday << "T"
                << std::setfill('0') << std::setw(2) << timeinfo.tm_hour << ":"
                << std::setfill('0') << std::setw(2) << timeinfo.tm_min << ":"
                << std::setfill('0') << std::setw(2) << timeinfo.tm_sec << "Z";
            return fmt.str();
        }

        /// <summary>
        /// Converts the time to TZ format
        /// </summary>
        /// <param name="t">time struct to convert</param>
        static std::string ConvertToTZFormat(struct tm t) {
            std::stringstream fmt;
            time_t epochTime = mktime(&t);
            struct tm timeinfo;
            gmtime_s(&timeinfo, &epochTime);

            fmt << (timeinfo.tm_year + 1900)
                << std::setfill('0') << std::setw(2) << (timeinfo.tm_mon + 1)
                << std::setfill('0') << std::setw(2) << timeinfo.tm_mday << "T"
                << std::setfill('0') << std::setw(2) << timeinfo.tm_hour
                << std::setfill('0') << std::setw(2) << timeinfo.tm_min
                << std::setfill('0') << std::setw(2) << timeinfo.tm_sec << "Z-";
            return fmt.str();
        }

        /// <summary>
        /// Converts the UTC time format to string format (HH:MM::SS, Day Month)
        /// </summary>
        /// <param name="utcFormat">time string in UTC format (YYYYmmddTHHMMSSZ)</param>
        static std::string CovertUTCTimeFormatToString(std::string utcFormat) {
            std::vector<std::string> months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
            std::stringstream dateStream(utcFormat);
            struct tm parseTime;
            //Here parse date and time string value to time structure
            dateStream >> std::get_time(&parseTime, "%Y-%m-%dT%H:%M:%S.%X");
            std::string convertedStr = std::to_string(parseTime.tm_hour) + ":" +
                std::to_string(parseTime.tm_min) + ":" +
                std::to_string(parseTime.tm_sec) + "," +
                std::to_string(parseTime.tm_mday) + " " + months[parseTime.tm_mon];
            return convertedStr;
        }

        /// <summary>
        /// Show progress indicator in console
        /// </summary>
        /// <param name="statusMsg">Message to display</param>
        /// <param name="x">progress value</param>
        /// <param name="n">actual size</param>
        /// <param name="w">width of bar</param>
        static void ShowProgress(std::string statusMsg, unsigned int x, unsigned int n, int w = 50) {
            if ((x != n) && (x % (n / 100 + 1) != 0)) return;

            float ratio = x / static_cast<float>(n);
            int  c = static_cast<int>(ratio * w);
            int percentToDisplay = static_cast<int>(ratio * 100);
            if (percentToDisplay > 100) percentToDisplay = 100; //Sometimes, it can go upto 101, 102; so limit it to 100.
            std::cout << "  " << statusMsg << "  " << std::setfill(' ') << std::setw(3) << percentToDisplay << "% [";
            for (int k = 0; k<c; k++) std::cout << "=";
            for (int m = c; m<w; m++) std::cout << " ";
            std::cout << "]\r" << std::flush;
        }

        /// <summary>
        /// Display the options that can be entered by user when a stream is playing
        /// </summary>
        /// <param name="isPtzEnabled">True indicates PTZ options to be displayed else player controls only</param>
        /// <param name="isLive">True indicates to show live options only else include playback options also</param>
        static void DisplayPlayerOptionsToConsole(bool isPtzEnabled, bool isLive) {
            if (isPtzEnabled) {
                std::cout <<
                    "USAGE: Choose one of the following options, then press enter:\n"
                    " '7' to send PTZ command: UpLeft\n"
                    " '8' to send PTZ command: Up\n"
                    " '9' to send PTZ command: UpRight\n"
                    " '4' to send PTZ command: Left\n"
                    " '6' to send PTZ command: Right\n"
                    " '1' to send PTZ command: DownLeft\n"
                    " '2' to send PTZ command: Down\n"
                    " '3' to send PTZ command: DownRight\n"
                    " '+' to send PTZ command: ZoomIn\n"
                    " '-' to send PTZ command: ZoomOut\n"
                    " '0' to show presets\n"
                    " '.' to show patterns\n"
                    " 'P' to toggle between PAUSE and PLAY\n";
                if (!isLive) {
                    std::cout << Constants::kZKeyMessage;
                    std::cout << Constants::kXKeyMessage;
                    std::cout << Constants::kLKeyMessage;
                }
                std::cout << Constants::kQKeyMessage;
            }
            else {
                std::cout <<
                    "USAGE: Choose one of the following options, then press enter:\n"
                    " 'P' to toggle between PAUSE and PLAY\n";
                if (!isLive) {
                    std::cout << Constants::kZKeyMessage;
                    std::cout << Constants::kXKeyMessage;
                    std::cout << Constants::kLKeyMessage;
                }
                std::cout << Constants::kQKeyMessage;
            }
        }

        /// <summary>
        /// Draw a line on console
        /// </summary>
        static void DrawLine() {
            std::cout << std::setfill('-') << std::setw(80) << "-";
        }

        /// <summary>
        /// Display and get the main menu choice from user
        /// </summary>
        static int GetMainMenuChoiceFromUser() {
            int option = 0;
            std::cout << "\n\n  MAIN MENU\n";
            DrawLine();
            std::cout << "\n  1. Devices";
            std::cout << "\n  2. Export";
            std::cout << "\n  3. Events";
            std::cout << "\n  4. Exit";
            std::cout << Constants::kSelectOptionMessage;
            std::cin >> option;
            return option;
        }

        /// <summary>
        /// Display and get the devices sub menu choice from user
        /// </summary>
        static int GetDevicesSubMenuChoiceFromUser() {
            system("cls");
            int option = 0;
            DrawLine();
            std::cout << "\n  DEVICES\n";
            DrawLine();
            std::cout << "\n  1. View all Devices";
            std::cout << "\n  2. View devices page by page";
            std::cout << "\n  3. View Device details";
            std::cout << "\n  4. Live Streaming";
            std::cout << "\n  5. Playback";
            std::cout << "\n  6. Go back to main menu";
            std::cout << Constants::kSelectOptionMessage;
            std::cin >> option;
            return option;
        }

        /// <summary>
        /// Display and get the export sub menu choice from user
        /// </summary>
        static int GetExportSubMenuChoiceFromUser() {
            system("cls");
            int option = 0;
            DrawLine();
            std::cout << "\n  EXPORT\n";
            DrawLine();
            std::cout << "\n  1. View Exports";
            std::cout << "\n  2. Create New Export";
            std::cout << "\n  3. Delete Export";
            std::cout << "\n  4. Download Export";
            std::cout << "\n  5. Go back to main menu";
            std::cout << Constants::kSelectOptionMessage;
            std::cin >> option;
            return option;
        }

        /// <summary>
        /// Display and get the events sub menu choice from user
        /// </summary>
        static int GetEventsSubMenuChoiceFromUser() {
            system("cls");
            int option = 0;
            DrawLine();
            std::cout << "\n  EVENTS\n";
            DrawLine();
            std::cout << "\n  1. View events";
            std::cout << "\n  2. View Situations";
            std::cout << "\n  3. Add New Situation";
            std::cout << "\n  4. Delete Situation";
            std::cout << "\n  5. Inject Events";
            std::cout << "\n  6. Subscribe events";
            std::cout << "\n  7. Unsubscribe events";
            std::cout << "\n  8. Go back to main menu";
            std::cout << Constants::kSelectOptionMessage;
            std::cin >> option;
            return option;
        }
    };
}
