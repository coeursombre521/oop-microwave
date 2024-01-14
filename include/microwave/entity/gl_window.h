
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/entity/gl_window.h
 */

#ifndef __ENTITY_GL_WINDOW_H_
#define __ENTITY_GL_WINDOW_H_

#include <string>

#include <gl_common.h>

#include <microwave/interface/window.h>

class GLWindow :
    public IWindow
{
public:
    GLWindow(GLFWwindow *window, const std::string &title, int width, int height);
    ~GLWindow();

    void set_window_title(const std::string &title) override;
    void set_window_width(int w) override;
    void set_window_height(int h) override;

    std::string get_window_title() const override;
    int get_window_width() const override;
    int get_window_height() const override;

    GLFWwindow *get_glfw_window() const;
    void set_glfw_window(GLFWwindow *glfw_window);

private:
    GLFWwindow *glfw_window__;
    std::string title__;
    int width__;
    int height__;
};

#endif

/* EOF */
