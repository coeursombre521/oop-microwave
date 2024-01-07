
#include <typeinfo>

#include <logger.h>
#include <context.h>

Context::Context(BaseState *state) : state__(state) {
    this->transition_to(state);
}

Context::~Context() {
    this->purge_state();
}

void
Context::transition_to(BaseState *state)
{
    Logger::log("Context", "Application is transitioning to BaseState object of type %s", typeid(*state).name());
    if (this->state__ != nullptr) {
        this->state__ = nullptr;
    }
    this->state__ = state;
    this->state__->set_context(this);
}

void
Context::purge_state()
{
    Logger::log("Context", "Purging BaseState object of type %s", typeid(*this->state__).name());
    if (this->state__ == nullptr) {
        return;
    }
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

void
Context::get_ticks()
{
    this->state__->get_ticks();
}
