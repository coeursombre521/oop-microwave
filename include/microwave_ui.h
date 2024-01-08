#ifndef __MICROWAVE_UI_H_
#define __MICROWAVE_UI_H_

#include <context.h>
#include <state_door_closed.h>

class MicrowaveUI
{
public:
    MicrowaveUI() {
        this->context__ = new Context(StateDoorClosed::get_instance());
    }

    ~MicrowaveUI() {
        delete this->context__;
        this->context__ = nullptr;
    }

    void        render_ui();

    void        open_door();
    void        close_door();
    void        cook_on();
    void        cook_off();
    long double get_ticks();

private:
    Context* context__;
};

#endif
