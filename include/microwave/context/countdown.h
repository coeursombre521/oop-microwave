
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/context/countdown.h
 */

#ifndef __CONTEXT_COUNTDOWN_H_
#define __CONTEXT_COUNTDOWN_H_

#include <unordered_set>

#include <microwave/base_type/singleton.h>
#include <microwave/debug/logger.h>
#include <microwave/interface/observable.h>
#include <microwave/interface/observer.h>

static constexpr unsigned int MICROWAVE_COUNTDOWN_NOTIFY_ID = 3;

class CountdownContext :
    public BaseSingleton<CountdownContext>,
    public IObservable
{
public:
    void start(int time = 30);
    void stop();
    void reset();
    void add_time(int time = 30);
    void update();

    void register_observer(IObserver* observer) override;
    void unregister_observer(IObserver* observer) override;
    void notify_observers() override;

    int get_time() const;
    bool is_running() const;

    void set_time(int time);
    void set_running(bool running);

protected:
    CountdownContext() { }
    virtual ~CountdownContext();

private:
    std::unordered_set<IObserver *> observers__;
    bool running__ = false;
    bool previous_running__ = false;
    int time__ = 0;
    int previous_time__ = 0;

    void notify_observers_if_anything_changed();

    friend class BaseSingleton<CountdownContext>;
};

#endif

/* EOF */

