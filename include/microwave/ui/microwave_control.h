
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/ui/microwave_control.h
 */

#ifndef __UI_MICROWAVE_CONTROL_H_
#define __UI_MICROWAVE_CONTROL_H_

#include <string>
#include <sstream>

#include <microwave/context/clock.h>
#include <microwave/context/countdown.h>
#include <microwave/context/state.h>
#include <microwave/interface/microwave.h>
#include <microwave/interface/observer.h>
#include <microwave/interface/ui.h>

static constexpr int MICROWAVE_DEFAULT_COUNTDOWN = 30;

class MicrowaveControl :
    public IApplicationUI,
    public IMicrowave,
    public IObserver
{
public:
    const float MC_WINDOW_WIDTH = 250.0f;
    const float MC_WINDOW_HEIGHT = 360.0f;
    const float MC_DUMMY_OBJECT_HEIGHT = 10.0f;
    const float MC_STATE_DESCRIPTION_TEXT_HEIGHT = 60.0f;
    const float MC_STATE_DESCRIPTION_WRAP_OFFSET = 10.0f;

    const std::string MC_CONTROL_TITLE = "Microwave control";
    const std::string MC_OPEN_DOOR_BUTTON = "Open door";
    const std::string MC_CLOSE_DOOR_BUTTON = "Close door";
    const std::string MC_COOK_ON_BUTTON = "Start cooking";
    const std::string MC_COOK_OFF_BUTTON = "Stop cooking";
    const std::string MC_STATE_LABEL = "State:";
    const std::string MC_STATE_DESCRIPTION_LABEL = "State description:";

    const ImVec4 MC_TEAL_COLOR = ImVec4(0.0f, 1.0f, 1.0f, 1.0f);
    const ImVec4 MC_RED_COLOR = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    const ImVec4 MC_GREEN_COLOR = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
    const ImVec4 MC_YELLOW_COLOR = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
    const ImVec4 MC_WHITE_COLOR = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

    MicrowaveControl();
    ~MicrowaveControl();

    void render() override;

    void open_door() override;
    void close_door() override;
    void cook_on() override;
    void cook_off() override;

    void update(unsigned int notify_id) override;

private:
    std::string get_countdown_notice() const;

    void draw_state_name(std::string state_name);
    void draw_state_description(std::string state_description);
    void draw_dummy_object();
    void draw_countdown();
    void draw_buttons();

    ClockContext* clock_context__;
    StateContext* state_context__;
    CountdownContext* microwave_countdown__;

    std::string state_name__;
    std::string state_description__;
    long double elapsed_time__ = 0.0;
    long double last_elapsed_time = 0.0;
    int countdown__ = 0;
    bool countdown_running__ = false;
};

#endif

/* EOF */

