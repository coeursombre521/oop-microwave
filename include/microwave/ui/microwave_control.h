
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

