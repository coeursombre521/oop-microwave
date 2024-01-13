#ifndef __MICROWAVE_UI_H_
#define __MICROWAVE_UI_H_

#include <string>

#include <clock_context.h>
#include <state_context.h>
#include <interface_microwave_ui.h>
#include <interface_observer.h>

static constexpr int MICROWAVE_DEFAULT_COUNTDOWN = 30;

class MicrowaveUI : public IMicrowaveUI, public IObserver
{
public:
    MicrowaveUI();
    ~MicrowaveUI();

    void render_ui();

    void open_door() override;
    void close_door() override;
    void cook_on() override;
    void cook_off() override;

    void update(unsigned int notify_id) override;

private:
    ClockContext* clock_context__;
    StateContext* state_context__;

    std::string state_name__;
    std::string state_description__;
    long double elapsed_time__ = 0.0;
    long double last_elapsed_time = 0.0;
    int countdown__ = 0;
    int counter_index__;
};

#endif
