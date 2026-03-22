#include "../include/Global.h"

void DuckClientMainLoop() {
    while (true) {
        // Toggle GUI with Right Shift
        if (GetAsyncKeyState(VK_RSHIFT) & 1) {
            DuckClient::showGui = !DuckClient::showGui;
        }

        // Smooth Animation Logic (0.0 to 1.0)
        if (DuckClient::showGui && DuckClient::guiAnimation < 1.0f) {
            DuckClient::guiAnimation += 0.08f; // Speed of opening
        } 
        else if (!DuckClient::showGui && DuckClient::guiAnimation > 0.0f) {
            DuckClient::guiAnimation -= 0.08f; // Speed of closing
        }

        Sleep(10); // Keep CPU usage low
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DuckClientMainLoop, 0, 0, 0);
    }
    return TRUE;
}
