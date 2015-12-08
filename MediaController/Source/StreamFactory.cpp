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

    if (request.protocol == VxStreamProtocol::kRtspRtp) {
        char endpoint[Constants::kEndpointMaxSize];
        int size = Constants::kEndpointMaxSize;
        VxResult::Value result = request.dataSource->GetRtspEndpoint(endpoint, size);
        if (result == VxResult::kOK)
            stream = new Rtsp::Stream(request, controller, endpoint);
    }
    else if (request.protocol == VxStreamProtocol::kMjpegPull) {
        stream = new MjpegPull::Stream(request, controller);
    }
    return stream;
}