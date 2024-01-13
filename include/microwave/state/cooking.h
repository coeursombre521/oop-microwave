
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/state/cooking.h
 */

#ifndef __STATE_COOKING_H_
#define __STATE_COOKING_H_

#include <microwave/base_type/state.h>
#include <microwave/base_type/singleton.h>

class StateCooking :
    public BaseSingleton<StateCooking>,
    public BaseState
{
public:
    void purge_state() override;
    void open_door() override;
    void cook(int microwave_time = 30) override;
    void close_door() override;
    int get_countdown() const override;

protected:
    StateCooking();

    friend class BaseSingleton<StateCooking>;
};

#endif

/* EOF */

