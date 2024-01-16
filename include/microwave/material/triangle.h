
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/model/triangle.h
 */

#ifndef __MATERIAL_TRIANGLE_H_
#define __MATERIAL_TRIANGLE_H_

#include <gl_common.h>

#include <microwave/app_impl/gl_material.h>

class TriangleMaterial :
    public GLMaterial
{
public:
    void set_custom_color(double r, double g, double b, double a);
};

#endif

/* EOF */
