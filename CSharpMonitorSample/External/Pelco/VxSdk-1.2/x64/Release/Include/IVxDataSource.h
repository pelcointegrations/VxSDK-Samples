#ifndef IVxDataSource_h__
#define IVxDataSource_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxClip.h"
#include "IVxPtzController.h"
#include "IVxDataSession.h"
#include "VxCollection.h"
#include "IVxDataInterface.h"
#include "IVxDataStorage.h"

namespace VxSdk {
    struct IVxDevice;

    /// <summary>
    /// Represents a data producer in the system hosted by a device. Each data source provides a list of data interfaces, which
    /// provide a particular protocol used to transmit and control the data produced by this data source.
    /// </summary>
    struct IVxDataSource {
    public:
        /// <summary>
        /// Gets a value indicating whether PTZ is enabled.
        /// </summary>
        /// <param name="canPtz"><c>true</c> if PTZ is enabled, <c>false</c> if not.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CanPtz(bool& canPtz) const = 0;
        /// <summary>
        /// Create a new MJPEG <see cref="IVxDataSession"/>.
        /// </summary>
        /// <param name="dataSession"><c>nullptr</c> if it fails, else the new MJPEG streams <see cref="IVxDataSession"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreateMjpegDataSession(IVxDataSession*& dataSession) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the clips associated with this data source.
        /// <para>Available filters: kDataSourceId, kEndTime, kEvent, kFramerate, kPriority, kSearchEndTime, kSearchStartTime, kStartTime.</para>
        /// </summary>
        /// <param name="clipCollection">A <see cref="VxCollection"/> of the associated clips.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetClips(VxCollection<IVxClip**>& clipCollection) const = 0;
        /// <summary>
        /// Gets the data storages associated with this data source.
        /// <para>Available filters: kId, kModifiedSince, kName, kType.</para>
        /// </summary>
        /// <param name="dataStorageCollection">A <see cref="VxCollection"/> of data storages.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataStorages(VxCollection<IVxDataStorage**>& dataStorageCollection) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDevice"/> that hosts this data source.
        /// </summary>
        /// <param name="hostDevice">The host <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxPtzController"/> associated with this data source.
        /// </summary>
        /// <param name="ptzController"><c>nullptr</c> if PTZ is not supported on the device, else the <see cref="IVxPtzController"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPtzController(IVxPtzController*& ptzController) const = 0;
        /// <summary>
        /// Gets the RTSP stream endpoint URI.
        /// </summary>
        /// <param name="endpoint">The RTSP endpoint.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRtspEndpoint(char* endpoint, int& size) const = 0;
        /// <summary>
        /// Refreshes the member values for this object by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member values for this object.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the number property.
        /// </summary>
        /// <param name="number">The new number value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetNumber(int number) = 0;

    public:
        /// <summary>
        /// Indicates whether this data source is currently being captured by a recorder.
        /// </summary>
        bool isCapturing;
        /// <summary>
        /// Indicates whether the data source is currently recording.
        /// </summary>
        bool isRecording;
        /// <summary>
        /// Indicates whether the live stream is available.
        /// </summary>
        bool hasLive;
        /// <summary>
        /// Indicates whether the recorded video is available.
        /// </summary>
        bool hasRecorded;
        /// <summary>
        /// The unique identifier of the data source.
        /// </summary>
        char id[64];
        /// <summary>
        /// The IP of this data source.
        /// </summary>
        char ip[64];
        /// <summary>
        /// The friendly name of this data source.
        /// </summary>
        char name[64];
        /// <summary>
        /// The URI to retrieve the current live frame.
        /// </summary>
        char snapshotUri[512];
        /// <summary>
        /// The size of <see cref="dataInterfaces"/>.
        /// </summary>
        int dataInterfaceSize;
        /// <summary>
        /// The number used to designate the data source.
        /// </summary>
        int number;
        /// <summary>
        /// The data interfaces available for retrieval of data from this data source.
        /// </summary>
        IVxDataInterface** dataInterfaces;
        /// <summary>
        /// The type of media this data source contains.
        /// </summary>
        VxDataSourceType::Value type;
        /// <summary>
        /// The current operational state of the associated device.
        /// </summary>
        VxDeviceState::Value state;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->dataInterfaces = nullptr;
            VxZeroArray(this->id);
            VxZeroArray(this->ip);
            VxZeroArray(this->name);
            this->dataInterfaceSize = 0;
            this->number = 0;
            this->isCapturing = false;
            this->isRecording = false;
            this->hasLive = false;
            this->hasRecorded = false;
            this->type = VxDataSourceType::kUnknown;
            this->state = VxDeviceState::kUnknown;
        }
    };
}

#endif // IVxDataSource_h__
