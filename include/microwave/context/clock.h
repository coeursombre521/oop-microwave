
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * File name: microwave/context/clock.h
 */

#ifndef __CONTEXT_CLOCK_H_
#define __CONTEXT_CLOCK_H_

#include <string>
#include <memory>
#include <unordered_set>

#include <microwave/base_type/singleton.h>
#include <microwave/entity/clock.h>
#include <microwave/interface/observable.h>
#include <microwave/interface/observer.h>

static constexpr unsigned int CLOCK_CONTEXT_NOTIFY_ID = 1;

class ClockContext :
    public BaseSingleton<ClockContext>,
    public IObservable
{
public:
    void start_time();
    void stop_time();
    void reset_time();
    void update_time();

    void register_observer(IObserver *observer) override;
    void unregister_observer(IObserver *observer) override;
    void notify_observers() override;

    long double get_elapsed_time() const;

protected:
    ClockContext();
    ~ClockContext();

private:
    std::unordered_set<IObserver *> observers__;
    std::unique_ptr<Clock> clock__;

    friend class BaseSingleton<ClockContext>;
};

#endif

/* EOF */

