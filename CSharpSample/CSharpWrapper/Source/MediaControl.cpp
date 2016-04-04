/// <summary>
/// Implements the MediaControl class.
/// </summary>
#include "MediaControl.h"

using namespace System::Runtime::InteropServices;

CPPCli::MediaControl::MediaControl(DataSource^ dataSource, DataInterface^ dataInterface) {
    // Create a new MediaRequest object
    MediaController::MediaRequest request;
    request.dataSource = dataSource->_dataSource;
    request.dataInterface = *dataInterface->_dataInterface;

    // Get the MediaController which allows the client to control streams
    MediaController::IController* control = nullptr;
    MediaController::GetController(&request, &control);

    // Set the callback for timestamp events
    _timestampCallback = gcnew TimestampCallbackDelegate(this, &CPPCli::MediaControl::_FireTimestampEvent);
    control->AddObserver(MediaController::TimestampEventCallback(Marshal::GetFunctionPointerForDelegate(_timestampCallback).ToPointer()));

    _control = control;
    _currentdataSource = dataSource;
}

void CPPCli::MediaControl::SetVideoWindow(System::IntPtr windowHandle) {
    // Set the display for the MediaController using windowHandle
    void* VideoWindow = windowHandle.ToPointer();
    _control->SetWindow(VideoWindow);
}

void CPPCli::MediaControl::SetDataSource(DataSource^ dataSource, DataInterface^ dataInterface) {
    // Create a new MediaRequest object
    MediaController::MediaRequest request;
    request.dataSource = dataSource->_dataSource;
    request.dataInterface = *dataInterface->_dataInterface;
    // Update the stream settings for the MediaController using the MediaRequest
    _control->NewRequest(request);
    _currentdataSource = dataSource;
}

CPPCli::MediaControl::!MediaControl() {
    // Clear all subscriptions to the timestamp events
    _control->ClearObservers();
    delete _control;
}

void CPPCli::MediaControl::Play(int speed) {
    _control->Play(speed);
}

void CPPCli::MediaControl::Pause() {
    _control->Pause();
}

void CPPCli::MediaControl::Stop() {
    _control->Stop();
}

void CPPCli::MediaControl::GoToLive() {
    _control->GoToLive();
}

void CPPCli::MediaControl::Seek(System::DateTime time, int speed) {
    // Convert the seek time from a DateTime format to unix time format
    System::TimeSpan ts = (time - System::DateTime(1970, 1, 1, 0, 0, 0));
    unsigned int seekTime = safe_cast<unsigned int>(ts.TotalSeconds);

    _control->Seek(seekTime, speed);
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
