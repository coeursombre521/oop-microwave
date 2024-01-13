
#include <clock.h>

Clock::Clock() :
    start_time__(clock::now()),
    end_time__(clock::now()),
    running__(false)
{}

void
Clock::start()
{
    this->start_time__ = clock::now();
    this->running__ = true;
}

void
Clock::update()
{
    if (this->running__) {
        this->end_time__ = clock::now();
    }
}

void
Clock::stop()
{
    this->end_time__ = clock::now();
    this->running__ = false;
}

void
Clock::reset()
{
    this->start_time__ = clock::now();
    this->end_time__ = clock::now();
    this->running__ = false;
}

bool
Clock::running() const
{
    return this->running__;
}

long double
Clock::elapsed_time()
{
    if (this->running__) {
        this->end_time__ = clock::now();
    }
    return std::chrono::duration_cast<duration>(this->end_time__ - this->start_time__).count();
}
