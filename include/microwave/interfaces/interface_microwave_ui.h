#ifndef __INTEFACE_MICROWAVE_UI_H_
#define __INTEFACE_MICROWAVE_UI_H_

class IMicrowaveUI
{
public:
    virtual ~IMicrowaveUI() = default;
    virtual void open_door() = 0;
    virtual void close_door() = 0;
    virtual void cook_on() = 0;
    virtual void cook_off() = 0;
};

#endif
