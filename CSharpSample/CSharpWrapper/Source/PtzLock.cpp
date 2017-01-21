/// <summary>
/// Implements the ptz lock class.
/// </summary>
#include "PtzLock.h"

CPPCli::PtzLock::PtzLock(VxSdk::IVxPtzLock* vxPtzLock) {
    _ptzLock = vxPtzLock;
}

CPPCli::PtzLock::!PtzLock() {
    _ptzLock->Delete();
    _ptzLock = nullptr;
}

CPPCli::Results::Value CPPCli::PtzLock::Lock(int expireTime) {
    // Call Lock and return the result
    VxSdk::VxResult::Value result = _ptzLock->Lock(expireTime);
    return CPPCli::Results::Value(result);
}

CPPCli::Results::Value CPPCli::PtzLock::Refresh() {
    return (CPPCli::Results::Value)_ptzLock->Refresh();
}

CPPCli::Results::Value CPPCli::PtzLock::Unlock() {
    // Call Unlock and return the result
    VxSdk::VxResult::Value result = _ptzLock->Unlock();
    return CPPCli::Results::Value(result);
}

int CPPCli::PtzLock::_GetExpireTime() {
    // Get and return the expire time
    int expireTime;
    _ptzLock->GetExpireTime(expireTime);
    return expireTime;
}

bool CPPCli::PtzLock::_GetLockState() {
    // Get and return the current lock state
    bool lockStatus;
    _ptzLock->GetLockState(lockStatus);
    return lockStatus;
}

System::String^ CPPCli::PtzLock::_GetOwner() {
    char* owner = nullptr;
    int size = 0;

    // The owner can be empty if the ptz controller is not currently locked. If that is the case then the result
    // returned will be VxSdk::VxResult::kOk and owner will remain a nullptr. Otherwise the return is
    // VxSdk::VxResult::kInsufficientSize
    VxSdk::VxResult::Value result = _ptzLock->GetOwner(owner, size);
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // Allocate enough space for owner
        owner = new char[size];
        // The result should now be kOK since we have allocated enough space
        _ptzLock->GetOwner(owner, size);
    }
    return gcnew System::String(owner);
}
