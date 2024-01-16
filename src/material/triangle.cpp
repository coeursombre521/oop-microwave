
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: model/triangle.cpp
 */

#include <microwave/debug/logger.h>
#include <microwave/material/triangle.h>

void
TriangleMaterial::set_custom_color(double r, double g, double b, double a)
{
    GLint color_location = glGetUniformLocation(program__, "custom_color");
    if (color_location == -1) {
        Logger::log("TriangleMaterial", "Failed to get uniform location for custom_color");
        return;
    }

    glUniform4f(color_location, r, g, b, a);
}

/* EOF */
