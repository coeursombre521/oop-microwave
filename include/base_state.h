#ifndef __BASE_STATE_H_
#define __BASE_STATE_H_

#include <string>

#include <context.h>

class Context;

class BaseState
{
protected:
    Context *context_;

    std::string short_name_;
    std::string description_;

public:
    virtual ~BaseState() {}

    void set_context(Context *context) {
        this->context_ = context;
    }

    virtual void purge_state() = 0;

    virtual void open_door() = 0;
    virtual void cook() = 0;
    virtual void close_door() = 0;
    virtual void get_ticks() = 0;

    std::string get_short_name() const { return this->short_name_; }
    std::string get_description() const { return this->description_; }
};

#endif
