#include "stdafx.h"
#include "Clip.h"


CPPConsole::Clip::Clip(VxSdk::IVxClip* vxClip)
{
    _clip = vxClip;
}


CPPConsole::Clip::~Clip()
{
    _clip->Delete();
    _clip = nullptr;
}
