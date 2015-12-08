#include "stdafx.h"
#include "System.h"
#include "Device.h"
#include "MediaControl.h"
#include "Utils.h"
#include "Constants.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <direct.h>
#include <curl.h>
#include <fstream>
#include <Windows.h>

using namespace std;
using namespace CPPConsole::Constants;

//Make sure event is displayed if event page is currently displayed on screen.
bool gEventsPageDisplayed = false;
bool gGotPlayerHandle = false; //Set to true once GStreamer player window is available in TimeStampCallback
string gCurrentlyPlayingCam = "";
HWND gGstreamerPlayerWindow = nullptr;

#pragma region Method_Declarations
/*Main Menu Options*/
void DevicesMenu(list<CPPConsole::Device*>* devices, CPPConsole::System* sys);
void ExportsMenu(list<CPPConsole::Device*>* devices, CPPConsole::System* sys);
void EventsMenu(list<CPPConsole::Device*>* devices, CPPConsole::System* sys);

/*Devices Sub Menu Options*/
void DisplayallDevices(list<CPPConsole::Device*>* devices);
void DisplayDevicesUsingPagination(CPPConsole::System* sys);
void DisplayDeviceDetails(list<CPPConsole::Device*>* devices);
void DoLiveStreamingOption(list<CPPConsole::Device*>* devices);
void DoPlaybackOption(list<CPPConsole::Device*>* devices);

/*Exports Sub Menu Options*/
void ShowExports(CPPConsole::System* sys);
void CreateNewExportOption(list<CPPConsole::Device*>* devices, CPPConsole::System* sys);
void DeleteExport(CPPConsole::System* sys);
void DownloadExport(CPPConsole::System* sys);

/*Exports Sub Menu Options*/
void DisplayEventsPool();
void DisplaySituations(CPPConsole::System* sys);
void AddNewSituation(CPPConsole::System* sys);
void DeleteSituation(CPPConsole::System* sys);
void InjectEvents(CPPConsole::System* sys);
void SubscribeEvents(CPPConsole::System* sys);
void UnSubscribeEvents(CPPConsole::System* sys);
#pragma endregion

#pragma region Helper_Methods
/// <summary>
/// Callback method to get the download progress
/// </summary>
/// <param name="ptr">custom data assigned to curl</param>
/// <param name="totalToDownload">total data to download; not used (ptr contain actual file size)</param>
/// <param name="downloaded">total data downloaded</param>
/// <param name="totalToUpload">total data to upload; not used</param>
/// <param name="uploaded">total data uploaded; not used</param>
/// <param name="stream">file pointer to which data is being written</param>
int progress_func(void* ptr, double totalToDownload, double downloaded, double totalToUpload, double uploaded)
{
    int actualSize = *static_cast<int*>(ptr);
    CPPConsole::Utils::ShowProgress("Downloading", static_cast<int>(downloaded) / 1000, actualSize, 50);    //downloaded in bytes. So convert to Kb
    return 0;
}

/// <summary>
/// Callback method for writing export data to file
/// </summary>
/// <param name="ptr">stream data</param>
/// <param name="size">size of the data</param>
/// <param name="nmemb">count of the data</param>
/// <param name="stream">file pointer to which data is being written</param>
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

/// <summary>
/// Static helper method to perform PTZ command on currently playing stream
/// </summary>
/// <param name="keyCode">User entered keycode </param>
/// <param name="ptzControl"/> PTZ control instance</param>
static bool ProcessPTZKeyEvents(char keyCode, CPPConsole::PTZController* ptzControl) {
    bool ptzCommandProcessed = true; //This will be false for non PTZ commands
    bool ptzRes = false;
    bool showResult = true; //To make exceptional cases for presets and patterns

    //Keycode functions mentioned in CPPConsole::Utils::DisplayPlayerOptionsToConsole.
    switch (keyCode) {
    case '7':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:UpLeft.";
            ptzRes = ptzControl->ContinuousMove(-10, 10, CPPConsole::PTZController::ZoomDirection::None);
        }
        break;
    case '8':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:Up.";
            ptzRes = ptzControl->ContinuousMove(0, 10, CPPConsole::PTZController::ZoomDirection::None);
        }
        break;
    case '9':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:UpRight.";
            ptzRes = ptzControl->ContinuousMove(10, 10, CPPConsole::PTZController::ZoomDirection::None);
        }
        break;
    case '4':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:Left.";
            ptzRes = ptzControl->ContinuousMove(-10, 0, CPPConsole::PTZController::ZoomDirection::None);
        }
        break;
    case '6':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:Right.";
            ptzRes = ptzControl->ContinuousMove(10, 0, CPPConsole::PTZController::ZoomDirection::None);
        }
        break;
    case '1':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:DownLeft.";
            ptzRes = ptzControl->ContinuousMove(-10, -10, CPPConsole::PTZController::ZoomDirection::None);
        }
        break;
    case '2':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:Down.";
            ptzRes = ptzControl->ContinuousMove(0, -10, CPPConsole::PTZController::ZoomDirection::None);
        }
        break;
    case '3':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:DownRight.";
            ptzRes = ptzControl->ContinuousMove(10, -10, CPPConsole::PTZController::ZoomDirection::None);
        }
        break;
    case '+':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:ZoomIn.";
            ptzRes = ptzControl->ContinuousMove(0, 0, CPPConsole::PTZController::ZoomDirection::In);
        }
        break;
    case '-':
        if (ptzControl != nullptr) {
            cout << "\nSending PTZ Command:ZoomOut.";
            ptzRes = ptzControl->ContinuousMove(0, 0, CPPConsole::PTZController::ZoomDirection::Out);
        }
        break;
    case '0':
        if (ptzControl != nullptr) {
            cout << "\nFetching presets...";
            list<CPPConsole::Preset*>* presets = ptzControl->GetPresets();
            if (presets != nullptr && !presets->empty()) {
                int index = 0;
                int ch;
                for (list<CPPConsole::Preset*>::const_iterator presetIter = presets->begin(), end = presets->end(); presetIter != end; ++presetIter) {
                    cout << "\n  " << index + 1 << ": " << (*presetIter)->GetPresetName();
                    index++;
                }
                cout << "\nEnter the index of preset to be triggered (0 to cancel): ";
                cin >> ch;
                if (ch != 0) {
                    list<CPPConsole::Preset*>::iterator it = next(presets->begin(), ch - 1);
                    if (ptzControl->TriggerPreset((*it)))
                        cout << "\nPreset triggered succesfully..\n";
                    else
                        cout << "\nFailed to trigger preset.\n";
                }
                else {
                    cout << kCancelledMessage;
                }
            }
            else {
                cout << "\nNo presets available for this device!\n";
            }
        }
        showResult = false;
        break;
    case '.':
        if (ptzControl != nullptr) {
            cout << "\nFetching patterns...";
            list<CPPConsole::Pattern*>* patterns = ptzControl->GetPatterns();
            if (patterns != nullptr && !patterns->empty()) {
                int index = 0;
                int ch;
                for (list<CPPConsole::Pattern*>::const_iterator patternIter = patterns->begin(), end = patterns->end(); patternIter != end; ++patternIter) {
                    cout << "\n  " << index + 1 << ": " << (*patternIter)->GetPatternName();
                    index++;
                }
                cout << "\nEnter the index of pattern to be triggered (0 to cancel): ";
                cin >> ch;
                if (ch != 0) {
                    list<CPPConsole::Pattern*>::iterator it = next(patterns->begin(), ch - 1);
                    if (ptzControl->TriggerPattern((*it)))
                        cout << "\nPattern triggered succesfully..\n";
                    else
                        cout << "\nFailed to trigger pattern.\n";
                }
                else {
                    cout << kCancelledMessage;
                }
            }
            else {
                cout << "\nNo patterns available for this device!\n";
            }
        }
        showResult = false;
        break;
    default:
        ptzCommandProcessed = false; //Not received a PTZ command keycode
        break;
    }
    if (ptzCommandProcessed && showResult) {
        if (ptzRes)
            cout << "\nPTZ command sent succefully.\n ";
        else {
            cout << "\nPTZ command failed!!\n";
        }
    }
    return ptzCommandProcessed;
}

