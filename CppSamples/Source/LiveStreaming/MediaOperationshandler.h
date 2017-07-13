#pragma once

#include "VxSdk.h"
#include "MediaController.h"

namespace CppSamples {
    namespace LiveStreaming {

        /// <summary>
        /// MediaOperationshandler wraps the IController instance and some associated properties for streaming.
        /// </summary>
        class MediaOperationshandler {
        public:
            MediaOperationshandler(MediaController::IController* mediaControl) : _mediaControl(mediaControl), _isPlaying(true), _speed(1) { }
            ~MediaOperationshandler() { }

            /// <summary>
            /// Do media operation for given character.
            /// </summary>
            /// <param name="keyCode">Character code represent a command.</param>
            bool DoOperation(char keyCode);

        protected:
            /// <summary>
            /// Decrease speed and play with new speed.
            /// </summary>
            void DecreaseSpeed();

            /// <summary>
            /// Request the media control to move the stream to live.
            /// </summary>
            void GoToLive() const;
            
            /// <summary>
            /// Increase speed and play with new speed.
            /// </summary>
            void IncreaseSpeed();
            
            /// <summary>
            /// Toggle between pause and play options.
            /// </summary>
            void PauseOrPlay();

        private:
            MediaController::IController* _mediaControl;
            bool _isPlaying;
            float _speed;
        };
    }
}
