
#include <microwave/context/countdown.h>
#include <microwave/debug/logger.h>
#include <microwave/state/cooking.h>
#include <microwave/state/door_closed.h>
#include <microwave/state/door_opened.h>

StateDoorOpened::StateDoorOpened() : BaseState()
{
    countdown_ = CountdownContext::get_instance();
    name_ = "StateDoorOpened";
    description_ = "The microwave door is opened.";
}

void
StateDoorOpened::purge_state()
{
    if (CountdownContext::is_alive()) {
        CountdownContext::destroy_instance();
    }
    destroy_instance();
}

void
StateDoorOpened::open_door()
{
    Logger::log("StateDoorOpened", "The door is already opened");
    countdown_->reset();
}

void
StateDoorOpened::cook(int /*microwave_time*/)
{
    Logger::log("StateDoorOpened", "The microwave has the door opened. Close the door and cook your mancarica");
}

void
StateDoorOpened::close_door()
{
    Logger::log("StateDoorOpened", "Closing door");
    context_->transition_to(StateDoorClosed::get_instance());
}

int
StateDoorOpened::get_countdown() const
{
    return countdown_->get_time();
}
