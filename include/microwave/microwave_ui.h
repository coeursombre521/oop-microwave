#ifndef __MICROWAVE_UI_H_
#define __MICROWAVE_UI_H_

#include <string>
#include <sstream>

#include <microwave/clock_context.h>
#include <microwave/state_context.h>
#include <microwave/interfaces/interface_microwave_ui.h>
#include <microwave/interfaces/interface_observer.h>

static constexpr int MICROWAVE_DEFAULT_COUNTDOWN = 30;

class MicrowaveUI :
    public IMicrowaveUI,
    public IObserver
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
    std::string get_countdown_notice() const;

    ClockContext* clock_context__;
    StateContext* state_context__;
    MicrowaveCountdown* microwave_countdown__;

    std::string state_name__;
    std::string state_description__;
    long double elapsed_time__ = 0.0;
    long double last_elapsed_time = 0.0;
    int countdown__ = 0;
    bool countdown_running__ = false;
};

#endif
