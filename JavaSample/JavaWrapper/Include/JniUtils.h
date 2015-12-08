#pragma once
#include<string>
#include <sstream>
#include <vector>

namespace CPPJniUtil
{
    void  CreateHitachiBinaryFile(int nCount);
    void BinaryFileToCsv();
    const std::string CurrentDateTime();
    template <typename T>
    T stringToNumber (std::string sNum )
    {
        T value;
        std::istringstream (sNum)>> value;   // value = 45
        return value;
    }
    template <typename T>
    std::string NumberToString ( T Number )
    {
        std::ostringstream ss;
        ss << Number;
        return ss.str();
    }
    template <typename T>
    T WStringToNumber (std::wstring sNum )
    {
        T value;
        std::wistringstream (sNum)>> value;   // value = 45
        return value;
    }
    template <typename T>
    std::wstring NumberToWString ( T Number )
    {
        std::wostringstream ss;
        ss << Number;
        return ss.str();
    }

    size_t  GetFileSize( const std::wstring& filePath );
    void GenerateInputCsv(const std::string& sCsvFileName, int nCount);
    void Test();
    void HitachiBinaryToTxt(std::string sFileName);
    std::vector<std::string> Split(const std::string& s, const std::string& delim, const bool keep_empty = true);
    void Split(const std::string& s, const std::string& delim, std::vector<std::string>& result, const bool keep_empty = true );
    void TestUnicode();
    std::wstring GetDirNameFromFullPath (const std::wstring& str);
    std::wstring GetFileNameFromFullPath (const std::wstring& str);
    std::string GetFileNameWithoutExtension(const std::string& fileName);
    const std::string CurrentDate(const char* format);
    bool IsFileExists(const std::wstring& fileName);
    std::string get_string_from_wsz(const wchar_t* pwsz);
    void CreateHitachiPcsBinaryFile(int nCount);
    const std::wstring& GetLocaleString(size_t ID);
}
