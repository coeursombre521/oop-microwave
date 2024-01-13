#ifndef __STATE_COOKING_H_
#define __STATE_COOKING_H_

#include <base_state.h>
#include <base_unique_singleton.h>

class StateCooking :
    public BaseUniqueSingleton<StateCooking>,
    public BaseState
{
public:
    void purge_state() override;
    void open_door() override;
    void cook() override;
    void close_door() override;

protected:
    StateCooking();

    friend class BaseUniqueSingleton<StateCooking>;
};

#endif
