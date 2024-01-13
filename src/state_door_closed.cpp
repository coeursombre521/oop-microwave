
#include <logger.h>
#include <state_cooking.h>
#include <state_door_closed.h>
#include <state_door_opened.h>
#include <clock.h>

StateDoorClosed::StateDoorClosed() : BaseState()
{
    countdown_ = MicrowaveCountdown::get_instance();
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
    if (countdown_->get_time() > 0) {
        countdown_->start(-1);
    }
    else {
        countdown_->start(microwave_time);
    }
}

void
StateDoorClosed::close_door()
{
    Logger::log("StateDoorClosed", "The door is closed already");
}

int
StateDoorClosed::get_countdown() const
{
    return countdown_->get_time();
}
