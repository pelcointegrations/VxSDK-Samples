#include "stdafx.h"
#include "StreamState.h"

#include "Controller.h"
#include "StreamBase.h"
#include "GstWrapper.h"

using namespace MediaController;

//=======================================================
// StreamState
//=======================================================

StreamState::StreamState() {}

bool StreamState::Play(Controller& controller, float speed) { return false; }
void StreamState::Pause(Controller& controller) {}
void StreamState::Stop(Controller& controller) {}
bool StreamState::GoToLive(Controller& controller) { return false; }
bool StreamState::Seek(Controller& controller, unsigned int unixTime, float speed) { return false; }

void StreamState::SetState(Controller& controller, StreamState* state) {
    controller.state = state;
}

//=======================================================
// PlayingState
//=======================================================

bool PlayingState::Play(Controller& controller, float speed) {
    // Fast forward is not allowed if the stream is currently live so return
    // if it's attempted.
    bool ret = true;
    if (controller.stream->GetGstreamer()->GetMode() == Controller::kLive) {
        if (speed > 0) {
            return ret;
        }
        controller.stream->Stop();
        ret = controller.stream->Seek(controller.stream->GetGstreamer()->GetLastTimestamp(VxSdk::VxStreamProtocol::kRtspRtp), speed);
        if (!ret) {
            ret = controller.stream->Play(1);
        }
    }
    else {
        if (speed != controller.stream->GetGstreamer()->GetSpeed()) {
            ret = controller.stream->Resume(0, speed);
            if (ret) {
                controller.stream->GetGstreamer()->SetMode(Controller::kPlayback);
            }
        }
    }

    // The stream will be in playback mode at this point, so a Resume call will be
    // needed instead of a Play call in order to keep the right time.
    SetState(controller, new PlayingState());
    controller.stream->GetGstreamer()->Play(speed);
    return ret;
}

void PlayingState::Pause(Controller& controller) {
    // We only pause the stream here.  Determining the stream state will be done
    // during the next action.
    controller.stream->Pause();
    SetState(controller, new PausedState());
    controller.stream->GetGstreamer()->Pause();
}

void PlayingState::Stop(Controller& controller) {
    controller.stream->Stop();
    SetState(controller, new StoppedState());
    controller.stream->GetGstreamer()->SetMode(Controller::kStopped);
}

bool PlayingState::GoToLive(Controller& controller) {
    // If the stream is already live then simply return.
    if (controller.stream->GetGstreamer()->GetMode() == Controller::kLive) return true;

    // The stream needs to be stopped since it will be transitioning from playback to live.
    //controller.stream->Stop();
    // Live streams can only play at 1x.
    controller.stream->Stop();
    bool ret = controller.stream->GoToLive();
    controller.stream->GetGstreamer()->SetMode(Controller::kLive);
    SetState(controller, new PlayingState());
    controller.stream->GetGstreamer()->Play(1);
    return ret;
}

bool PlayingState::Seek(Controller& controller, unsigned int unixTime, float speed) {
    if (controller.stream->GetGstreamer()->GetMode() == Controller::kLive)
        controller.stream->Stop();

    bool ret = controller.stream->Resume(unixTime, speed);
    SetState(controller, new PlayingState());
    controller.stream->GetGstreamer()->SetMode(Controller::kPlayback);
    controller.stream->GetGstreamer()->Play(speed);
    return ret;
}

//=======================================================
// PausedState
//=======================================================

bool PausedState::Play(Controller& controller, float speed) {
    // Calling Play from a paused state means the stream is in playback mode, so call Resume.
    bool ret;
    if (controller.stream->GetGstreamer()->GetMode() == Controller::kLive) {
        controller.stream->Stop();
        ret = controller.stream->Seek(controller.stream->GetGstreamer()->GetLastTimestamp(VxSdk::VxStreamProtocol::kRtspRtp), speed);
    }
    else {
        ret = controller.stream->Resume(0, speed);
    }

    if (ret) {
        controller.stream->GetGstreamer()->SetMode(Controller::kPlayback);
    }
    else {
        ret = controller.stream->Play(speed);
        controller.stream->GetGstreamer()->SetMode(Controller::kLive);
    }

    SetState(controller, new PlayingState());    
    controller.stream->GetGstreamer()->Play(speed);
    return ret;
}

void PausedState::Stop(Controller& controller) {
    controller.stream->Stop();
    SetState(controller, new StoppedState());
    controller.stream->GetGstreamer()->SetMode(Controller::kStopped);
}

bool PausedState::GoToLive(Controller& controller) {
    // Being in a paused state means the stream is in playback mode, so the stream needs to
    // be stopped since it will be transitioning to live.
    controller.stream->Stop();
    controller.stream->GetGstreamer()->SetMode(Controller::kLive);
    bool ret = controller.stream->GoToLive();
    SetState(controller, new PlayingState());
    controller.stream->GetGstreamer()->Play(1);
    return ret;
}

bool PausedState::Seek(Controller& controller, unsigned int unixTime, float speed) {
    if (controller.stream->GetGstreamer()->GetMode() == Controller::kLive)
        controller.stream->Stop();

    bool ret = controller.stream->Resume(unixTime, speed);
    SetState(controller, new PlayingState());
    controller.stream->GetGstreamer()->SetMode(Controller::kPlayback);
    controller.stream->GetGstreamer()->Play(speed);
    return ret;
}

//=======================================================
// StoppedState
//=======================================================

bool StoppedState::Play(Controller& controller, float speed) {
    bool ret;
    // Playing from a stopped state assumes the stream starts in live mode.  However,
    // if a negative speed value is given then the stream will be in playback mode since
    // it is playing in reverse from live.
    if (speed < 0) {
        controller.stream->GetGstreamer()->SetMode(Controller::kPlayback);
        ret = controller.stream->Seek(Utilities::CurrentUnixTime(), speed);
        SetState(controller, new PlayingState());
        controller.stream->GetGstreamer()->Play(speed);
    }
    else {
        controller.stream->GetGstreamer()->SetMode(Controller::kLive);
        ret = controller.stream->Play(1);
        SetState(controller, new PlayingState());
        controller.stream->GetGstreamer()->Play(speed);
    }
    return ret;
}

bool StoppedState::GoToLive(Controller& controller) {
    controller.stream->GetGstreamer()->SetMode(Controller::kLive);
    bool ret = controller.stream->Play(1);
    SetState(controller, new PlayingState());
    controller.stream->GetGstreamer()->Play(1);
    return ret;
}

bool StoppedState::Seek(Controller& controller, unsigned int unixTime, float speed) {
    bool ret = controller.stream->Seek(unixTime, speed);
    controller.stream->GetGstreamer()->SetMode(Controller::kPlayback);
    SetState(controller, new PlayingState());
    controller.stream->GetGstreamer()->Play(speed);
    return ret;
}
