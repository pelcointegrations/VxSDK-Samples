#ifndef MediaController_h__
#define MediaController_h__

#include "Macros.h"
#include "IController.h"
#include "MediaRequest.h"

/// <summary>
/// Contains classes used to create and manage media streams.
/// </summary>
namespace MediaController {

    /// <summary>
    /// Create a new media controller object.
    /// </summary>
    /// <param name="request">The requested media to initialize.</param>
    /// <param name="control">The new media controller object.</param>
    EXTERN_C RTSPAPI void GetController(MediaRequest* request, IController** control);
}
#endif // MediaController_h__
