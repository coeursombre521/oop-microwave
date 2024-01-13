
#include <microwave_countdown.h>

MicrowaveCountdown::~MicrowaveCountdown()
{
    reset();
    Logger::log("MicrowaveCountdown", "MicrowaveCountdown object destroyed");
    observers__.clear();
}

void
MicrowaveCountdown::start(int time)
{
    running__ = true;
    if (time >= 0) {
        time__ = time;
    }
    Logger::log("MicrowaveCountdown", "MicrowaveCountdown started with time %d", time);
    notify_observers_if_anything_changed();
}

void
MicrowaveCountdown::stop()
{
    running__ = false;
    Logger::log("MicrowaveCountdown", "MicrowaveCountdown stopped");
    notify_observers_if_anything_changed();
}

void
MicrowaveCountdown::reset()
{
    running__ = false;
    time__ = 0;
    Logger::log("MicrowaveCountdown", "MicrowaveCountdown reset");
    notify_observers_if_anything_changed();
}

void
MicrowaveCountdown::add_time(int time)
{
    time__ += time;
    Logger::log("MicrowaveCountdown", "MicrowaveCountdown time increased by %d", time);
    notify_observers_if_anything_changed();
}

void
MicrowaveCountdown::update()
{
    if (running__ && time__ > 0) {
        time__--;
        if (time__ == 0) {
            running__ = false;
        }
        Logger::log("MicrowaveCountdown", "Countdown time is now %d", time__);
        notify_observers_if_anything_changed();
    }
}

void
MicrowaveCountdown::register_observer(IObserver* observer)
{
    observers__.insert(observer);
}

void
MicrowaveCountdown::unregister_observer(IObserver* observer)
{
    auto it = observers__.find(observer);
    if (it != observers__.end()) {
        observers__.erase(observer);
    }
}

void
MicrowaveCountdown::notify_observers()
{
    for (auto observer : observers__) {
        observer->update(MICROWAVE_COUNTDOWN_NOTIFY_ID);
    }
}

int
MicrowaveCountdown::get_time() const
{
    return time__;
}

bool
MicrowaveCountdown::is_running() const
{
    return running__;
}

void
MicrowaveCountdown::set_time(int time)
{
    time__ = time;
    notify_observers_if_anything_changed();
}

void
MicrowaveCountdown::set_running(bool running)
{
    running__ = running;
    notify_observers_if_anything_changed();
}

void
MicrowaveCountdown::notify_observers_if_anything_changed()
{
    if (running__ != previous_running__) {
        previous_running__ = running__;
        notify_observers();
    }

    if (time__ != previous_time__) {
        previous_time__ = time__;
        notify_observers();
    }
}
