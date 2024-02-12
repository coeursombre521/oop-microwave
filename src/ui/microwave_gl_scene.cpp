
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: ui/microwave_scene.cpp
 */

#include <microwave/debug/logger.h>
#include <microwave/entity/gl_window.h>
#include <microwave/ui/microwave_gl_scene.h>

MicrowaveGLScene::MicrowaveGLScene(IWindow *window) :
    display_width__(window->get_window_width()),
    display_height__(window->get_window_height())
{
    GLWindow *gl_window = dynamic_cast<GLWindow *>(window); // bruh
    if (gl_window == nullptr) {
        throw std::runtime_error("Failed to cast IWindow to GLWindow");
    }
    glfw_window__ = gl_window->get_glfw_window();
}

MicrowaveGLScene::~MicrowaveGLScene()
{
    glfw_window__ = nullptr;
}

void
MicrowaveGLScene::render()
{
    glfwGetFramebufferSize(glfw_window__, &display_width__, &display_height__);
    glViewport(0, 0, display_width__, display_height__);
    glClearColor(0.0, 0.067, 0.239, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/* EOF */
