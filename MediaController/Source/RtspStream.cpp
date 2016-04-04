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
    // The elements in the GStreamer pipeline need to have unique names in order to run multiple instances.
    // So a random UUID is generated and appended to the element names.
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    // Initial pipeline, will be recreated later.
    string pipeline = str(boost::format(kRtspPipeline) % uuid % "90000" % "H264" % kUnicastPort % "" % uuid % (kUnicastPort + 1));

    // Build a new pipeline using the description generated above.
    this->_gst = GstWrapper::Builder()
        .SetPipelineDescription(pipeline)
        .Build();
}

Rtsp::Stream::~Stream() {}

void Rtsp::Stream::Play(int speed) {
    // Send the sequence of RTSP commands needed to start a new stream.
    this->_rtspCommands.Options();
    this->_rtspCommands.Describe();
    this->_rtspCommands.Setup();
    this->_rtspCommands.Play(speed);

    if (!_rtspKeepAlive) {
        // Start the keep alive loop in a new thread.
        _rtspKeepAlive = new KeepAlive(this->_rtspCommands);
    }
}

void Rtsp::Stream::Pause() {
    if (this->GetGstreamer()->GetMode() == IController::kLive) {
        // Pausing the stream moves it to playback mode so the live stream session needs to be torn down.
        this->_rtspCommands.Teardown();
    }
    else {
        // Pause can be called directly if the stream is in playback mode.
        this->_rtspCommands.Pause();
    }
}

void Rtsp::Stream::Stop() {
    // Signal the keep alive thread to shut down.
    delete _rtspKeepAlive;
    _rtspKeepAlive = nullptr;
    this->_rtspCommands.Teardown();
}

void Rtsp::Stream::FrameForward() {}

void Rtsp::Stream::FrameBackward() {}

void Rtsp::Stream::Seek(unsigned int unixTime, int speed) {
    this->_rtspCommands.Options();
    this->_rtspCommands.Describe();
    this->_rtspCommands.Setup();
    this->_rtspCommands.SeekPlay(unixTime, speed);

    if (!_rtspKeepAlive) {
        // Start the keep alive loop in a new thread.
        _rtspKeepAlive = new KeepAlive(this->_rtspCommands);
    }
}

void Rtsp::Stream::GoToLive() {}

void Rtsp::Stream::Resume(int speed) {
    // Seek to the last received timestamp.
    Seek(this->_gst->GetLastTimestamp(VxStreamProtocol::kRtspRtp), speed);
}

void Rtsp::Stream::NewRequest(MediaRequest& request) {
    this->_rtspCommands.ResetPath(request.dataInterface.dataEndpoint);
}
