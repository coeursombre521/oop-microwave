
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * File name: microwave/entity/clock.h
 */

#ifndef __ENTITY_CLOCK_H_
#define __ENTITY_CLOCK_H_

#include <chrono>
#include <unordered_set>

#include <microwave/base_type/singleton.h>
#include <microwave/interface/observable.h>
#include <microwave/interface/observer.h>

class Clock
{
public:
    using clock = std::chrono::steady_clock;
    using time_point = std::chrono::time_point<clock>;
    using duration = std::chrono::duration<long double>;

    Clock();

    void start();
    void update();
    void stop();
    void reset();

    bool running() const;
    long double elapsed_time();

private:
    time_point start_time__;
    time_point end_time__;
    bool running__ = false;
};

#endif

/* EOF */

