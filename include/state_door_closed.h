#ifndef __STATE_DOOR_CLOSED_H_
#define __STATE_DOOR_CLOSED_H_

#include <base_state.h>
#include <base_unique_singleton.h>

class StateDoorClosed :
    public BaseUniqueSingleton<StateDoorClosed>,
    public BaseState
{
public:
    void purge_state() override;
    void open_door() override;
    void cook(int microwave_time = 30) override;
    void close_door() override;
    int get_countdown() const override;

protected:
    StateDoorClosed();

    friend class BaseUniqueSingleton<StateDoorClosed>;
};

#endif
