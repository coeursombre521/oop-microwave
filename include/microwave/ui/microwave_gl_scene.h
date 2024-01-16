
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/ui/microwave_scene.h
 */

#ifndef __UI_MICROWAVE_SCENE_H_
#define __UI_MICROWAVE_SCENE_H_

#include <stdexcept>

#include <GLFW/glfw3.h>

#include <microwave/model/triangle.h>
#include <microwave/interface/ui.h>
#include <microwave/interface/window.h>

class MicrowaveGLScene :
    public IApplicationUI
{
public:
    MicrowaveGLScene(IWindow *window);
    virtual ~MicrowaveGLScene();

    void render() override;

private:
    GLFWwindow *glfw_window__;
    int display_width__;
    int display_height__;

    TriangleModel *triangle__;
};

#endif

/* EOF */
