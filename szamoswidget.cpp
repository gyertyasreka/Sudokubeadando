#include "szamoswidget.hpp"

using namespace genv;
using namespace std;

SzamosWidget::SzamosWidget(Window *w,int min_, int max_, int x_,int y_): Widget(w)
{
    min=min_;
    max=max_;
    a=min_;
    x=x_*(sx+sy+5)+5;
    y=y_*(sy+5)+5;
}
void SzamosWidget::handle(int b)
{
    a+=b;
    if(a<min)a=max;
    if(a>max)a=min;
}
void SzamosWidget::rajzol()
{
    gout<<color(255,255-szin,255-szin)<<move_to(x,y)<<box(sx,sy);
    if(a!=0)gout<<color(0,0,0)<<move_to(x+5,y+5)<<text(to_string(a));
    gout<<move_to(x+sx,y)<<color(237,219,255)<<box(sy,sy)
    <<move_to(x+sx+10,y)<<color(0,0,0)<<text('^')
    <<move_to(x+sx+10,y+sy-20)<<text('v');
}
void SzamosWidget::egerhandle(int evx,int evy)
{
    if(evx>x+sx && evx<x+sx+sy)
    {
        if(evy>y && evy<y+sy/2)
        {
            a++;
            if(a>max)a=min;
        }
        if(evy>y+sy/2 && evy<y+sy)
        {
            a--;
            if(a<min)a=max;
        }
    }
}
void SzamosWidget::idfv(int id_)
{
    id=id_;
}
