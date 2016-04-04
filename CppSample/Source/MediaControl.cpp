#include "stdafx.h"
#include "MediaControl.h"

CPPConsole::MediaControl::MediaControl(CPPConsole::DataSource* ds) : _isPlaying(false), _speed(0) {
    MediaController::MediaRequest request;
    request.dataSource = ds->Self();
    auto dsi = ds->GetDataInterfaces();
    for (std::list<DataInterface*>::const_iterator dsiIter = dsi->begin(), end = dsi->end(); dsiIter != end; ++dsiIter) {
        if ((*dsiIter)->GetProtocol() == DataInterface::StreamProtocol::kStreamProtocolRtspRtp)
            request.dataInterface = *(*dsiIter)->GetDataInterfacePtr();
    }
    
    MediaController::IController* control = nullptr;
    MediaController::GetController(&request, &control);
    _control = control;
}

void CPPConsole::MediaControl::SetVideoWindow(void* handle) {
    _control->SetWindow(handle);
}

void CPPConsole::MediaControl::Play(int speed) {
    _speed = speed;
    _control->Play(speed);
    _isPlaying = true;
}

void CPPConsole::MediaControl::GoToLive() {
    _control->GoToLive();
    _isPlaying = true;
}

void CPPConsole::MediaControl::Pause() {
    _control->Pause();
    _isPlaying = false;
}

void CPPConsole::MediaControl::Stop() {
    _control->Stop();
    _isPlaying = false;
}

void CPPConsole::MediaControl::Seek(unsigned int time, int speed) {
    _speed = speed;
    _control->Seek(time, speed);
    _isPlaying = true;
}

void CPPConsole::MediaControl::SetTimestampCallback(MediaController::TimestampEventCallback callBackMethod) {
    _control->AddObserver(callBackMethod);
}

CPPConsole::MediaControl::~MediaControl() {
    _control->ClearObservers();
    _control->Stop();
    delete _control;
}
