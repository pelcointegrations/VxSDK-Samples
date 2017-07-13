#include "stdafx.h"
#include "Constants.h"
#include "Utility.h"
#include <iomanip>
#ifndef WIN32
#include<time.h>
#include <uuid/uuid.h>
#endif

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

// Login to the VideoExpert system.
IVxSystem* Utility::Login(VxLoginInfo& loginInfo) {
    // Login to the VideoExpert system and get an instance of it.
    IVxSystem* system = nullptr;
    VxSystemLogin(loginInfo, system);

    // Return the system
    return system;
}

/// <summary>
/// Converts the local time to UTC format
/// </summary>
/// <param name="t">time struct to convert</param>
string Utility::ConvertLocalTimetoUTC(struct tm t) {
    // Convert local time to UTC
    stringstream fmt;
    time_t epochTime = mktime(&t);
    struct tm timeinfo;
#ifndef WIN32
    gmtime_r(&epochTime, &timeinfo);
#else
    gmtime_s(&timeinfo, &epochTime);
#endif

    // Convert tm structure to string
    fmt << timeinfo.tm_year + 1900 << "-"
        << setfill('0') << setw(2) << (timeinfo.tm_mon + 1) << "-"
        << setfill('0') << setw(2) << timeinfo.tm_mday << "T"
        << setfill('0') << setw(2) << timeinfo.tm_hour << ":"
        << setfill('0') << setw(2) << timeinfo.tm_min << ":"
        << setfill('0') << setw(2) << timeinfo.tm_sec << "Z";
    return fmt.str();
}

/// <summary>
/// Converts the UTC time to local time format
/// </summary>
/// <param name="t">time struct to convert</param>
string Utility::ConvertUTCtoLocalTime(struct tm t) {
    // Convert UTC to local time
    stringstream fmt;
    time_t epochTime = mktime(&t);
    epochTime += TzOffset();
    struct tm timeinfo;
    localtime_s(&timeinfo, &epochTime);

    // Convert tm structure to string
    fmt << timeinfo.tm_year + 1900 << "-"
        << setfill('0') << setw(2) << (timeinfo.tm_mon + 1) << "-"
        << setfill('0') << setw(2) << timeinfo.tm_mday << "T"
        << setfill('0') << setw(2) << timeinfo.tm_hour << ":"
        << setfill('0') << setw(2) << timeinfo.tm_min << ":"
        << setfill('0') << setw(2) << timeinfo.tm_sec << "Z";
    return fmt.str();
}

