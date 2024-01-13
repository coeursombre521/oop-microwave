
#include <base_state.h>

void
BaseState::set_context(StateContext *context)
{
    this->context_ = context;
}

std::string
BaseState::get_name() const
{
    return this->name_;
}

std::string
BaseState::get_description() const
{
    return this->description_;
}
