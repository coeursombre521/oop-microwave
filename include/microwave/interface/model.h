
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/interface/model.h
 */

#ifndef __INTERFACE_MODEL_H_
#define __INTERFACE_MODEL_H_

class IModel
{
public:
    virtual ~IModel() = default;
    virtual void init() = 0;
    virtual void draw() = 0;
};

#endif

/* EOF */
