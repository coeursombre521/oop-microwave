
#include <iostream>

#include <imgui.h>
#include <microwave_ui.h>

void
MicrowaveUI::render_ui()
{
    if (ImGui::Begin("Control cuptor cu microunde")) {
        ImGui::SetWindowSize(ImVec2(250, 300));

        ImGui::TextColored(ImVec4(0.0f, 1.0f, 1.0f, 1.0f), "State:");
        ImGui::Text("%s", this->context__->get_state_short_name().c_str());

        ImGui::Dummy(ImVec2(0.0f, 10.0f));

        ImGui::TextColored(ImVec4(0.0f, 1.0f, 1.0f, 1.0f), "State description:");

        ImVec2 description_size = ImVec2(ImGui::GetWindowWidth() - 10.0f, 40.0f);
        const std::string description = this->context__->get_state_description();

        ImGui::PushTextWrapPos(ImGui::GetCursorPos().x + description_size.x);
        ImGui::Text("%s", description.c_str());
        ImGui::PopTextWrapPos();

        ImGui::Dummy(ImVec2(0.0f, description_size.y - ImGui::CalcTextSize(description.c_str(), NULL, true, description_size.x).y));

        if (ImGui::Button("Open door", ImVec2(-1.0f, 0.0f))) {
            this->open_door();
        }

        if (ImGui::Button("Close door", ImVec2(-1.0f, 0.0f))) {
            this->close_door();
        }

        if (ImGui::Button("Cook mancarica", ImVec2(-1.0f, 0.0f))) {
            this->cook_on();
        }

        if (ImGui::Button("Stop cooking", ImVec2(-1.0f, 0.0f))) {
            this->cook_off();
        }
    }
    ImGui::End();

}

void
MicrowaveUI::open_door()
{
    this->context__->open_door();
}

void
MicrowaveUI::close_door()
{
    this->context__->close_door();
}

void
MicrowaveUI::cook_on()
{
    this->context__->cook();
}

void
MicrowaveUI::cook_off()
{
    this->context__->close_door();
}

long double
MicrowaveUI::get_ticks()
{
    return this->context__->get_ticks();
}
