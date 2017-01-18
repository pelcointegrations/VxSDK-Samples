#ifndef VxNewEvent_h__
#define VxNewEvent_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxKvObject.h"

namespace VxSdk {
    /// <summary>
    /// Represents a request for a new event to be generated. The event will be generated based upon the event data, its situation
    /// configuration, and will receive a unique identifier.
    /// </summary>
    struct VxNewEvent {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewEvent"/> struct.
        /// </summary>
        VxNewEvent() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewEvent"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewEvent(const VxNewEvent& ref) {
            Utilities::StrCopySafe(this->generatorDeviceId, ref.generatorDeviceId);
            Utilities::StrCopySafe(this->situationType, ref.situationType);
            Utilities::StrCopySafe(this->sourceDeviceId, ref.sourceDeviceId);
            Utilities::StrCopySafe(this->sourceUserName, ref.sourceUserName);
            Utilities::StrCopySafe(this->time, ref.time);
            this->propertySize = ref.propertySize;
            this->properties = ref.properties;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewEvent"/> class.
        /// </summary>
        ~VxNewEvent() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->generatorDeviceId);
            VxZeroArray(this->situationType);
            VxZeroArray(this->sourceDeviceId);
            VxZeroArray(this->sourceUserName);
            VxZeroArray(this->time);
            this->propertySize = 0;
            this->properties = nullptr;
        }

    public:
        /// <summary>
        /// The unique identifier of the device that generated this event.
        /// </summary>
        char generatorDeviceId[64];
        /// <summary>
        /// The identifier for the type of situation that led to this new event.
        /// </summary>
        char situationType[64];
        /// <summary>
        /// The unique identifier of the device that the situation occurred on.
        /// </summary>
        char sourceDeviceId[64];
        /// <summary>
        /// The unique identifier of the user that caused the situation to occur.
        /// </summary>
        char sourceUserName[64];
        /// <summary>
        /// The time at which the situation occurred.
        /// </summary>
        char time[64];
        /// <summary>
        /// The size of <see cref="properties"/>.
        /// </summary>
        int propertySize;
        /// <summary>
        /// Optional additional information related to the event.
        /// </summary>
        VxKvObject* properties;
    };
}

#endif // VxNewEvent_h__
