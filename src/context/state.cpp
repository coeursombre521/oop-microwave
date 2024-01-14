
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: context/state.cpp
 */

#include <typeinfo>

#include <microwave/debug/logger.h>
#include <microwave/context/state.h>
#include <microwave/state/cooking.h>
#include <microwave/state/door_closed.h>
#include <microwave/state/door_opened.h>

StateContext::StateContext()
{
    countdown_context__ = CountdownContext::get_instance();
    countdown_context__->register_observer(this);
}

StateContext::~StateContext() {
    countdown_context__->unregister_observer(this);

    purge_state();
    observers__.clear();

    if (CountdownContext::is_alive()) {
        CountdownContext::destroy_instance();
        countdown_context__ = nullptr;
    }
    if (StateCooking::is_alive()) {
        StateCooking::destroy_instance();
    }
    if (StateDoorClosed::is_alive()) {
        StateDoorClosed::destroy_instance();
    }
    if (StateDoorOpened::is_alive()) {
        StateDoorOpened::destroy_instance();
    }
}

void
StateContext::transition_to(BaseState *state)
{
    if (state__ != nullptr) {
        state__ = nullptr;
    }
    state__ = state;
    state__->set_context(this);
    notify_observers();

    Logger::log("StateContext", "Application transitioned to BaseState object of type %s", typeid(*state).name());
}

void
StateContext::purge_state()
{
    if (state__ == nullptr) {
        return;
    }

    Logger::log("StateContext", "Purging BaseState object of type %s", typeid(*state__).name());

    state__->purge_state();
    state__ = nullptr;
}

void
StateContext::open_door()
{
    state__->open_door();
}

void
StateContext::close_door()
{
    state__->close_door();
}

void
StateContext::cook(int microwave_time)
{
    state__->cook(microwave_time);
}

int
StateContext::get_countdown() const
{
    return state__->get_countdown();
}

void
StateContext::register_observer(IObserver *observer)
{
    observers__.insert(observer);
}

void
StateContext::unregister_observer(IObserver *observer)
{
    auto it = observers__.find(observer);
    if (it != observers__.end()) {
        observers__.erase(observer);
    }
}

void
StateContext::notify_observers()
{
    for (IObserver *observer : observers__) {
        observer->update(STATE_CONTEXT_NOTIFY_ID);
    }
}

void
StateContext::update(unsigned int notify_id)
{
    switch (notify_id)
    {
        case MICROWAVE_COUNTDOWN_NOTIFY_ID:
            if (state__->get_countdown() == 0 && state__->get_name() == "StateCooking") {
                open_door();
            }
            break;
    }
}

std::string
StateContext::get_state_name() const
{
    return state__->get_name();
}

std::string
StateContext::get_state_description() const
{
    return state__->get_description();
}

/* EOF */

