
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: base_type/state.cpp
 */

#include <microwave/base_type/state.h>

void
BaseState::set_context(StateContext *context)
{
    context_ = context;
}

std::string
BaseState::get_name() const
{
    return name_;
}

std::string
BaseState::get_description() const
{
    return description_;
}

/* EOF */