/// <summary>
/// Callback fired from MediaController class for updating the timestamp of currently playing stream
/// </summary>
/// <param name="timeEvent">Contains time info </param>
void TimestampCallback(MediaController::TimestampEvent* timeEvent) {
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

    //Normally when gstreamer player is invoked it comes with a predefined window title as given below.
    //So use that text to get the window handle.
    if (!gGotPlayerHandle) {
        gGstreamerPlayerWindow = FindWindow(nullptr, _T("GStreamer D3D video sink (internal window)"));
        if (gGstreamerPlayerWindow != nullptr)
        {
            gGotPlayerHandle = true;
        }
    }
    //Once window handle is available, update the title text with currently streaming camera name and time.
    if (gGotPlayerHandle) {
        string textToDisplayIntitle = gCurrentlyPlayingCam + " (" + fmt.str() + ")";
        ::SetWindowTextA(gGstreamerPlayerWindow, textToDisplayIntitle.c_str());
    }
    
    //Delet event data once done
    delete timeEvent;
}

/// <summary>
/// Method for displaying details of given device on console
/// </summary>
/// <param name="device">device pointer</param>
void ShowDeviceDetails(CPPConsole::Device* device) {

    cout << "\n  Device Details: " << "\n";
    CPPConsole::Utils::DrawLine();
    cout << kNameMessage << device->GetDeviceName();
    cout << "\n  ID: " << device->GetDeviceId();
    cout << "\n  IP: " << device->GetDeviceIp();
    cout << "\n  Model: " << device->GetDeviceModel();
    cout << "\n  Vendor: " << device->GetVendor();
    cout << "\n  Type: " << device->GetDeviceTypeInString();
    string isOnline = "No";
    if (device->IsOnline()) isOnline = "Yes";
    cout << "\n  Online: " << isOnline;
    cout << "\n  Datasources:" << device->GetDatasources()->size() << "\n";
    CPPConsole::Utils::DrawLine();
    cout << "\n";
}

/// <summary>
/// Method for displaying export details on console
/// </summary>
/// <param name="exportToDisplay">export pointer</param>
void ShowExportDetails(CPPConsole::Export* exportToDisplay) {
    cout << "\n  Export you selected: " << "\n";
    CPPConsole::Utils::DrawLine();
    cout << kNameMessage << exportToDisplay->GetExportName();
    cout << "\n  Size (In Kb): " << exportToDisplay->GetFileSizeinKb();
    cout << "\n  Status: " << exportToDisplay->GetExportStatusInString(false);
    cout << "\n  Format: " << exportToDisplay->GetExportFormatInString() << "\n";
    CPPConsole::Utils::DrawLine();
}

