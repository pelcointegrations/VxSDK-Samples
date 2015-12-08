using System;
using System.Windows.Forms;

namespace SDKSampleApp.Source
{
    /// <summary>
    /// The Program class
    /// </summary>
    public static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        public static void Main()
        {
            // Build the path to GStreamer based on the current system settings.
            var processType = Environment.Is64BitProcess ? "x64" : "x86";
            var currentPath = new System.IO.DirectoryInfo(Application.ExecutablePath);
            var rootSamplePath = currentPath.Parent.Parent.Parent.Parent.Parent.Parent.FullName;
            const string pathTemplate = "{0}\\MediaController\\ThirdParty\\GStreamer\\1.5.2\\{1}\\gstreamer_runtime\\bin";
            var gstreamerPath = new System.IO.DirectoryInfo(string.Format(pathTemplate, rootSamplePath, processType));

            // Add the GStreamer location to the path.  It will use it to automatically find the needed files.
            Environment.SetEnvironmentVariable("PATH", gstreamerPath.FullName);

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
    }
}
