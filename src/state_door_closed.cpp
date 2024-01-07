
#include <logger.h>
#include <state_cooking.h>
#include <state_door_closed.h>
#include <state_door_opened.h>

void
StateDoorClosed::purge_state()
{
    this->destroy_instance();
}

void
StateDoorClosed::open_door()
{
    Logger::log("StateDoorClosed", "Opening door");
    this->context_->transition_to(StateDoorOpened::get_instance());
}

void
StateDoorClosed::cook()
{
    Logger::log("StateDoorClosed", "Cooking your mancarica");
    this->context_->transition_to(StateCooking::get_instance());
}

void
StateDoorClosed::close_door()
{
    Logger::log("StateDoorClosed", "The door is closed already");
}

void
StateDoorClosed::get_ticks()
{
    Logger::log("StateDoorClosed", "Getting ticks");
}