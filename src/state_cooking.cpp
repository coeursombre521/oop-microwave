
#include <logger.h>
#include <state_cooking.h>
#include <state_door_closed.h>
#include <state_door_opened.h>
#include <clock.h>

StateCooking::StateCooking() : BaseState()
{
    countdown_ = MicrowaveCountdown::get_instance();
    name_ = "StateCooking";
    description_ = "The microwave is cooking mancarica.";
}

void
StateCooking::purge_state()
{
    if (MicrowaveCountdown::is_alive()) {
        MicrowaveCountdown::destroy_instance();
    }
    destroy_instance();
}

void
StateCooking::open_door()
{
    Logger::log("StateCooking", "Your mancarica finished cooking");
    context_->transition_to(StateDoorOpened::get_instance());
    countdown_->stop();
}

void
StateCooking::cook(int microwave_time)
{
    Logger::log("StateCooking", "The microwave is cooking mancarica. Cooking MORE!!!");
    countdown_->add_time(microwave_time);
}

void
StateCooking::close_door()
{
    Logger::log("StateCooking", "The door is already closed because the microwave is cooking");
}

int
StateCooking::get_countdown() const
{
    return countdown_->get_time();
}
