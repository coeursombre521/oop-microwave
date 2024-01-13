
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * File name: ui/microwave_control.cpp
 */

#include <iostream>

#include <imgui/imgui.h>
#include <microwave/ui/microwave_control.h>
#include <microwave/state/door_closed.h>

MicrowaveControl::MicrowaveControl() {
    clock_context__ = ClockContext::get_instance();
    clock_context__->register_observer(this);
    clock_context__->reset_time();
    clock_context__->start_time();

    state_context__ = StateContext::get_instance();
    state_context__->transition_to(StateDoorClosed::get_instance());
    state_context__->register_observer(this);

    microwave_countdown__ = CountdownContext::get_instance();
    microwave_countdown__->register_observer(this);

    state_name__ = state_context__->get_state_name();
    state_description__ = state_context__->get_state_description();
}

MicrowaveControl::~MicrowaveControl() {
    microwave_countdown__->unregister_observer(this);
    state_context__->unregister_observer(this);
    state_context__->destroy_instance();
    state_context__ = nullptr;
    microwave_countdown__->destroy_instance();
    microwave_countdown__ = nullptr;

    clock_context__->stop_time();
    clock_context__->unregister_observer(this);
    clock_context__->destroy_instance();
    clock_context__ = nullptr;
}

void
MicrowaveControl::render()
{
    if (ImGui::Begin("Microwave control")) {
        ImGui::SetWindowSize(ImVec2(250, 300));

        ImGui::TextColored(ImVec4(0.0f, 1.0f, 1.0f, 1.0f), "State:");
        ImGui::Text("%s", state_name__.c_str());

        ImGui::Dummy(ImVec2(0.0f, 10.0f));

        ImGui::TextColored(ImVec4(0.0f, 1.0f, 1.0f, 1.0f), "State description:");

        ImVec2 description_size = ImVec2(ImGui::GetWindowWidth() - 10.0f, 40.0f);
        const std::string description = state_description__;

        ImGui::PushTextWrapPos(ImGui::GetCursorPos().x + description_size.x);
        ImGui::Text("%s", description.c_str());
        ImGui::PopTextWrapPos();

        ImGui::Dummy(ImVec2(0.0f, description_size.y - ImGui::CalcTextSize(description.c_str(), NULL, true, description_size.x).y));

        if (ImGui::Button("Open door", ImVec2(-1.0f, 0.0f))) {
            open_door();
        }

        if (ImGui::Button("Close door", ImVec2(-1.0f, 0.0f))) {
            close_door();
        }

        if (ImGui::Button("Cook mancarica", ImVec2(-1.0f, 0.0f))) {
            cook_on();
        }

        if (ImGui::Button("Stop cooking", ImVec2(-1.0f, 0.0f))) {
            cook_off();
        }

        ImGui::Dummy(ImVec2(0.0f, 10.0f));

        if (countdown_running__) {
            ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), get_countdown_notice().c_str());
        }
        else {
            ImGui::Text("%s", get_countdown_notice().c_str());
        }
    }
    ImGui::End();
}

void
MicrowaveControl::open_door()
{
    state_context__->open_door();
}

void
MicrowaveControl::close_door()
{
    state_context__->close_door();
}

void
MicrowaveControl::cook_on()
{
    if (!countdown_running__) {
        last_elapsed_time = elapsed_time__;
    }
    state_context__->cook();
}

void
MicrowaveControl::cook_off()
{
    state_context__->open_door();
}

void
MicrowaveControl::update(unsigned int notify_id)
{
    switch (notify_id)
    {
        case CLOCK_CONTEXT_NOTIFY_ID:
            elapsed_time__ = clock_context__->get_elapsed_time();
            if (elapsed_time__ - last_elapsed_time >= 1.0) {
                last_elapsed_time = elapsed_time__;
                microwave_countdown__->update();
            }
            break;
        case STATE_CONTEXT_NOTIFY_ID:
            state_name__ = state_context__->get_state_name();
            state_description__ = state_context__->get_state_description();
            break;
        case MICROWAVE_COUNTDOWN_NOTIFY_ID:
            countdown__ = microwave_countdown__->get_time();
            countdown_running__ = microwave_countdown__->is_running();
            break;
        default:
            break;
    }
}

std::string
MicrowaveControl::get_countdown_notice() const
{
    std::stringstream ss;
    ss << "Countdown is " << countdown__ << ". ";
    if (countdown_running__) {
        ss << "Cooking!";
    }
    else {
        ss << "Not cooking yet.";
    }
    return ss.str();
}

/* EOF */

