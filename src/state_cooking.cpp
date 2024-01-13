
#include <logger.h>
#include <state_cooking.h>
#include <state_door_closed.h>
#include <state_door_opened.h>
#include <clock.h>

StateCooking::StateCooking() : BaseState()
{
    this->name_ = "StateCooking";
    this->description_ = "The microwave is cooking mancarica.";
}

void
StateCooking::purge_state()
{
    this->destroy_instance();
}

void
StateCooking::open_door()
{
    Logger::log("StateCooking", "Whoa! Your mancarica finished cooking too early");
    this->context_->transition_to(StateDoorOpened::get_instance());
}

void
StateCooking::cook()
{
    Logger::log("StateCooking", "The microwave is cooking mancarica. Cooking MORE!!!");
    // TODO: cooking more mancarica here
}

void
StateCooking::close_door()
{
    Logger::log("StateCooking", "The door is already closed because the microwave is cooking");
}