/// <summary>
/// Encode given string using Base64
/// </summary>
/// <param name="toEncode">string to encode</param>
string Utility::Encode(const string& toEncode) {
    string kBase64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const char* data = toEncode.c_str();
    size_t size = toEncode.length();
    string ret;
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
/// Get the date and time input from user and returns in struct format
/// </summary>
tm Utility::GetDateAndTimeFromUser() {
    struct tm parseTime;
    while (true) {
        // Read a line from user input
        string dateAndTimeVal;
        getline(cin, dateAndTimeVal);

        if (!dateAndTimeVal.empty()) {
            // Here parse date and time string value to time structure
            stringstream dateStream(dateAndTimeVal);
            dateStream >> get_time(&parseTime, "%Y-%m-%d %H:%M:%S");
            if (dateStream.fail()) {
                cout << "Invalid time.\n";
            }
            else {
                break;
            }
        }
        else {
            cout << "Please enter a time.\n";
        }
        cout << "\n" << "Enter time (yyyy-mm-dd hh:mm:ss): ";
    }

    // Create new instance of time structure to avoid unnecessary info.
    struct tm t;
    t.tm_mon = parseTime.tm_mon;
    t.tm_year = parseTime.tm_year;
    t.tm_mday = parseTime.tm_mday;
    t.tm_hour = parseTime.tm_hour;
    t.tm_min = parseTime.tm_min;
    t.tm_sec = parseTime.tm_sec;
    return t;
}

/// <summary>
/// Parses a date time string and returns in struct format
/// </summary>
tm Utility::ParseDateTime(char* dateTime) {
    struct tm parseTime;
    string dateAndTimeVal = string(dateTime);

    // Here parse date and time string value to time structure
    stringstream dateStream(dateAndTimeVal);
    dateStream >> get_time(&parseTime, "%Y-%m-%dT%H:%M:%S");

    // Create new instance of time structure to avoid unnecessary info.
    struct tm t;
    t.tm_mon = parseTime.tm_mon;
    t.tm_year = parseTime.tm_year;
    t.tm_mday = parseTime.tm_mday;
    t.tm_hour = parseTime.tm_hour;
    t.tm_min = parseTime.tm_min;
    t.tm_sec = parseTime.tm_sec;
    return t;
}

/// <summary>
/// Show progress indicator in console
/// </summary>
/// <param name="statusMsg">Message to display</param>
/// <param name="x">progress value</param>
/// <param name="n">actual size</param>
/// <param name="w">width of bar</param>
void Utility::ShowProgress(string statusMsg, unsigned int x, unsigned int n, int w) {
    if ((x != n) && (x % (n / 100 + 1) != 0))
        return;

    float ratio = x / static_cast<float>(n);
    int  c = static_cast<int>(ratio * w);
    int percentToDisplay = static_cast<int>(ratio * 100);
    // Sometimes, it can go upto 101, 102; so limit it to 100.
    if (percentToDisplay > 100)
        percentToDisplay = 100;
    cout << "  " << statusMsg << "  " << setfill(' ') << setw(3) << percentToDisplay << "% [";
    for (int k = 0; k < c; k++) cout << "=";
    for (int m = c; m < w; m++) cout << " ";
    cout << "]\r" << flush;
}

/// <summary>
/// Initializes a new instance of the System.Guid structure and returns equivalent string.
/// </summary>
/// <returns>String value of new Guid.</returns>
string Utility::GetNewGuid() {
    // Create new instance of GUID
#ifndef WIN32
    uuid_t uuid;
    uuid_generate_random ( uuid );
    char buffer[37];
    uuid_unparse ( uuid, buffer );
    return string(buffer);
#else
    GUID newGuid;
    HRESULT hCreateGuid = CoCreateGuid(&newGuid);

    // Convert the GUID to string
    char buffer[37];
    sprintf_s(buffer, "%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
        newGuid.Data1, newGuid.Data2, newGuid.Data3,
        newGuid.Data4[0], newGuid.Data4[1], newGuid.Data4[2], newGuid.Data4[3],
        newGuid.Data4[4], newGuid.Data4[5], newGuid.Data4[6], newGuid.Data4[7]);
    return string(buffer);
#endif
}

/// <summary>
/// Get the time zone offset in seconds
/// </summary>
int Utility::TzOffset() {
    int offset;
    tm utcTm{ 0 }, localTm{ 0 };
    time_t local = time(nullptr), utc;
#ifndef WIN32
    gmtime_r(&local, &utcTm);
#else
    gmtime_s(&utcTm, &local);
#endif
    localtime_s(&localTm, &local);
    localTm.tm_isdst = 0;
    local = mktime(&localTm);
    utc = mktime(&utcTm);
    offset = static_cast<int>(difftime(local, utc));
    return offset;
}

/// <summary>
/// Clear the screen
/// </summary>
void Utility::ClearScreen() {
#ifndef WIN32
    system("clear");
#else
    system("cls");
#endif
}

/// <summary>
/// Read a string from console input
/// </summary>
string Utility::ReadString() {
    string line = "";
    std::getline(std::cin, line);
    return line;
}

/// <summary>
/// Read an integer from console input
/// </summary>
int Utility::ReadInt() {
    string line = "";
    cin >> line;
    int value = atoi(line.c_str());
    while (std::cin.get() != '\n');
    return value;
}

/// <summary>
/// Pause for a user input
/// </summary>
void Utility::Pause() {
#ifndef WIN32
    std::cout << "Press any key to continue...";
    std::cin.clear();
    fseek(stdin, 0, SEEK_END);
    fflush(stdin);
    while (std::cin.get() != '\n');
#else
    system("pause");
#endif
}

/// <summary>
/// Replace a give string
/// </summary>
string Utility::Replace(string original, string from, string to) {
    int index = 0;
    int len = from.length();
    while (true) {
        index = original.find(from);
        if (index < 0) {
            break;
        }
        original = original.replace(index, len, to);
    }
    return original;
}

/// <summary>
/// Converts the UTC time format to string format (HH:MM::SS, Day Month)
/// </summary>
/// <param name="utcFormat">time string in UTC format (YYYYmmddTHHMMSSZ)</param>
string Utility::ConvertUTCTimeFormatToString(string utcFormat) {
    stringstream dateStream(utcFormat);
    struct tm parseTime;
    //Here parse date and time string value to time structure
    dateStream >> get_time(&parseTime, "%Y-%m-%dT%H:%M:%S");
    char buffer[18];
    strftime(buffer, 18, "%X %x", &parseTime);

    return string(buffer);
}
