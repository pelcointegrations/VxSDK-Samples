#include "stdafx.h"
#include "MjpegPullStream.h"

#include "GstWrapper.h"
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace MediaController;
using namespace VxSdk;

MjpegPull::Stream::Stream(MediaRequest& request, Controller& controller)
    : StreamBase(request, controller) {
    _mediaRequest = request;
    _mediaRequest.dataSource->CreateMjpegDataSession(_dataSession);
    // The elements in the GStreamer pipeline need to have unique names in order to run multiple instances.
    // So a random UUID is generated and appended to the element names.
    _uuid = to_string(boost::uuids::random_generator()());
    std::string pipeline = boost::str(boost::format(Constants::kMjpegPipeline) % _dataSession->jpegUri % _uuid);

    // Build a new pipeline using the description generated above.
    this->_gst = new GstWrapper();

    // Update the pipeline using the description generated above.
    this->_gst->UpdatePipeline(pipeline);
}

MjpegPull::Stream::~Stream() {}

bool MjpegPull::Stream::Play(float speed) {
    // If the jpegUri is empty send a new stream request.
    if (_dataSession->jpegUri[0] == '\0')
        NewRequest(_mediaRequest);

    if (!this->_gst->IsPipelineActive()) {
        this->_gst->SetPipeline();
        // Subscribe to the GStreamer Bus element in order to get timestamps.
        this->_gst->SubscribeToBusEvents(_uuid);
    }
    _dataSession->GoLive();
    return true;
}

void MjpegPull::Stream::Pause() {
    // Pausing the stream moves it to playback mode so the live stream session needs to be deleted.
    _dataSession->DeleteDataSession();
    // The timestamp is set to the last received timestamp so Resume will start at the correct time.
    this->_gst->SetTimestamp(this->_gst->GetLastTimestamp(VxStreamProtocol::kMjpegPull));
}

void MjpegPull::Stream::Stop() {
    _dataSession->DeleteDataSession();
}

void MjpegPull::Stream::FrameForward() {}

void MjpegPull::Stream::FrameBackward() {}

bool MjpegPull::Stream::Seek(unsigned int unixTime, float speed) {
    // If the jpegUri is empty send a new stream request.
    if (_dataSession->jpegUri[0] == '\0')
        NewRequest(_mediaRequest);

    if (!this->_gst->IsPipelineActive()) {
        this->_gst->SetPipeline();
        // Subscribe to the GStreamer Bus element in order to get timestamps.
        this->_gst->SubscribeToBusEvents(_uuid);
    }
    VxSdk::VxResult::Value ret = _dataSession->Seek(unixTime, static_cast<int>(speed));
    if (ret == VxSdk::VxResult::kOK) {
        // Set the initial timestamp to the seek time.
        this->_gst->SetTimestamp(unixTime);
    }
    return true;
}

bool MjpegPull::Stream::GoToLive() { return true; }

bool MjpegPull::Stream::Resume(unsigned int unixTime, float speed) {
    // If the jpegUri is empty send a new stream request.
    if (_dataSession->jpegUri[0] == '\0')
        NewRequest(_mediaRequest);

    if (!this->_gst->IsPipelineActive()) {
        this->_gst->SetPipeline();
        // Subscribe to the GStreamer Bus element in order to get timestamps.
        this->_gst->SubscribeToBusEvents(_uuid);
    }
    // Seek to the last received timestamp generated during the Pause call.
    VxSdk::VxResult::Value ret = _dataSession->Seek(this->_gst->GetLastTimestamp(VxStreamProtocol::kMjpegPull), static_cast<int>(speed));
    if (ret == VxSdk::VxResult::kOK) {
        // Set the initial timestamp to the seek time.
        this->_gst->SetTimestamp(this->_gst->GetLastTimestamp(VxStreamProtocol::kMjpegPull));
    }
    return true;
}

void MjpegPull::Stream::NewRequest(MediaRequest& request) {
    _mediaRequest = request;
    _mediaRequest.dataSource->CreateMjpegDataSession(_dataSession);
    this->_gst->SetLocation(_dataSession->jpegUri, _uuid);
}
