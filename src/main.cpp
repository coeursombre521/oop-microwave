
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * File name: main.cpp
 */

#include <microwave/debug/logger.h>
#include <microwave/app_impl/builder.h>
#include <microwave/app_impl/app_gl.h>
#include <microwave/interface/application.h>
#include <microwave/ui/microwave_control.h>

#include <config.h>

static void error_callback(int, const char*);

int
main (void)
{
    Logger::log("main", "Hello there, starting application");

    ApplicationBuilder builder = ApplicationBuilder();
    IApplicationUI *control = new MicrowaveControl();
    IApplication *app = builder
        .create_gl_application()
        .set_window_title("cuptor cu microunde pofta buna youtube :)")
        .set_window_width(WINDOW_WIDTH)
        .set_window_height(WINDOW_HEIGHT)
        .set_glsl_version(std::string(GLSL_VERSION))
        .set_gl_major(GL_MAJOR)
        .set_gl_minor(GL_MINOR)
        .set_error_callback(error_callback)
        .set_run_callback([&control]() -> void {
            control->render();
        })
        .build();

    app->main_loop();

    delete app;
    app = nullptr;

    delete control;
    control = nullptr;

    Logger::log("main", "Bye bye");

    return 0;
}

static void
error_callback(int error, const char* description)
{
    Logger::log("GLFW", "Error %d: %s", error, description);
}

/* EOF */

