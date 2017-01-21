#include "stdafx.h"
#include "MediaOperationshandler.h"

using namespace std;
using namespace VxSdk;

// Do media operation for given character.
void CppSamples::LiveStreaming::MediaOperationshandler::DoOperation(char keyCode) {
    // Map the character code with operations
    // p => Play or Pause
    // z => Increase Speed
    // x => Decrease Speed
    // l -> Go to Live
    switch (keyCode) {
        case 'p':
            PauseOrPlay();
            break;
        case 'z':
            IncreaseSpeed();
            break;
        case 'x':
            DecreaseSpeed();
            break;
        case 'l':
            GoToLive();
            break;
        default:
            break;
    }
}

// Decrease speed and play with new speed.
void CppSamples::LiveStreaming::MediaOperationshandler::DecreaseSpeed() {
    // Decrease the current speed by 2
    _speed -= 2;
    // Play the stream with new speed
    bool result = _mediaControl->Play(_speed);
    // Verfify the result.
    if (!result)
        cout << "\nFailed to decrease speed.";
}

// Request the media control to move the stream to live.
void CppSamples::LiveStreaming::MediaOperationshandler::GoToLive() const {
    _mediaControl->GoToLive();
}

// Increase speed and play with new speed.
void CppSamples::LiveStreaming::MediaOperationshandler::IncreaseSpeed() {
    // Increase the current speed by 2
    _speed += 2;
    // Play the stream with new speed
    bool result = _mediaControl->Play(_speed);
    // Verfify the result.
    if (!result)
        cout << "\nFailed to increase speed.";
}

// Toggle between pause and play options.
void CppSamples::LiveStreaming::MediaOperationshandler::PauseOrPlay() {
    if (_isPlaying) {
        // Play mode to Pause mode
        cout << "\n" << "Pausing the stream.\n";
        _mediaControl->Pause();
        _isPlaying = false;
    }
    else {
        // Pause Mode to Play mode
        cout << "\nResuming the stream.\n";
        _mediaControl->Play(_speed);
        _isPlaying = true;
    }
}
