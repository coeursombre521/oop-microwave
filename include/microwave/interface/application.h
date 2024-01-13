#ifndef __INTERFACE_APPLICATION_H_
#define __INTERFACE_APPLICATION_H_

#include <functional>
#include <string>

class IApplication
{
public:
    virtual ~IApplication() = default;

    virtual void print_app_info_to_log() = 0;
    virtual void print_gpu_info_to_log() = 0;

    virtual void init() = 0;
    virtual void main_loop() = 0;

    virtual std::string get_window_title() const = 0;
    virtual int get_window_width() const = 0;
    virtual int get_window_height() const = 0;
    virtual bool is_running() const = 0;

    virtual void set_window_title(const std::string &title) = 0;
    virtual void set_window_width(int w) = 0;
    virtual void set_window_height(int h) = 0;

    virtual void set_error_callback(void(*)(int, const char *)) = 0;
    virtual void set_run_callback(std::function<void()>) = 0;

    virtual void call_run_callback() = 0;
};

#endif
