#pragma once
#include <MediaController.h>
#include "DataSource.h"

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for RTSP Controller project
    /// This class has methods that will invoke underlying RTSPController library methods
    /// </summary>
    class MediaControl {
    public:

        /// <summary>
        /// Enums to keep track of playback state
        /// </summary>
        enum class Mode {
            Stopped,
            Live,
            Playback
        };

        /// <summary>
        /// Constructor. Initialzes with RTSP uri and port
        /// </summary>
        /// <param name="uri">RTSP url received from VxSDK</param>
        /// <param name="port">port number to connect</param>
        MediaControl(DataSource *ds);

        /// <summary>
        /// Set the window handle to stream into
        /// </summary>
        /// <param name="time">Time to seek</param>
        void SetVideoWindow(void* handle);

        /// <summary>
        /// Start playback
        /// </summary>
        void Play(int speed);

        /// <summary>
        /// Jump to live
        /// </summary>
        void GoToLive();

        /// <summary>
        /// Pause playback
        /// </summary>
        void Pause();

        /// <summary>
        /// Stop playback
        /// </summary>
        void Stop();

        /// <summary>
        /// Seek to a particular time
        /// </summary>
        /// <param name="time">Time to seek</param>
        void Seek(unsigned int time, int speed);

        /// <summary>
        /// Set timestamp callback method to receive timestamp events from Media Controller
        /// </summary>
        /// <param name="callBackMethod">Pointer to callback method</param>
        void SetTimestampCallback(MediaController::TimestampEventCallback callBackMethod);

        /// <summary>
        /// Returns the play/pause state
        /// </summary>
        bool IsPlaying() { return _isPlaying; }

        /// <summary>
        /// Returns the current playing speed.
        /// </summary>
        int GetCurrentSpeed() { return _speed; }

        /// <summary>
        /// Destructor
        /// </summary>
        ~MediaControl();

    private:
        MediaController::IController* _control; //RTSPcontroller wrapper instance
        bool _isPlaying;
        int _speed;
    };
}
