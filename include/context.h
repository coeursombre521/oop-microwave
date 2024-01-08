#ifndef __CONTEXT_H_
#define __CONTEXT_H_

#include <string>
#include <unordered_set>

#include <base_state.h>
#include <base_unique_singleton.h>
#include <interface_observable.h>

class BaseState;

class Context : public BaseUniqueSingleton<Context>, public IObservable
{
public:
    void transition_to(BaseState *state);
    void purge_state();

    void        open_door();
    void        cook();
    void        close_door();
    long double get_ticks();

    void        register_observer(IObserver *observer);
    void        unregister_observer(IObserver *observer);
    void        notify_observers();

    std::string get_state_name() const;
    std::string get_state_description() const;

protected:
    Context() { }
    ~Context();

private:
    BaseState                          *state__ = nullptr;
    std::unordered_set<IObserver *>     observers__;

    friend class BaseUniqueSingleton<Context>;
};

#endif
