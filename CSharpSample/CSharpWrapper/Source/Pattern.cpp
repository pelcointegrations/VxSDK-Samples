/// <summary>
/// Implements the pattern class.
/// </summary>
#include "Pattern.h"

CPPCli::Pattern::Pattern(VxSdk::IVxPattern* vxPattern) {
    _pattern = vxPattern;
}

CPPCli::Pattern::!Pattern() {
    _pattern->Delete();
    _pattern = nullptr;
}