/// <summary>
/// Initiate streaming for selected datasource.
/// This method checks the parameter isMjpegEnabled to determine whether streaming is RTSP or MJPEG
/// Also, it will automatically invoke playback method, if seekTime is given a value; otherwise live streaming will be invoked
/// </summary>
/// <param name="dataSourceToPlay">Selected datasource</param>
/// <param name="isMjpegEnabled">true if Mjpeg streaming to be started</param>
/// <param name="seekTime">nullptr for live; otherwise pass time in "yyyymmddThhmmssZ-" format</param>
void StartStreamingForDataSource(CPPConsole::DataSource* dataSourceToPlay, bool isMjpegEnabled, time_t seekTime) {
    CPPConsole::PTZController* ptzControl = nullptr; //Only if datasource supports PTZ, this will get instantiated

    cout << "Invoking MediaController..\n";
    CPPConsole::MediaControl *mediaControl = new CPPConsole::MediaControl(dataSourceToPlay);

    HWND gstWindowHandle = ::CreateWindowA("Gstreamer", "VideoPlayer", WS_VISIBLE, 0, 0, 600, 600, NULL, NULL, NULL, NULL);
    ::SetWindowTextA(gstWindowHandle, "GStreamer Player");

    mediaControl->SetVideoWindow(gstWindowHandle);
    if (seekTime == 0)
        mediaControl->Play(1);
    else
        mediaControl->Seek(static_cast<unsigned int>(seekTime), 1);
    mediaControl->SetTimestampCallback(TimestampCallback);

    gCurrentlyPlayingCam = string(dataSourceToPlay->GetDataSourceName());

    if (dataSourceToPlay->IsPTZ()) {
        ptzControl = dataSourceToPlay->GetPtzController();
        CPPConsole::Utils::DisplayPlayerOptionsToConsole(true, (seekTime == 0));
    }
    else {
        CPPConsole::Utils::DisplayPlayerOptionsToConsole(false, (seekTime == 0));
    }

    bool isPtzCommandProcessed = false;

    char option;

    do{
        cin >> option;
        
        if (ptzControl != nullptr) {
            isPtzCommandProcessed = ProcessPTZKeyEvents(tolower(option), ptzControl);
        }

        if (!isPtzCommandProcessed) {
            switch (tolower(option)) {
                case 'p':{
                    if (mediaControl->IsPlaying()) {
                        cout << "\nPausing the stream.\n";
                        mediaControl->Pause();
                    }
                    else {
                        cout << "\nResuming the stream.\n";
                        mediaControl->Play(mediaControl->GetCurrentSpeed());
                    }

                    break;
                }
                case 'z':{
                    if (seekTime == 0) break; //For live streaming speed is not required

                    mediaControl->Play(mediaControl->GetCurrentSpeed() + 2);
                    break;
                }
                case 'x':{
                    if (seekTime == 0) break; //For live streaming speed is not required

                    mediaControl->Play(mediaControl->GetCurrentSpeed() - 2);
                    break;
                }
                case 'l':{
                    if (seekTime == 0) break;

                    mediaControl->GoToLive();
                    break;
                }
                default:
                    break;
            }
        }

    } while (tolower(option) != 'q');

    gCurrentlyPlayingCam = "";
    gGotPlayerHandle = false;

    if (ptzControl != nullptr) {
        delete ptzControl;
    }
    delete mediaControl;
}

/// <summary>
/// Fetch and display clips available for selected datasource
/// This method is used when we need to know what all clips are available for export
/// </summary>
/// <param name="dataSource">dataSource pointer</param>
bool ShowAvailableClips(CPPConsole::DataSource* dataSource) {
    bool clipsAvailable = false;
    cout << "Searching for available clips..Please wait..\n";

    list<CPPConsole::DataInterface*>* dataInterfaces = dataSource->GetDataInterfaces();

    for (list<CPPConsole::DataInterface*>::const_iterator dataInterfaceIter =
        dataInterfaces->begin(), end = dataInterfaces->end(); dataInterfaceIter != end; ++dataInterfaceIter) {

        if ((*dataInterfaceIter)->GetProtocol() == CPPConsole::DataInterface::StreamProtocol::kStreamProtocolRtspRtp) {
            if (dataSource->GetClips()->size() > 0) {
                clipsAvailable = true;
                cout << "Total Number of clips available: " << dataSource->GetClips()->size() << "\n";
                int index = 0;
                list<CPPConsole::Clip*>* availableClips = dataSource->GetClips();
                for (list<CPPConsole::Clip*>::const_iterator clipIter = availableClips->begin(),
                    availEnd = availableClips->end(); clipIter != availEnd; ++clipIter) {
                    index += 1;
                    cout << index << ". " << (*clipIter)->GetStartTime() <<
                        "---" << (*clipIter)->GetEndTime() << "\n";
                }
            }
            break;
        }
    }
    return clipsAvailable;
}

/// <summary>
/// Display export lists (Name and status)
/// </summary>
/// <param name="exports">Exports list</param>
void DisplayExportDetailsOnScreen(list<CPPConsole::Export*>* exports) {
    if (exports != nullptr && !exports->empty()) {
        cout << exports->size() << " exports found.\n";

        cout << "\n\n";
        cout << setfill(' ') << kIndexHeader << setw(50) << left << "NAME" << setw(15) << "  STATUS" << "\n";
        CPPConsole::Utils::DrawLine();

        int index = 0;
        for (list<CPPConsole::Export*>::const_iterator iterator = exports->begin(), end = exports->end(); iterator != end; ++iterator) {
            CPPConsole::Export::ExportStatus expStatus = (*iterator)->GetExportStatus();
            string expStatusInString = "U";
            if (expStatus == CPPConsole::Export::ExportStatus::Exporting) {
                expStatusInString = "E";
            }
            else if (expStatus == CPPConsole::Export::ExportStatus::Successful) {
                expStatusInString = "S";
            }
            else if (expStatus == CPPConsole::Export::ExportStatus::Failed) {
                expStatusInString = "F";
            }
            else if (expStatus == CPPConsole::Export::ExportStatus::Pending) {
                expStatusInString = "P";
            }

            cout << setfill(' ') << "\n" << "    " << index + 1 << "    " << left << setw(50) <<
                (*iterator)->GetExportName() << "    " << setw(15) << expStatusInString;
            index++;
        }
        cout << "\n";
        CPPConsole::Utils::DrawLine();

        cout << "\n  Status: E-Exporting  S-Successful  F-Failed  P-Pending  U-Unknown\n";
        CPPConsole::Utils::DrawLine();
        cout << "\n";
    }
    else {
        cout << "No exports found!!\n";
    }
}

