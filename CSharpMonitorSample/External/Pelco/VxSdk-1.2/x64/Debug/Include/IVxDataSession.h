#ifndef IVxDataSession_h__
#define IVxDataSession_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    struct IVxDataSource;
    struct IVxUser;

    /// <summary>
    /// Represents a data session that is being transmitted by a data source, via a data interface, to a client.
    /// </summary>
    struct IVxDataSession {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Terminates the current data session.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value DeleteDataSession() = 0;
        /// <summary>
        /// Gets the data session authentication token.
        /// </summary>
        /// <param name="token">The authentication token.</param>
        /// <param name="size">The size of <paramref name="token"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAuthToken(char* token, int& size) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDataSource"/> from which this session is retrieving data.
        /// </summary>
        /// <param name="dataSource">The <see cref="IVxDataSource"/> for this session.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSource(IVxDataSource*& dataSource) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxUser"/> that this session is being used by, if any.
        /// </summary>
        /// <param name="user">The <see cref="IVxUser"/> using this session.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUser(IVxUser*& user) const = 0;
        /// <summary>
        /// Sets the position of the data session as close to live as possible.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GoLive() = 0;
        /// <summary>
        /// Pauses the data session.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Pause() = 0;
        /// <summary>
        /// Starts or resumes the data session.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Play() = 0;
        /// <summary>
        /// Seeks to the frame nearest to the given time.
        /// </summary>
        /// <param name="unixTime">The seek time in unix time format.</param>
        /// <param name="speed">The playback speed.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Seek(long long unixTime, float speed) = 0;
        /// <summary>
        /// Sets the play speed of the data session. Negative values indicate reverse speeds while positive values indicate
        /// forward speeds (1 is normal speed).
        /// </summary>
        /// <param name="speed">The playback speed.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetSpeed(float speed) = 0;
        /// <summary>
        /// Sets the quality property.
        /// </summary>
        /// <param name="quality">The new quality value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetQuality(unsigned short quality) = 0;
        /// <summary>
        /// Sets the resolution properties.
        /// </summary>
        /// <param name="xResolution">The new horizontal resolution value.</param>
        /// <param name="yResolution">The new vertical resolution value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the properties.</returns>
        virtual VxResult::Value SetResolution(unsigned short xResolution, unsigned short yResolution) = 0;
        /// <summary>
        /// Updates the values of this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of updating this instance.</returns>
        virtual VxResult::Value Update() = 0;

    public:
        /// <summary>
        /// The unique identifier of the data session.
        /// </summary>
        char id[64];
        /// <summary>
        /// The URI of the JPEG frame.
        /// </summary>
        char jpegUri[512];
        /// <summary>
        /// The play speed of the data.
        /// </summary>
        float speed;
        /// <summary>
        /// The image quality of the data from 1 to 100. Smaller numbers have better quality than larger numbers.
        /// </summary>
        unsigned short quality;
        /// <summary>
        /// The horizontal resolution of the data (Width).
        /// </summary>
        unsigned short xResolution;
        /// <summary>
        /// The vertical resolution of the data (Height).
        /// </summary>
        unsigned short yResolution;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->jpegUri);
            this->speed = 0;
            this->quality = 0;
            this->xResolution = 0;
            this->yResolution = 0;
        }
    };
}

#endif // IVxDataSession_h__
