
#include <iostream>

#include <imgui.h>
#include <microwave_ui.h>

MicrowaveUI::MicrowaveUI() {
    this->clock_context__ = ClockContext::get_instance();
    this->clock_context__->register_observer(this);
    this->clock_context__->reset_time();
    this->clock_context__->start_time();

    this->state_context__ = StateContext::get_instance();
    this->state_context__->transition_to(StateDoorClosed::get_instance());
    this->state_context__->register_observer(this);

    this->state_name__ = this->state_context__->get_state_name();
    this->state_description__ = this->state_context__->get_state_description();
}

MicrowaveUI::~MicrowaveUI() {
    this->state_context__->unregister_observer(this);
    this->state_context__->destroy_instance();
    this->state_context__ = nullptr;

    this->clock_context__->stop_time();
    this->clock_context__->unregister_observer(this);
    this->clock_context__->destroy_instance();
    this->clock_context__ = nullptr;
}

void
MicrowaveUI::render_ui()
{
    if (ImGui::Begin("Control cuptor cu microunde")) {
        ImGui::SetWindowSize(ImVec2(250, 300));

        ImGui::TextColored(ImVec4(0.0f, 1.0f, 1.0f, 1.0f), "State:");
        ImGui::Text("%s", this->state_name__.c_str());

        ImGui::Dummy(ImVec2(0.0f, 10.0f));

        ImGui::TextColored(ImVec4(0.0f, 1.0f, 1.0f, 1.0f), "State description:");

        ImVec2 description_size = ImVec2(ImGui::GetWindowWidth() - 10.0f, 40.0f);
        const std::string description = this->state_description__;

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

        ImGui::Text("Elapsed time: %Lf", this->elapsed_time__);
    }
    ImGui::End();

    this->clock_context__->update_time();
}

void
MicrowaveUI::open_door()
{
    this->state_context__->open_door();
}

void
MicrowaveUI::close_door()
{
    this->state_context__->close_door();
}

void
MicrowaveUI::cook_on()
{
    this->state_context__->cook();
}

void
MicrowaveUI::cook_off()
{
    this->state_context__->open_door();
}

void
MicrowaveUI::update(unsigned int notify_id)
{
    switch (notify_id)
    {
        case CLOCK_CONTEXT_NOTIFY_ID:
            this->elapsed_time__ = this->clock_context__->get_elapsed_time();
            break;
        case STATE_CONTEXT_NOTIFY_ID:
            this->state_name__ = this->state_context__->get_state_name();
            this->state_description__ = this->state_context__->get_state_description();
            break;
        default:
            break;
    }
}
