#include "widget.hpp"
#include "window.hpp"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(Window* w)
{
    w->registerwidget(this);
    sx=30;
    sy=30;
}

bool Widget::felette(int ex, int ey)
{
    return (ex >= x && ey >= y && ex < x + sx + sy && ey < y + sy);
}

void Widget::torol()
    {
        gout << color(222,205,239)<<move_to(0,0)<<box(800,600)
        <<move_to(195,5)<<color(0,0,0)<<box(5,310)
        <<move_to(195*2,5)<<color(0,0,0)<<box(5,310)
        <<move_to(5,105)<<color(0,0,0)<<box(580,5)
        <<move_to(5,2*105)<<color(0,0,0)<<box(580,5);
    }
void Widget::alapszin(int szin_)
{
    szin=szin_;
}
void Widget::idfv(int id_)
{
    id=0;
}
