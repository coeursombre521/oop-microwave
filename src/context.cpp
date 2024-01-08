
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

long double
Context::get_ticks()
{
    return this->state__->get_ticks();
}

std::string
Context::get_state_short_name() const
{
    return this->state__->get_short_name();
}

std::string
Context::get_state_description() const
{
    return this->state__->get_description();
}
