#include "stdafx.h"
#include "StreamFactory.h"

#include "StreamBase.h"
#include "MediaRequest.h"
#include "RtspStream.h"
#include "MjpegPullStream.h"

using namespace MediaController;
using namespace VxSdk;

StreamBase* StreamFactory::CreateStream(MediaRequest& request, Controller& controller) {
    StreamBase* stream = nullptr;
    if (!request.dataSource) return stream;

    if (request.dataInterface.protocol == VxStreamProtocol::kRtspRtp) {
        stream = new Rtsp::Stream(request, controller);
    }
    else if (request.dataInterface.protocol == VxStreamProtocol::kMjpegPull) {
        stream = new MjpegPull::Stream(request, controller);
    }
    return stream;
}
