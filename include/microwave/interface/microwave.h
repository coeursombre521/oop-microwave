#ifndef __INTERFACE_MICROWAVE_H_
#define __INTERFACE_MICROWAVE_H_

class IMicrowave
{
public:
    virtual ~IMicrowave() = default;
    virtual void open_door() = 0;
    virtual void close_door() = 0;
    virtual void cook_on() = 0;
    virtual void cook_off() = 0;
};

#endif
