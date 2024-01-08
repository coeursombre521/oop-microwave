#ifndef __MICROWAVE_UI_H_
#define __MICROWAVE_UI_H_

#include <string>

#include <clock_context.h>
#include <state_context.h>
#include <state_door_closed.h>
#include <interface_observer.h>

class MicrowaveUI : public IObserver
{
public:
    MicrowaveUI();
    ~MicrowaveUI();

    void        render_ui();

    void        open_door();
    void        close_door();
    void        cook_on();
    void        cook_off();

    void        update(unsigned int notify_id) override;

private:
    ClockContext* clock_context__;
    StateContext* state_context__;

    std::string state_name__;
    std::string state_description__;
    long double elapsed_time__ = 0.0;
};

#endif
