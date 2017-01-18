// Declares the utilities class.
#ifndef Utils_h__
#define Utils_h__

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <string>
#include "VxSdk.h"

namespace CPPCli {

    /// <summary>
    /// The Results class is a helper class that contains the <see cref="Results::Value">Results</see> enum.
    /// </summary>
    public ref class Results {
    public:

        /// <summary>
        /// Values that represent the result of calls to the VideoXpert system.
        /// </summary>
        enum class Value {
            /// <summary>An error or unknown value was returned.</summary>
            UnknownError,

            /// <summary>The action was successful.</summary>
            OK,

            /// <summary>The VideoXpert system version is not supported.</summary>
            UnsupportedVersion,

            /// <summary>The size value was not sufficient enough to allocate the collection.</summary>
            InsufficientSize,

            /// <summary>The login credentials were invalid.</summary>
            InvalidLoginInfo,

            /// <summary>The attempted action is unsupported by the system.</summary>
            ActionUnavailable,

            /// <summary>A parameter was invalid.</summary>
            InvalidParameters,

            /// <summary>There was an error communicating to the device.</summary>
            CommunicationError,

            /// <summary>The key used to initialize the SDK was invalid.</summary>
            InvalidKey
        };
    };

    /// <summary>
    /// The LogLevel class is a helper class that contains the logging severity <see cref="LogLevel::Value">Values</see> enum.
    /// </summary>
    public ref class LogLevel {
    public:

        /// <summary>
        /// Values that represent the logging severity levels.
        /// </summary>
        enum class Value {
            Trace,
            Debug,
            Info,
            Warning,
            Error,
            Fatal,
            None
        };
    };

    /// <summary>
    /// Provides commonly used methods.
    /// </summary>
    private class Utils {
    public:
        static const char* GetDateFormat() { return "yyyy-MM-dd'T'HH:mm:ss.fff'Z'"; }

        /// <summary>
        /// Convert a system string to a char.
        /// </summary>
        /// <param name="sysString">The system string.</param>
        /// <returns>Null if it fails, else the converted string.</returns>
        static const char* ConvertSysString(System::String^ sysString) {
            msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
            return ctx->marshal_as<const char*>(sysString);
        }

        /// <summary>
        /// Convert a system string to a char.
        /// </summary>
        /// <param name="sysString">The system string.</param>
        /// <returns>Null if it fails, else the converted string.</returns>
        static char* ConvertSysStringNonConst(System::String^ sysString) {
            return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sysString);
        }

        /// <summary>
        /// Convert a system string to a standard string.
        /// </summary>
        /// <param name="sysString">The system string.</param>
        /// <returns>Null if it fails, else the converted string.</returns>
        static std::string ConvertSysStringStdString(System::String^ sysString) {
            msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
            return ctx->marshal_as<std::string>(sysString);
        }

        /// <summary>
        /// Convert a char to a DateTime.
        /// </summary>
        /// <param name="dateTimeString">The date string.</param>
        /// <returns>Default DateTime if it fails, else the parsed DateTime.</returns>
        static System::DateTime ConvertCharToDateTime(char* dateTimeString) {
            System::String^ value = gcnew System::String(dateTimeString);
            System::String^ format = gcnew System::String(GetDateFormat());
            if (value == System::String::Empty)
                return System::DateTime();

            System::DateTime timeValue;
            System::Globalization::CultureInfo^ culture = System::Globalization::CultureInfo::InvariantCulture;
            System::DateTime::TryParseExact(value, format, culture, System::Globalization::DateTimeStyles::None, timeValue);
            return timeValue;
        }

        /// <summary>
        /// Convert a DateTime to a char.
        /// </summary>
        /// <param name="dateTime">The DateTime.</param>
        /// <returns>The DateTime as a char.</returns>
        static const char* ConvertDateTimeToChar(System::DateTime dateTime) {
            System::String^ timeString = dateTime.ToString(gcnew System::String(GetDateFormat()));
            msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
            return ctx->marshal_as<const char*>(timeString);
        }

        /// <summary>
        /// Convert a DateTime to a char.
        /// </summary>
        /// <param name="dateTime">The DateTime.</param>
        /// <returns>The DateTime as a char.</returns>
        static char* ConvertDateTimeToCharNonConst(System::DateTime dateTime) {
            System::String^ timeString = dateTime.ToString(gcnew System::String(GetDateFormat()));
            msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
            return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(timeString);
        }

        /// <summary>
        /// Convert a DateTime to a char in TimeOfDay format.
        /// </summary>
        /// <param name="dateTime">The DateTime.</param>
        /// <returns>The DateTime as a char in TimeOfDay format.</returns>
        static const char* ConvertDateTimeToTimeChar(System::DateTime dateTime) {
            System::String^ timeString = dateTime.ToString(gcnew System::String("HH:mm:ss"));
            msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
            return ctx->marshal_as<const char*>(timeString);
        }

        /// <summary>
        /// Convert a DateTime to a char in TimeOfDay format.
        /// </summary>
        /// <param name="dateTime">The DateTime.</param>
        /// <returns>The DateTime as a char in TimeOfDay format.</returns>
        static char* ConvertDateTimeToTimeCharNonConst(System::DateTime dateTime) {
            System::String^ timeString = dateTime.ToString(gcnew System::String("HH:mm:ss"));
            msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
            return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(timeString);
        }

        /// <summary>
        /// Convert a char to a DateTime using TimeOfDay format.
        /// </summary>
        /// <param name="timeString">The time string.</param>
        /// <returns>Default DateTime if it fails, else the parsed DateTime.</returns>
        static System::DateTime ConvertTimeCharToDateTime(char* timeString) {
            System::String^ value = gcnew System::String(timeString);
            System::String^ format = gcnew System::String("HH:mm:ss");
            if (value == System::String::Empty)
                return System::DateTime();

            return System::DateTime::ParseExact(value, format, System::Globalization::CultureInfo::InvariantCulture);
        }
    };

    /// <summary>
    /// Provides global VxSDK methods.
    /// </summary>
    public ref class VxGlobal{
    public:
        /// <summary>
        /// Initialize the VideoXpert SDK.
        /// </summary>
        /// <param name="key">The key to initialize the SDK with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the initialization process.</returns>
        static CPPCli::Results::Value InitializeSdk(System::String^ key) {
            // Init the sdk with your key generated using VxSdkKeyGen.exe
            VxSdk::VxResult::Value result = VxSdk::VxInit(Utils::ConvertSysString(key));

            return CPPCli::Results::Value(result);
        }

        /// <summary>
        /// Sets the minimum severity level of messages to log.
        /// </summary>
        /// <param name="logLevel">The logging severity <see cref="LogLevel">level</see>.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of setting the configuration.</returns>
        static CPPCli::Results::Value SetLogLevel(CPPCli::LogLevel::Value logLevel) {
            // Set the log level
            VxSdk::VxResult::Value result = VxSdk::VxSetLogLevel((VxSdk::VxLogLevel::Value)logLevel);

            return CPPCli::Results::Value(result);
        }

        /// <summary>
        /// Sets the output path for log files.
        /// </summary>
        /// <param name="logPath">The directory to store the generated log files.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of setting the configuration.</returns>
        static CPPCli::Results::Value SetLogPath(System::String^ logPath) {
            // Set the log path
            VxSdk::VxResult::Value result = VxSdk::VxSetLogPath(CPPCli::Utils::ConvertSysString(logPath));

            return CPPCli::Results::Value(result);
        }
    };
}
#endif // Utils_h__
