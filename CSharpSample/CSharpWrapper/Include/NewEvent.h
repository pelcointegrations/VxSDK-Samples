// Declares the event class.
#ifndef NewEvent_h__
#define NewEvent_h__

#include "Utils.h"
#include "Event.h"

namespace CPPCli {

    /// <summary>
    /// The NewEvent class represents a request for a new event to be generated. The
    /// event will be generated based upon the NewEvent data, its Situation configuration,
    /// and will receive a unique identifier.
    /// </summary>
    public ref class NewEvent {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        NewEvent() {
            _newEvent = new VxSdk::VxNewEvent();
        }

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxNewEvent">The new event.</param>
        NewEvent(VxSdk::VxNewEvent* vxNewEvent) : _newEvent(vxNewEvent) {};

        /// <summary>
        /// Gets or sets the identifier for the type of situation that led to this new event.
        /// </summary>
        /// <value>The type identifier of the situation.</value>
        property System::String^ SituationType {
        public:
            System::String^ get() { return gcnew System::String(_newEvent->situationType); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newEvent->situationType, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the unique identifier of the device that generated this event.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ GeneratorDeviceId {
        public:
            System::String^ get() { return gcnew System::String(_newEvent->generatorDeviceId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newEvent->generatorDeviceId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the unique identifier of the device that the situation occurred on.
        /// </summary>
        /// <value>The unique identifier.</value>
        property System::String^ SourceDeviceId {
        public:
            System::String^ get() { return gcnew System::String(_newEvent->sourceDeviceId); }
            void set(System::String^ value) { VxSdk::Utilities::StrCopySafe(_newEvent->sourceDeviceId, Utils::ConvertSysString(value)); }
        }

        /// <summary>
        /// Gets or sets the time at which the situation occurred.
        /// </summary>
        /// <value>The time.</value>
        property System::DateTime Time {
        public:
            System::DateTime get() { return Utils::ConvertCharToDateTime(_newEvent->time); }
            void set(System::DateTime value) { VxSdk::Utilities::StrCopySafe(_newEvent->time, Utils::ConvertDateTimeToChar(value)); }
        }

        /// <summary>
        /// Gets or sets any additional information related to the event.
        /// </summary>
        /// <value>A <c>List</c> containing the event properties.</value>
        property System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ Properties {
        public:
            System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ get() {
                System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ mList =
                    gcnew System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>();

                for (int i = 0; i < _newEvent->propertySize; i++)
                {
                    System::Collections::Generic::KeyValuePair<System::String^, System::String^> kvPair(gcnew System::String(_newEvent->properties[i].key),
                        gcnew System::String(_newEvent->properties[i].value));

                    mList->Add(kvPair);
                }

                return mList;
            }

            void set(System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<System::String^, System::String^>>^ value) {
                _newEvent->propertySize = value->Count;
                VxSdk::VxKvObject *kvObj = new VxSdk::VxKvObject[_newEvent->propertySize];
                _newEvent->properties = kvObj;

                for (int i = 0; i < _newEvent->propertySize; i++)
                {
                    strncpy_s(_newEvent->properties[i].key, Utils::ConvertSysString(value[i].Key), sizeof(_newEvent->properties[i].key));
                    strncpy_s(_newEvent->properties[i].value, Utils::ConvertSysString(value[i].Value), sizeof(_newEvent->properties[i].value));
                }
            }
        }

    internal:
        VxSdk::VxNewEvent* _newEvent;
    };
}
#endif // NewEvent_h__
