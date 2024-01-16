
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: material/camera_view.cpp
 */

#include <microwave/material/camera_view.h>

void
CameraViewMaterial::set_model_matrix(const glm::mat4 &model_matrix)
{
    GLint location = get_uniform_location(VERTEX_SHADER_UNIFORM_MODEL);
    if (location != -1) {
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(model_matrix));
    }
}

void
CameraViewMaterial::set_view_matrix(const glm::mat4 &view_matrix)
{
    GLint location = get_uniform_location(VERTEX_SHADER_UNIFORM_VIEW);
    if (location != -1) {
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(view_matrix));
    }
}

void
CameraViewMaterial::set_projection_matrix(const glm::mat4 &projection_matrix)
{
    GLint location = get_uniform_location(VERTEX_SHADER_UNIFORM_PROJECTION);
    if (location != -1) {
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(projection_matrix));
    }
}

/* EOF */
