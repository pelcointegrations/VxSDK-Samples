#include "stdafx.h"
#include "StreamState.h"

#include "Controller.h"
#include "StreamBase.h"
#include "GstWrapper.h"

using namespace MediaController;

//=======================================================
// PlayingState
//=======================================================

bool PlayingState::Play(StreamBase& stream, float speed, unsigned int unixTime) {
    // Fast forward is not allowed if the stream is currently live so return
    // if it's attempted.
    if (stream.GetMode() == Controller::kLive) {
        if (speed < 0 || unixTime != 0) {
            return stream.Play(speed, unixTime == 0 ? stream.GetLastTimestamp() : unixTime);
        }
    }
    else {
        if (speed != stream.GetGstreamer()->GetSpeed() || unixTime != 0)
            return stream.Resume(speed, unixTime);
    }

    return true;
}

void PlayingState::Pause(StreamBase& stream) {
    stream.Pause();
}

void PlayingState::Stop(StreamBase& stream) {
    stream.Stop();
}

bool PlayingState::GoToLive(StreamBase& stream) {
    // If the stream is already live then simply return.
    if (stream.GetMode() == Controller::kLive) return true;

    // The stream needs to be stopped since it will be transitioning from playback to live.
    return stream.Play();
}

//=======================================================
// PausedState
//=======================================================

bool PausedState::Play(StreamBase& stream, float speed, unsigned int unixTime) {
    if (stream.GetMode() == Controller::kLive)
        return stream.Play(speed, unixTime == 0 ? stream.GetLastTimestamp() : unixTime);

    return stream.Resume(speed);
}

void PausedState::Stop(StreamBase& stream) {
    stream.Stop();
}

bool PausedState::GoToLive(StreamBase& stream) {
    return stream.Play();
}

//=======================================================
// StoppedState
//=======================================================

bool StoppedState::Play(StreamBase& stream, float speed, unsigned int unixTime) {
    // Playing from a stopped state assumes the stream starts in live mode.  However,
    // if a negative speed value is given then the stream will be in playback mode since
    // it is playing in reverse from live.
    if (speed < 0 || unixTime != 0)
        return stream.Play(speed, unixTime == 0 ? Utilities::CurrentUnixTime() : unixTime);

    return stream.Play();
}

bool StoppedState::GoToLive(StreamBase& stream) {
    return stream.Play();
}
