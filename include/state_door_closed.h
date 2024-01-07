#ifndef __STATE_DOOR_CLOSED_H_
#define __STATE_DOOR_CLOSED_H_

#include <base_state.h>
#include <base_unique_singleton.h>

class StateDoorClosed : public BaseState, public BaseUniqueSingleton<StateDoorClosed>
{
protected:
    StateDoorClosed()
    {
        this->short_name_ = "Door Closed";
        this->description_ = "The microwave door is closed";
    }

public:
    void purge_state() override;
    void open_door() override;
    void cook() override;
    void close_door() override;
    void get_ticks() override;
};

#endif
