using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

namespace SDKSampleApp.Source
{
    public static class Utilities
    {
        /// <summary>
        /// The EncodeToBase64 method.
        /// </summary>
        /// <param name="toEncode">The string to encode to Base64.</param>
        /// <returns>The Base64 encoded string.</returns>        
        public static string EncodeToBase64(string toEncode)
        {
            var toEncodeAsBytes = Encoding.ASCII.GetBytes(toEncode);
            var returnValue = Convert.ToBase64String(toEncodeAsBytes);
            return returnValue;
        }

        /// <summary>
        /// The RotateImage method.
        /// </summary>
        /// <param name="image">The image to be rotated.</param>
        /// <param name="rotationAngle">The angle (in degrees).</param>
        /// <returns>The rotated image.</returns>
        public static Image RotateImage(Image image, float rotationAngle)
        {
            if (image == null)
                return null;

            // Create an empty image.
            var bitmap = new Bitmap(image.Width, image.Height);
            bitmap.SetResolution(image.HorizontalResolution, image.VerticalResolution);

            // Turn the bitmap into a graphics object.
            var graphics = Graphics.FromImage(bitmap);

            // Set the rotation point to the center of the image.
            graphics.TranslateTransform((float)bitmap.Width / 2, (float)bitmap.Height / 2);

            // Rotate the image.
            graphics.RotateTransform(rotationAngle);
            graphics.TranslateTransform(-(float)bitmap.Width / 2, -(float)bitmap.Height / 2);

            // Set the InterpolationMode to HighQualityBicubic to ensure a high
            // quality image once it is transformed to the specified size.
            graphics.InterpolationMode = InterpolationMode.HighQualityBicubic;

            // Draw the new image onto the graphics object.
            graphics.DrawImage(image, new Point(0, 0));

            // Dispose of the graphics object.
            graphics.Dispose();

            // Return the image.
            return bitmap;
        }

        /// <summary>
        /// The SendRequest method.
        /// </summary>
        /// <param name="uri">The request <c>Uri</c>.</param>
        /// <returns>The response message.</returns>
        public static async Task<HttpResponseMessage> SendRequest(Uri uri)
        {
            // Create a new WebClient instance.
            var client = new HttpClient();

            // Supply the username and password that was used to create the VideoXpert system.
            var request = new HttpRequestMessage(HttpMethod.Get, uri);
            request.Headers.Add("X-Serenity-User", EncodeToBase64(MainForm.CurrentUserName));
            request.Headers.Add("X-Serenity-Password", EncodeToBase64(MainForm.CurrentPassword));

            // Forces the WebClient to trust the security certificate handed back from the VideoXpert server.
            ServicePointManager.ServerCertificateValidationCallback = delegate { return true; };

            var response = await client.SendAsync(request);
            return response;
        }
    }
}
