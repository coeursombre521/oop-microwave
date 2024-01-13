
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: state/cooking.cpp
 */

#include <microwave/context/countdown.h>
#include <microwave/debug/logger.h>
#include <microwave/state/cooking.h>
#include <microwave/state/door_closed.h>
#include <microwave/state/door_opened.h>

StateCooking::StateCooking() : BaseState()
{
    countdown_ = CountdownContext::get_instance();
    name_ = "StateCooking";
    description_ = "The microwave is cooking mancarica.";
}

void
StateCooking::purge_state()
{
    if (CountdownContext::is_alive()) {
        CountdownContext::destroy_instance();
    }
    destroy_instance();
}

void
StateCooking::open_door()
{
    Logger::log("StateCooking", "Your mancarica finished cooking");
    context_->transition_to(StateDoorOpened::get_instance());
    countdown_->stop();
}

void
StateCooking::cook(int microwave_time)
{
    Logger::log("StateCooking", "The microwave is cooking mancarica. Cooking MORE!!!");
    countdown_->add_time(microwave_time);
}

void
StateCooking::close_door()
{
    Logger::log("StateCooking", "The door is already closed because the microwave is cooking");
}

int
StateCooking::get_countdown() const
{
    return countdown_->get_time();
}

/* EOF */

