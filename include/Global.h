#pragma once
#include <windows.h>
#include <vector>
#include <string>

namespace DuckClient {
    // GUI States
    inline bool showGui = false;
    inline float guiAnimation = 0.0f; // 0.0 to 1.0 for the slide effect

    // PVP Module Toggles
    inline bool cpsEnabled = true;
    inline bool fpsEnabled = true;
    inline bool keystrokesEnabled = true;

    // Visual Customization (Neon Cyan)
    inline float neonColor[3] = { 0.0f, 1.0f, 1.0f }; 
}
