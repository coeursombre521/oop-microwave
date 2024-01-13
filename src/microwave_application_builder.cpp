
#include <logger.h>
#include <microwave_application_builder.h>

MicrowaveApplicationBuilder::MicrowaveApplicationBuilder()
{
    application__ = nullptr;
}

MicrowaveApplicationBuilder::~MicrowaveApplicationBuilder()
{
    if (application__ != nullptr)
    {
        delete application__;
        application__ = nullptr;
    }
}

MicrowaveApplicationBuilder&
MicrowaveApplicationBuilder::create_gl_application()
{
    reset();

    application__ = new MicrowaveGLApplication();

    Logger::log("MicrowaveApplicationBuilder", "Created GL application");

    return *this;
}

MicrowaveApplicationBuilder&
MicrowaveApplicationBuilder::set_window_title(const std::string &title)
{
    if (application__ != nullptr)
    {
        application__->set_window_title(title);
        Logger::log("MicrowaveApplicationBuilder", "Set window title to %s", application__->get_window_title().c_str());
    }

    return *this;
}

MicrowaveApplicationBuilder&
MicrowaveApplicationBuilder::set_window_width(int w)
{
    if (application__ != nullptr)
    {
        application__->set_window_width(w);
        Logger::log("MicrowaveApplicationBuilder", "Set window width to %d", application__->get_window_width());
    }

    return *this;
}

MicrowaveApplicationBuilder&
MicrowaveApplicationBuilder::set_window_height(int h)
{
    if (application__ != nullptr)
    {
        application__->set_window_height(h);
        Logger::log("MicrowaveApplicationBuilder", "Set window height to %d", application__->get_window_height());
    }

    return *this;
}

MicrowaveApplicationBuilder&
MicrowaveApplicationBuilder::set_glsl_version(const std::string &version)
{
    if (application__ != nullptr)
    {
        MicrowaveGLApplication *gl_app = get_gl_application(application__);
        if (gl_app != nullptr) {
            gl_app->set_glsl_version(version);
            Logger::log("MicrowaveApplicationBuilder", "Set GLSL version to %s", gl_app->get_glsl_version().c_str());
        }
    }

    return *this;
}

MicrowaveApplicationBuilder&
MicrowaveApplicationBuilder::set_gl_major(int major)
{
    if (application__ != nullptr)
    {
        MicrowaveGLApplication *gl_app = get_gl_application(application__);
        if (gl_app != nullptr) {
            gl_app->set_gl_major(major);
            Logger::log("MicrowaveApplicationBuilder", "Set GL major version to %d", gl_app->get_gl_major());
        }
    }

    return *this;
}

MicrowaveApplicationBuilder&
MicrowaveApplicationBuilder::set_gl_minor(int minor)
{
    if (application__ != nullptr)
    {
        MicrowaveGLApplication *gl_app = get_gl_application(application__);
        if (gl_app != nullptr) {
            gl_app->set_gl_minor(minor);
            Logger::log("MicrowaveApplicationBuilder", "Set GL minor version to %d", gl_app->get_gl_minor());
        }
    }

    return *this;
}

MicrowaveApplicationBuilder&
MicrowaveApplicationBuilder::set_error_callback(void(*callback)(int, const char *))
{
    if (application__ != nullptr)
    {
        application__->set_error_callback(callback);
        Logger::log("MicrowaveApplicationBuilder", "Set error callback");
    }

    return *this;
}

MicrowaveApplicationBuilder&
MicrowaveApplicationBuilder::set_run_callback(std::function<void()> callback)
{
    if (application__ != nullptr)
    {
        application__->set_run_callback(callback);
        Logger::log("MicrowaveApplicationBuilder", "Set run callback");
    }

    return *this;
}

IMicrowaveApplication*
MicrowaveApplicationBuilder::build()
{
    if (application__ == nullptr)
    {
        Logger::log("MicrowaveApplicationBuilder", "No application created");
        return nullptr;
    }

    IMicrowaveApplication *tmp = application__;
    tmp->init();

    reset();

    Logger::log("MicrowaveApplicationBuilder", "Built application");

    return tmp;
}

void
MicrowaveApplicationBuilder::reset()
{
    if (application__ != nullptr)
    {
        application__ = nullptr;

        Logger::log("MicrowaveApplicationBuilder", "Reset application");
    }
}

MicrowaveGLApplication*
MicrowaveApplicationBuilder::get_gl_application(IMicrowaveApplication *app)
{
    if (typeid(*app) == typeid(MicrowaveGLApplication))
    {
        return dynamic_cast<MicrowaveGLApplication*>(app);
    }

    return nullptr;
}
