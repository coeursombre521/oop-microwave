
#include <clock.h>

void
Clock::start()
{
    this->__start_time = clock::now();
    this->__running = true;
}

void
Clock::stop()
{
    this->__end_time = clock::now();
    this->__running = false;
}

void
Clock::reset()
{
    this->__start_time = clock::now();
    this->__end_time = clock::now();
    this->__running = false;
}

long double
Clock::elapsed_time()
{
    if (this->__running) {
        this->__end_time = clock::now();
    }
    return std::chrono::duration_cast<duration>(this->__end_time - this->__start_time).count();
}
