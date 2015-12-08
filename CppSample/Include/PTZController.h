#pragma once
#include "Pattern.h"
#include "Preset.h"
#include <list>

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxPtzController
    /// </summary>
    class PTZController {
    public:

        /// <summary>
        /// Defines the pan tilt direction
        /// </summary>
        enum class PanTiltDirection {
            Unknown,
            None,
            UpLeft,
            Up,
            UpRight,
            Right,
            DownRight,
            Down,
            DownLeft,
            Left
        };

        /// <summary>
        /// Defines the zoom direction
        /// </summary>
        enum class ZoomDirection {
            Unknown,
            None,
            In,
            Out
        };

        /// <summary>
        /// Constructor - copies the VxSDK ptzController pointer
        /// </summary>
        /// <param name="ptzController">The ptzController pointer</param>
        PTZController(VxSdk::IVxPtzController* ptzController);

        /// <summary>
        /// Destructor
        /// </summary>
        ~PTZController();

        /// <summary>
        /// Returns the list of presets associated with this PTZ controller
        /// List will be deleted in its destructor
        /// </summary>
        std::list<Preset*>* GetPresets();

        /// <summary>
        /// Returns the list of patterns associated with this PTZ controller
        /// List will be deleted in its destructor
        /// </summary>
        std::list<Pattern*>* GetPatterns();

        /// <summary>
        /// Trigger the given pattern
        /// </summary>
        /// <param name="pattern">Pattern pointer to trigger</param>
        bool TriggerPattern(Pattern* pattern);

        /// <summary>
        /// Trigger the given preset
        /// </summary>
        /// <param name="preset">Preset pointer to trigger</param>
        bool TriggerPreset(Preset* preset);
        
        /// <summary>
        /// Continuously move the field of view at the given speed until stopped
        /// </summary>
        /// <param name="speedX">X axis speed (pan). Negative values perform
        /// continuous left pan, while positive values perform continuous right pan.</param>
        /// <param name="speedY">Y axis velocity (tilt). Negative values perform continuous downward
        /// tilt, while positive values perform continuous upward tilt.</param>
        /// <param name="zoomDirection">Zoom direction</param>
        bool ContinuousMove(int speedX, int speedY, ZoomDirection zoomDirection);
        
        /// <summary>
        /// Stop running PTZ command
        /// </summary>
        void PtzStop();

    private:
        VxSdk::IVxPtzController* _ptzController;
        std::list<Preset*>* _presetsList;
        std::list<Pattern*>* _patternsList;
    };
}
