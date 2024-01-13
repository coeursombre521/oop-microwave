
#include <microwave/debug/logger.h>
#include <microwave/app_impl/builder.h>

ApplicationBuilder::ApplicationBuilder()
{
    application__ = nullptr;
}

ApplicationBuilder::~ApplicationBuilder()
{
    if (application__ != nullptr)
    {
        delete application__;
        application__ = nullptr;
    }
}

ApplicationBuilder&
ApplicationBuilder::create_gl_application()
{
    reset();

    application__ = new AppImplGL();

    Logger::log("ApplicationBuilder", "Created GL application");

    return *this;
}

ApplicationBuilder&
ApplicationBuilder::set_window_title(const std::string &title)
{
    if (application__ != nullptr)
    {
        application__->set_window_title(title);
        Logger::log("ApplicationBuilder", "Set window title to %s", application__->get_window_title().c_str());
    }

    return *this;
}

ApplicationBuilder&
ApplicationBuilder::set_window_width(int w)
{
    if (application__ != nullptr)
    {
        application__->set_window_width(w);
        Logger::log("ApplicationBuilder", "Set window width to %d", application__->get_window_width());
    }

    return *this;
}

ApplicationBuilder&
ApplicationBuilder::set_window_height(int h)
{
    if (application__ != nullptr)
    {
        application__->set_window_height(h);
        Logger::log("ApplicationBuilder", "Set window height to %d", application__->get_window_height());
    }

    return *this;
}

ApplicationBuilder&
ApplicationBuilder::set_glsl_version(const std::string &version)
{
    if (application__ != nullptr)
    {
        AppImplGL *gl_app = get_gl_application(application__);
        if (gl_app != nullptr) {
            gl_app->set_glsl_version(version);
            Logger::log("ApplicationBuilder", "Set GLSL version to %s", gl_app->get_glsl_version().c_str());
        }
    }

    return *this;
}

ApplicationBuilder&
ApplicationBuilder::set_gl_major(int major)
{
    if (application__ != nullptr)
    {
        AppImplGL *gl_app = get_gl_application(application__);
        if (gl_app != nullptr) {
            gl_app->set_gl_major(major);
            Logger::log("ApplicationBuilder", "Set GL major version to %d", gl_app->get_gl_major());
        }
    }

    return *this;
}

ApplicationBuilder&
ApplicationBuilder::set_gl_minor(int minor)
{
    if (application__ != nullptr)
    {
        AppImplGL *gl_app = get_gl_application(application__);
        if (gl_app != nullptr) {
            gl_app->set_gl_minor(minor);
            Logger::log("ApplicationBuilder", "Set GL minor version to %d", gl_app->get_gl_minor());
        }
    }

    return *this;
}

ApplicationBuilder&
ApplicationBuilder::set_error_callback(void(*callback)(int, const char *))
{
    if (application__ != nullptr)
    {
        application__->set_error_callback(callback);
        Logger::log("ApplicationBuilder", "Set error callback");
    }

    return *this;
}

ApplicationBuilder&
ApplicationBuilder::set_run_callback(std::function<void()> callback)
{
    if (application__ != nullptr)
    {
        application__->set_run_callback(callback);
        Logger::log("ApplicationBuilder", "Set run callback");
    }

    return *this;
}

IApplication*
ApplicationBuilder::build()
{
    if (application__ == nullptr)
    {
        Logger::log("ApplicationBuilder", "No application created");
        return nullptr;
    }

    IApplication *tmp = application__;
    tmp->init();

    reset();

    Logger::log("ApplicationBuilder", "Built application");

    return tmp;
}

void
ApplicationBuilder::reset()
{
    if (application__ != nullptr)
    {
        application__ = nullptr;

        Logger::log("ApplicationBuilder", "Reset application");
    }
}

AppImplGL*
ApplicationBuilder::get_gl_application(IApplication *app)
{
    if (typeid(*app) == typeid(AppImplGL))
    {
        return dynamic_cast<AppImplGL*>(app);
    }

    return nullptr;
}
