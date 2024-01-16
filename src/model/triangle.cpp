
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: model/triangle.cpp
 */

#include <microwave/model/triangle.h>

TriangleModel::TriangleModel(float x1, float y1, float x2, float y2, float x3, float y3) : GLModel()
{
    vertices = {
        x1, y1, 0.0f,
        x2, y2, 0.0f,
        x3, y3, 0.0f
    };

    indices = {
        0, 1, 2
    };
}

void
TriangleModel::draw()
{
    material__.use();
    glBindVertexArray(vao__);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

/* EOF */
