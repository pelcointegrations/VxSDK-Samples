/// <summary>
/// Implements the new schedule class.
/// </summary>
#include "NewSchedule.h"

CPPCli::NewSchedule::NewSchedule(VxSdk::VxNewSchedule* vxNewSchedule) {
    _newSchedule = vxNewSchedule;
}

CPPCli::NewSchedule::!NewSchedule() {
    delete _newSchedule;
}