/// <summary>
/// Callback method to handle events received from VxSDK
/// Events will be written to a txt file
/// </summary>
/// <param name="ev">IVxEvent pointer containing newly received event details</param>
void EventsCallBack(VxSdk::IVxEvent* ev) {
    //Only log acknowledgement needed events. Skip others
    if (ev->ackState == VxSdk::VxAckState::kAckNeeded) {
        ofstream fStream(CPPConsole::Utils::GetEventLogFilePath(), ios_base::app | ios_base::out);

        if (fStream)
        {
            fStream << ev->generatorDeviceId << ";" <<
                ev->time << ";" <<
                ev->situationType << ";" <<
                ev->severity << ";" <<
                ev->sourceDeviceId << ";" <<
                ev->sourceUserName << ";" << endl;
            fStream.close();
        }

        if (gEventsPageDisplayed) { //If View Events page is currently displayed on screen, then refresh the screen
            DisplayEventsPool();
        }
    }

}
#pragma endregion

#pragma region Main
/// <summary>
/// Entry point to program
/// Connect to system defined in Constants.h, Fetch devices and show menu to User
/// </summary>
/// <param name="argc">default argument; not used</param>
/// <param name="argv[]">default argument; not used</param>
int main(int argc, char* argv[]) {
    cout << "VxSDK C++ console application - Started.\n\n";
    //Create an instance of wrapper class, all the SDK methods will be called with the help of wrapper classes
    CPPConsole::System* sys = new CPPConsole::System();
    cout << "Connecting to system " << kSysIp << "...\n";
    bool loggedIn = sys->Login(kSysIp, kPortnum, kUserName, kPassword);
    if (!loggedIn) {
        cout << "Failed to login!!\n";
    }
    else {
        cout << "Logged into system:" << kSysIp << " as " << kUserName << "\n";
        cout << "Fetching devices from system, Please wait...\n";
        list<CPPConsole::Device*>* devices = sys->GetDevices();
        cout << devices->size() << " devices found.\n";

        int option;

        do{ //Showing Main menu. Refer CPPConsole::Utils::GetMainMenuChoiceFromUser for details
            system("cls");
            CPPConsole::Utils::DrawLine();
            cout << "\n  CONNECTED TO:" << kSysIp;
            cout << "\n  TOTAL DEVICES FOUND:" << devices->size() << "\n";
            CPPConsole::Utils::DrawLine();
            option = CPPConsole::Utils::GetMainMenuChoiceFromUser();

            switch (option) {
                case 1:{
                        // Dsiplay submenu related with devices (Show details, streaming)
                        DevicesMenu(devices, sys);
                        break;
                }
                case 2:{
                        // Dsiplay submenu related with exports (View,create,delete,download)
                        ExportsMenu(devices, sys);
                        break;
                }
                case 3:{
                        // Dsiplay submenu related with events (View/Inject/Subscribe/Unsubscribe events,
                        // View/Add/Delete situations)
                        EventsMenu(devices, sys);
                        break;
                }
                case 4:{
                        break;
                }
                default:{
                        cout << "\n Invalid Option!!";
                        break;
                }
            }

        } while (option != 4);
    }
    cout << "VxSDK C++ console application - Shutting down.\n";
    system(kPauseCommand);
    delete sys;    //cleanup system instance.
    return 0;
}
#pragma endregion

#pragma region MainMenu
/// <summary>
/// Devices sub menu option
/// Show options to display all devices, live/playback streaming
/// </summary>
/// <param name="devices">collected devices</param>
/// <param name="sys">System pointer</param>
void DevicesMenu(list<CPPConsole::Device*>* devices, CPPConsole::System* sys) {
    int choice;
    do{
        choice = CPPConsole::Utils::GetDevicesSubMenuChoiceFromUser();
        if (choice == 1) { //View all devices
            DisplayallDevices(devices);
            system(kPauseCommand);
        }
        else if (choice == 2) { // View devices page by page
            DisplayDevicesUsingPagination(sys);
            system(kPauseCommand);
        }
        else if (choice == 3) { // Get the details of a particular device
            DisplayDeviceDetails(devices);
            system(kPauseCommand);
        }
        else if (choice == 4) { //Start live streaming
            DoLiveStreamingOption(devices);
            system(kPauseCommand);
        }
        else if (choice == 5) { //Perform playback
            DoPlaybackOption(devices);
            system(kPauseCommand);
        }
    } while (choice != 6);
}

/// <summary>
/// Exports sub menu option
/// Show options to display all exports, create/delete/download an export
/// </summary>
/// <param name="devices">collected devices</param>
/// <param name="sys">System pointer</param>
void ExportsMenu(list<CPPConsole::Device*>* devices, CPPConsole::System* sys) {
    int choice;
    do {
        choice = CPPConsole::Utils::GetExportSubMenuChoiceFromUser();
        if (choice == 1) { //View Exports
            ShowExports(sys);
            system(kPauseCommand);
        }
        else if (choice == 2) { //Create new export
            CreateNewExportOption(devices, sys);
            system(kPauseCommand);
        }
        else if (choice == 3) { //Delete an existing export
            DeleteExport(sys);
            system(kPauseCommand);
        }
        else if (choice == 4) { //Download an export
            DownloadExport(sys);
            system(kPauseCommand);
        }
    } while (choice != 5);
}

/// <summary>
/// Events sub menu option
/// Show options to display/inject/subscribe/unsubscribe events, view/add/delete situation
/// </summary>
/// <param name="devices">collected devices</param>
/// <param name="sys">System pointer</param>
void EventsMenu(list<CPPConsole::Device*>* devices, CPPConsole::System* sys) {
    int choice;
    do {
        choice = CPPConsole::Utils::GetEventsSubMenuChoiceFromUser();
        
        if (choice == 1) { //View all events
            DisplayEventsPool();
            gEventsPageDisplayed = true;
            system(kPauseCommand);
            gEventsPageDisplayed = false;
        }
        else if (choice == 2) { //View all situations
            DisplaySituations(sys);
            system(kPauseCommand);
        }
        else if (choice == 3) { //Add New Situation
            AddNewSituation(sys);
            system(kPauseCommand);
        }
        else if (choice == 4) { //Delete situation
            DeleteSituation(sys);
            system(kPauseCommand);
        }
        else if (choice == 5) { //Inject Events
            InjectEvents(sys);
            system(kPauseCommand);
        }
        else if (choice == 6) { //Subscribe events
            SubscribeEvents(sys);
            system(kPauseCommand);
        }
        else if (choice == 7) { //UnSubscribe to event
            UnSubscribeEvents(sys);
            system(kPauseCommand);
        }

    } while (choice != 8);
}
#pragma endregion

