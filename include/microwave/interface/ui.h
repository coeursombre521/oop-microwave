
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/interface/ui.h
 */

#ifndef __INTERFACE_UI_H_
#define __INTERFACE_UI_H_

class IApplicationUI
{
public:
    virtual ~IApplicationUI() = default;
    virtual void render() = 0;
};

#endif

/* EOF */

