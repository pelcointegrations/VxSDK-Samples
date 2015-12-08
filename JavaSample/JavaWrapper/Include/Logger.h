#ifndef CUSTOM_CLogger_H
#define CUSTOM_CLogger_H
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>

#define LOGGER CLogger::getLogger()
/**
*   Singleton Logger Class.
*/
class CLogger
{
public:
    /**
    *   Logs a message
    *   @param sMessage message to be logged.
    */
    void Log(const std::string& sMessage);
    /**
    *   Variable Length Logger function
    *   @param format string for the message to be logged.
    */
    void Log(const char * format, ...);
    /**
    *   << overloaded function to Logs a message
    *   @param sMessage message to be logged.
    */
    CLogger& operator<<(const std::string& sMessage);
    /**
    *   Funtion to create the instance of logger class.
    *   @return singleton object of Clogger class..
    */
    static CLogger* getLogger();
private:
    /**
    *    Default constructor for the Logger class.
    */
    CLogger();
    /**
    *   copy constructor for the Logger class.
    */
    CLogger(const CLogger&){};             // copy constructor is private
    /**
    *   assignment operator for the Logger class.
    */
    CLogger& operator=(const CLogger&){ return *this; };  // assignment operator is private
    /**
    *   Log file name.
    **/
    static const std::string m_sFileName;
    /**
    *   Singleton logger class object pointer.
    **/
    static CLogger* m_pThis;
    /**
    *   Log file stream object.
    **/
    static std::ofstream m_Logfile;
};
#endif