#pragma region Devices_SubMenu
/// <summary>
/// Display a page of details for devices
/// </summary>
/// <param name="devices">collected devices</param>
void PrintPage(list<CPPConsole::Device*>* devices) {
    int index = 0;
    for (list<CPPConsole::Device*>::const_iterator iterator = devices->begin(), end = devices->end(); iterator != end; ++iterator) {
        //if-else doesn't contain any difference other than adding padding based on two digit/three difit index
        if (index + 1 < 10)
            cout << setfill(' ') << "\n" << "    " << index + 1 << "    " << left << setw(50) <<
            (*iterator)->GetDeviceName() << "    " << setw(20) << (*iterator)->GetDeviceIp();
        else if (index + 1 < 100)
            cout << setfill(' ') << "\n" << "    " << index + 1 << "   " << left << setw(50) <<
            (*iterator)->GetDeviceName() << "    " << setw(20) << (*iterator)->GetDeviceIp();
        else
            cout << setfill(' ') << "\n" << "    " << index + 1 << "  " << left << setw(50) <<
            (*iterator)->GetDeviceName() << "    " << setw(20) << (*iterator)->GetDeviceIp();

        index++;
    }
    cout << "\n";
    CPPConsole::Utils::DrawLine();
}

/// <summary>
/// Display details of devices available in system
/// </summary>
/// <param name="devices">collected devices</param>
void DisplayallDevices(list<CPPConsole::Device*>* devices) {
    system("cls");

    cout << "\n\n";
    cout << setfill(' ') << kIndexHeader << setw(50) << left << kNameHeader << setw(20) << kIpHeader << "\n";
    CPPConsole::Utils::DrawLine();
    PrintPage(devices);
    cout << "\n";
}

/// <summary>
/// Display device with paging
/// </summary>
/// <param name="sys">system pointer</param>
void DisplayDevicesUsingPagination(CPPConsole::System* sys) {
    int startIndex = 0;
    int numberOfItemsPerPage = 20;
    int totalNumberOfItems = 0;
    cout << "\n  Enter number of items per page: ";
    cin >> numberOfItemsPerPage;

    system("cls");
    cout << "Fetching first " << numberOfItemsPerPage << " devices..";
    cout << "\n\n";

    list<CPPConsole::Device*>* devices = sys->GetDevices(startIndex, numberOfItemsPerPage, totalNumberOfItems);

    cout << setfill(' ') << kIndexHeader << setw(50) << left << "NAME  " << setw(20) << "    IP" << "\n";
    CPPConsole::Utils::DrawLine();
    
    int totalIteration = (totalNumberOfItems + numberOfItemsPerPage - 1) / numberOfItemsPerPage;
    cin.ignore();
    for (int i = 0; i < totalIteration; i++) {
        if (devices != nullptr)
            delete devices;

        devices = sys->GetDevices(startIndex, numberOfItemsPerPage, totalNumberOfItems);
        PrintPage(devices);
        if ((startIndex + numberOfItemsPerPage) > totalNumberOfItems) { //Last page
            cout << kShowingMessage << totalNumberOfItems << kOutOfMessage << totalNumberOfItems;
            break;
        }

        cout << kShowingMessage << startIndex + numberOfItemsPerPage << kOutOfMessage << totalNumberOfItems;
        cout << "\n\n  Press q to quit or any other key to continue fetching next page...";
        string a;
        getline(cin, a);

        if (a == "q" || a == "Q") {
            break;
        }
        startIndex += numberOfItemsPerPage;
    }
    cout << "\n";
}

/// <summary>
/// Get the device index for displaying its details
/// </summary>
/// <param name="devices">collected devices</param>
void DisplayDeviceDetails(list<CPPConsole::Device*>* devices) {
    int devIndex;
    cout << kEnterDeviceIndexMessage;
    cin >> devIndex;

    list<CPPConsole::Device*>::iterator it = next(devices->begin(), devIndex - 1);
    ShowDeviceDetails((*it));
}

/// <summary>
/// Get the device index for performing live streaming
/// </summary>
/// <param name="devices">collected devices</param>
void DoLiveStreamingOption(list<CPPConsole::Device*>* devices) {
    int camNum;
    cout << kEnterCameraIndexMessage;
    cin >> camNum;

    list<CPPConsole::Device*>::iterator it = next(devices->begin(), camNum - 1);
    if ((*it)->GetDeviceType() != CPPConsole::Device::DeviceType::Camera) {
        cout << "\n  Device you selected is not a camera!!\n";
        return;
    }
    bool isMjpegEnabled = false;
    string mJPEGOption = "N";
    cout << "\n  Do you want to play MJPEG (Y/N) [Default is RTSP]: ";
    cin >> mJPEGOption;
    if (mJPEGOption == "Y" || mJPEGOption == "y") { isMjpegEnabled = true; }

    ShowDeviceDetails((*it));
    list<CPPConsole::DataSource*>* dataSources = (*it)->GetDatasources();

    CPPConsole::DataSource* dataSourceSelectedForStreaming = nullptr;

    for (list<CPPConsole::DataSource*>::const_iterator iterator = dataSources->begin(), end = dataSources->end(); iterator != end; ++iterator) {
        list<CPPConsole::DataInterface*>* dataInterfaces = (*iterator)->GetDataInterfaces();

        for (list<CPPConsole::DataInterface*>::const_iterator dataInterfaceIter = dataInterfaces->begin(), e = dataInterfaces->end();
            dataInterfaceIter != e; ++dataInterfaceIter) {
            if (isMjpegEnabled) {
                if ((*dataInterfaceIter)->GetProtocol() == CPPConsole::DataInterface::StreamProtocol::kStreamProtocolMjpegPull) {
                    dataSourceSelectedForStreaming = (*iterator);
                    break;
                }
            }
            else {
                if ((*dataInterfaceIter)->GetProtocol() == CPPConsole::DataInterface::StreamProtocol::kStreamProtocolRtspRtp) {
                    dataSourceSelectedForStreaming = (*iterator);
                    break;
                }
            }
        }
    }
    if (dataSourceSelectedForStreaming != nullptr) {
        StartStreamingForDataSource(dataSourceSelectedForStreaming, isMjpegEnabled, 0);
    }
}

