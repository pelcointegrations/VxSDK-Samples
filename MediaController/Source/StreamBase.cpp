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

void StreamBase::Play(int speed) {}

void StreamBase::Pause() {}

void StreamBase::Stop() {}

void StreamBase::FrameForward() {}

void StreamBase::FrameBackward() {}

void StreamBase::Seek(unsigned int unixTime, int speed) {}

void StreamBase::NewRequest(MediaRequest& request) {}

void StreamBase::Resume(int speed) {}

GstWrapper* StreamBase::GetGstreamer() {
    return this->_gst;
}
