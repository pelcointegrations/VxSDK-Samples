// Declares the ptz controller class.
#ifndef PtzController_h__
#define PtzController_h__

#include "Pattern.h"
#include "Preset.h"
#include "PtzLimits.h"
#include "PtzLock.h"

namespace CPPCli {

    /// <summary>
    /// The PtzController class can be created for a device that has pan, tilt, and/or zoom functionality.
    /// </summary>
    public ref class PtzController {
    public:

        /// <summary>
        /// Values that represent iris directions.
        /// </summary>
        enum class IrisDirections
        {
            /// <summary>Stop iris movement.</summary>
            Stop,

            /// <summary>Close the iris.</summary>
            Close,

            /// <summary>Open the iris.</summary>
            Open
        };

        /// <summary>
        /// Values that represent focus directions.
        /// </summary>
        enum class FocusDirections
        {
            /// <summary>Stop focus movement.</summary>
            Stop,

            /// <summary>Focus far.</summary>
            Far,

            /// <summary>Focus near.</summary>
            Near
        };

        /// <summary>
        /// Values that represent zoom directions.
        /// </summary>
        enum class ZoomDirections
        {
            /// <summary>Do not perform a zoom action.</summary>
            None,

            /// <summary>Stop zoom movement.</summary>
            Stop,

            /// <summary>Zoom in.</summary>
            In,

            /// <summary>Zoom out.</summary>
            Out
        };

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="ptzController">The ptz controller.</param>
        PtzController(VxSdk::IVxPtzController* ptzController);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~PtzController() {
            this->!PtzController();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !PtzController();

        /// <summary>
        /// Move to the absolute position of the given coordinates.
        /// </summary>
        /// <param name="positionX">The X coordinate absolute position (pan).</param>
        /// <param name="positionY">The Y coordinate absolute position (tilt).</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the absolute move.</returns>
        Results::Value AbsoluteMove(int positionX, int positionY);

        /// <summary>
        /// Move to the absolute position of the given coordinates.
        /// </summary>
        /// <param name="positionX">The X coordinate absolute position (pan).</param>
        /// <param name="positionY">The Y coordinate absolute position (tilt).</param>
        /// <param name="positionZ">The Z coordinate absolute position (zoom).</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the absolute move.</returns>
        Results::Value AbsoluteMove(int positionX, int positionY, int positionZ);

        /// <summary>
        /// Pan to the absolute position of the given coordinate.
        /// </summary>
        /// <param name="positionX">The X coordinate absolute position (pan).</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the absolute pan.</returns>
        Results::Value AbsolutePan(int positionX);

        /// <summary>
        /// Tilt to the absolute position of the given coordinate.
        /// </summary>
        /// <param name="positionY">The Y coordinate absolute position (tilt).</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the absolute tilt.</returns>
        Results::Value AbsoluteTilt(int positionY);

        /// <summary>
        /// Zoom to the absolute position of the given coordinates.
        /// </summary>
        /// <param name="positionZ">The Z coordinate absolute position (zoom).</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the absolute zoom.</returns>
        Results::Value AbsoluteZoom(int positionZ);

        /// <summary>
        /// Creates a new preset using the current PTZ spatial coordinates.
        /// </summary>
        /// <param name="index">The unique index value for the new preset.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the adding the preset.</returns>
        Results::Value AddPreset(int index);

        /// <summary>
        /// Focus near or far until the user wants to stop.
        /// </summary>
        /// <param name="nearFar">The direction to focus.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the focus call.</returns>
        Results::Value ContinuousFocus(FocusDirections nearFar);

        /// <summary>
        /// Open or close the iris until the user wants to stop.
        /// </summary>
        /// <param name="openClose">The direction to change the iris.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the iris call.</returns>
        Results::Value ContinuousIris(IrisDirections openClose);

        /// <summary>
        /// Continuously move the field of view at the given speed until stopped.
        /// </summary>
        /// <param name="speedX">Pan speed. Negative values pan left, positive values pan right.</param>
        /// <param name="speedY">Tilt speed. Negative values tilt downward, positive values tilt upward.</param>
        /// <param name="inOut">The direction to zoom.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the continuous move.</returns>
        Results::Value ContinuousMove(int speedX, int speedY, ZoomDirections inOut);

        /// <summary>
        /// Deletes a preset from the system.
        /// </summary>
        /// <param name="preset">The <see cref="Preset"/> to delete.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of deleting the preset.</returns>
        CPPCli::Results::Value DeletePreset(Preset^ preset);

        /// <summary>
        /// Get the available patterns.
        /// </summary>
        /// <returns>A <c>List</c> of patterns.</returns>
        System::Collections::Generic::List<Pattern^>^ GetPatterns();

        /// <summary>
        /// Get the available presets.
        /// </summary>
        /// <returns>A <c>List</c> of presets.</returns>
        System::Collections::Generic::List<Preset^>^ GetPresets();

        /// <summary>
        /// Update this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Moves the camera position relative to the current position.
        /// </summary>
        /// <param name="deltaX">The degree to pan relative to the current X position.  Negative values pan
        ///               left, positive values pan right.</param>
        /// <param name="deltaY">The degree to tilt relative to the current Y position.  Negative values
        ///               pan left, positive values pan right.</param>
        /// <param name="deltaZ">The magnification level relative to the current Z position.  Negative values
        ///               pan left, positive values pan right.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the relative move.</returns>
        Results::Value RelativeMove(int deltaX, int deltaY, int deltaZ);

        /// <summary>
        /// Moves the camera position within a percentage relative to the device’s current field of view.
        /// </summary>
        /// <remarks>
        /// The rotational x and y parameters are used to move within a percentage of the current field of view of the camera. For
        /// instance, if the x parameter were 50 and the y parameter were -50, the pan/tilt would move halfway to the edge of the field
        /// of view along the x axis and halfway to the field of view along the negative y axis from its present position.
        /// </remarks>
        /// <param name="percentageX">Percentage of the current field of view of the camera (X axis).  Positive values are to the right,
        ///               negative values are to the left. Range: -100 to 100.</param>
        /// <param name="percentageY">Percentage of the current field of view of the camera (Y axis).  Positive values are up, negative
        ///               values are down. Range: -100 to 100.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of the relative percentage move.</returns>
        Results::Value RelativePercentageMove(int percentageX, int percentageY);

        /// <summary>
        /// Repositions a preset to the current PTZ spatial coordinates.
        /// </summary>
        /// <param name="preset">The <see cref="Preset"/> to reposition.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of repositioning the preset.</returns>
        Results::Value RepositionPreset(Preset^  preset);

        /// <summary>
        /// Stops all PTZ actions.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of the stop call.</returns>
        Results::Value Stop();

        /// <summary>
        /// Trigger a pattern.
        /// </summary>
        /// <param name="pattern">The <see cref="Pattern"/> to trigger.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of triggering the pattern.</returns>
        Results::Value TriggerPattern(Pattern^ pattern);

        /// <summary>
        /// Triggers a preset by index.
        /// </summary>
        /// <param name="index">The index of the preset to trigger.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of triggering the preset.</returns>
        Results::Value TriggerPreset(int index);

        /// <summary>
        /// Trigger a preset.
        /// </summary>
        /// <param name="preset">The <see cref="Preset"/> to trigger.</param>
        /// <returns>The <see cref="Results::Value">Result</see> of triggering the preset.</returns>
        Results::Value TriggerPreset(Preset^ preset);

        /// <summary>
        /// Triggers a refresh of this <see cref="PtzController"/> on the VideoXpert system; updating its <see cref="Pattern">patterns</see>
        /// and <see cref="Preset">presets</see> based on the current camera configuration.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of refreshing the <see cref="PtzController"/>.</returns>
        Results::Value TriggerRefresh();

        /// <summary>
        /// Gets a value indicating whether the PTZ control is locked.
        /// </summary>
        /// <value><c>true</c> if locked, <c>false</c> if not.</value>
        property bool IsLocked {
        public:
            bool get() { return _ptzController->isLocked; }
        }

        /// <summary>
        /// Gets the time remaining (in seconds) until the PTZ lock expires.
        /// </summary>
        /// <value>The expire time in seconds.</value>
        property int LockExpireTime {
        public:
            int get() { return _ptzController->lockExpireTime; }
        }

        /// <summary>
        /// Gets the <see cref="PtzLimits"/> for this ptz controller.
        /// </summary>
        /// <value><c>nullptr</c> if no ptz limits are available, else the <see cref="PtzLimits"/>.</value>
        property PtzLimits^ PTZLimits {
        public:
            PtzLimits^ get() { return _GetPtzLimits(); }
        }

        /// <summary>
        /// Gets the <see cref="PtzLock"/> associated with this ptz controller.
        /// </summary>
        /// <value><c>nullptr</c> if no ptz lock is available, else the <see cref="PtzLock"/>.</value>
        property PtzLock^ PTZLock {
        public:
            PtzLock^ get() { return _GetPtzLock(); }
        }

        /// <summary>
        /// Gets the X coordinate absolute position (pan).
        /// </summary>
        /// <value>The current X coordinate.</value>
        property int X {
        public:
            int get() {
                int x, y, z;
                _ptzController->GetPosition(x, y, z);
                return x;
            }
        }

        /// <summary>
        /// Gets the Y coordinate absolute position (tilt).
        /// </summary>
        /// <value>The current Y coordinate.</value>
        property int Y {
        public:
            int get() {
                int x, y, z;
                _ptzController->GetPosition(x, y, z);
                return y;
            }
        }

        /// <summary>
        /// Gets the Z coordinate absolute position (zoom).
        /// </summary>
        /// <value>The current Z coordinate.</value>
        property int Z {
        public:
            int get() {
                int x, y, z;
                _ptzController->GetPosition(x, y, z);
                return z;
            }
        }

    internal:
        VxSdk::IVxPtzController* _ptzController;
        PtzLimits^ _GetPtzLimits();
        PtzLock^ _GetPtzLock();
    };
}
#endif // PtzController_h__
