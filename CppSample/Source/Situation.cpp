#include "stdafx.h"
#include "Situation.h"


CPPConsole::Situation::Situation(VxSdk::IVxSituation* vxSituation)
{
    _situation = vxSituation;
}


CPPConsole::Situation::~Situation()
{
    _situation->Delete();
    _situation = nullptr;
}
