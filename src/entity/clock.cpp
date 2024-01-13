
#include <microwave/entity/clock.h>

Clock::Clock() :
    start_time__(clock::now()),
    end_time__(clock::now()),
    running__(false)
{}

void
Clock::start()
{
    start_time__ = clock::now();
    running__ = true;
}

void
Clock::update()
{
    if (running__) {
        end_time__ = clock::now();
    }
}

void
Clock::stop()
{
    end_time__ = clock::now();
    running__ = false;
}

void
Clock::reset()
{
    start_time__ = clock::now();
    end_time__ = clock::now();
    running__ = false;
}

bool
Clock::running() const
{
    return running__;
}

long double
Clock::elapsed_time()
{
    if (running__) {
        end_time__ = clock::now();
    }
    return std::chrono::duration_cast<duration>(end_time__ - start_time__).count();
}
