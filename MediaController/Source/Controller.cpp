#include "stdafx.h"
#include "Controller.h"

#include "MediaController.h"
#include "MediaRequest.h"
#include "StreamFactory.h"
#include "StreamBase.h"
#include "StreamState.h"
#include "GstWrapper.h"
#include <boost/thread.hpp>

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
    this->stream = StreamFactory::CreateStream(request);
    this->audioStream = StreamFactory::CreateAudioStream(request);
}

Controller::~Controller() {
    if (this->stream != nullptr) {
        delete this->stream;
        this->stream = nullptr;
    }

    if (this->audioStream != nullptr) {
        delete this->audioStream;
        this->audioStream = nullptr;
    }
}

void Controller::SetWindow(void* handle) {
    if (this->stream != nullptr)
        this->stream->GetGstreamer()->SetWindowHandle(guintptr(handle));
}

void Controller::NewRequest(MediaRequest& request) {
    if (this->stream != nullptr)
        this->stream->NewRequest(request);

    if (this->audioStream != nullptr) {
        MediaRequest* audioRequest = StreamFactory::CreateMediaRequest(request);
        this->audioStream->NewRequest(*audioRequest);
    }
}

bool Controller::GoToLive() {
    bool result = true;
    if (this->stream != nullptr) {
        result &= this->stream->state->GoToLive(*this->stream);
        CallPlayStream(this->stream, 0, 0);
    }

    if (this->audioStream != nullptr) {
        result &= this->audioStream->state->GoToLive(*this->audioStream);
        CallPlayStream(this->audioStream, 0, 0);
    }

    return result;
}

bool Controller::Play(float speed, unsigned int unixTime) {
    // Setup audio stream in new thread
    bool audioResult = true;
    boost::thread* t1 = nullptr;
    if (this->audioStream != nullptr) {
        t1 = new boost::thread(CallSetupStream, this->audioStream, speed, unixTime, &audioResult);
    }

    // Setup video stream in main thread
    bool videoResult = true;
    CallSetupStream(this->stream, speed, unixTime, &videoResult);

    // Wait for audio stream to complete
    if (t1 != nullptr)
        t1->join();

    if (!videoResult || !audioResult)
        return false;

    // Create pipeline for audio stream in new thread
    boost::thread* t2 = nullptr;
    if (audioResult) {
        t2 = new boost::thread(CallPlayStream, this->audioStream, speed, unixTime);
    }

    // Create pipeline for video stream in main thread
    if (videoResult) {
        CallPlayStream(this->stream, speed, unixTime);
    }

    // Wait for audio stream to complete
    if (t2 != nullptr)
        t2->join();

    return true;
}

void Controller::PlayStream(float speed, unsigned int unixTime) {
}

void Controller::CallSetupStream(StreamBase* stream, float speed, unsigned int unixTime, bool* result) {
    if (stream != nullptr) {
        *result = stream->state->Play(*stream, speed, unixTime);
    }
}

void Controller::CallPlayStream(StreamBase* stream, float speed, unsigned int unixTime) {
    if (stream != nullptr) {
        stream->PlayStream(speed, unixTime);
    }
}

void Controller::Pause() {
    if (this->stream != nullptr)
        this->stream->state->Pause(*this->stream);

    if (this->audioStream != nullptr)
        this->audioStream->state->Pause(*this->audioStream);
}

void Controller::Stop() {
    if (this->stream != nullptr)
        this->stream->state->Stop(*this->stream);

    if (this->audioStream != nullptr)
        this->audioStream->state->Stop(*this->audioStream);
}

void Controller::AddObserver(TimestampEventCallback observer) {
    if (this->stream != nullptr)
        this->stream->GetGstreamer()->AddObserver(observer);
}

void Controller::AddEventData(void* customData) {
    if (this->stream != nullptr)
        this->stream->GetGstreamer()->AddEventData(customData);
}

void Controller::RemoveObserver(TimestampEventCallback observer) {
    if (this->stream != nullptr)
        this->stream->GetGstreamer()->RemoveObserver(observer);
}

void Controller::ClearObservers() {
    if (this->stream != nullptr)
        this->stream->GetGstreamer()->ClearObservers();
}

Controller::Mode Controller::GetMode() {
    if (this->stream != nullptr)
        return this->stream->GetGstreamer()->GetMode();

    return Controller::Mode::kStopped;
}

bool Controller::IsPipelineActive() {
    if (this->stream != nullptr)
        return this->stream->GetGstreamer()->IsPipelineActive();
    return false;
}
