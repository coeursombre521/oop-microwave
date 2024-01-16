
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/ui/microwave_scene.h
 */

#ifndef __UI_MICROWAVE_SCENE_H_
#define __UI_MICROWAVE_SCENE_H_

#include <stdexcept>

#include <gl_common.h>

#include <microwave/app_impl/gl_camera.h>
#include <microwave/material/camera_view.h>
#include <microwave/model/triangle.h>
#include <microwave/interface/ui.h>
#include <microwave/interface/window.h>

class MicrowaveGLScene :
    public IApplicationUI
{
public:
    const std::string CAMERA_VIEW_VERTEX_SHADER_PATH = "assets/world/camera.vs";

    MicrowaveGLScene(IWindow *window);
    virtual ~MicrowaveGLScene();

    void render() override;

private:
    GLFWwindow *glfw_window__;
    int display_width__;
    int display_height__;

    GLCamera *camera__;
    CameraViewMaterial *camera_view__;
    TriangleModel *triangle__;
};

#endif

/* EOF */
