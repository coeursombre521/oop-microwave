
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: context/countdown.cpp
 */

#include <microwave/context/countdown.h>

CountdownContext::~CountdownContext()
{
    reset();
    Logger::log("CountdownContext", "CountdownContext object destroyed");
    observers__.clear();
}

void
CountdownContext::start(int time)
{
    running__ = true;
    if (time >= 0) {
        time__ = time;
    }
    Logger::log("CountdownContext", "CountdownContext started with time %d", time);
    notify_observers_if_anything_changed();
}

void
CountdownContext::stop()
{
    running__ = false;
    Logger::log("CountdownContext", "CountdownContext stopped");
    notify_observers_if_anything_changed();
}

void
CountdownContext::reset()
{
    running__ = false;
    time__ = 0;
    Logger::log("CountdownContext", "CountdownContext reset");
    notify_observers_if_anything_changed();
}

void
CountdownContext::add_time(int time)
{
    time__ += time;
    Logger::log("CountdownContext", "CountdownContext time increased by %d", time);
    notify_observers_if_anything_changed();
}

void
CountdownContext::update()
{
    if (running__ && time__ > 0) {
        time__--;
        if (time__ == 0) {
            running__ = false;
        }
        Logger::log("CountdownContext", "Countdown time is now %d", time__);
        notify_observers_if_anything_changed();
    }
}

void
CountdownContext::register_observer(IObserver* observer)
{
    observers__.insert(observer);
}

void
CountdownContext::unregister_observer(IObserver* observer)
{
    auto it = observers__.find(observer);
    if (it != observers__.end()) {
        observers__.erase(observer);
    }
}

void
CountdownContext::notify_observers()
{
    for (auto observer : observers__) {
        observer->update(MICROWAVE_COUNTDOWN_NOTIFY_ID);
    }
}

int
CountdownContext::get_time() const
{
    return time__;
}

bool
CountdownContext::is_running() const
{
    return running__;
}

void
CountdownContext::set_time(int time)
{
    time__ = time;
    notify_observers_if_anything_changed();
}

void
CountdownContext::set_running(bool running)
{
    running__ = running;
    notify_observers_if_anything_changed();
}

void
CountdownContext::notify_observers_if_anything_changed()
{
    if (running__ != previous_running__) {
        previous_running__ = running__;
        notify_observers();
    }

    if (time__ != previous_time__) {
        previous_time__ = time__;
        notify_observers();
    }
}

/* EOF */

