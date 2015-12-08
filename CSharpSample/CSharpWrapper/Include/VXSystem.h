// Declares the VX System class.
#ifndef VXSystem_h__
#define VXSystem_h__

#include "Device.h"
#include "NewEvent.h"
#include "NewExport.h"
#include "NewSituation.h"

namespace CPPCli {

    /// <summary>
    /// The VXSystem class represents a VideoXpert system.  It is the entry point of the VideoXpert SDK
    /// and allows the user to manage the system and devices.
    /// </summary>
    public ref class VXSystem {
    public:

        /// <summary>
        /// Constructor that takes an IP as a parameter.
        /// </summary>
        /// <param name="ip">The IP address of the VideoXpert system.</param>
        VXSystem(System::String^ ip);

        /// <summary>
        /// Virtual destructor.
        /// </summary>
        virtual ~VXSystem() {
            this->!VXSystem();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !VXSystem();

        /// <summary>
        /// Log in to the VideoXpert system.
        /// </summary>
        /// <param name="username">The user name to log in with.</param>
        /// <param name="password">The password to log in with.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the log in process.</returns>
        Results::Value Login(System::String^ username, System::String^ password);

        /// <summary>
        /// Create a new export on the VideoXpert system.
        /// </summary>
        /// <param name="newExport">The new export to be added to the system.</param>
        /// <returns><c>nullptr</c> if it fails, else the new export ID.</returns>
        System::String^ CreateExport(NewExport^ newExport);

        /// <summary>
        /// Delete an export from the VideoXpert system.
        /// </summary>
        /// <param name="exportItem">The export to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the export.</returns>
        Results::Value DeleteExport(Export^ exportItem);

        /// <summary>
        /// Get the devices from the VideoXpert system.
        /// </summary>
        /// <returns>A <c>List</c> containing the devices on the system.</returns>
        System::Collections::Generic::List<Device^>^ GetDevices();

        /// <summary>
        /// Get the exports residing on the system.
        /// </summary>
        /// <returns>A <c>List</c> containing the exports on the system.</returns>
        System::Collections::Generic::List<Export^>^ GetExports();

        /// <summary>
        /// Get the situations residing on the system.
        /// </summary>
        /// <returns>A <c>List</c> containing the situations on the system.</returns>
        System::Collections::Generic::List<Situation^>^ GetSituations();

        /// <summary>
        /// Add a new situation to the system.
        /// </summary>
        /// <param name="newSituation">The new situation to be added to the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of adding the situation.</returns>
        Results::Value AddSituation(NewSituation^ newSituation);

        /// <summary>
        /// Delete an existing situation from the system.
        /// </summary>
        /// <param name="situationItem">The situation to be deleted from the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the situation.</returns>
        Results::Value DeleteSituation(Situation^ situationItem);

        /// <summary>
        /// Insert a new event into the system.
        /// </summary>
        /// <param name="newEvent">The new event to be injected into the system.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of injecting the event.</returns>
        Results::Value InjectEvent(NewEvent^ newEvent);

        /// <summary>
        /// Gets the unique identifier of the VideoXpert system.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
            System::String^ get() { return gcnew System::String(_system->id); }
        }

        /// <summary>
        /// Gets the friendly name of the VideoXpert system.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
            System::String^ get() { return gcnew System::String(_system->name); }
        }

        /// <summary>
        /// The native event callback delegate.
        /// </summary>
        /// <param name="vxEvent">The event sent from system.</param>
        [System::Runtime::InteropServices::UnmanagedFunctionPointer(
            System::Runtime::InteropServices::CallingConvention::Cdecl)]
        delegate void EventCallbackDelegate(VxSdk::IVxEvent* vxEvent);

        /// <summary>
        /// The managed event delegate.
        /// </summary>
        /// <param name="vxEvent">The event sent from the system as a managed type.</param>
        delegate void EventDelegate(Event^ vxEvent);

        /// <summary>
        /// SystemEvent is raised whenever a new event is created on the system.
        /// </summary>
        event EventDelegate ^ SystemEvent {
            void add(EventDelegate ^eventDelegate);
            void remove(EventDelegate ^eventDelegate);
        }

    internal:
        static void _FireEvent(VxSdk::IVxEvent* vxEvent);
        VxSdk::IVxSystem* _system;
        VxSdk::VxLoginInfo* _loginInfo;
        EventCallbackDelegate ^ _callback;
        static EventDelegate ^ _systemEvent;
    };
}
#endif // VXSystem_h__
