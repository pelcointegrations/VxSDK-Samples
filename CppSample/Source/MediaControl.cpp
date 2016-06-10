#include "stdafx.h"
#include "MediaControl.h"

CPPConsole::MediaControl::MediaControl(DataSource* ds, bool isMjpegEnabled) : _isPlaying(false), _speed(0) {
    auto protocol = isMjpegEnabled ? DataInterface::StreamProtocol::kStreamProtocolMjpegPull : DataInterface::StreamProtocol::kStreamProtocolRtspRtp;

    MediaController::MediaRequest request;
    request.dataSource = ds->Self();
    auto dsi = ds->GetDataInterfaces();
    for (std::list<DataInterface*>::const_iterator iterator = dsi->begin(), end = dsi->end(); iterator != end; ++iterator) {
        if ((*iterator)->GetProtocol() == protocol) {
            request.dataInterface = *(*iterator)->_dataInterface;
            break;
        }
    }

    MediaController::IController* control = nullptr;
    GetController(&request, &control);
    _control = control;
}

void CPPConsole::MediaControl::SetVideoWindow(void* handle) {
    _control->SetWindow(handle);
}

bool CPPConsole::MediaControl::Play(int speed) {
    _speed = speed;
    auto ret = _control->Play(speed);
    _isPlaying = true;
    return ret;
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

bool CPPConsole::MediaControl::Seek(unsigned int time, int speed) {
    _speed = speed;
    auto ret = _control->Seek(time, speed);
    _isPlaying = true;
    return ret;
}

void CPPConsole::MediaControl::SetTimestampCallback(MediaController::TimestampEventCallback callBackMethod) {
    _control->AddObserver(callBackMethod);
}

CPPConsole::MediaControl::~MediaControl() {
    _control->ClearObservers();
    _control->Stop();
    delete _control;
}
