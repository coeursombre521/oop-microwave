
#include <typeinfo>

#include <logger.h>
#include <state_context.h>

StateContext::~StateContext() {
    this->purge_state();
}

void
StateContext::transition_to(BaseState *state)
{
    this->purge_state();
    if (this->state__ != nullptr) {
        this->state__ = nullptr;
    }
    this->state__ = state;
    this->state__->set_context(this);
    this->notify_observers();

    Logger::log("StateContext", "Application transitioned to BaseState object of type %s", typeid(*state).name());
}

void
StateContext::purge_state()
{
    if (this->state__ == nullptr) {
        return;
    }

    Logger::log("StateContext", "Purging BaseState object of type %s", typeid(*this->state__).name());

    this->state__->purge_state();
    this->state__ = nullptr;
}

void
StateContext::open_door()
{
    this->state__->open_door();
}

void
StateContext::close_door()
{
    this->state__->close_door();
}

void
StateContext::cook()
{
    this->state__->cook();
}

void
StateContext::register_observer(IObserver *observer)
{
    this->observers__.insert(observer);
}

void
StateContext::unregister_observer(IObserver *observer)
{
    this->observers__.erase(observer);
}

void
StateContext::notify_observers()
{
    for (IObserver *observer : this->observers__) {
        observer->update(STATE_CONTEXT_NOTIFY_ID);
    }
}

std::string
StateContext::get_state_name() const
{
    return (state__ != nullptr) ? this->state__->get_name() : "";
}

std::string
StateContext::get_state_description() const
{
    return (state__ != nullptr) ? this->state__->get_description() : "";
}
