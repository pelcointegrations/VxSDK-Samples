#pragma once

#include "VxSdk.h"

namespace CppSamples {
    namespace LiveStreaming {

        /// <summary>
        /// PtzOperationsHandler helps to converts the user inputs into operations like panning, tilting and zooming or their combinations.
        /// </summary>
        class PtzOperationsHandler {
        public:
            PtzOperationsHandler(VxSdk::IVxPtzController* ptzControl) : _ptzControl(ptzControl), _showResult(false) { }
            ~PtzOperationsHandler() { }

            /// <summary>
            /// Do media operation for given character.
            /// </summary>
            /// <param name="keyCode">Character code represent a command.</param>
            /// <returns>True if corresponding operation found for given keyCode. False otherwise.</returns>
            bool DoOperation(char keyCode);

        protected:
            // Get collection of patterns from the PTZ control
            VxSdk::VxCollection<VxSdk::IVxPattern**> GetPatterns() const;
            // Get collection of presets from the PTZ control
            VxSdk::VxCollection<VxSdk::IVxPreset**> GetPresets() const;
            // Move the camera down
            VxSdk::VxResult::Value MoveDown() const;
            // Move the camera diagonally towards down left
            VxSdk::VxResult::Value MoveDownLeft() const;
            // Move the camera diagonally towards down right
            VxSdk::VxResult::Value MoveDownRight() const;
            // Move the camera left
            VxSdk::VxResult::Value MoveLeft() const;
            // Move the camera up
            VxSdk::VxResult::Value MoveUp() const;
            // Move the camera diagonally towards up left
            VxSdk::VxResult::Value MoveUpLeft() const;
            // Move the camera diagonally towards up right
            VxSdk::VxResult::Value MoveUpRight() const;
            // Move the camera right
            VxSdk::VxResult::Value MoveRight() const;
            // Trigger using the selected pattern
            void TriggerPattern();
            // Trigger using the selected preset
            void TriggerPreset();
            // Zoom in the camera
            VxSdk::VxResult::Value ZoomIn() const;
            // Zoom out the camera
            VxSdk::VxResult::Value ZoomOut() const;

        private:
            VxSdk::IVxPtzController* _ptzControl;
            bool _showResult;
        };
    }
}
