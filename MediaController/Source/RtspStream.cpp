#include "stdafx.h"
#include "RtspStream.h"

#include "Controller.h"
#include "RtspCommands.h"
#include "GstWrapper.h"
#include <StreamState.h>

using namespace std;
using namespace MediaController;
using namespace Constants;
using namespace VxSdk;

Rtsp::Stream::Stream(MediaRequest& request, bool isVideo) :
    StreamBase(request),
    _rtspCommands(new Commands(request.dataInterface.dataEndpoint, isVideo)),
    _rtspKeepAlive() {
}

Rtsp::Stream::~Stream() {
    this->_rtspKeepAlive.reset(nullptr);
    delete _rtspCommands;
    _rtspCommands = nullptr;
}

bool Rtsp::Stream::Play(float speed, unsigned int unixTime) {
    if (this->_gst->GetMode() != IController::kStopped)
        this->Stop();

    if (speed == 0 && unixTime == 0)
        this->_gst->SetMode(IController::kLive);
    else
        this->_gst->SetMode(IController::kPlayback);

    // Send the sequence of RTSP commands needed to start a new stream.
    if (!this->_rtspCommands->Options())
        return false;

    if (!this->_rtspCommands->Describe(true))
        return false;

    if (!this->_rtspCommands->Setup(true))
        return false;

    if (this->_rtspCommands->SetupStream(this->_gst, speed, unixTime))
        return true;

    return false;
}

void Rtsp::Stream::PlayStream(float speed, unsigned int unixTime) {
    this->_rtspCommands->PlayStream(this->_gst);
    this->_gst->Play(speed == 0 ? 1 : speed);

    // Start the keep alive loop in a new thread.
    if (!this->_rtspKeepAlive)
        this->_rtspKeepAlive = make_unique<KeepAlive>(this->_rtspCommands);

    this->state = new PlayingState();
}

void Rtsp::Stream::Pause() {
    // Pause the stream.
    this->_rtspCommands->Pause();
    this->_gst->Pause();
    this->state = new PausedState();
}

void Rtsp::Stream::Stop() {
    // Signal the keep alive thread to shut down.
    this->_rtspKeepAlive.reset();
    this->_rtspCommands->Teardown();
    this->_gst->ClearPipeline();
    this->_gst->SetMode(IController::kStopped);
    this->state = new StoppedState();
}

bool Rtsp::Stream::GoToLive() { return true; }

bool Rtsp::Stream::Resume(float speed, unsigned int unixTime) {
    bool ret = this->_rtspCommands->SetupStream(this->_gst, speed, unixTime);
    if (ret)
        this->_rtspCommands->PlayStream(this->_gst);

    this->_gst->Play(speed == 0 ? 1 : speed);
    this->state = new PlayingState();
    return ret;
}

void Rtsp::Stream::NewRequest(MediaRequest& request) {
    this->_rtspCommands->ResetPath(request.dataInterface.dataEndpoint);
}
