#ifndef StreamFactory_h__
#define StreamFactory_h__

namespace MediaController {
    class StreamBase;
    struct MediaRequest;
    class Controller;

    /// <summary>
    /// Handles the creation of new stream objects.
    /// </summary>
    class StreamFactory {
    public:

        /// <summary>
        /// Create a new stream object.
        /// </summary>
        /// <param name="request">The requested media.</param>
        /// <returns>A new <see cref="StreamBase"/> object.</returns>
        static StreamBase* CreateStream(MediaRequest& request);

        /// <summary>
        /// Create a new audio stream object.
        /// </summary>
        /// <param name="request">The requested media.</param>
        /// <returns>A new <see cref="StreamBase"/> object.</returns>
        static StreamBase* CreateAudioStream(MediaRequest& request);

        /// <summary>
        /// Create a new audio MediaRequest object.
        /// </summary>
        /// <param name="request">The requested media.</param>
        /// <returns>A new MediaRequest object.</returns>
        static MediaRequest* CreateMediaRequest(MediaRequest& request);
    };
}
#endif // StreamFactory_h__
