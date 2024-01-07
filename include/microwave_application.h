
#ifndef __MICROWAVE_APPLICATION_H_
#define __MICROWAVE_APPLICATION_H_

#include <functional>

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <base_unique_singleton.h>

#define GLSL_VERSION "#version 330 core"

class MicrowaveApplication : public BaseUniqueSingleton<MicrowaveApplication>
{
public:
    static void     init_opengl(int major, int minor);
    static void     create_window(const std::string &title, int w = 1280, int h = 720);
    static void     init_imgui();
    static void     destroy_context();

    static void     run(std::function<void()> ui, std::function<void()> opengl);

    std::string     window_title() const    { return window_title_; }
    GLFWwindow*     window() const          { return window_; }
    int             window_width() const    { return window_width_; }
    int             window_height() const   { return window_height_; }

private:
    std::string     window_title_;
    std::string     glsl_version_ = GLSL_VERSION;
    GLFWwindow      *window_;
    int             window_width_;
    int             window_height_;

    static void __glfw_error_callback(int error, const char* description);

    friend class BaseUniqueSingleton<MicrowaveApplication>;
};

#endif
