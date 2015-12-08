#pragma once
#include "DataSource.h"

namespace CPPConsole {

    /// <summary>
    /// Wrapper class to VxSDK VxDevice for fetching datasources
    /// </summary>
    class Device {
    public:

        /// <summary>
        /// Defines the type of device
        /// </summary>
        enum class DeviceType {
            Unknown,
            Camera,
            Core,
            CoreMg,
            Decoder,
            Encoder,
            Manager,
            Mg,
            Monitor,
            Recorder,
            Udi,
            Ui,
            Vcd
        };

        /// <summary>
        /// Constructor - copies the VxSDK device pointer
        /// </summary>
        /// <param name="vxDevice">The device pointer</param>
        Device(VxSdk::IVxDevice* vxDevice);

        /// <summary>
        /// Returns the datasources available for this device
        /// This list returned will be deleted in its destructor
        /// </summary>
        std::list<DataSource*>* GetDatasources();

        /// <summary>
        /// Returns the name of device
        /// </summary>
        const char* GetDeviceName() { return _device->name; }

        /// <summary>
        /// Returns the device ip
        /// </summary>
        const char* GetDeviceIp() { return _device->ip; }

        /// <summary>
        /// Returns the device model
        /// </summary>
        const char* GetDeviceModel() { return _device->model; }

        /// <summary>
        /// Returns the device id
        /// </summary>
        const char* GetDeviceId() { return _device->id; }

        /// <summary>
        /// Returns the vendor name
        /// </summary>
        const char* GetVendor() { return _device->vendor; }

        /// <summary>
        /// Returns the online state
        /// </summary>
        bool IsOnline() { return _device->state == VxSdk::VxDeviceState::kOnline; }

        /// <summary>
        /// Gets the device type
        /// </summary>
        DeviceType GetDeviceType() { return (DeviceType)_device->type; }

        /// <summary>
        /// Returns the device id
        /// </summary>
        const char* GetDeviceTypeInString() {
            const char* devType = "Unknown";
            switch (_device->type){
                case VxSdk::VxDeviceType::kCamera:
                    devType = "Camera";
                    break;
                case VxSdk::VxDeviceType::kCore:
                    devType = "Core";
                    break;
                case VxSdk::VxDeviceType::kCoreMg:
                    devType = "Core MG";
                    break;
                case VxSdk::VxDeviceType::kEncoder:
                    devType = "Encoder";
                    break;
                case VxSdk::VxDeviceType::kDecoder:
                    devType = "Decoder";
                    break;
                case VxSdk::VxDeviceType::kManager:
                    devType = "Manager";
                    break;
                case VxSdk::VxDeviceType::kMg:
                    devType = "Media Gateway";
                    break;
                case VxSdk::VxDeviceType::kMonitor:
                    devType = "Monitor";
                    break;
                case VxSdk::VxDeviceType::kRecorder:
                    devType = "Recorder";
                    break;
                case VxSdk::VxDeviceType::kUdi:
                    devType = "Udi";
                    break;
                case VxSdk::VxDeviceType::kUi:
                    devType = "Ui";
                    break;
                case VxSdk::VxDeviceType::kVcd:
                    devType = "Vcd";
                    break;
                case VxSdk::VxDeviceType::kUnknown:
                default:
                    break;
            }
            return devType;
        }

        /// <summary>
        /// Destructor
        /// </summary>
        ~Device();

    private:
        VxSdk::IVxDevice* _device;
        std::list<DataSource*>* _dataSourceList;
    };
}
