#pragma once
#include "Clip.h"
#include "DataInterface.h"
#include "DataSession.h"
#include "PTZController.h"
#include <list>

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxDatasource
    /// </summary>
    class DataSource {
    public:

        /// <summary>
        /// Defines the state of device
        /// </summary>
        enum class DeviceState {
            Unknown,
            Offline,
            Online
        };

        /// <summary>
        /// Constructor - copies the VxSDK datasource pointer
        /// </summary>
        /// <param name="vxDataSource">The datasource pointer</param>
        DataSource(VxSdk::IVxDataSource* vxDataSource);

        /// <summary>
        /// Returns the clips available for this datasource
        /// List gets deleted on its destructor
        /// </summary>
        std::list<Clip*>* GetClips();

        /// <summary>
        /// Returns the dataInterfaces available for this datasource
        /// List gets deleted on its destructor
        /// </summary>
        std::list<CPPConsole::DataInterface*>* GetDataInterfaces();

        /// <summary>
        /// Returns the RTSP endpoint url
        /// Caller should be responsible for cleaning up the url memory
        /// </summary>
        char* GetRtspEndpoint();

        /// <summary>
        /// Creates and return DataSession pointer containg details to start MJPEG streaming
        /// Caller should be responsible for cleaning up the DataSession instance
        /// </summary>
        DataSession* CreateMJPEGSession();

        /// <summary>
        /// Returns datasource id
        /// </summary>
        const char* GetDataSourceId() { return _dataSource->id; }

        /// <summary>
        /// Returns datasource name
        /// </summary>
        const char* GetDataSourceName() { return _dataSource->name; }

        /// <summary>
        /// Returns datasource ip
        /// </summary>
        const char* GetDataSourceIp() { return _dataSource->ip; }

        /// <summary>
        /// Returns state of device
        /// </summary>
        const char* GetDeviceState() {
            if (_dataSource->state == VxSdk::VxDeviceState::kOffline) { return "Offline"; }
            if (_dataSource->state == VxSdk::VxDeviceState::kOnline) { return "Online"; }
            return "Unknown";
        }

        /// <summary>
        /// Returns new PTZController instance
        /// Caller should be responsible for deleting this
        /// </summary>
        PTZController* GetPtzController() {
            VxSdk::IVxPtzController* ptzController;
            VxSdk::VxResult::Value result = _dataSource->GetPtzController(ptzController);
            if (result == VxSdk::VxResult::kOK)
                return new PTZController(ptzController);

            return nullptr;
        }

        /// <summary>
        /// Returns whether this datasource supports PTZ or not
        /// </summary>
        bool IsPTZ() {
            bool result;
            _dataSource->CanPtz(result);
            return result;
        }

        VxSdk::IVxDataSource* Self() {
            return _dataSource;
        }

        /// <summary>
        /// Destructor
        /// </summary>
        ~DataSource();

    private:
        VxSdk::IVxDataSource* _dataSource;
        std::list<Clip*>* _clipsList;
        std::list<DataInterface*>* _dataInterfaceList;
    };
}
