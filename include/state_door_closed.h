#ifndef __STATE_DOOR_CLOSED_H_
#define __STATE_DOOR_CLOSED_H_

#include <base_state.h>
#include <base_unique_singleton.h>

class StateDoorClosed : public BaseState, public BaseUniqueSingleton<StateDoorClosed>
{
public:
    void purge_state() override;
    void open_door() override;
    void cook() override;
    void close_door() override;

protected:
    StateDoorClosed()
    {
        this->name_ = "Door Closed";
        this->description_ = "The microwave door is closed";
    }

    friend class BaseUniqueSingleton<StateDoorClosed>;
};

#endif
