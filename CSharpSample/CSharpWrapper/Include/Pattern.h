// Declares the pattern class.
#ifndef Pattern_h__
#define Pattern_h__

#include "VxSdk.h"

namespace CPPCli {

    /// <summary>
    /// The Pattern class represents a predefined sequence of movement that a PTZ device can
    /// perform when triggered. A running pattern will be halted upon any other PTZ request.
    /// </summary>
    public ref class Pattern {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxPattern">The vx pattern.</param>
        Pattern(VxSdk::IVxPattern* vxPattern);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~Pattern() {
            this->!Pattern();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !Pattern();

        /// <summary>
        /// Gets the friendly name of the pattern.
        /// </summary>
        /// <value>The friendly name.</value>
        property System::String^ Name {
        public:
            System::String^ get() { return gcnew System::String(_pattern->name); }
        }

        /// <summary>
        /// Gets the friendly description of the pattern.
        /// </summary>
        /// <value>The friendly description.</value>
        property System::String^ Description {
        public:
            System::String^ get() { return gcnew System::String(_pattern->description); }
        }

    internal:
        VxSdk::IVxPattern* _pattern;
    };
}
#endif // Pattern_h__
