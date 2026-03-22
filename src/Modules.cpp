#include "../include/Global.h"
#include <chrono>
#include <algorithm>

std::vector<long long> clickTicks;

// Clicks Per Second Math
int GetCPS() {
    long long now = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    
    // Remove clicks older than 1 second (1000ms)
    clickTicks.erase(std::remove_if(clickTicks.begin(), clickTicks.end(),
        [now](long long t) { return now - t > 1000; }), clickTicks.end());
        
    return (int)clickTicks.size();
}

// Key Detection (For Keystrokes Module)
bool IsKeyDown(int vKey) {
    return (GetAsyncKeyState(vKey) & 0x8000);
}
