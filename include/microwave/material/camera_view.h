
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/material/camera_view.h
 */

#ifndef __MATERIAL_CAMERA_VIEW_H_
#define __MATERIAL_CAMERA_VIEW_H_

#include <gl_common.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <microwave/app_impl/gl_material.h>

class CameraViewMaterial :
    public GLMaterial
{
public:
    const std::string VERTEX_SHADER_UNIFORM_MODEL = "model";
    const std::string VERTEX_SHADER_UNIFORM_VIEW = "view";
    const std::string VERTEX_SHADER_UNIFORM_PROJECTION = "projection";

    void set_model_matrix(const glm::mat4 &model_matrix);
    void set_view_matrix(const glm::mat4 &view_matrix);
    void set_projection_matrix(const glm::mat4 &projection_matrix);
};

#endif

/* EOF */
