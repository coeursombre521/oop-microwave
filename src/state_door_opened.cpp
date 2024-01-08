
#include <logger.h>
#include <state_cooking.h>
#include <state_door_closed.h>
#include <state_door_opened.h>
#include <clock.h>

void
StateDoorOpened::purge_state()
{
    this->destroy_instance();
}

void
StateDoorOpened::open_door()
{
    Logger::log("StateDoorOpened", "The door is already opened");
}

void
StateDoorOpened::cook()
{
    Logger::log("StateDoorOpened", "The microwave has the door opened. Close the door and cook your mancarica");
}

void
StateDoorOpened::close_door()
{
    Logger::log("StateDoorOpened", "Closing door");
    this->context_->transition_to(StateDoorClosed::get_instance());
}
