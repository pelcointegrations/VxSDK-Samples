// Declares the snapshot filter class.
#ifndef SnapshotFilter_h__
#define SnapshotFilter_h__

#include "VxSdk.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The SnapshotFilter class represents a filter that can be used when generating snapshots.
    /// </summary>
    public ref class SnapshotFilter {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        SnapshotFilter() {
            Clear();
        }

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~SnapshotFilter() {
            this->!SnapshotFilter();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !SnapshotFilter(){
            Clear();
        }

        /// <summary>
        /// Gets or sets the DateTime at which no further images should be returned.
        /// Defaults to the associated clips end time.
        /// </summary>
        /// <value>The end time.</value>
        property System::DateTime EndTime {
        public:
            System::DateTime get() { return *_endTime; }
            void set(System::DateTime value) { _endTime = value; }
        }

        /// <summary>
        /// Gets or sets the time offset between images.
        /// </summary>
        /// <value>The amount of time, in seconds, between images.</value>
        property int Offset {
        public:
            int get() { return _offset; }
            void set(int value) { _offset = value; }
        }

        /// <summary>
        /// Gets or sets the DateTime at which the initial image should start.
        /// Defaults to the associated clips start time.
        /// </summary>
        /// <value>The start time.</value>
        property System::DateTime StartTime {
        public:
            System::DateTime get() { return *_startTime; }
            void set(System::DateTime value) { _startTime = value; }
        }

        /// <summary>
        /// Gets or sets the width of the snapshot, maintaining ratio.
        /// </summary>
        /// <value>The width of the snapshot in pixels.</value>
        property int Width {
        public:
            int get() { return _width; }
            void set(int value) { _width = value; }
        }

    internal:
        System::DateTime^ _endTime;
        System::DateTime^ _startTime;
        int _offset;
        int _width;

        /// <summary>
        /// Finaliser.
        /// </summary>
        void Clear() {
            _endTime = gcnew System::DateTime();
            _startTime = gcnew System::DateTime();
            _offset = 0;
            _width = 0;
        }
    };
}
#endif // SnapshotFilter_h__