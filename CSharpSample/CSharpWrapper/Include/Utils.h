// Declares the utilities class.
#ifndef Utils_h__
#define Utils_h__

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <string>

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

            return System::DateTime::ParseExact(value, format, System::Globalization::CultureInfo::InvariantCulture);
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
}
#endif // Utils_h__
