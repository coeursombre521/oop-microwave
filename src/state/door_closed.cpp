
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: state/door_closed.cpp
 */

#include <microwave/context/countdown.h>
#include <microwave/debug/logger.h>
#include <microwave/state/cooking.h>
#include <microwave/state/door_closed.h>
#include <microwave/state/door_opened.h>

StateDoorClosed::StateDoorClosed() : BaseState()
{
    countdown_ = CountdownContext::get_instance();
    name_ = "StateDoorClosed";
    description_ = "The microwave door is closed.";
}

void
StateDoorClosed::purge_state()
{
    if (CountdownContext::is_alive()) {
        CountdownContext::destroy_instance();
    }
    destroy_instance();
}

void
StateDoorClosed::open_door()
{
    Logger::log("StateDoorClosed", "Opening door");
    context_->transition_to(StateDoorOpened::get_instance());
}

void
StateDoorClosed::cook(int microwave_time)
{
    Logger::log("StateDoorClosed", "Cooking your mancarica");
    context_->transition_to(StateCooking::get_instance());
    if (countdown_->get_time() > 0) {
        countdown_->start(-1);
    }
    else {
        countdown_->start(microwave_time);
    }
}

void
StateDoorClosed::close_door()
{
    Logger::log("StateDoorClosed", "The door is closed already");
}

int
StateDoorClosed::get_countdown() const
{
    return countdown_->get_time();
}

/* EOF */

