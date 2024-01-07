#ifndef __STATE_COOKING_H_
#define __STATE_COOKING_H_

#include <base_state.h>
#include <base_unique_singleton.h>

class StateCooking : public BaseState, public BaseUniqueSingleton<StateCooking>
{
protected:
    StateCooking()
    {
        this->short_name_ = "Cooking";
        this->description_ = "The microwave is cooking your mancarica";
    }

public:
    void purge_state() override;
    void open_door() override;
    void cook() override;
    void close_door() override;
    void get_ticks() override;
};

#endif
