#ifndef __CONTEXT_H_
#define __CONTEXT_H_

#include <string>

#include <base_state.h>

class BaseState;

class Context
{
public:
    Context(BaseState *state);
    ~Context();

    void transition_to(BaseState *state);
    void purge_state();

    void        open_door();
    void        cook();
    void        close_door();
    long double get_ticks();

    std::string get_state_short_name() const;
    std::string get_state_description() const;

private:
    BaseState   *state__;
};

#endif
