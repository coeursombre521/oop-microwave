#ifndef __STATE_DOOR_OPENED_H_
#define __STATE_DOOR_OPENED_H_

#include <base_state.h>
#include <base_unique_singleton.h>

class StateDoorOpened : public BaseState, public BaseUniqueSingleton<StateDoorOpened>
{
protected:
    StateDoorOpened(): BaseState()
    {
        this->short_name_ = "Door Opened";
        this->description_ = "The microwave door is opened";
    }

public:
    void purge_state() override;
    void open_door() override;
    void cook() override;
    void close_door() override;
    void get_ticks() override;
};

#endif
