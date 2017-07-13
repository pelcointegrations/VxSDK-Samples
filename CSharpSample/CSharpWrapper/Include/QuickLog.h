// Declares the quick log class.
#ifndef QuickLog_h__
#define QuickLog_h__

#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The QuickLog class represents a quick system health log.
    /// </summary>
    public ref class QuickLog {
    public:

        /// <summary>
        /// Values that represent status of creating a quick log.
        /// </summary>
        enum class LogCreationStatus {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,
            /// <summary>The log creation is in progress.</summary>
            InProgress,
            /// <summary>The log failed to be created.</summary>
            Failed,
            /// <summary>The log has successfully been created.</summary>
            Successful
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxQuickLog">The vx quick log.</param>
        QuickLog(VxSdk::IVxQuickLog* vxQuickLog);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~QuickLog() {
            this->!QuickLog();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !QuickLog();

        /// <summary>
        /// Gets the URI to the download location of the quick log.  The endpoint will only be available if the VideoXpert
        /// system has completed generating the log.
        /// </summary>
        /// <returns>The quick log endpoint, if available.</returns>
        property System::String^ QuickLogEndpoint {
        public:
            System::String^ get() { return _GetQuickLogEndpoint(); }
        }

        /// <summary>
        /// Gets the current status of generating the quick log.
        /// </summary>
        /// <value>The current quick log creation status.</value>
        property LogCreationStatus Status {
        public:
            LogCreationStatus get() { return _GetStatus(); }
        }

    internal:
        VxSdk::IVxQuickLog* _log;
        System::String^ _GetQuickLogEndpoint();
        LogCreationStatus _GetStatus();
    };
}
#endif // QuickLog_h__
