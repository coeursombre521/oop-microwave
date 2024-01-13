#ifndef __CLOCK_CONTEXT_H_
#define __CLOCK_CONTEXT_H_

#include <string>
#include <memory>
#include <unordered_set>

#include <clock.h>
#include <interface_observable.h>
#include <interface_observer.h>

static constexpr unsigned int CLOCK_CONTEXT_NOTIFY_ID = 1;

class ClockContext : public BaseUniqueSingleton<ClockContext>, public IObservable
{
public:
    void start_time();
    void stop_time();
    void reset_time();
    void update_time();

    void register_observer(IObserver *observer) override;
    void unregister_observer(IObserver *observer) override;
    void notify_observers() override;

    long double get_elapsed_time() const;

protected:
    ClockContext();
    ~ClockContext();

private:
    std::unordered_set<IObserver *> observers__;
    std::unique_ptr<Clock> clock__;

    friend class BaseUniqueSingleton<ClockContext>;
};

#endif
