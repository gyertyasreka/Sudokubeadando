#include "graphics.hpp"
#include "gomb.hpp"
#include "window.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Gomb::Gomb(Window* w, std::function<void()> f,int Y): Widget(w)
{
    x=50;
    y=Y;
    sx=30;
    sy=sx;
    _f=f;
}

void Gomb::rajzol()
{
    for(int i=-sx;i<=sx;i++)
    {
        for(int j=-sx;j<=sx;j++)
        {
            if(i*i+j*j<=sx*sx)gout << color(0, 0, 0)<<move_to(x+i,y+j)<<dot;
        }
    }
    for(int i=-sx+4;i<=sx-4;i++)
    {
        for(int j=-sx+4;j<=sx-4;j++)
        {
            if(i*i+j*j<=(sx-4)*(sx-4))gout<< color(255,255-szin, 255-szin)<<move_to(x+i,y+j)<<dot;
        }
    }
    if(szin==0)
    {
        gout<<move_to(x-sx,y+sy+20)<<color(0,0,0)<<text("Uj palyahoz nyomd meg a gombot");
    }
}
void Gomb::egerhandle(int evx,int evy)
{
    if ((evx-x)*(evx-x)+(evy-y)*(evy-y)<sx*sx)
    {
        szin=100;
        _f();
    }
    else
    {
        szin=0;
    }
}
