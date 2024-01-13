#ifndef __STATE_DOOR_OPENED_H_
#define __STATE_DOOR_OPENED_H_

#include <base_state.h>
#include <base_unique_singleton.h>

class StateDoorOpened :
    public BaseUniqueSingleton<StateDoorOpened>,
    public BaseState
{
public:
    void purge_state() override;
    void open_door() override;
    void cook(int microwave_time) override;
    void close_door() override;

protected:
    StateDoorOpened();

    friend class BaseUniqueSingleton<StateDoorOpened>;
};

#endif
