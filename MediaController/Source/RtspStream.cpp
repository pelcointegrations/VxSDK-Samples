#include "stdafx.h"
#include "RtspStream.h"

#include "Controller.h"
#include "RtspCommands.h"
#include "GstWrapper.h"
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace std;
using namespace MediaController;
using namespace Constants;
using namespace VxSdk;

Rtsp::Stream::Stream(MediaRequest& request, MediaController::Controller& controller)
    : StreamBase(request, controller), _rtspCommands(&controller, request.dataInterface.dataEndpoint), _rtspKeepAlive() {
    // Build a new pipeline using the description generated above.
    this->_gst = new GstWrapper();
}

Rtsp::Stream::~Stream() {}

bool Rtsp::Stream::Play(int speed) {
    // Send the sequence of RTSP commands needed to start a new stream.
    if (!this->_rtspCommands.Options())
        return false;
    if (!this->_rtspCommands.Describe())
        return false;
    if (!this->_rtspCommands.Setup())
        return false;
    if (!this->_rtspCommands.Play(speed))
        return false;

    if (!this->_rtspKeepAlive) {
        // Start the keep alive loop in a new thread.
        this->_rtspKeepAlive = make_unique<KeepAlive>(this->_rtspCommands);
    }
    return true;
}

void Rtsp::Stream::Pause() {
    // Pause the stream.
    this->_rtspCommands.Pause();
}

void Rtsp::Stream::Stop() {
    // Signal the keep alive thread to shut down.
    this->_rtspKeepAlive.reset();
    this->_rtspCommands.Teardown();
    this->_gst->ClearWindow();
}

void Rtsp::Stream::FrameForward() {}

void Rtsp::Stream::FrameBackward() {}

bool Rtsp::Stream::Seek(unsigned int unixTime, int speed) {
    if (!this->_rtspCommands.Options())
        return false;
    if (!this->_rtspCommands.Describe())
        return false;
    if (!this->_rtspCommands.Setup())
        return false;
    if (!this->_rtspCommands.SeekPlay(unixTime, speed))
        return false;

    if (!this->_rtspKeepAlive) {
        // Start the keep alive loop in a new thread.
        this->_rtspKeepAlive = make_unique<KeepAlive>(this->_rtspCommands);
    }
    return true;
}

void Rtsp::Stream::GoToLive() {}

bool Rtsp::Stream::Resume(int speed) {
    // Seek to the last received timestamp.
    return Seek(this->_gst->GetLastTimestamp(VxStreamProtocol::kRtspRtp), speed);
}

void Rtsp::Stream::NewRequest(MediaRequest& request) {
    this->_rtspCommands.ResetPath(request.dataInterface.dataEndpoint);
}
