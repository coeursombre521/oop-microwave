#ifndef __INTERFACE_OBSERVER_H__
#define __INTERFACE_OBSERVER_H__

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void update() = 0;
};

#endif
