#ifndef __INTERFACE_OBSERVER_H__
#define __INTERFACE_OBSERVER_H__

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void update(unsigned int notify_id) = 0;
};

#endif
