#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED

#include "widget.hpp"
//#include "graphics.hpp"
#include <functional>

class Gomb : public Widget
{
protected:
    std::function<void()> _f;
public:
    Gomb(Window* w,std::function<void()> f,int Y);
    virtual void rajzol();
    virtual void egerhandle(int evx,int evy);
};


#endif // GOMB_HPP_INCLUDED
