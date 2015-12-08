#include "stdafx.h"

#include "Logger.h"
#include "JniUtils.h"


const std::string CLogger::m_sFileName = "Log.txt";
CLogger* CLogger::m_pThis = NULL;
std::ofstream CLogger::m_Logfile;
CLogger::CLogger()
{

}
CLogger* CLogger::getLogger(){
    if (m_pThis == NULL){
        m_pThis = new CLogger();
        m_Logfile.open(m_sFileName.c_str(), std::ios::out | std::ios::app);
    }
    return m_pThis;
}

void CLogger::Log(const char * format, ...)
{
    char sMessage[256];
    va_list args;
    va_start(args, format);
    vsprintf_s(sMessage, format, args);
    m_Logfile << "\n" << CPPJniUtil::CurrentDateTime() << ":\t";
    m_Logfile << sMessage;
    va_end(args);
}

void CLogger::Log(const std::string& sMessage)
{
    m_Logfile << "\n" << CPPJniUtil::CurrentDateTime() << ":\t";
    m_Logfile << sMessage;
}

CLogger& CLogger::operator<<(const std::string& sMessage)
{
    m_Logfile << "\n" << CPPJniUtil::CurrentDateTime() << ":\t";
    m_Logfile << sMessage;
    return *this;
}