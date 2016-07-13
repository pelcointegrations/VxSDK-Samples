#include "stdafx.h"
#include "StreamBase.h"

#include "GstWrapper.h"

using namespace std;
using namespace MediaController;
using namespace VxSdk;

StreamBase::StreamBase() {}

StreamBase::StreamBase(MediaRequest& request, Controller& controller) :
   _mediaRequest(request),  _controller(&controller)  {
   this->_gst = nullptr;
}

StreamBase::~StreamBase() {
    delete this->_gst;
}

bool StreamBase::Play(float speed) { return false; }

void StreamBase::Pause() {}

void StreamBase::Stop() {}

void StreamBase::FrameForward() {}

void StreamBase::FrameBackward() {}

bool StreamBase::Seek(unsigned int unixTime, float speed) { return false; }

void StreamBase::NewRequest(MediaRequest& request) {}

bool StreamBase::Resume(unsigned int unixTime, float speed) { return false; }

GstWrapper* StreamBase::GetGstreamer() {
    return this->_gst;
}
