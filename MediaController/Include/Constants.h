#ifndef Constants_h__
#define Constants_h__

namespace MediaController {
    namespace Constants {
        // Numerics
        static const unsigned long long kNsInSec = 1000000000;
        static const unsigned int kMsInNs = 1000000;
        static const unsigned int kNtpToEpochDiffSec = 2208988800;
        static const unsigned int kClockRate = 90000;
        static const unsigned short kPayloadType = 96;
        static const unsigned short kUnicastPort = 51298;
        static const unsigned short kKeepAliveRefreshSec = 15;
        static const unsigned short kEndpointMaxSize = 512;
        static const unsigned short kDateMaxSize = 32;
        static const unsigned short kMillisecondsInt = 1000;
        static const float kMillisecondsFloat = 1000.0;

        // Header names
        static const char* kHeaderLocation = "Location";
        static const char* kHeaderSession = "Session";
        static const char* kHeaderUserAgent = "User-Agent";
        static const char* kHeaderTransport = "Transport";
        static const char* kHeaderCSeq = "CSeq";
        static const char* kHeaderAccept = "Accept";
        static const char* kHeaderRange = "Range";
        static const char* kHeaderScale = "Scale";
        static const char* kHeaderContentLength = "Content-Length";
        static const char* kHeaderContentDisposition = "Content-Disposition";
        static const char* kControl = "a=control";

        // Status codes
        static const unsigned short kStatusCode200 = 200;
        static const unsigned short kStatusCode301 = 301;
        static const unsigned short kStatusCode302 = 302;

        // Rtsp
        static const char* kWhitespace = " ";
        static const char* kColon = ":";
        static const char* kColonSpace = ": ";
        static const char* kSemicolon = ";";
        static const char* kForwardSlash = "/";
        static const char* kReturn = "\r";
        static const char* kOneNewLine = "\r\n";
        static const char* kTwoNewLines = "\r\n\r\n";
        static const char* kRtspVersion = "RTSP/1.0";
        static const char* kActualUserAgent = "Pelco VxSdk";
        static const char* kOptions = "OPTIONS";
        static const char* kGetParameter = "GET_PARAMETER";
        static const char* kDescribe = "DESCRIBE";
        static const char* kSetup = "SETUP";
        static const char* kPlay = "PLAY";
        static const char* kPause = "PAUSE";
        static const char* kTeardown = "TEARDOWN";
        static const char* kSdpMimeType = "application/sdp";
        static const std::string kRtspPipeline = "rtpbin name=rtpbin "
                                                 "udpsrc name=udpsrc0%1% "
                                                 "caps=\"application/x-rtp,media=(string)video,clock-rate=(int)%2%,encoding-name=(string)%3%\" "
                                                 "port=%4% %5% ! queue ! decodebin ! d3dvideosink name=videoSink "
                                                 "udpsrc name=udpsrc1%6% port=%7% ! rtpbin.recv_rtcp_sink_0";

        // Mjpeg
        static const char* kHttpHeaders = "http-headers";
        static const char* kResponseHeaders = "response-headers";
        static const char* kHttpSrc = "httpsrc";
        static const char* kSrc = "src";
        static const std::string kMjpegPipeline = "souphttpsrc retries=-1 location=%1% name=httpsrc%2% http-log-level=SOUP_LOGGER_LOG_HEADERS ssl-strict=false "
                                                  "! jpegdec ! d3dvideosink name=videoSink";
    }
}
#endif // Constants_h__
