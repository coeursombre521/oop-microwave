#ifndef __CLOCK_H_
#define __CLOCK_H_

#include <chrono>

#include <base_unique_singleton.h>

class Clock : public BaseUniqueSingleton<Clock>
{
public:
    using clock = std::chrono::steady_clock;
    using time_point = std::chrono::time_point<clock>;
    using duration = std::chrono::duration<long double>;

    void        start();
    void        stop();
    void        reset();
    long double elapsed_time();

protected:
    Clock() {

    }

private:
    time_point  __start_time;
    time_point  __end_time;
    bool        __running = false;

    friend class BaseUniqueSingleton<Clock>;
};

#endif
