
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

    camera__ = new GLCamera();

    camera_view__ = new CameraViewMaterial();
    camera_view__->set_vertex_shader_source(CAMERA_VIEW_VERTEX_SHADER_PATH);
    camera_view__->init();
    camera_view__->compile();

    triangle__ = new TriangleModel(-0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f);
    triangle__->init();
}

MicrowaveGLScene::~MicrowaveGLScene()
{
    glfw_window__ = nullptr;
}

void
MicrowaveGLScene::render()
{
    // set position of camera to be a bit behind the triangle
    camera__->set_position(glm::vec3(0.0f, 0.0f, 2.0f + sin(glfwGetTime()) * 2.0f));
    camera__->set_pitch(10.0f + sin(glfwGetTime()) * 30.0f);

    camera_view__->use();
    camera_view__->set_model_matrix(glm::mat4(1.0f));
    camera_view__->set_view_matrix(camera__->get_view_matrix());
    camera_view__->set_projection_matrix(glm::perspective(glm::radians(45.0f), (float)display_width__ / (float)display_height__, 0.1f, 100.0f));

    glfwGetFramebufferSize(glfw_window__, &display_width__, &display_height__);
    glViewport(0, 0, display_width__, display_height__);
    glClearColor(0.0, 0.067, 0.239, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    triangle__->draw();

}

/* EOF */
