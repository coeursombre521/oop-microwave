
#include <microwave/logger.h>
#include <microwave/microwave_gl_application.h>

MicrowaveGLApplication::MicrowaveGLApplication()
{
    Logger::log("MicrowaveGLApplication", "Creating instance");
    clock_context__ = ClockContext::get_instance();
}

MicrowaveGLApplication::~MicrowaveGLApplication()
{
    Logger::log("MicrowaveGLApplication", "Destroying instance");
    destroy();
}

void
MicrowaveGLApplication::print_app_info_to_log()
{
    Logger::log("MicrowaveGLApplication", "Application info:");
    Logger::log("MicrowaveGLApplication", "- Window title: %s", window_title__.c_str());
    Logger::log("MicrowaveGLApplication", "- Window width: %d", window_width__);
    Logger::log("MicrowaveGLApplication", "- Window height: %d", window_height__);
    Logger::log("MicrowaveGLApplication", "- OpenGL version: %d.%d", gl_major__, gl_minor__);
    Logger::log("MicrowaveGLApplication", "- GLSL version: %s", glsl_version__.c_str());
}

void
MicrowaveGLApplication::print_gpu_info_to_log()
{
    Logger::log("MicrowaveGLApplication", "GPU info:");
    Logger::log("MicrowaveGLApplication", "- Vendor: %s", glGetString(GL_VENDOR));
    Logger::log("MicrowaveGLApplication", "- Renderer: %s", glGetString(GL_RENDERER));
    Logger::log("MicrowaveGLApplication", "- Version: %s", glGetString(GL_VERSION));
    Logger::log("MicrowaveGLApplication", "- GLSL: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void
MicrowaveGLApplication::init()
{
    Logger::log("MicrowaveGLApplication", "Initializing GLFW");
    init_glfw();

    Logger::log("MicrowaveGLApplication", "Initializing window");
    init_window();

    Logger::log("MicrowaveGLApplication", "Initializing ImGui");
    init_imgui();

    running__ = true;
}

void
MicrowaveGLApplication::main_loop()
{
    Logger::log("MicrowaveGLApplication", "Starting main loop");

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
MicrowaveGLApplication::get_window_title() const
{
    return window_title__;
}

std::string
MicrowaveGLApplication::get_glsl_version() const
{
    return glsl_version__;
}

int
MicrowaveGLApplication::get_window_width() const
{
    return window_width__;
}

int
MicrowaveGLApplication::get_window_height() const
{
    return window_height__;
}

int
MicrowaveGLApplication::get_gl_major() const
{
    return gl_major__;
}

int
MicrowaveGLApplication::get_gl_minor() const
{
    return gl_minor__;
}

bool
MicrowaveGLApplication::is_running() const
{
    return running__;
}

void
MicrowaveGLApplication::set_window_title(const std::string &title)
{
    window_title__ = title;
}

void
MicrowaveGLApplication::set_glsl_version(const std::string &version)
{
    glsl_version__ = version;
}

void
MicrowaveGLApplication::set_window_width(int w)
{
    window_width__ = w;
}

void
MicrowaveGLApplication::set_window_height(int h)
{
    window_height__ = h;
}

void
MicrowaveGLApplication::set_gl_major(int major)
{
    gl_major__ = major;
}

void
MicrowaveGLApplication::set_gl_minor(int minor)
{
    gl_minor__ = minor;
}

MicrowaveGLApplication::error_callback_t
MicrowaveGLApplication::get_error_callback()
{
    return error_callback__;
}

MicrowaveGLApplication::run_callback_t
MicrowaveGLApplication::get_run_callback()
{
    return run_callback__;
}

void
MicrowaveGLApplication::set_error_callback(error_callback_t callback)
{
    error_callback__ = callback;
}

void
MicrowaveGLApplication::set_run_callback(run_callback_t callback)
{
    run_callback__ = callback;
}

void
MicrowaveGLApplication::call_run_callback()
{
    if (run_callback__) {
        run_callback__();
    }
}

void
MicrowaveGLApplication::init_glfw()
{
    glfwSetErrorCallback(error_callback__);

    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    Logger::log("MicrowaveGLApplication", "GLFW initialized successfully");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_major__);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_minor__);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Logger::log("MicrowaveGLApplication", "OpenGL context version set to %d.%d", gl_major__, gl_minor__);
}

void
MicrowaveGLApplication::init_window()
{
    Logger::log(
        "MicrowaveGLApplication",
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

    Logger::log("MicrowaveGLApplication", "Window created successfully");

    glfwMakeContextCurrent(window__);

    print_app_info_to_log();
    print_gpu_info_to_log();
}

void
MicrowaveGLApplication::init_imgui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window__, true);
    ImGui_ImplOpenGL3_Init(glsl_version__.c_str());

    Logger::log("MicrowaveGLApplication", "ImGui initialized successfully");
    Logger::log("MicrowaveGLApplication", "ImGui version: %s", IMGUI_VERSION);
    Logger::log("MicrowaveGLApplication", "GLSL version: %s", glsl_version__.c_str());
}

void
MicrowaveGLApplication::destroy()
{
    Logger::log("MicrowaveGLApplication", "Shutting down ImGui");
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    Logger::log("MicrowaveGLApplication", "Destroying GLFW window");
    glfwDestroyWindow(window__);
    glfwTerminate();
}
