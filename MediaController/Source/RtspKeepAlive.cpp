#include "stdafx.h"
#include "RtspKeepAlive.h"
#include <thread>
#include <atomic>

struct MediaController::Rtsp::KeepAlive::ThreadInfo {
    std::thread _keepAliveThread;
    std::atomic<bool> _shutdownRequested;
};

MediaController::Rtsp::KeepAlive::KeepAlive(Commands* commands) : _commands(commands), d_ptr(new ThreadInfo()) {
    d_ptr->_shutdownRequested = false;
    d_ptr->_keepAliveThread = std::thread(&KeepAlive::GetParamsLoop, this);
}

MediaController::Rtsp::KeepAlive::~KeepAlive() {
    d_ptr->_shutdownRequested = true;
    d_ptr->_keepAliveThread.join();
}

void MediaController::Rtsp::KeepAlive::GetParamsLoop() {
    int _count = 0;
    while (!d_ptr->_shutdownRequested) {
        if (_count < Constants::kKeepAliveRefreshSec) {
            ++_count;
        }
        else {
            _commands->GetParameter();
            _count = 0;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
