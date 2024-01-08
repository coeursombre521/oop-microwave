#ifndef __MICROWAVE_UI_H_
#define __MICROWAVE_UI_H_

#include <string>

#include <context.h>
#include <state_door_closed.h>
#include <interface_observer.h>

class MicrowaveUI : public IObserver
{
public:
    MicrowaveUI() {
        this->context__ = Context::get_instance();
        this->context__->transition_to(StateDoorClosed::get_instance());
        this->context__->register_observer(this);

        this->state_name__ = this->context__->get_state_name();
        this->state_description__ = this->context__->get_state_description();
    }

    ~MicrowaveUI() {
        this->context__->unregister_observer(this);
        this->context__->destroy_instance();
        this->context__ = nullptr;
    }

    void        render_ui();

    void        open_door();
    void        close_door();
    void        cook_on();
    void        cook_off();
    long double get_ticks();

    void        update() override;

private:
    Context* context__;

    std::string state_name__;
    std::string state_description__;
};

#endif
