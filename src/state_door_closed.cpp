
#include <logger.h>
#include <state_cooking.h>
#include <state_door_closed.h>
#include <state_door_opened.h>
#include <clock.h>

StateDoorClosed::StateDoorClosed() : BaseState()
{
    name_ = "StateDoorClosed";
    description_ = "The microwave door is closed.";
}

void
StateDoorClosed::purge_state()
{
    destroy_instance();
}

void
StateDoorClosed::open_door()
{
    Logger::log("StateDoorClosed", "Opening door");
    context_->transition_to(StateDoorOpened::get_instance());
}

void
StateDoorClosed::cook(int microwave_time)
{
    Logger::log("StateDoorClosed", "Cooking your mancarica");
    context_->transition_to(StateCooking::get_instance());
    if (context_->get_countdown_time() > 0) {
        context_->start_countdown(-1);
    }
    else {
        context_->start_countdown(microwave_time);
    }
}

void
StateDoorClosed::close_door()
{
    Logger::log("StateDoorClosed", "The door is closed already");
}
