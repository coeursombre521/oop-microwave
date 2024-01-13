#ifndef __STATE_DOOR_CLOSED_H_
#define __STATE_DOOR_CLOSED_H_

#include <microwave/base_type/state.h>
#include <microwave/base_type/singleton.h>

class StateDoorClosed :
    public BaseSingleton<StateDoorClosed>,
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

    friend class BaseSingleton<StateDoorClosed>;
};

#endif
