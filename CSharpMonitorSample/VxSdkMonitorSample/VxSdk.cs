using CPPCli;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VxSdkMonitorSample
{
    class VxSdk
    {
        private VXSystem _system;
        private BindingList<Monitor> _monitors = new BindingList<Monitor>();
        private BindingList<DataSource> _cameras = new BindingList<DataSource>();

        public enum VxLayout { Layout1x1, Layout2x2, Layout3x3, Layout4x4 }

        public VxSdk()
        {
            var retVal = VxGlobal.InitializeSdk("ReplaceWithGeneratedKey");
            if (retVal != Results.Value.OK)
                throw new Exception(retVal + "Unable to InitializeSdk");
        }

        public BindingList<Monitor> Monitors
        {
            get { return _monitors; }
        }

        public BindingList<DataSource> Cameras
        {
            get { return _cameras; }
        }

        public async Task GetMonitors()
        {
            if (_system == null) return;
            _monitors.Clear();
            var monitors = await Task.Run(() => _system.GetMonitors());
            foreach (var monitor in monitors)
                _monitors.Add(monitor);
        }

        public async Task GetCameras()
        {
            if (_system == null) return;
            _cameras.Clear();
            var cameras = await Task.Run(() => _system.GetDataSources());
            foreach (var camera in cameras)
                _cameras.Add(camera);
        }

        public async Task<bool> Init(string ip, string username, string password)
        {
            bool success = false;
            try
            {
                _system = new VXSystem(ip);
                var retVal = await Task.Run(() => _system.Login(username, password));
                if (retVal != Results.Value.OK)
                    throw new Exception(retVal + "Unable to login to the VideoXpert system provided ({ip}) with user ({username})");
                success = true;
            }
            catch (Exception e)
            {
                Trace.WriteLine(new Exception("Threw while Init VxSdk", e));
                _system = null;
            }
            return success;
        }

        public async Task ChangeLayout(Monitor monitor, VxLayout layout)
        {
            if (_system == null) return;
            switch (layout)
            {
                case VxLayout.Layout1x1:
                    await Task.Run(() => monitor.Layout = Monitor.Layouts.CellLayout1x1);
                    break;
                case VxLayout.Layout2x2:
                    await Task.Run(() => monitor.Layout = Monitor.Layouts.CellLayout2x2);
                    break;
                case VxLayout.Layout3x3:
                    await Task.Run(() => monitor.Layout = Monitor.Layouts.CellLayout3x3);
                    break;
                case VxLayout.Layout4x4:
                    await Task.Run(() => monitor.Layout = Monitor.Layouts.CellLayout4x4);
                    break;
            }
        }

        public async Task PlayVideo(Monitor monitor, int cellIdx, DataSource dataSource, DateTime dateTime)
        {
            bool live = dateTime == default(DateTime);
            var cell = monitor.MonitorCells[cellIdx];
            cell.DataSourceId = dataSource.Id;
            if (live)
                await Task.Run(() => cell.GoToLive());
            else
                await Task.Run(() => cell.Time = dateTime.ToUniversalTime());
        }
    }
}
