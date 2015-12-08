#include "VxSdk.h"
#pragma once

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxEvent
    /// </summary>
    class Event {
    public:

        /// <summary>
        /// Defines the acknowledgement state of event
        /// </summary>
        enum class AckState {
            Unknown,
            AckNeeded,
            Acked,
            AutoAcked,
            NoAckNeeded,
            Silenced
        };

        /// <summary>
        /// Constructor - copies the VxSDK event pointer
        /// </summary>
        /// <param name="vxEvent">The event pointer</param>
        Event(VxSdk::IVxEvent* vxEvent) { _event = vxEvent; }
        
        /// <summary>
        /// Destructor
        /// </summary>
        ~Event();

        /// <summary>
        /// Returns the acknowledgment state
        /// </summary>
        AckState GetAckState() { return static_cast<AckState>(_event->ackState); }

        /// <summary>
        /// Returns event id
        /// </summary>
        const char* GetEventId() { return _event->id; }

        /// <summary>
        /// Returns generator device id for this event
        /// </summary>
        const char* GeneratorDeviceId() { return _event->generatorDeviceId; }

        /// <summary>
        /// Returns the severity for this event
        /// </summary>
        unsigned short GetSeverity() { return _event->severity; }

        /// <summary>
        /// Returns the situation type for this event
        /// </summary>
        const char* GetSituationType() { return _event->situationType; }

        /// <summary>
        /// Returns the time for this event
        /// </summary>
        const char* GetEventTime() { return _event->time; }

        /// <summary>
        /// Returns the source device id for this event
        /// </summary>
        const char* GetSourceDevideId() { return _event->sourceDeviceId; }

    private:
        VxSdk::IVxEvent* _event;
    };
    
}