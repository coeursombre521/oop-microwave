
#include <typeinfo>

#include <logger.h>
#include <context.h>

Context::~Context() {
    this->purge_state();
}

void
Context::transition_to(BaseState *state)
{
    this->purge_state();
    if (this->state__ != nullptr) {
        this->state__ = nullptr;
    }
    this->state__ = state;
    this->state__->set_context(this);
    this->notify_observers();

    Logger::log("Context", "Application transitioned to BaseState object of type %s", typeid(*state).name());
}

void
Context::purge_state()
{
    if (this->state__ == nullptr) {
        return;
    }

    Logger::log("Context", "Purging BaseState object of type %s", typeid(*this->state__).name());

    this->state__->purge_state();
    this->state__ = nullptr;
}

void
Context::open_door()
{
    this->state__->open_door();
}

void
Context::close_door()
{
    this->state__->close_door();
}

void
Context::cook()
{
    this->state__->cook();
}

long double
Context::get_ticks()
{
    return this->state__->get_ticks();
}

void
Context::register_observer(IObserver *observer)
{
    this->observers__.insert(observer);
}

void
Context::unregister_observer(IObserver *observer)
{
    this->observers__.erase(observer);
}

void
Context::notify_observers()
{
    for (IObserver *observer : this->observers__) {
        observer->update();
    }
}

std::string
Context::get_state_name() const
{
    return this->state__->get_name();
}

std::string
Context::get_state_description() const
{
    return this->state__->get_description();
}
