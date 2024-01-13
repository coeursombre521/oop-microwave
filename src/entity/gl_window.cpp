
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: entity/gl_window.cpp
 */

#include <microwave/entity/gl_window.h>

GLWindow::GLWindow(GLFWwindow *window, const std::string &title, int width, int height)
    : glfw_window__(nullptr)
    , title__(title)
    , width__(width)
    , height__(height)
{
    glfw_window__ = window;
}

GLWindow::~GLWindow()
{
    glfw_window__ = nullptr;
}

void
GLWindow::set_window_title(const std::string &title)
{
    title__ = title;
    if (glfw_window__ != nullptr) {
        glfwSetWindowTitle(glfw_window__, title__.c_str());
    }
}

void
GLWindow::set_window_width(int w)
{
    width__ = w;
    if (glfw_window__ != nullptr) {
        glfwSetWindowSize(glfw_window__, width__, height__);
    }
}

void
GLWindow::set_window_height(int h)
{
    height__ = h;
    if (glfw_window__ != nullptr) {
        glfwSetWindowSize(glfw_window__, width__, height__);
    }
}

std::string
GLWindow::get_window_title() const
{
    return title__;
}

int
GLWindow::get_window_width() const
{
    return width__;
}

int
GLWindow::get_window_height() const
{
    return height__;
}

GLFWwindow *
GLWindow::get_glfw_window() const
{
    return glfw_window__;
}

void
GLWindow::set_glfw_window(GLFWwindow *glfw_window)
{
    glfw_window__ = glfw_window;
}

/* EOF */