/// <summary>
/// Get the device index for performing playback
/// </summary>
/// <param name="devices">collected devices</param>
void DoPlaybackOption(list<CPPConsole::Device*>* devices) {
    int camNum;
    cout << kEnterCameraIndexMessage;
    cin >> camNum;

    list<CPPConsole::Device*>::iterator it = next(devices->begin(), camNum - 1);
    cout << "\n  Camera selected for playback is:" << (*it)->GetDeviceName() << "\n";

    cin.ignore();
    cout << "\n\n  Input date and time to start playback(yyyy-mm-dd hh:mm:ss)";
    struct tm playBackTime = CPPConsole::Utils::GetDateAndTimeFromUser();

    time_t timeSinceEpoch = mktime(&playBackTime);

    list<CPPConsole::DataSource*>* dataSources = (*it)->GetDatasources();

    CPPConsole::DataSource* dataSourceSelectedForStreaming = nullptr;

    for (list<CPPConsole::DataSource*>::const_iterator iterator = dataSources->begin(), end = dataSources->end(); iterator != end; ++iterator) {
        list<CPPConsole::DataInterface*>* dataInterfaces = (*iterator)->GetDataInterfaces();

        for (list<CPPConsole::DataInterface*>::const_iterator dataInterfaceIter = dataInterfaces->begin(), e = dataInterfaces->end();
            dataInterfaceIter != e; ++dataInterfaceIter) {
            if ((*dataInterfaceIter)->GetProtocol() == CPPConsole::DataInterface::StreamProtocol::kStreamProtocolRtspRtp) {
                dataSourceSelectedForStreaming = (*iterator);
                break;
            }
        }
    }
    if (dataSourceSelectedForStreaming != nullptr) {
        StartStreamingForDataSource(dataSourceSelectedForStreaming, false, timeSinceEpoch);
    }
}
#pragma endregion

