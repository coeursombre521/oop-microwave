
#include <clock_context.h>
#include <logger.h>

ClockContext::ClockContext()
{
    this->clock__ = std::make_unique<Clock>();
}

ClockContext::~ClockContext() {
    this->clock__.reset();
    this->observers__.clear();
}

void
ClockContext::start_time()
{
    this->clock__->start();
    this->notify_observers();
}

void
ClockContext::stop_time()
{
    this->clock__->stop();
    this->notify_observers();
}

void
ClockContext::reset_time()
{
    this->clock__->reset();
    this->notify_observers();
}

void
ClockContext::update_time()
{
    this->clock__->update();
    this->notify_observers();
}

void
ClockContext::register_observer(IObserver *observer)
{
    this->observers__.insert(observer);
}

void
ClockContext::unregister_observer(IObserver *observer)
{
    this->observers__.erase(observer);
}

void
ClockContext::notify_observers()
{
    for (IObserver *observer : this->observers__) {
        observer->update(CLOCK_CONTEXT_NOTIFY_ID);
    }
}

long double
ClockContext::get_elapsed_time() const
{
    return this->clock__->elapsed_time();
}
