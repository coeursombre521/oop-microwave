
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/context/state.h
 */

#ifndef __CONTEXT_STATE_H_
#define __CONTEXT_STATE_H_

#include <string>
#include <unordered_set>

#include <microwave/base_type/state.h>
#include <microwave/base_type/singleton.h>
#include <microwave/interface/observable.h>
#include <microwave/interface/observer.h>
#include <microwave/context/countdown.h>

static constexpr unsigned int STATE_CONTEXT_NOTIFY_ID = 2;

class BaseState;

class StateContext :
    public BaseSingleton<StateContext>,
    public IObservable,
    public IObserver
{
public:
    void transition_to(BaseState *state);
    void purge_state();

    void open_door();
    void cook(int microwave_time = 30);
    void close_door();
    int get_countdown() const;

    void register_observer(IObserver *observer) override;
    void unregister_observer(IObserver *observer) override;
    void notify_observers() override;

    void update(unsigned int notify_id) override;

    std::string get_state_name() const;
    std::string get_state_description() const;

protected:
    StateContext();
    virtual ~StateContext();

private:
    BaseState *state__ = nullptr;
    CountdownContext *countdown_context__ = nullptr;
    std::unordered_set<IObserver *> observers__;

    friend class BaseSingleton<StateContext>;
};

#endif

/* EOF */

