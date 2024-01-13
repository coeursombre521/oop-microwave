#ifndef __STATE_CONTEXT_H_
#define __STATE_CONTEXT_H_

#include <string>
#include <unordered_set>

#include <microwave/base_state.h>
#include <microwave/base_unique_singleton.h>
#include <microwave/interfaces/interface_observable.h>
#include <microwave/interfaces/interface_observer.h>
#include <microwave/microwave_countdown.h>

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
    void cook(int microwave_time = 30);
    void close_door();
    int get_countdown() const;

    void register_observer(IObserver *observer) override;
    void unregister_observer(IObserver *observer) override;
    void notify_observers() override;

    std::string get_state_name() const;
    std::string get_state_description() const;

protected:
    StateContext();
    ~StateContext();

private:
    BaseState *state__ = nullptr;
    std::unordered_set<IObserver *> observers__;

    friend class BaseUniqueSingleton<StateContext>;
};

#endif
