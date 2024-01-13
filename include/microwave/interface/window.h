
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/interface/window.h
 */

#ifndef __INTERFACE_WINDOW_H_
#define __INTERFACE_WINDOW_H_

#include <string>

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual void set_window_title(const std::string &title) = 0;
    virtual void set_window_width(int w) = 0;
    virtual void set_window_height(int h) = 0;

    virtual std::string get_window_title() const = 0;
    virtual int get_window_width() const = 0;
    virtual int get_window_height() const = 0;
};

#endif

/* EOF */
