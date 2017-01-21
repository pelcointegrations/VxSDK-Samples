/// <summary>
/// Implements the MediaControl class.
/// </summary>
#include "MediaControl.h"

#ifndef NO_MEDIA
using namespace System::Runtime::InteropServices;

CPPCli::MediaControl::MediaControl(DataSource^ videoSource, DataInterface^ videoInterface, DataSource^ audioSource, DataInterface^ audioInterface) {
    // Create a new MediaRequest object
    MediaController::MediaRequest request;
    if (videoSource != nullptr) {
        request.dataSource = videoSource->_dataSource;
        request.dataInterface = *videoInterface->_dataInterface;
    }
    
    if (audioSource != nullptr) {
        request.audioDataSource = audioSource->_dataSource;
        request.audioDataInterface = *audioInterface->_dataInterface;
    }

    // Get the MediaController which allows the client to control streams
    MediaController::IController* control = nullptr;
    MediaController::GetController(&request, &control);

    // Set the callback for timestamp events
    _timestampCallback = gcnew TimestampCallbackDelegate(this, &CPPCli::MediaControl::_FireTimestampEvent);
    control->AddObserver(MediaController::TimestampEventCallback(Marshal::GetFunctionPointerForDelegate(_timestampCallback).ToPointer()));

    _control = control;
    _currentdataSource = videoSource;
}

CPPCli::MediaControl::!MediaControl() {
    // Clear all subscriptions to the timestamp events
    _control->ClearObservers();
    delete _control;
    _control = nullptr;
}

void CPPCli::MediaControl::GoToLive() {
    _control->GoToLive();
}

void CPPCli::MediaControl::Pause() {
    _control->Pause();
}

bool CPPCli::MediaControl::Play(float speed) {
    return _control->Play(speed);
}

bool CPPCli::MediaControl::Seek(System::DateTime time, float speed) {
    // Convert the seek time from a DateTime format to unix time format
    System::TimeSpan ts = (time - System::DateTime(1970, 1, 1, 0, 0, 0));
    unsigned int seekTime = safe_cast<unsigned int>(ts.TotalSeconds);

    return _control->Play(speed, seekTime);
}

void CPPCli::MediaControl::SetDataSource(DataSource^ videoSource, DataInterface^ videoInterface, DataSource^ audioSource, DataInterface^ audioInterface) {
    // Create a new MediaRequest object
    MediaController::MediaRequest request;
    if (videoSource != nullptr) {
        request.dataSource = videoSource->_dataSource;
        request.dataInterface = *videoInterface->_dataInterface;
    }

    if (audioSource != nullptr) {
        request.audioDataSource = audioSource->_dataSource;
        request.audioDataInterface = *audioInterface->_dataInterface;
    }

    // Update the stream settings for the MediaController using the MediaRequest
    _control->NewRequest(request);
    _currentdataSource = videoSource;
}

void CPPCli::MediaControl::SetVideoWindow(System::IntPtr windowHandle) {
    // Set the display for the MediaController using windowHandle
    HWND VideoWindow = static_cast<HWND>(windowHandle.ToPointer());
    _control->SetWindow(VideoWindow);
}

void CPPCli::MediaControl::Stop() {
    _control->Stop();
}

void CPPCli::MediaControl::TimestampEvent::add(TimestampEventDelegate ^eventDelegate) {
    // Add a new subscription to the TimestampEventDelegate
    _timestampEvent += eventDelegate;
};

void CPPCli::MediaControl::TimestampEvent::remove(TimestampEventDelegate ^eventDelegate) {
    // Remove the TimestampEventDelegate subscription
    _timestampEvent -= eventDelegate;
};

void CPPCli::MediaControl::_FireTimestampEvent(MediaController::TimestampEvent* timeEvent) {
    // Fire the notification if there is a subscription to the timestamp events
    if (_timestampEvent != nullptr)
        return _timestampEvent(gcnew MediaEvent(timeEvent));
}
#else //NO_MEDIA defined
CPPCli::MediaControl::MediaControl(DataSource^ videoSource, DataInterface^ videoInterface, DataSource^ audioSource, DataInterface^ audioInterface) {
}

void CPPCli::MediaControl::SetVideoWindow(System::IntPtr windowHandle) {
}

void CPPCli::MediaControl::SetDataSource(DataSource^ videoSource, DataInterface^ videoInterface, DataSource^ audioSource, DataInterface^ audioInterface) {
}

CPPCli::MediaControl::!MediaControl() {
}

bool CPPCli::MediaControl::Play(float speed) {
    return false;
}

void CPPCli::MediaControl::Pause() {
}

void CPPCli::MediaControl::Stop() {
}

void CPPCli::MediaControl::GoToLive() {
}

bool CPPCli::MediaControl::Seek(System::DateTime time, float speed) {
    return false;
}

void CPPCli::MediaControl::TimestampEvent::add(TimestampEventDelegate ^eventDelegate) {

};

void CPPCli::MediaControl::TimestampEvent::remove(TimestampEventDelegate ^eventDelegate) {
};

void CPPCli::MediaControl::_FireTimestampEvent(MediaController::TimestampEvent* timeEvent) {
}
#endif
