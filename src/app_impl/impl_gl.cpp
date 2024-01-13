
#include <microwave/debug/logger.h>
#include <microwave/app_impl/impl_gl.h>

AppImplGL::AppImplGL()
{
    Logger::log("AppImplGL", "Creating instance");
    clock_context__ = ClockContext::get_instance();
}

AppImplGL::~AppImplGL()
{
    Logger::log("AppImplGL", "Destroying instance");
    destroy();
}

void
AppImplGL::print_app_info_to_log()
{
    Logger::log("AppImplGL", "Application info:");
    Logger::log("AppImplGL", "- Window title: %s", window_title__.c_str());
    Logger::log("AppImplGL", "- Window width: %d", window_width__);
    Logger::log("AppImplGL", "- Window height: %d", window_height__);
    Logger::log("AppImplGL", "- OpenGL version: %d.%d", gl_major__, gl_minor__);
    Logger::log("AppImplGL", "- GLSL version: %s", glsl_version__.c_str());
}

void
AppImplGL::print_gpu_info_to_log()
{
    Logger::log("AppImplGL", "GPU info:");
    Logger::log("AppImplGL", "- Vendor: %s", glGetString(GL_VENDOR));
    Logger::log("AppImplGL", "- Renderer: %s", glGetString(GL_RENDERER));
    Logger::log("AppImplGL", "- Version: %s", glGetString(GL_VERSION));
    Logger::log("AppImplGL", "- GLSL: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void
AppImplGL::init()
{
    Logger::log("AppImplGL", "Initializing GLFW");
    init_glfw();

    Logger::log("AppImplGL", "Initializing window");
    init_window();

    Logger::log("AppImplGL", "Initializing ImGui");
    init_imgui();

    running__ = true;
}

void
AppImplGL::main_loop()
{
    Logger::log("AppImplGL", "Starting main loop");

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
AppImplGL::get_window_title() const
{
    return window_title__;
}

std::string
AppImplGL::get_glsl_version() const
{
    return glsl_version__;
}

int
AppImplGL::get_window_width() const
{
    return window_width__;
}

int
AppImplGL::get_window_height() const
{
    return window_height__;
}

int
AppImplGL::get_gl_major() const
{
    return gl_major__;
}

int
AppImplGL::get_gl_minor() const
{
    return gl_minor__;
}

bool
AppImplGL::is_running() const
{
    return running__;
}

void
AppImplGL::set_window_title(const std::string &title)
{
    window_title__ = title;
}

void
AppImplGL::set_glsl_version(const std::string &version)
{
    glsl_version__ = version;
}

void
AppImplGL::set_window_width(int w)
{
    window_width__ = w;
}

void
AppImplGL::set_window_height(int h)
{
    window_height__ = h;
}

void
AppImplGL::set_gl_major(int major)
{
    gl_major__ = major;
}

void
AppImplGL::set_gl_minor(int minor)
{
    gl_minor__ = minor;
}

AppImplGL::error_callback_t
AppImplGL::get_error_callback()
{
    return error_callback__;
}

AppImplGL::run_callback_t
AppImplGL::get_run_callback()
{
    return run_callback__;
}

void
AppImplGL::set_error_callback(error_callback_t callback)
{
    error_callback__ = callback;
}

void
AppImplGL::set_run_callback(run_callback_t callback)
{
    run_callback__ = callback;
}

void
AppImplGL::call_run_callback()
{
    if (run_callback__) {
        run_callback__();
    }
}

void
AppImplGL::init_glfw()
{
    glfwSetErrorCallback(error_callback__);

    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    Logger::log("AppImplGL", "GLFW initialized successfully");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_major__);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_minor__);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Logger::log("AppImplGL", "OpenGL context version set to %d.%d", gl_major__, gl_minor__);
}

void
AppImplGL::init_window()
{
    Logger::log(
        "AppImplGL",
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

    Logger::log("AppImplGL", "Window created successfully");

    glfwMakeContextCurrent(window__);

    print_app_info_to_log();
    print_gpu_info_to_log();
}

void
AppImplGL::init_imgui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window__, true);
    ImGui_ImplOpenGL3_Init(glsl_version__.c_str());

    Logger::log("AppImplGL", "ImGui initialized successfully");
    Logger::log("AppImplGL", "ImGui version: %s", IMGUI_VERSION);
    Logger::log("AppImplGL", "GLSL version: %s", glsl_version__.c_str());
}

void
AppImplGL::destroy()
{
    Logger::log("AppImplGL", "Shutting down ImGui");
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    Logger::log("AppImplGL", "Destroying GLFW window");
    glfwDestroyWindow(window__);
    glfwTerminate();
}
