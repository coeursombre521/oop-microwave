
#include <logger.h>
#include <microwave_application.h>
#include <microwave_ui.h>

int
main (void)
{
    Logger::log("main", "Hello there, starting application");

    MicrowaveApplication* tmp = MicrowaveApplication::get_instance();

    tmp->init_opengl(3, 3);
    tmp->create_window("cuptor cu microunde pofta buna", 1280, 720);
    tmp->init_imgui();

    GLFWwindow* window = tmp->window();
    MicrowaveUI *ui = new MicrowaveUI();

    tmp->run(
        [&ui]() -> void {
            ui->render_ui();
        },
        [&window]() -> void {
            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(0.04, 0.1, 0.23, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);
        }
    );

    delete ui;
    ui = nullptr;

    tmp->destroy_context();
    MicrowaveApplication::destroy_instance();

    Logger::log("main", "Bye bye");

    return 0;
}
