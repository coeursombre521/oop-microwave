
#include <microwave/logger.h>
#include <microwave/state_cooking.h>
#include <microwave/state_door_closed.h>
#include <microwave/state_door_opened.h>
#include <microwave/clock.h>

StateDoorOpened::StateDoorOpened() : BaseState()
{
    countdown_ = MicrowaveCountdown::get_instance();
    name_ = "StateDoorOpened";
    description_ = "The microwave door is opened.";
}

void
StateDoorOpened::purge_state()
{
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
