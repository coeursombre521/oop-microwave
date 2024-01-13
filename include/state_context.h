#ifndef __STATE_CONTEXT_H_
#define __STATE_CONTEXT_H_

#include <string>
#include <unordered_set>

#include <base_state.h>
#include <base_unique_singleton.h>
#include <interface_observable.h>
#include <interface_observer.h>

static constexpr unsigned int STATE_CONTEXT_NOTIFY_ID = 2;

class BaseState;

class StateContext :
    public BaseUniqueSingleton<StateContext>,
    public IObservable
{
public:
    void transition_to(BaseState *state);
    void purge_state();

    void open_door();
    void cook();
    void close_door();

    void register_observer(IObserver *observer) override;
    void unregister_observer(IObserver *observer) override;
    void notify_observers() override;

    std::string get_state_name() const;
    std::string get_state_description() const;

protected:
    StateContext() { }
    ~StateContext();

private:
    BaseState *state__ = nullptr;
    std::unordered_set<IObserver *> observers__;

    friend class BaseUniqueSingleton<StateContext>;
};

#endif
