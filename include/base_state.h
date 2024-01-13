#ifndef __BASE_STATE_H_
#define __BASE_STATE_H_

#include <string>

#include <state_context.h>

class StateContext;

class BaseState
{
public:
    virtual ~BaseState() {}

    void set_context(StateContext *context);

    virtual void purge_state() = 0;

    virtual void open_door() = 0;
    virtual void cook(int microwave_time = 30) = 0;
    virtual void close_door() = 0;

    std::string get_name() const;
    std::string get_description() const;

protected:
    StateContext *context_;

    std::string name_;
    std::string description_;
};

#endif
