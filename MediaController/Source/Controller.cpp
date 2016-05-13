#include "stdafx.h"
#include "Controller.h"

#include "MediaController.h"
#include "MediaRequest.h"
#include "StreamFactory.h"
#include "StreamBase.h"
#include "StreamState.h"
#include "GstWrapper.h"

using namespace MediaController;

//=======================================================
// Entry Point
//=======================================================

namespace MediaController {
    void GetController(MediaRequest* request, IController** control) {
        *control = nullptr;
        if (!request) return;
        *control = new Controller(*request);
    }
}

//=======================================================
// Controller
//=======================================================

Controller::Controller(MediaRequest& request) {
    this->stream = StreamFactory::CreateStream(request, *this);
    this->state = new StoppedState();
}

Controller::~Controller() {}

void Controller::SetWindow(void* handle) {
    this->stream->GetGstreamer()->SetWindowHandle(intptr_t(handle));
}

void Controller::NewRequest(MediaRequest& request) {
    this->stream->NewRequest(request);
}

void Controller::GoToLive() {
    state->GoToLive(*this);
}

bool Controller::Play(int speed) {
    return state->Play(*this, speed);
}

void Controller::Pause() {
    state->Pause(*this);
}

void Controller::Stop() {
    state->Stop(*this);
}

void Controller::FrameForward() {}

void Controller::FrameBackward() {}

bool Controller::Seek(unsigned int unixTime, int speed) {
    return state->Seek(*this, unixTime, speed);
}

void Controller::AddObserver(TimestampEventCallback observer) {
    this->stream->GetGstreamer()->AddObserver(observer);
}

void Controller::AddEventData(void* customData) {
    this->stream->GetGstreamer()->AddEventData(customData);
}

void Controller::RemoveObserver(TimestampEventCallback observer) {
    this->stream->GetGstreamer()->RemoveObserver(observer);
}

void Controller::ClearObservers() {
    this->stream->GetGstreamer()->ClearObservers();
}

Controller::Mode Controller::GetMode() {
    return this->stream->GetGstreamer()->GetMode();
}

bool Controller::IsPipelineActive() {
    return this->stream->GetGstreamer()->IsPipelineActive();
}
