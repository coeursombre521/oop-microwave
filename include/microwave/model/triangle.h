
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/model/triangle.h
 */

#ifndef __MODEL_TRIANGLE_H_
#define __MODEL_TRIANGLE_H_

#include <gl_common.h>

#include <microwave/app_impl/gl_model.h>
#include <microwave/material/triangle.h>

class TriangleModel :
    public GLModel
{
public:
    TriangleModel(float x1, float y1, float x2, float y2, float x3, float y3);
    virtual ~TriangleModel();

    void init() override;
    void draw() override;

private:
    TriangleMaterial *material__;
};

#endif

/* EOF */
