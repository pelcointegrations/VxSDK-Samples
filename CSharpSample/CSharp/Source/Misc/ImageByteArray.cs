using System;
using System.Linq;
using System.Net.Http.Headers;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// Holds a <c>byte</c> array response.
    /// </summary>
    public class ImageByteArray
    {
        /// <summary>
        /// Gets or sets the image <c>byte</c> array.
        /// </summary>
        /// <value>The <c>byte</c> array.</value>
        public byte[] Bytes { get; set; }

        /// <summary>
        /// Gets or sets the content type of the <c>byte</c> array.
        /// </summary>
        /// <value>The content type.</value>
        public string ContentType { get; set; }

        /// <summary>
        /// Gets or sets the <c>DateTime</c> of the snapshot image.
        /// </summary>
        /// <value>The <c>DateTime</c>.</value>
        public DateTime ImageTime { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ImageByteArray" /> class.
        /// </summary>
        /// <param name="imageData">The image data byte array.</param>
        /// <param name="headers">The response headers.</param>
        public ImageByteArray(byte[] imageData, HttpContentHeaders headers)
        {
            Bytes = imageData;
            if (headers == null)
                return;

            // Attempt to set the ImageTime property.
            if (headers.Contains("Image-Time"))
            {
                try
                {
                    var imageTimeHeaderValues = headers.GetValues("Image-Time");
                    if (imageTimeHeaderValues != null)
                    {
                        var imageTimeHeaderValue = imageTimeHeaderValues.FirstOrDefault();
                        if (!string.IsNullOrWhiteSpace(imageTimeHeaderValue))
                        {
                            DateTime parsedTime;
                            if (DateTime.TryParse(imageTimeHeaderValue, out parsedTime))
                                ImageTime = parsedTime.ToUniversalTime();
                            else
                                MainForm.Instance.WriteToLog("Failed to parse Image-Time header field.");
                        }
                    }
                }
                catch (Exception)
                {
                    MainForm.Instance.WriteToLog("Failed to set the image time.");
                }
            }

            if (headers.ContentType != null)
                ContentType = headers.ContentType.MediaType;
        }
    }
}
