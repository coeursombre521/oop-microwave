#ifndef __INTERFACE_UI_H_
#define __INTERFACE_UI_H_

class IApplicationUI
{
public:
    virtual ~IApplicationUI() = default;
    virtual void render() = 0;
};

#endif
