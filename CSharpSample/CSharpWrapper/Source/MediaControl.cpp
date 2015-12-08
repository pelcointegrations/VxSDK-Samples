/// <summary>
/// Implements the MediaControl class.
/// </summary>
#include "MediaControl.h"

using namespace System::Runtime::InteropServices;

CPPCli::MediaControl::MediaControl(DataSource^ dataSource, DataInterface::StreamProtocols protocol) {
    MediaController::MediaRequest request;
    request.dataSource = dataSource->_dataSource;
    request.protocol = VxSdk::VxStreamProtocol::Value(protocol);

    MediaController::IController* control = nullptr;
    MediaController::GetController(&request, &control);
    
    _timestampCallback = gcnew TimestampCallbackDelegate(this, &CPPCli::MediaControl::_FireTimestampEvent);
    control->AddObserver(MediaController::TimestampEventCallback(Marshal::GetFunctionPointerForDelegate(_timestampCallback).ToPointer()));

    _control = control;
}

void CPPCli::MediaControl::SetVideoWindow(System::IntPtr windowHandle) {
    void* VideoWindow = windowHandle.ToPointer();
    _control->SetWindow(VideoWindow);
}

void CPPCli::MediaControl::SetDataSource(DataSource^ dataSource, DataInterface::StreamProtocols protocol) {
    MediaController::MediaRequest request;
    request.dataSource = dataSource->_dataSource;
    request.protocol = VxSdk::VxStreamProtocol::Value(protocol);
    _control->NewRequest(request);
}

CPPCli::MediaControl::!MediaControl() {
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
    System::TimeSpan ts = (time - System::DateTime(1970, 1, 1, 0, 0, 0));
    unsigned int seekTime = safe_cast<unsigned int>(ts.TotalSeconds);
    _control->Seek(seekTime, speed);
}

void CPPCli::MediaControl::TimestampEvent::add(TimestampEventDelegate ^eventDelegate) {
    _timestampEvent += eventDelegate;
};

void CPPCli::MediaControl::TimestampEvent::remove(TimestampEventDelegate ^eventDelegate) {
    _timestampEvent -= eventDelegate;
};

void CPPCli::MediaControl::_FireTimestampEvent(MediaController::TimestampEvent* timeEvent) {
    if (_timestampEvent != nullptr)
        return _timestampEvent(gcnew MediaEvent(timeEvent));
}
