// Declares the ptz limits class.
#ifndef PtzLimits_h__
#define PtzLimits_h__

#include "VxSdk.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The PtzLimits class represents the value limits for a ptz controller.
    /// </summary>
    public ref class PtzLimits {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxPtzLimits">The ptz limits.</param>
        PtzLimits(VxSdk::VxPtzLimits* vxPtzLimits){
            _ptzLimits = vxPtzLimits;
        }

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~PtzLimits() {
            this->!PtzLimits();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !PtzLimits() {
            _ptzLimits->Clear();
            _ptzLimits = nullptr;
        }

        /// <summary>
        /// Gets the Y coordinate minimum limit.
        /// </summary>
        /// <value>The minimum Y coordinate, 0 if limit is unavailable.</value>
        property int MinPositionY {
        public:
            int get() { return _ptzLimits->minPositionY; }
        }

        /// <summary>
        /// Gets the Y coordinate maximum limit.
        /// </summary>
        /// <value>The maximum Y coordinate, 0 if limit is unavailable.</value>
        property int MaxPositionY {
        public:
            int get() { return _ptzLimits->maxPositionY; }
        }

        /// <summary>
        /// Gets the Z coordinate maximum limit.
        /// </summary>
        /// <value>The maximum Z coordinate, 0 if limit is unavailable.</value>
        property int MaxPositionZ {
        public:
            int get() { return _ptzLimits->maxPositionZ; }
        }

        /// <summary>
        /// Gets the pan speed minimum limit.
        /// </summary>
        /// <value>The minimum pan speed.</value>
        property int MinSpeedX {
        public:
            int get() { return _ptzLimits->minSpeedX; }
        }

        /// <summary>
        /// Gets the pan speed maximum limit.
        /// </summary>
        /// <value>The maximum pan speed.</value>
        property int MaxSpeedX {
        public:
            int get() { return _ptzLimits->maxSpeedX; }
        }

        /// <summary>
        /// Gets the tilt speed minimum limit.
        /// </summary>
        /// <value>The minimum tilt speed.</value>
        property int MinSpeedY {
        public:
            int get() { return _ptzLimits->minSpeedY; }
        }

        /// <summary>
        /// Gets the tilt speed maximum limit.
        /// </summary>
        /// <value>The maximum tilt speed.</value>
        property int MaxSpeedY {
        public:
            int get() { return _ptzLimits->maxSpeedY; }
        }

    internal:
        VxSdk::VxPtzLimits* _ptzLimits;
    };
}
#endif // PtzLimits_h__