#pragma region Exports_SubMenu
/// <summary>
/// Fetch and display available exports
/// </summary>
/// <param name="sys">system pointer</param>
void ShowExports(CPPConsole::System* sys) {
    system("cls");
    cout << kFetchingExportMessage;
    list<CPPConsole::Export*>* exports = sys->GetExports();
    DisplayExportDetailsOnScreen(exports);

    //Cleanup exports array
    if (exports != nullptr) {
        for (list<CPPConsole::Export*>::const_iterator iterator = exports->begin(), end = exports->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete exports;
    }
}

/// <summary>
/// Collect details from user and create new export
/// </summary>
/// <param name="devices">collected devices</param>
/// <param name="sys">system pointer</param>
void CreateNewExportOption(list<CPPConsole::Device*>* devices, CPPConsole::System* sys) {
    int camNum;
    cout << kEnterCameraIndexMessage;
    cin >> camNum;

    list<CPPConsole::Device*>::iterator it = next(devices->begin(), camNum - 1);
    cout << "\n  Camera selected for export is:" << (*it)->GetDeviceName() << "\n";

    list<CPPConsole::DataSource*>* dataSources = (*it)->GetDatasources();

    string exportName;
    string exportPasswd;
    int fileFormatOption = 1;

    for (list<CPPConsole::DataSource*>::const_iterator iterator = dataSources->begin(), end = dataSources->end(); iterator != end; ++iterator) {
        if (ShowAvailableClips(*iterator)) {
            cin.ignore();
            cout << "\n  Input start time for export clip(yyyy-mm-dd hh:mm:ss): ";
            struct tm strtTime = CPPConsole::Utils::GetDateAndTimeFromUser();
            string startTimeInUTC = CPPConsole::Utils::ConvertLocalTimetoUTC(strtTime);

            cout << "\n  Input end time for export clip(yyyy-mm-dd hh:mm:ss): ";
            struct tm endtme = CPPConsole::Utils::GetDateAndTimeFromUser();
            string endTimeInUTC = CPPConsole::Utils::ConvertLocalTimetoUTC(endtme);

            cout << "\n  Enter name for your export: ";
            cin >> exportName;

            cout << "\n  Enter password for your export: ";
            cin >> exportPasswd;

            cout << "\n\t1.MkvZip\n";
            cout << "\t2.Mp4\n";
            cout << "\n  Chose a file format for your export from above options: ";
            cin >> fileFormatOption;
            

            CPPConsole::NewExportClip* exportClip = new CPPConsole::NewExportClip();
            exportClip->SetDataSourceId((*iterator)->GetDataSourceId());
            exportClip->SetStartTime(startTimeInUTC.c_str());
            exportClip->SetEndTime(endTimeInUTC.c_str());

            CPPConsole::NewExport* newExport = new CPPConsole::NewExport();
            newExport->AddClip(exportClip);
            newExport->SetExportName(exportName.c_str());
            newExport->SetExportPassword(exportPasswd.c_str());

            if (fileFormatOption == 1) {
                newExport->SetExportFormat(CPPConsole::Export::ExportFormat::MkvZip);
            }
            if (fileFormatOption == 2) {
                newExport->SetExportFormat(CPPConsole::Export::ExportFormat::Mp4);
            }

            CPPConsole::Export* exp = sys->CreateExport(newExport);

            if (exp != nullptr) {
                do {
                    CPPConsole::Export* newExp = sys->GetExportDetails(exp->GetExportName(), exp->GetExportId());

                    if (newExp->GetExportStatus() == CPPConsole::Export::ExportStatus::Failed) {
                        cout << "\n  Export failed!!\n";
                        break;
                    }
                    if (newExp->GetExportStatus() == CPPConsole::Export::ExportStatus::Successful) {
                        CPPConsole::Utils::ShowProgress(kExportingMessage, 100, 100, 50);
                        cout << "\n  Export successfully created..\n";
                        break;
                    }
                    if (newExp->GetExportStatus() == CPPConsole::Export::ExportStatus::Exporting) {
                        CPPConsole::Utils::ShowProgress(kExportingMessage, static_cast<int>(exp->GetPercentComplete()), 100, 50);
                    }
                    else if (newExp->GetExportStatus() == CPPConsole::Export::ExportStatus::Pending) {
                        CPPConsole::Utils::ShowProgress("Pending", static_cast<int>(exp->GetPercentComplete()), 100, 50);
                    }

                    delete newExp;
                    Sleep(1000);
                } while (true);

                delete exp;
            }
            else {
                cout << "\n  Failed to export!!.\n";
            }
            delete exportClip;
            delete newExport;

            break;
        }
        cout << "  No clips available for selected camera!!\n";
    }
}

/// <summary>
/// Get the export details to delete from server
/// </summary>
/// <param name="sys">system pointer</param>
void DeleteExport(CPPConsole::System* sys) {
    system("cls");
    cout << kFetchingExportMessage;
    list<CPPConsole::Export*>* exports = sys->GetExports();
    DisplayExportDetailsOnScreen(exports);

    if (exports != nullptr && !exports->empty()) {
        int exportIndex;
        cout << "\n  Enter index of export to delete: ";
        cin >> exportIndex;

        list<CPPConsole::Export*>::iterator it = next(exports->begin(), exportIndex - 1);
        cout << "\n  Export you selected for delete: " << (*it)->GetExportName();

        if (sys->DeleteExport(*it)) {
            cout << "\n  Export deleted succesfully.\n";
        }
        else {
            cout << "\n  Failed to delete export!!\n";
        }

        //Cleanup exports array
        if (exports != nullptr) {
            for (list<CPPConsole::Export*>::const_iterator iterator = exports->begin(), end = exports->end(); iterator != end; ++iterator) {
                delete *iterator;
            }
            delete exports;
        }
    }
}

/// <summary>
/// Get the export details to download from server
/// </summary>
/// <param name="sys">system pointer</param>
void DownloadExport(CPPConsole::System* sys) {
    system("cls");
    cout << kFetchingExportMessage;
    list<CPPConsole::Export*>* exports = sys->GetExports();
    DisplayExportDetailsOnScreen(exports);

    if (exports != nullptr && !exports->empty()) {
        int exportIndex;
        cout << "\n  Enter index of export to download: ";
        cin >> exportIndex;

        list<CPPConsole::Export*>::iterator it = next(exports->begin(), exportIndex - 1);
        ShowExportDetails((*it));

        string pathToSave = "";
        string fileToSave = "";
        string fullPath;

        cout << "\n  Enter path to save export file(eg: C:\\ExportFolder): ";
        cin >> pathToSave;

        cout << "\n  Enter name to save export file: ";
        cin >> fileToSave;

        if ((*it)->GetExportFormat() == CPPConsole::Export::ExportFormat::Mp4) {
            fullPath = pathToSave + "\\" + fileToSave + ".mp4";
        }
        else {
            fullPath = pathToSave + "\\" + fileToSave + ".zip";
        }
        _mkdir(pathToSave.c_str());

        CURL *curl;
        FILE *fp;
        int actualFileSize = (*it)->GetFileSizeinKb();

        curl = curl_easy_init();

        if (curl) {
            fopen_s(&fp, fullPath.c_str(), "wb");

            struct curl_slist *headers = nullptr;

            string userNameHeader = "X-Serenity-User: " + CPPConsole::Utils::Encode(kUserName);
            string passwordHeader = "X-Serenity-Password: " + CPPConsole::Utils::Encode(kPassword);

            headers = curl_slist_append(headers, userNameHeader.c_str());
            headers = curl_slist_append(headers, passwordHeader.c_str());

            curl_easy_setopt(curl, CURLOPT_URL, (*it)->GetExportDataUri());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);
            curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_func);
            curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &actualFileSize);

            cout << "\n  Exporting to " << fullPath << "\n\n";

            curl_easy_perform(curl);
            /* always cleanup */
            curl_easy_cleanup(curl);
            fclose(fp);
            cout << "\n\n";
        }

        //Cleanup exports array
        if (exports != nullptr) {
            for (list<CPPConsole::Export*>::const_iterator iterator = exports->begin(), end = exports->end(); iterator != end; ++iterator) {
                delete *iterator;
            }
            delete exports;
        }
    }
}
#pragma endregion

#pragma region Events_SubMenu
/// <summary>
/// Method for displaying events details in screen
/// Events available in text file will be parsed and displayed on screen
/// </summary>
void DisplayEventsPool() {
    system("cls");
    cout << "  Events extracted from " << CPPConsole::Utils::GetEventLogFilePath() << "\n\n";
    CPPConsole::Utils::DrawLine();
    cout << "\n";
    const int nameWidth = 24;
    const int numWidth = 20;
    cout << left << setw(nameWidth) << setfill(' ') << "Type";
    cout << left << setw(numWidth) << setfill(' ') << "Time(UTC)";
    cout << left << setw(15) << setfill(' ') << "Severity";
    cout << left << setw(nameWidth) << setfill(' ') << "Source User" << "\n";
    CPPConsole::Utils::DrawLine();

    ifstream infile(CPPConsole::Utils::GetEventLogFilePath());
    if (infile)
    {
        while (infile)
        {
            string s;
            if (!getline(infile, s)) break;

            istringstream ss(s);
            vector <string> record;

            while (ss)
            {
                string str;
                if (!getline(ss, str, ';')) break;
                record.push_back(str);
            }

            cout << left << setw(nameWidth) << setfill(' ') << record[2];
            cout << left << setw(numWidth) << setfill(' ') << CPPConsole::Utils::CovertUTCTimeFormatToString(record[1]);
            cout << left << setw(15) << setfill(' ') << record[3];
            cout << left << setw(nameWidth) << setfill(' ') << record[5];

            cout << "\n";
        }
        CPPConsole::Utils::DrawLine();
    }
    cout << "\n";
}

