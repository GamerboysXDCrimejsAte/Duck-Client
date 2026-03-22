#include "../include/Global.h"
#include "../vendor/imgui/imgui.h"

void RenderDuckGUI() {
    // Stop rendering if GUI is closed and animation is done
    if (DuckClient::guiAnimation <= 0.01f && !DuckClient::showGui) return;

    // Neon Styling
    auto& style = ImGui::GetStyle();
    style.WindowRounding = 12.0f; // Rounded corners like Lunar
    style.WindowBorderSize = 2.0f;
    style.Colors[ImGuiCol_Border] = ImVec4(DuckClient::neonColor[0], DuckClient::neonColor[1], DuckClient::neonColor[2], 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f); // Dark transparent

    // Animation: Slide-up math
    float yOffset = (1.0f - DuckClient::guiAnimation) * 600.0f;

    ImGui::SetNextWindowPos(ImVec2(200, 200 + yOffset), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(450, 400));

    ImGui::Begin("DUCK CLIENT", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    
    ImGui::TextColored(ImVec4(0, 1, 1, 1), "D U C K   C L I E N T | 1.26.3");
    ImGui::Separator();

    // Module Toggles
    ImGui::Checkbox("CPS Counter", &DuckClient::cpsEnabled);
    ImGui::Checkbox("Keystrokes", &DuckClient::keystrokesEnabled);
    ImGui::Checkbox("FPS Counter", &DuckClient::fpsEnabled);

    ImGui::Dummy(ImVec2(0.0f, 10.0f)); // Space
    
    // Customization
    ImGui::Text("Neon Customization:");
    ImGui::ColorEdit3("Glow Color", DuckClient::neonColor);

    if (ImGui::Button("CLOSE", ImVec2(100, 35))) {
        DuckClient::showGui = false;
    }

    ImGui::End();
}
