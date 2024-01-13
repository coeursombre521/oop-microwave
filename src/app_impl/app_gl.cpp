
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: app_impl/app_gl.cpp
 */

#include <microwave/app_impl/app_gl.h>
#include <microwave/debug/logger.h>

GLFWApplication::GLFWApplication()
{
    Logger::log("GLFWApplication", "Creating instance");
    clock_context__ = ClockContext::get_instance();
}

GLFWApplication::~GLFWApplication()
{
    Logger::log("GLFWApplication", "Destroying instance");
    destroy();
}

void
GLFWApplication::print_app_info_to_log()
{
    Logger::log("GLFWApplication", "Application info:");
    Logger::log("GLFWApplication", "- Window title: %s", window_title__.c_str());
    Logger::log("GLFWApplication", "- Window width: %d", window_width__);
    Logger::log("GLFWApplication", "- Window height: %d", window_height__);
    Logger::log("GLFWApplication", "- OpenGL version: %d.%d", gl_major__, gl_minor__);
    Logger::log("GLFWApplication", "- GLSL version: %s", glsl_version__.c_str());
}

void
GLFWApplication::print_gpu_info_to_log()
{
    Logger::log("GLFWApplication", "GPU info:");
    Logger::log("GLFWApplication", "- Vendor: %s", glGetString(GL_VENDOR));
    Logger::log("GLFWApplication", "- Renderer: %s", glGetString(GL_RENDERER));
    Logger::log("GLFWApplication", "- Version: %s", glGetString(GL_VERSION));
    Logger::log("GLFWApplication", "- GLSL: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void
GLFWApplication::init()
{
    Logger::log("GLFWApplication", "Initializing GLFW");
    init_glfw();

    Logger::log("GLFWApplication", "Initializing window");
    init_window();

    Logger::log("GLFWApplication", "Initializing ImGui");
    init_imgui();

    running__ = true;
}

void
GLFWApplication::main_loop()
{
    Logger::log("GLFWApplication", "Starting main loop");

    running__ = true;

    while (running__) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        call_run_callback();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window__);

        clock_context__->update_time();

        if (glfwWindowShouldClose(window__)) {
            running__ = false;
        }

        if (!running__) {
            break;
        }
    }
}

std::string
GLFWApplication::get_window_title() const
{
    return window_title__;
}

std::string
GLFWApplication::get_glsl_version() const
{
    return glsl_version__;
}

int
GLFWApplication::get_window_width() const
{
    return window_width__;
}

int
GLFWApplication::get_window_height() const
{
    return window_height__;
}

int
GLFWApplication::get_gl_major() const
{
    return gl_major__;
}

int
GLFWApplication::get_gl_minor() const
{
    return gl_minor__;
}

bool
GLFWApplication::is_running() const
{
    return running__;
}

void
GLFWApplication::set_window_title(const std::string &title)
{
    window_title__ = title;
}

void
GLFWApplication::set_glsl_version(const std::string &version)
{
    glsl_version__ = version;
}

void
GLFWApplication::set_window_width(int w)
{
    window_width__ = w;
}

void
GLFWApplication::set_window_height(int h)
{
    window_height__ = h;
}

void
GLFWApplication::set_gl_major(int major)
{
    gl_major__ = major;
}

void
GLFWApplication::set_gl_minor(int minor)
{
    gl_minor__ = minor;
}

GLFWApplication::error_callback_t
GLFWApplication::get_error_callback()
{
    return error_callback__;
}

GLFWApplication::run_callback_t
GLFWApplication::get_run_callback()
{
    return run_callback__;
}

void
GLFWApplication::set_error_callback(error_callback_t callback)
{
    error_callback__ = callback;
}

void
GLFWApplication::set_run_callback(run_callback_t callback)
{
    run_callback__ = callback;
}

void
GLFWApplication::call_run_callback()
{
    if (run_callback__) {
        run_callback__();
    }
}

void
GLFWApplication::init_glfw()
{
    glfwSetErrorCallback(error_callback__);

    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    Logger::log("GLFWApplication", "GLFW initialized successfully");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_major__);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_minor__);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Logger::log("GLFWApplication", "OpenGL context version set to %d.%d", gl_major__, gl_minor__);
}

void
GLFWApplication::init_window()
{
    Logger::log(
        "GLFWApplication",
        "Creating window",
        window_title__.c_str(),
        window_width__,
        window_height__
    );

    window__ = glfwCreateWindow(
        window_width__,
        window_height__,
        window_title__.c_str(),
        nullptr,
        nullptr
    );

    if (window__ == nullptr) {
        throw std::runtime_error("Failed to create GLFW window");
    }

    Logger::log("GLFWApplication", "Window created successfully");

    glfwMakeContextCurrent(window__);

    print_app_info_to_log();
    print_gpu_info_to_log();
}

void
GLFWApplication::init_imgui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window__, true);
    ImGui_ImplOpenGL3_Init(glsl_version__.c_str());

    Logger::log("GLFWApplication", "ImGui initialized successfully");
    Logger::log("GLFWApplication", "ImGui version: %s", IMGUI_VERSION);
    Logger::log("GLFWApplication", "GLSL version: %s", glsl_version__.c_str());
}

void
GLFWApplication::destroy()
{
    Logger::log("GLFWApplication", "Shutting down ImGui");
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    Logger::log("GLFWApplication", "Destroying GLFW window");
    glfwDestroyWindow(window__);
    glfwTerminate();
}

/* EOF */

