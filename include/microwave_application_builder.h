#ifndef __MICROWAVE_APPLICATION_BUILDER_H_
#define __MICROWAVE_APPLICATION_BUILDER_H_

#include <string>
#include <typeinfo>

#include <microwave_gl_application.h>
#include <interface_microwave_application.h>

class MicrowaveApplicationBuilder
{
public:
    MicrowaveApplicationBuilder();
    ~MicrowaveApplicationBuilder();

    MicrowaveApplicationBuilder& create_gl_application();

    MicrowaveApplicationBuilder& set_window_title(const std::string &title);
    MicrowaveApplicationBuilder& set_window_width(int w);
    MicrowaveApplicationBuilder& set_window_height(int h);

    MicrowaveApplicationBuilder& set_glsl_version(const std::string &version);
    MicrowaveApplicationBuilder& set_gl_major(int major);
    MicrowaveApplicationBuilder& set_gl_minor(int minor);

    MicrowaveApplicationBuilder& set_error_callback(void(*)(int, const char *));
    MicrowaveApplicationBuilder& set_run_callback(std::function<void()>);

    IMicrowaveApplication* build();

    void reset();

private:
    IMicrowaveApplication *application__;

    MicrowaveGLApplication *get_gl_application(IMicrowaveApplication *app);
};

#endif
