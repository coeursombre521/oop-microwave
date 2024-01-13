
#include <microwave/base_state.h>

void
BaseState::set_context(StateContext *context)
{
    context_ = context;
}

std::string
BaseState::get_name() const
{
    return name_;
}

std::string
BaseState::get_description() const
{
    return description_;
}