/// <summary>
/// Method for displaying situation details
/// </summary>
/// <param name="situations">Situations list to iterate</param>
void DisplaySituationDetailsOnScreen(list<CPPConsole::Situation*>* situations) {
    if (situations != nullptr && !situations->empty()) {
        cout << situations->size() << " situations found.\n";

        cout << "\n\n";
        cout << setfill(' ') << kIndexHeader << setw(60) << left << "  TYPE" << "\n";
        CPPConsole::Utils::DrawLine();

        int index = 0;
        for (list<CPPConsole::Situation*>::const_iterator iterator = situations->begin(), end = situations->end(); iterator != end; ++iterator) {
            cout << setfill(' ') << "\n" << "    " << index + 1 << "    " << left << setw(60) << left << (*iterator)->GetSituationType();
            index++;
        }
        cout << "\n";
        CPPConsole::Utils::DrawLine();
    }
    else {
        cout << "No situations found!!\n";
    }
    cout << "\n";
}

/// <summary>
/// Menu function for displaying situations available in a system
/// </summary>
/// <param name="sys">system pointer</param>
void DisplaySituations(CPPConsole::System* sys) {
    system("cls");
    cout << kFetchingMessage;
    list<CPPConsole::Situation*>* situations = sys->GetSituations();
    DisplaySituationDetailsOnScreen(situations);

    //Cleanup situations array
    if (situations != nullptr) {
        for (list<CPPConsole::Situation*>::const_iterator iterator = situations->begin(), end = situations->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        delete situations;
    }
}

/// <summary>
/// Menu function for adding new situation to server
/// </summary>
/// <param name="sys">system pointer</param>
void AddNewSituation(CPPConsole::System* sys) {
    string sitName = "";
    string sitType = "";

    cout << "\n\n  Enter name for situation: ";
    cin >> sitName;

    cout << "\n  Enter type for situation (in format: 'external/{company_name}/{situation_type}'): ";
    cin >> sitType;

    if (sys->AddNewSituation(sitName.c_str(), sitType.c_str()))
        cout << "\n  Situation added succesfully.\n";
    else
        cout << "\n  Failed to add situation.\n";
}

/// <summary>
/// Menu function for deleting situation from server
/// </summary>
/// <param name="sys">system pointer</param>
void DeleteSituation(CPPConsole::System* sys) {
    system("cls");
    cout << kFetchingMessage;
    list<CPPConsole::Situation*>* situations = sys->GetSituations();
    DisplaySituationDetailsOnScreen(situations);

    int situationToDelete = -1;
    cout << "\n  Enter the index of situation to delete: ";
    cin >> situationToDelete;

    list<CPPConsole::Situation*>::iterator it = next(situations->begin(), situationToDelete - 1);
    cout << "\n  Situation selected for delete is:" << (*it)->GetSituationType() << "\n";

    bool result = sys->DeleteSituation((*it));
    if (result) {
        cout << "\n  Situation deleted succesfully.\n";
    }
    else {
        cout << "\n  Failed to delete situation.\n";
    }

    if (situations != nullptr) {
        for (list<CPPConsole::Situation*>::const_iterator iterator = situations->begin(), end = situations->end(); iterator != end; ++iterator) {
            delete *iterator;
        }
        situations->clear();
    }
}

/// <summary>
/// Menu function for injecting events to server
/// </summary>
/// <param name="sys">system pointer</param>
void InjectEvents(CPPConsole::System* sys) {
    system("cls");
    cout << kFetchingMessage;
    list<CPPConsole::Situation*>* situations = sys->GetSituations();
    DisplaySituationDetailsOnScreen(situations);

    int sitnId = -1;
    string generatorDeviceId = "";
    string sourceDeviceId = "";

    cout << "\n\n  Enter the id of the situation to be associated with the event: ";
    cin >> sitnId;

    list<CPPConsole::Situation*>::iterator it = next(situations->begin(), sitnId - 1);

    cout << "\n  Enter generator device id: ";
    cin >> generatorDeviceId;

    cout << "\n  Enter source device id: ";
    cin >> sourceDeviceId;

    cin.ignore();
    cout << "\n  Enter event time(yyyy-mm-dd hh:mm:ss): ";
    struct tm strtTime = CPPConsole::Utils::GetDateAndTimeFromUser();
    string startTimeInUTC = CPPConsole::Utils::ConvertLocalTimetoUTC(strtTime);

    if (sys->InjectNewEvent((*it), generatorDeviceId, sourceDeviceId, startTimeInUTC)) {
        cout << "\n  Succesfully injected new event.\n";
    }
    else {
        cout << "\n  Failed to inject event.\n";
    }
}

/// <summary>
/// Menu function for subscribing events
/// </summary>
/// <param name="sys">system pointer</param>
void SubscribeEvents(CPPConsole::System* sys) {
    if (sys->SubscribeSystemEvents(&EventsCallBack)) {
        cout << "\n  Events subscription successful.\n";
        cout << "  Events received from server will be logged into a text file which can be viewed via 'View Events' option.\n";
    }
    else {
        cout << "\nFailed to subscribe events!!\n";
    }
}

/// <summary>
/// Menu function for unsubscribing events
/// </summary>
/// <param name="sys">system pointer</param>
void UnSubscribeEvents(CPPConsole::System* sys) {
    if (sys->UnSubscribeSystemEvents()) {
        cout << "\n  Events unsubscription successful.\n";
    }
    else {
        cout << "\n  Failed to unsubscribe events!!\n";
    }
}
#pragma endregion
