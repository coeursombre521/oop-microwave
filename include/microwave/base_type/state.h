
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * File name: microwave/base_type/state.h
 */

#ifndef __BASE_TYPE_STATE_H_
#define __BASE_TYPE_STATE_H_

#include <string>

#include <microwave/context/state.h>
#include <microwave/context/countdown.h>

class StateContext;

class BaseState
{
public:
    virtual ~BaseState() {}

    void set_context(StateContext *context);

    virtual void purge_state() = 0;

    virtual void open_door() = 0;
    virtual void cook(int) = 0;
    virtual void close_door() = 0;
    virtual int get_countdown() const = 0;

    std::string get_name() const;
    std::string get_description() const;

protected:
    StateContext *context_;
    CountdownContext *countdown_;

    std::string name_;
    std::string description_;
};

#endif

/* EOF */

