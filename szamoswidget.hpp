#ifndef SZAMOSWIDGET_HPP_INCLUDED
#define SZAMOSWIDGET_HPP_INCLUDED

#include "widget.hpp"
#include "graphics.hpp"

class SzamosWidget : public Widget
{
protected:
    int min,max;
public:
    SzamosWidget(Window *w,int min_,int max_, int x_,int y_);
    virtual void handle(int b);
    virtual void rajzol();
    virtual void egerhandle(int evx, int evy);
    virtual void idfv(int id_);
};

#endif // SZAMOSWIDGET_HPP_INCLUDED
