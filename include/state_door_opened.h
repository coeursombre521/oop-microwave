#ifndef __STATE_DOOR_OPENED_H_
#define __STATE_DOOR_OPENED_H_

#include <base_state.h>
#include <base_unique_singleton.h>

class StateDoorOpened : public BaseState, public BaseUniqueSingleton<StateDoorOpened>
{
public:
    void        purge_state() override;
    void        open_door() override;
    void        cook() override;
    void        close_door() override;
    long double get_ticks() override;

protected:
    StateDoorOpened(): BaseState()
    {
        this->name_ = "Door Opened";
        this->description_ = "The microwave door is opened";
    }

    friend class BaseUniqueSingleton<StateDoorOpened>;
};

#endif
