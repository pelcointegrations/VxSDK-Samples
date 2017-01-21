#pragma once

#include "VxSdk.h"
#include "MediaController.h"
#include <Windows.h>

#include "Plugin.h"

namespace CppSamples {
    namespace LiveStreaming {

        /// <summary>
        /// This plugin sample streams the video in live
        /// </summary>
        class DataSourceLiveStreaming : public CppSamples::Common::Plugin {
        private:
            bool _isPlayBack;

        public:
            DataSourceLiveStreaming(const std::string description, bool isPlayBack) : Plugin(description), _isPlayBack(isPlayBack) {}
            ~DataSourceLiveStreaming() {}

            /// <summary>
            /// Streams a video in live.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

        protected:
            /// <summary>
            /// Display the options that can be entered by user when a stream is playing
            /// </summary>
            /// <param name="isPtzEnabled">True indicates PTZ options to be displayed else player controls only</param>
            /// <param name="isLive">True indicates to show live options only else include playback options also</param>
            static void DisplayPlayerOptionsToConsole(bool isPtzEnabled, bool isLive);

            /// <summary>
            /// Streams a video in live.
            /// </summary>
            /// <param name="dataSources">collection of data source.</param>
            void DoLiveStreaming(VxSdk::VxCollection<VxSdk::IVxDataSource**> dataSources);

            /// <summary>
            /// Get an instance of IController for the given data source and data interface.
            /// </summary>
            /// <param name="dataSource">Instance of VxSdk::IVxDataSource.</param>
            /// <param name="dataInterface">Instance of VxSdk::IVxDataInterface.</param>
            /// <returns>Instance of IController.</returns>
            static MediaController::IController* GetController(VxSdk::IVxDataSource* dataSource, VxSdk::IVxDataInterface* dataInterface);

            /// <summary>
            /// Get a collection of data source from the given VideoExpert system.
            /// </summary>
            /// <param name="vxSystem">Pointer to the VideoExpert system.</param>
            /// <returns>A collection of data source.</returns>
            static VxSdk::VxCollection<VxSdk::IVxDataSource**> GetDataSources(VxSdk::IVxSystem* vxSystem);

            /// <summary>
            /// Print the details of the given data source to the screen.
            /// </summary>
            /// <param name="dataSource">The data source to be printed.</param>
            static void ShowDataSourceDetails(VxSdk::IVxDataSource* dataSource);

            /// <summary>
            /// Initiate streaming for selected datasource.
            /// This method checks the parameter isMjpegEnabled to determine whether streaming is RTSP or MJPEG
            /// Also, it will automatically invoke playback method, if seekTime is given a value; otherwise live streaming will be invoked
            /// </summary>
            /// <param name="dataSource">Selected datasource</param>
            /// <param name="dataInterface">Selected dataInterface</param>
            /// <param name="seekTime">nullptr for live; otherwise pass time in "yyyymmddThhmmssZ-" format</param>
            /// <returns>True if streaming was successfull. False otherwise.</returns>
            static bool StartStreamingForDataSource(VxSdk::IVxDataSource* dataSource, VxSdk::IVxDataInterface* dataInterface, time_t seekTime);

            /// <summary>
            /// Callback fired from MediaController class for updating the timestamp of currently playing stream
            /// </summary>
            /// <param name="timeEvent">Contains time info </param>
            static void TimestampCallback(MediaController::TimestampEvent* timeEvent);
        };
    }
}
