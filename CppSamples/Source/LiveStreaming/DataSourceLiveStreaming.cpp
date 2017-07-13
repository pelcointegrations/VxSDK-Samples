#include "stdafx.h"
#include "DataSourceLiveStreaming.h"
#ifndef VxSdkInLinux
#include <Windows.h>
#endif
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Utility.h"
#include "PtzOperationsHandler.h"
#include "MediaOperationshandler.h"

using namespace std;
using namespace VxSdk;
using namespace MediaController;
using namespace CppSamples::Common;

// Gloabl Variables used for live streaming control
string _currentlyPlayingCam = "";
bool _gotPlayerHandle = false;
#ifndef VxSdkInLinux
HWND _gstreamerPlayerWindow = nullptr;
#endif

// Streams a video in live.
Plugin* CppSamples::LiveStreaming::DataSourceLiveStreaming::Run(DataModel* dataModel) {
    cout << "\n\n";
    VxCollection<IVxDataSource**> dataSources = GetDataSources(dataModel->VxSystem);

    try {
        // Start the live stream
        DoLiveStreaming(dataSources);
    } catch (...) {
        cout << "\nStream is not working.\n";
    }

    // Wait for user response before going back to parent menu.
    Utility::Pause();

    // Remove the memory allocated to the collection.
    delete[] dataSources.collection;
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

/// <summary>
/// Display the options that can be entered by user when a stream is playing
/// </summary>
/// <param name="isPtzEnabled">True indicates PTZ options to be displayed else player controls only</param>
/// <param name="isLive">True indicates to show live options only else include playback options also</param>
/// <param name="isRecording">True indicates the camera is in recording state</param>
void CppSamples::LiveStreaming::DataSourceLiveStreaming::DisplayPlayerOptionsToConsole(bool isPtzEnabled, bool isLive, bool isRecording) {
    cout << "\nUSAGE: Choose one of the following options, then press enter:\n";
    if (isPtzEnabled) {
        // Menu for PTZ enabled devices
        cout <<
                " '7' to send PTZ command: UpLeft\n"
                " '8' to send PTZ command: Up\n"
                " '9' to send PTZ command: UpRight\n"
                " '4' to send PTZ command: Left\n"
                " '6' to send PTZ command: Right\n"
                " '1' to send PTZ command: DownLeft\n"
                " '2' to send PTZ command: Down\n"
                " '3' to send PTZ command: DownRight\n"
                " '+' to send PTZ command: ZoomIn\n"
                " '-' to send PTZ command: ZoomOut\n"
                " '0' to show presets\n"
                " '.' to show patterns\n";
    }
    if (isRecording && !isLive) {
        cout <<
                " 'P' to toggle between PAUSE and PLAY\n"
                " 'z' to increase playback speed\n"
                " 'x' to decrease playback speed\n";
    }
    cout << " 'Q' to quit\n";
}

// Streams a video in live.
void CppSamples::LiveStreaming::DataSourceLiveStreaming::DoLiveStreaming(VxCollection<IVxDataSource**> dataSources) {
    // Select a Data source
    cout << "\n" << "Enter data source number [1-" << dataSources.collectionSize << "] : ";
    int camNum = Utility::ReadInt();

    // Verify input
    if (camNum < 1 || camNum > dataSources.collectionSize)
        return;

    IVxDataSource* dataSource = dataSources.collection[camNum - 1];

    // Proceed with online device only
    if (dataSource->type != VxDataSourceType::kVideo) {
        cout << "\n" << "Please select a video data source.\n";
        return;
    }

    // Proceed with online device only
    if (dataSource->state != VxDeviceState::kOnline) {
        cout << "\nDevice is offline.";
        return;
    }

    // Choose MJPEG or RTSP
    bool isMjpegEnabled = false;
    std::cout << "\nDo you want to play MJPEG (Y/N) [Default is RTSP]: ";
    string mJPEGOption = Utility::ReadString();
    if (mJPEGOption == "Y" || mJPEGOption == "y") { isMjpegEnabled = true; }

    // Read date and time for play back streaming
    time_t timeSinceEpoch = 0;
    if (_isPlayBack) {
        cout << "\n\n" << "Input date and time to start playback(yyyy-mm-dd hh:mm:ss)";
        struct tm playBackTime = Utility::GetDateAndTimeFromUser();
        timeSinceEpoch = mktime(&playBackTime);
    }

    // Print the details of selected data source
    ShowDataSourceDetails(dataSource);

    // Traverse through the data interfaces and choose the first one with given protocol will be chosen.
    for (int i = 0; i < dataSource->dataInterfaceSize; i++) {

        IVxDataInterface* dataInterface = dataSource->dataInterfaces[i];
        if (isMjpegEnabled) {
            // MJPEG Protocol
            if (dataInterface->protocol == VxStreamProtocol::kMjpegPull) {
                std::cout << "\nFound MJPEG DataInterface.\n";
                if (!StartStreamingForDataSource(dataSource, dataInterface, timeSinceEpoch)) {
                    std::cout << "\nStream failed to start. Checking for another MJPEG DataInterface.\n";
                    continue;
                }
                break;
            }
        }
        else {
            // RTSP Protocol
            if (dataInterface->protocol == VxStreamProtocol::kRtspRtp) {
                std::cout << "Found RTSP DataInterface.\n";
                if (!StartStreamingForDataSource(dataSource, dataInterface, timeSinceEpoch)) {
                    std::cout << "\nStream failed to start. Checking for another RTSP DataInterface.\n";
                    continue;
                }
                break;
            }
        }
    }
}

// Get an instance of IController for the given data source and data interface.
IController* CppSamples::LiveStreaming::DataSourceLiveStreaming::GetController(IVxDataSource* dataSource, IVxDataInterface* dataInterface) {
    // Create new instance of MediaRequest
    MediaController::MediaRequest mediaRequest;
    mediaRequest.dataSource = dataSource;
    mediaRequest.dataInterface = *dataInterface;
    mediaRequest.audioDataSource = nullptr;

    // Get controller for the given MediaRequest
    MediaController::IController* control = nullptr;
    MediaController::GetController(&mediaRequest, &control);
    return control;
}

// Get a collection of data source from the given VideoExpert system.
VxCollection<IVxDataSource**> CppSamples::LiveStreaming::DataSourceLiveStreaming::GetDataSources(IVxSystem* vxSystem) {
    cout << "Fetching datasources from system, nPlease wait...\n";
    // Read the size of collection from system.
    VxCollection<IVxDataSource**> dataSources;
    VxResult::Value result = vxSystem->GetDataSources(dataSources);
    if (result == VxResult::kInsufficientSize) {
        // Allocate memory for the requried collection.
        dataSources.collection = new IVxDataSource*[dataSources.collectionSize];
        // Read the collection from system.
        vxSystem->GetDataSources(dataSources);
    }
    // Print the number of data source items read from the system.
    cout << dataSources.collectionSize << " datasources found.\n";
    return dataSources;
}

// Print the details of the given data source to the screen.
void CppSamples::LiveStreaming::DataSourceLiveStreaming::ShowDataSourceDetails(IVxDataSource* dataSource) {
    // Read PTZ info
    bool canPtz;
    dataSource->CanPtz(canPtz);

    // Convert the state to its corresponding string
    string deviceState = "Unknown";
    if (dataSource->state == VxDeviceState::kOffline)
        deviceState = "Offline";
    else if (dataSource->state == VxDeviceState::kOnline)
        deviceState = "Online";

    // Print the details to the console screen.
    cout << "-----------------------------------------------------------------";
    cout << "\nName            : " << dataSource->name;
    cout << "\nID              : " << dataSource->id;
    cout << "\nIP              : " << dataSource->ip;
    cout << "\nPTZ             : " << (canPtz ? "Yes" : "No");
    cout << "\nState           : " << deviceState;
    cout << "\nLive Stream     : " << (dataSource->hasLive ? "Yes" : "No");
    cout << "\nPlayback Stream : " << (dataSource->hasRecorded ? "Yes" : "No");
    cout << "\nCapturing       : " << (dataSource->isCapturing ? "Yes" : "No");
    cout << "\nRecording       : " << (dataSource->isRecording ? "Yes" : "No");
    cout << "\nDataInterfaces  : " << dataSource->dataInterfaceSize;
    cout << "\n-----------------------------------------------------------------\n";
}

/// <summary>
/// Initiate streaming for selected datasource.
/// This method checks the parameter isMjpegEnabled to determine whether streaming is RTSP or MJPEG
/// Also, it will automatically invoke playback method, if seekTime is given a value; otherwise live streaming will be invoked
/// </summary>
/// <param name="dataSource">Selected datasource</param>
/// <param name="dataInterface">Selected dataInterface</param>
/// <param name="seekTime">nullptr for live; otherwise pass time in "yyyymmddThhmmssZ-" format</param>
/// <returns>True if streaming was successfull. False otherwise.</returns>
bool CppSamples::LiveStreaming::DataSourceLiveStreaming::StartStreamingForDataSource(
    IVxDataSource* dataSource, IVxDataInterface* dataInterface, time_t seekTime) {

    // Get Controlller
    MediaController::IController* mediaControl = GetController(dataSource, dataInterface);

#ifdef VxSdkInLinux
    mediaControl->SetWindow(nullptr);
#else
    _currentlyPlayingCam = string(dataSource->name);

    // Create Window
    HWND gstWindowHandle = ::CreateWindowA("Gstreamer", "VideoPlayer", WS_VISIBLE, 0, 0, 200, 200, NULL, NULL, NULL, NULL);
    SetWindowTextA(gstWindowHandle, _currentlyPlayingCam.c_str());

    // Set the window handle to the controller
    mediaControl->SetWindow(gstWindowHandle);
#endif

    if (seekTime == 0) {
        // Start LIVE streaming
        cout << "\nStarting Live stream.\n";
        if (!mediaControl->Play(1)) {
            cout << "\nError starting stream.";
            delete mediaControl;
            return false;
        }
    }
    else {
        // Start playback streaming
	cout << "\nStarting Playback stream.";
        if (!mediaControl->Play(1, static_cast<unsigned int>(seekTime))) {
            cout << "\nError starting stream.";
            delete mediaControl;
            return false;
        }
    }

    // Register method for time stamp events
    mediaControl->AddObserver(&DataSourceLiveStreaming::TimestampCallback);

    // Get PTZ Controller
    bool isPtz = false;
    dataSource->CanPtz(isPtz);
    bool isRecording = dataSource->isRecording;
    IVxPtzController* ptzControl = nullptr;
    if (isPtz) {
        dataSource->GetPtzController(ptzControl);
    }

    bool isLive = seekTime == 0;
    char option;
    PtzOperationsHandler ptzOperationsHandler(ptzControl);
    MediaOperationshandler mediaOperationshandler(mediaControl);
    bool isPtzCommandProcessed = true;
    do {
        if (!isPtzCommandProcessed)
            cout << "Invalid Option !!\n";

        // Display the user options while streaming
        DisplayPlayerOptionsToConsole(isPtz, isLive, isRecording);

        // Read option from user
        cin >> option;
        option = tolower(option);

        // Process PTZ Operations
        isPtzCommandProcessed = false;
        if (isPtz)
            isPtzCommandProcessed = ptzOperationsHandler.DoOperation(option);
        if (!isPtzCommandProcessed && isRecording && !isLive) {
            // Process media operations
            isPtzCommandProcessed = mediaOperationshandler.DoOperation(option);
        }
    } while (option != 'q');

    // Stop Streaming
    mediaControl->Stop();
    _currentlyPlayingCam = "";
    _gotPlayerHandle = false;

    // Release all memory created here
    if (ptzControl != nullptr)
        delete ptzControl;

    delete mediaControl;
    return true;
}

/// <summary>
/// Callback fired from MediaController class for updating the timestamp of currently playing stream
/// </summary>
/// <param name="timeEvent">Contains time info </param>
void CppSamples::LiveStreaming::DataSourceLiveStreaming::TimestampCallback(TimestampEvent* timeEvent) {
    // Convert the time to string format
    time_t timestamp = timeEvent->unixTime;
    struct tm timeinfo;
    stringstream fmt;
    localtime_s(&timeinfo, &timestamp);
    fmt << (timeinfo.tm_year + 1900) << "-"
        << setfill('0') << setw(2) << (timeinfo.tm_mon + 1) << "-"
        << setfill('0') << setw(2) << timeinfo.tm_mday << " "
        << setfill('0') << setw(2) << timeinfo.tm_hour << ":"
        << setfill('0') << setw(2) << timeinfo.tm_min << ":"
        << setfill('0') << setw(2) << timeinfo.tm_sec;

    // Normally when gstreamer player is invoked it comes with a predefined window title as given below.
    // So use that text to get the window handle.

#ifndef VxSdkInLinux
#ifndef NO_MEDIA
    if (!_gotPlayerHandle) {
        _gstreamerPlayerWindow = FindWindow(nullptr, _T("GStreamer D3D video sink (internal window)"));
        if (_gstreamerPlayerWindow != nullptr)
        {
            _gotPlayerHandle = true;
        }
    }
#endif
    // Once window handle is available, update the title text with currently streaming camera name and time.
    if (_gotPlayerHandle) {
        string textToDisplayIntitle = _currentlyPlayingCam + " (" + fmt.str() + ")";
        ::SetWindowTextA(_gstreamerPlayerWindow, textToDisplayIntitle.c_str());
    }
#endif // #ifndef VxSdkInLinux
}
