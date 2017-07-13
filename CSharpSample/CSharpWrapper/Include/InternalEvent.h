// Declares the internal event class.
#ifndef InternalEvent_h__
#define InternalEvent_h__

#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The InternalEvent class represents an internal event generated by the VxSDK.
    /// </summary>
    public ref class InternalEvent {
    public:

        /// <summary>
        /// Values that represent event types sent from the VxSDK.
        /// </summary>
        enum class EventType {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,

            /// <summary>The connection to the VideoXpert system was lost.</summary>
            SystemConnectionLost,

            /// <summary>The connection to the VideoXpert system was restored.</summary>
            SystemConnectionRestored
        };

        /// <summary>
        /// Default constructor.
        /// </summary>
        InternalEvent() {
            _internalEvent = new VxSdk::VxInternalEvent();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxInternalEvent">The internal event.</param>
        InternalEvent(VxSdk::VxInternalEvent* vxInternalEvent) : _internalEvent(vxInternalEvent) {};

        /// <summary>
        /// Gets the unique identifier of the event.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ Id {
        public:
            System::String^ get() { return gcnew System::String(_internalEvent->id); }
        }

        /// <summary>
        /// Gets any additional information related to the event.
        /// </summary>
        /// <value>A <c>List</c> containing the event properties.</value>
        property System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ Properties {
        public:
            System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ get() {
                System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ mList =
                    gcnew System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>();

                for (int i = 0; i < _internalEvent->propertySize; i++)
                {
                    System::Collections::Generic::KeyValuePair<System::String^, System::String^> kvPair(gcnew System::String(_internalEvent->properties[i].key),
                        gcnew System::String(_internalEvent->properties[i].value));

                    mList->Add(kvPair);
                }

                return mList;
            }
        }

        /// <summary>
        /// Gets the internal event type.
        /// </summary>
        /// <value>The type identifier of the event.</value>
        property EventType Type {
        public:
            EventType get() { return EventType(_internalEvent->eventType); }
        }

    internal:
        VxSdk::VxInternalEvent* _internalEvent;
    };
}
#endif // InternalEvent_h__
