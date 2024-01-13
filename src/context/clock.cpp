
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * File name: context/clock.cpp
 */

#include <microwave/context/clock.h>
#include <microwave/debug/logger.h>

ClockContext::ClockContext()
{
    clock__ = std::make_unique<Clock>();
}

ClockContext::~ClockContext() {
    clock__.reset();
    observers__.clear();
}

void
ClockContext::start_time()
{
    clock__->start();
    notify_observers();
}

void
ClockContext::stop_time()
{
    clock__->stop();
    notify_observers();
}

void
ClockContext::reset_time()
{
    clock__->reset();
    notify_observers();
}

void
ClockContext::update_time()
{
    clock__->update();
    notify_observers();
}

void
ClockContext::register_observer(IObserver *observer)
{
    observers__.insert(observer);
}

void
ClockContext::unregister_observer(IObserver *observer)
{
    auto it = observers__.find(observer);
    if (it != observers__.end()) {
        observers__.erase(observer);
    }
}

void
ClockContext::notify_observers()
{
    for (IObserver *observer : observers__) {
        observer->update(CLOCK_CONTEXT_NOTIFY_ID);
    }
}

long double
ClockContext::get_elapsed_time() const
{
    return clock__->elapsed_time();
}

/* EOF */

