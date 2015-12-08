#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "JniUtils.h"
#include <fstream>
#include <iostream>
#include <codecvt>
#include <algorithm>

const std::string CPPJniUtil::CurrentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    localtime_s(&tstruct, &now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

const std::string CPPJniUtil::CurrentDate(const char* format) {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    localtime_s(&tstruct, &now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), format, &tstruct);
    return buf;
}
