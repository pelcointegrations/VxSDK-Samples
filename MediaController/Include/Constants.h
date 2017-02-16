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
        static const char* kHeaderLocation = "location";
        static const char* kHeaderSession = "session";
        static const char* kHeaderUserAgent = "User-Agent";
        static const char* kHeaderTransport = "Transport";
        static const char* kHeaderCSeq = "CSeq";
        static const char* kHeaderAccept = "Accept";
        static const char* kHeaderRange = "Range";
        static const char* kHeaderScale = "Scale";
        static const char* kHeaderContentLength = "content-length";
        static const char* kHeaderContentDisposition = "Content-Disposition";

		static const char* kLowerCaseHeaderLocation = "location";
		static const char* kLowerCaseHeaderSession = "session";
		static const char* kLowerCaseHeaderUserAgent = "user-agent";
		static const char* kLowerCaseHeaderTransport = "transport";
		static const char* kLowerCaseHeaderCSeq = "cseq";
		static const char* kLowerCaseHeaderAccept = "accept";
		static const char* kLowerCaseHeaderRange = "range";
		static const char* kLowerCaseHeaderScale = "scale";
		static const char* kLowerCaseHeaderContentLength = "content-length";
		static const char* kLowerCaseHeaderContentDisposition = "content-disposition";

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
        static const char* kEquals = "=";
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
        static const char* kHttpHeaders = "http-headers";
        static const char* kResponseHeaders = "response-headers";

        // GStreamer
        static const char* kSrc = "src";
        static const char* kSink = "sink";
        static const char* kPort = "port";
        static const char* kAddress = "address";
        static const char* kCaps = "caps";
        static const char* kHost = "host";
        static const char* kSync = "sync";
        static const char* kAsync = "async";
        static const char* kRetries = "retries";
        static const char* kKeepAlive = "keep-alive";
        static const char* kLocation = "location";
        static const char* kHttpLogLevel = "http-log-level";
        static const char* kSslStrict = "ssl-strict";
        static const char* kCookies = "cookies";
        static const char* kEncodingJpeg = "JPEG";
        static const char* kEncodingMpeg = "MP4V-ES";

        // GStreamer elements
        static const char* kUdpSrc = "udpsrc";
        static const char* kUdpSink = "udpsink";
        static const char* kRtpH264Depay = "rtph264depay";
        static const char* kRtpH264Dec = "avdec_h264";
        static const char* kRtpMp4vDepay = "rtpmp4vdepay";
        static const char* kRtpMp4vDec = "avdec_mpeg4";
        static const char* kVideoSink = "d3dvideosink";
        static const char* kRtpBin = "rtpbin";
        static const char* kHttpSrc = "souphttpsrc";
        static const char* kJpegDec = "jpegdec";
        static const char* kRtpJpegDepay = "rtpjpegdepay";
        static const char* kRtpAudioDepay = "rtppcmudepay";
        static const char* kRtpAudioDec = "mulawdec";
        static const char* kAudioSink = "directsoundsink";
    }
}
#endif // Constants_h__
