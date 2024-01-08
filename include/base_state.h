#ifndef __BASE_STATE_H_
#define __BASE_STATE_H_

#include <string>

#include <state_context.h>

class StateContext;

class BaseState
{
public:
    virtual ~BaseState() {}

    void set_context(StateContext *context) {
        this->context_ = context;
    }

    virtual void purge_state() = 0;

    virtual void open_door() = 0;
    virtual void cook() = 0;
    virtual void close_door() = 0;

    std::string get_name() const { return this->name_; }
    std::string get_description() const { return this->description_; }

protected:
    StateContext *context_;

    std::string name_;
    std::string description_;
};

#endif
