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

            /// <summary>No valid license was found on the VideoXpert system.</summary>
            InvalidLicense,

            /// <summary>Camera is unavailable, data cannot be retrieved at this time.</summary>
            CameraUnavailable,

            /// <summary>
            /// No further stream data is currently available (the edge of a currently recording clip has been reached); more data will
            /// be available shortly.
            /// </summary>
            EdgeOfStream,

            /// <summary>
            /// No further stream data is available (the end of all recorded data has been reached; no further data is currently be recorded).
            /// </summary>
            EndOfStream,

            /// <summary>The server is unable to initiate any new stream sessions due to having reached its stream count capacity.</summary>
            NoAvailableStreams,

            /// <summary>Storage is unavailable, data cannot be retrieved at this time.</summary>
            StorageUnavailable,

            /// <summary>The data needed to perform the export operation can not be retrieved.</summary>
            ExportDataUnretrievable,

            /// <summary>The export storage location does not have enough free space to store the export.</summary>
            ExportStorageFull,

            /// <summary> The export storage location is not accessible due to invalid credentials.</summary>
            ExportStorageUnauthenticated,

            /// <summary>
            /// The export storage location is not accessible; this may be due to an invalid location, network issue, or storage issue.
            /// </summary>
            ExportStorageUnavailable,

            /// <summary>
            /// The requested operation is not possible due to a conflict with the resource. Typically this is due to a violation of a
            /// uniqueness property on one of the resource’s fields.
            /// </summary>
            Conflict,

            /// <summary>The server has insufficient resources to satisfy the request.</summary>
            InsufficientResources,

            /// <summary>
            /// The server is not in an appropriate state to be able to service this request. The server requires intervention in order
            /// to resolve this.
            /// </summary>
            NotReady,

            /// <summary>
            /// The server is not in an appropriate state to be able to service this request due to an authentication issue between it
            /// and another entity. The server requires intervention in order to resolve this.
            /// </summary>
            NotReadyUnauthenticated,

            /// <summary>
            /// The server is not in an appropriate state to be able to service this request due to an authorization issue between it
            /// and another entity. The server requires intervention in order to resolve this.
            /// </summary>
            NotReadyUnauthorized,

            /// <summary>The requested operation failed.</summary>
            OperationFailed,

            /// <summary>
            /// The server is incapable of handling the client request due to the size of the resulting response.What constitutes
            /// ’too large’ is entirely up to the server.
            /// </summary>
            ResponseTooLarge,

            /// <summary>The license that was supplied has an activation conflict with an existing license(e.g.duplicate activation IDs).</summary>
            ActivationConflict,

            /// <summary>The activation failed due to communication error with the FNO licensing server.</summary>
            ActivationHostNotFound,

            /// <summary>The activation failed.</summary>
            ActivationFailed,

            /// <summary>The license that was supplied is not compatible with the device and/or system that it is being applied to.</summary>
            IncompatibleLicense,

            /// <summary>A valid license is available but the available count on that license is fully utilized.</summary>
            LicenseCountExceeded,

            /// <summary>A valid license is required to utilize this method on the resource; no valid license found.</summary>
            LicenseRequired,

            /// <summary>Unable to apply the license; valid LDAP administrator credentials are required.</summary>
            LicenseReqLdapAdmin,

            /// <summary>Unable to commission (or float) a feature because no valid license is available for it.</summary>
            NoLicense,

            /// <summary>Camera is in use (or the usage dwell time is active) by same or higher authority user.</summary>
            CameraInUse,

            /// <summary>Camera is locked by same or higher authority user.</summary>
            CameraLocked,

            /// <summary>Locked by lower authority user, may override.</summary>
            NeedOverride,

            /// <summary>
            /// An attempt to set an invalid value on a writable field was made. The value may be invalid due to being out of range, unavailable, etc.
            /// </summary>
            InvalidValue,

            /// <summary>An attempt to set a new port number failed because the port number is already in use.</summary>
            PortInUse,

            /// <summary>An attempt to edit a read-only field was made.</summary>
            ReadOnlyField,

            /// <summary>An attempt to edit a locked resource was made by a user that does not own the IVxResourceLock.</summary>
            ResourceLocked,

            /// <summary>A request was made using expired authentication credentials.</summary>
            AuthExpired,

            /// <summary>A password with an insufficient number of digits was supplied in an attempt to create a new user password.</summary>
            PasswordReqMoreDigits,

            /// <summary>A password with an insufficient number of lowercase letters was supplied in an attempt to create a new user password.</summary>
            PasswordReqMoreLower,

            /// <summary>A password with an insufficient number of special characters was supplied in an attempt to create a new user password.</summary>
            PasswordReqMoreSpecial,

            /// <summary>A password with an insufficient number of uppercase letters was supplied in an attempt to create a new user password.</summary>
            PasswordReqMoreUpper,

            /// <summary>A password of insufficient length was supplied in an attempt to create a new user password.</summary>
            PasswordTooShort,

            /// <summary>A password too similar to a previous password was supplied in an attempt to create a new user password.</summary>
            PasswordTooSimilar,

            /// <summary>
            /// The requested operation is not possible due to a permission conflict with the resource. Typically this is due to a violation
            /// of permission hierarchy (e.g. a nested permission is being assigned without its parent permission already assigned).
            /// </summary>
            PermissionConflict,

            /// <summary>An unauthenticated request was made (i.e. invalid username and/or password).</summary>
            Unauthenticated,

            /// <summary>An unauthorized request was made (i.e. user does not have permission to access the resource).</summary>
            Unauthorized
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
            timeValue = System::DateTime::SpecifyKind(timeValue, System::DateTimeKind::Utc);
            return timeValue;
        }

        /// <summary>
        /// Convert a DateTime to a char.
        /// </summary>
        /// <param name="dateTime">The DateTime.</param>
        /// <returns>The DateTime as a char.</returns>
        static const char* ConvertDateTimeToChar(System::DateTime dateTime) {
            dateTime = dateTime.ToUniversalTime();
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
            dateTime = dateTime.ToUniversalTime();
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
            System::DateTime parsedTime;
            System::String^ value = gcnew System::String(timeString);
            if (value == System::String::Empty)
                return parsedTime;

            array<System::String^>^ formats = gcnew array<System::String^>(2);
            formats[0] = gcnew System::String("HH:mm:ss");
            formats[1] = gcnew System::String("HH:mm:ss.fff");
            System::DateTime::TryParseExact(value, formats, System::Globalization::CultureInfo::InvariantCulture, System::Globalization::DateTimeStyles::None, parsedTime);

            return parsedTime;
        }
    };

    /// <summary>
    /// Provides global VxSDK methods.
    /// </summary>
    public ref class VxGlobal{
    public:
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
