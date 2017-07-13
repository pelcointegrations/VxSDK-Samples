// Declares the ResourceRel class.
#ifndef ResourceRel_h__
#define ResourceRel_h__

#include "VxSdk.h"
#include "DataSource.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The ResourceRel class represents a related resource; that is, a resource that is related in some way
    /// to a parent resource.  This related resource may be linked to its parent resource for some effect.
    /// </summary>
    public ref class ResourceRel {
    public:

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="vxResourceRel">The vx relative resource.</param>
        ResourceRel(VxSdk::IVxResourceRel* vxResourceRel);

        /// <summary>
        /// Destructor.
        /// </summary>
        virtual ~ResourceRel() {
            this->!ResourceRel();
        }

        /// <summary>
        /// Finaliser.
        /// </summary>
        !ResourceRel();

        /// <summary>
        /// Update this instances properties.
        /// </summary>
        /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
        Results::Value Refresh();

        /// <summary>
        /// Gets or sets whether the resource is linked to its parent.
        /// </summary>
        /// <value><c>true</c> if this resource is linked to its parent, <c>false</c> if not linked.</value>
        property bool IsLinked {
        public:
            bool get() { return _resourceRel->isLinked; }
            void set(bool value) { _resourceRel->SetLinkState(value); }
        }

        /// <summary>
        /// Gets the related resource.
        /// </summary>
        /// <value>The related resource.</value>
        property DataSource^ Resource {
            DataSource^ get() { return _GetResource(); }
        }

    internal:
        VxSdk::IVxResourceRel* _resourceRel;
        DataSource^ _GetResource();
    };
}
#endif // ResourceRel_h__
