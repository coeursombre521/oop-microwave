
#include <logger.h>
#include <microwave_application.h>

void
MicrowaveApplication::__glfw_error_callback(int error, const char* description)
{
    std::cerr << "GLFW Error " << error << ": " << description << "\n";
}

void
MicrowaveApplication::init_opengl(int major, int minor)
{
    glfwSetErrorCallback(__glfw_error_callback);

    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    Logger::log("MicrowaveApplication", "GLFW initialized successfully");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Logger::log("MicrowaveApplication", "OpenGL context version set to %d.%d", major, minor);
}

void
MicrowaveApplication::create_window(const std::string &title, int w, int h)
{
    MicrowaveApplication* tmp = get_instance();

    tmp->window_title_ = title;
    tmp->window_width_ = w;
    tmp->window_height_ = h;

    Logger::log("MicrowaveApplication", "Creating window titled `%s` with geometry w=%d, h=%d", title.c_str(), w, h);

    tmp->window_ = glfwCreateWindow(w, h, tmp->window_title_.c_str(), nullptr, nullptr);
    if (tmp->window_ == nullptr) {
        throw std::runtime_error("Failed to create GLFW window");
    }

    Logger::log("MicrowaveApplication", "Window created successfully");

    glfwMakeContextCurrent(tmp->window_);
    glfwSwapInterval(1);

    Logger::log("MicrowaveApplication", "Context made current and vsync enabled");

    Logger::log("MicrowaveApplication", "OpenGL is up! Here is your GPU info:");
    Logger::log("MicrowaveApplication", "- Vendor: %s", glGetString(GL_VENDOR));
    Logger::log("MicrowaveApplication", "- Renderer: %s", glGetString(GL_RENDERER));
    Logger::log("MicrowaveApplication", "- Version: %s", glGetString(GL_VERSION));
    Logger::log("MicrowaveApplication", "- GLSL: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void
MicrowaveApplication::init_imgui()
{
    MicrowaveApplication* tmp = get_instance();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(tmp->window_, true);
    ImGui_ImplOpenGL3_Init(tmp->glsl_version_.c_str());

    Logger::log("MicrowaveApplication", "Initializing ImGui");
    Logger::log("MicrowaveApplication", "ImGui version: %s", IMGUI_VERSION);
    Logger::log("MicrowaveApplication", "GLSL version: %s", tmp->glsl_version_.c_str());
}

void
MicrowaveApplication::destroy_context()
{
    MicrowaveApplication* tmp = get_instance();

    Logger::log("MicrowaveApplication", "Shutting down ImGui");
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    Logger::log("MicrowaveApplication", "Destroying GLFW window");
    glfwDestroyWindow(tmp->window_);
    glfwTerminate();
}

void
MicrowaveApplication::run(std::function<void()> f_ui, std::function<void()> f_opengl)
{
    GLFWwindow* window = get_instance()->window_;

    Logger::log("MicrowaveApplication", "Starting main loop");
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        f_ui();

        ImGui::Render();

        f_opengl();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
}

std::string
MicrowaveApplication::window_title() const
{
    return window_title_;
}

GLFWwindow*
MicrowaveApplication::window() const
{
    return window_;
}

int
MicrowaveApplication::window_width() const
{
    return window_width_;
}

int
MicrowaveApplication::window_height() const
{
    return window_height_;
}
