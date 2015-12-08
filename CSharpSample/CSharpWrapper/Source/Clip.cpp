/// <summary>
/// Implements the clip class.
/// </summary>
#include "Clip.h"

CPPCli::Clip::Clip(VxSdk::IVxClip* vxClip) {
    _clip = vxClip;
}

CPPCli::Clip::!Clip() {
    _clip->Delete();
    _clip = nullptr;
}
