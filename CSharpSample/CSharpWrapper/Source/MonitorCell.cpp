/// <summary>
/// Implements the MonitorCell class.
/// </summary>
#include "MonitorCell.h"

CPPCli::MonitorCell::MonitorCell(VxSdk::IVxMonitorCell* vxMonitorCell) {
    _monitorCell = vxMonitorCell;
}

CPPCli::MonitorCell::!MonitorCell() {
    _monitorCell->Delete();
    _monitorCell = nullptr;
}

CPPCli::Results::Value CPPCli::MonitorCell::Disconnect() {
    // Call SetDataSource with a nullptr to remove the current data source
    return (CPPCli::Results::Value)_monitorCell->SetDataSource(nullptr);
}

CPPCli::Results::Value CPPCli::MonitorCell::GoToLive() {
    // Call SetTime with a nullptr to move the playback position to live
    return (CPPCli::Results::Value)_monitorCell->SetTime(nullptr);
}

CPPCli::Results::Value CPPCli::MonitorCell::Refresh() {
    return (CPPCli::Results::Value)_monitorCell->Refresh();
}
