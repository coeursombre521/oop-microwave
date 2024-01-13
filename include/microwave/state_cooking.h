#ifndef __STATE_COOKING_H_
#define __STATE_COOKING_H_

#include <microwave/base_state.h>
#include <microwave/base_unique_singleton.h>

class StateCooking :
    public BaseUniqueSingleton<StateCooking>,
    public BaseState
{
public:
    void purge_state() override;
    void open_door() override;
    void cook(int microwave_time = 30) override;
    void close_door() override;
    int get_countdown() const override;

protected:
    StateCooking();

    friend class BaseUniqueSingleton<StateCooking>;
};

#endif
