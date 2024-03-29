
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/app_impl/app_gl.h
 */

#ifndef __APP_IMPL_IMPL_GL_H_
#define __APP_IMPL_IMPL_GL_H_

#include <functional>

#include <gl_common.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <microwave/context/clock.h>
#include <microwave/entity/gl_window.h>
#include <microwave/interface/application.h>
#include <microwave/interface/window.h>

class GLFWApplication :
    public IApplication
{
public:
    GLFWApplication();
    virtual ~GLFWApplication();

    using error_callback_t = void(*)(int, const char *);
    using run_callback_t = std::function<void()>;

    void print_app_info_to_log() override;
    void print_gpu_info_to_log() override;

    void init() override;
    void main_loop() override;

    IWindow *get_window() const override;
    std::string get_window_title() const override;
    std::string get_glsl_version() const;
    int get_window_width() const override;
    int get_window_height() const override;
    int get_gl_major() const;
    int get_gl_minor() const;
    bool is_running() const override;

    void set_window_title(const std::string &title) override;
    void set_glsl_version(const std::string &version);
    void set_window_width(int w) override;
    void set_window_height(int h) override;
    void set_gl_major(int major);
    void set_gl_minor(int minor);

    error_callback_t get_error_callback();
    run_callback_t get_run_callback();

    void set_error_callback(error_callback_t callback);
    void set_run_callback(run_callback_t callback);

    void call_run_callback();

private:
    GLWindow *window__;
    std::string glsl_version__;
    int gl_major__;
    int gl_minor__;
    bool running__ = false;

    error_callback_t error_callback__;
    run_callback_t run_callback__;

    ClockContext *clock_context__;

    void init_glfw();
    void init_window();
    void init_glad();
    void init_imgui();
    void destroy();
};

#endif

/* EOF */

