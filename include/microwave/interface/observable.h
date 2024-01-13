#ifndef __INTERFACE_OBSERVABLE_H__
#define __INTERFACE_OBSERVABLE_H__

#include <microwave/interface/observer.h>

class IObservable
{
public:
    virtual ~IObservable() = default;
    virtual void register_observer(IObserver* observer) = 0;
    virtual void unregister_observer(IObserver* observer) = 0;
    virtual void notify_observers() = 0;
};

#endif
