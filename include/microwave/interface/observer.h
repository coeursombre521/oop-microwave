
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/interface/observer.h
 */

#ifndef __INTERFACE_OBSERVER_H__
#define __INTERFACE_OBSERVER_H__

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void update(unsigned int notify_id) = 0;
};

#endif

/* EOF */

