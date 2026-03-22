#pragma once
#include <vector>

// Functions for your PVP modules
int getCPS();
void updateKeystrokes();

// Struct for the Neon GUI colors
struct NeonTheme {
    float mainColor[3] = { 0.0f, 1.0f, 1.0f }; // Neon Cyan
    float accentColor[3] = { 1.0f, 0.0f, 1.0f }; // Pink accent
};
