
#include <logger.h>
#include <state_cooking.h>
#include <state_door_closed.h>
#include <state_door_opened.h>
#include <clock.h>

StateDoorOpened::StateDoorOpened() : BaseState()
{
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
    context_->reset_countdown();
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
