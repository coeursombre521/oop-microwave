#ifndef __MICROWAVE_COUNTDOWN_H_
#define __MICROWAVE_COUNTDOWN_H_

#include <unordered_set>

#include <logger.h>
#include <base_unique_singleton.h>
#include <interface_observable.h>
#include <interface_observer.h>

static constexpr unsigned int MICROWAVE_COUNTDOWN_NOTIFY_ID = 3;

class MicrowaveCountdown :
    public BaseUniqueSingleton<MicrowaveCountdown>,
    public IObservable
{
public:
    void start(int time = 30);
    void stop();
    void reset();
    void add_time(int time = 30);
    void update();

    void register_observer(IObserver* observer) override;
    void unregister_observer(IObserver* observer) override;
    void notify_observers() override;

    int get_time() const;
    bool is_running() const;

    void set_time(int time);
    void set_running(bool running);

protected:
    MicrowaveCountdown() { }
    ~MicrowaveCountdown();

private:
    std::unordered_set<IObserver *> observers__;
    bool running__ = false;
    bool previous_running__ = false;
    int time__ = 0;
    int previous_time__ = 0;

    void notify_observers_if_anything_changed();

    friend class BaseUniqueSingleton<MicrowaveCountdown>;
};

#endif
