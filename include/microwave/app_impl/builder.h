#ifndef __APP_IMPL_BUILDER_H_
#define __APP_IMPL_BUILDER_H_

#include <string>
#include <typeinfo>

#include <microwave/app_impl/app_gl.h>
#include <microwave/interface/application.h>

class ApplicationBuilder
{
public:
    ApplicationBuilder();
    ~ApplicationBuilder();

    ApplicationBuilder& create_gl_application();

    ApplicationBuilder& set_window_title(const std::string &title);
    ApplicationBuilder& set_window_width(int w);
    ApplicationBuilder& set_window_height(int h);

    ApplicationBuilder& set_glsl_version(const std::string &version);
    ApplicationBuilder& set_gl_major(int major);
    ApplicationBuilder& set_gl_minor(int minor);

    ApplicationBuilder& set_error_callback(void(*)(int, const char *));
    ApplicationBuilder& set_run_callback(std::function<void()>);

    IApplication* build();

    void reset();

private:
    IApplication *application__;

    GLFWApplication *get_gl_application(IApplication *app);
};

#endif