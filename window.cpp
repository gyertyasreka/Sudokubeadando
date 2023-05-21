#include "window.hpp"
#include "graphics.hpp"
#include "widget.hpp"
#include "szabaly.hpp"
using namespace std;
using namespace genv;

Window::Window(int X, int Y):XX(X),YY(Y)
{
    gout.open(XX,YY);
    gout<< font("LiberationSans-Regular.ttf",20);
}

void Window::eventciklus()
{
    Szabaly *sz;
    widgetek[0]->torol();
    int id_=0;
    for(int i = 0; i < widgetek.size(); i++)
    {
        if(i % 3==0)
        {
            if(i%9==0)
            {
                if(i%27==0)id_++;
                else id_-=2;
            }
            else id_++;
        }
        widgetek[i]->idfv(id_);
    }
    for(Widget* wg :widgetek)
    {
        wg->rajzol();
    }
    gout<<refresh;
    event ev;
    int fokusz =-1;
    while(gin >> ev&& ev.keycode != key_escape)
    {
        if(ev.button==btn_left)
        {
            for(Widget *&w : widgetek)
            {
                w->egerhandle(ev.pos_x,ev.pos_y);
            }
            widgetek[0]->torol();
            sz->ellenorzes(fokusz,widgetek);
            for(Widget *w : widgetek)
            {
                 w->rajzol();
            }
            gout<<refresh;
        }
            if(ev.keycode==key_down && fokusz!=-1)
            {
                widgetek[0]->torol();
                widgetek[fokusz]->handle(-1);
                sz->ellenorzes(fokusz,widgetek);
                for(Widget *w : widgetek)
                {
                    w->rajzol();
                }
                 gout<<refresh;
            }
            if(ev.keycode==key_up && fokusz!=-1)
            {
                widgetek[0]->torol();
                widgetek[fokusz]->handle(1);
                sz->ellenorzes(fokusz,widgetek);
                 for(Widget *w : widgetek)
                 {
                     w->rajzol();
                 }
                gout<<refresh;
            }
            if(ev.keycode==key_pgdn && fokusz!=-1)
            {
                widgetek[0]->torol();
                widgetek[fokusz]->handle(-10);
                sz->ellenorzes(fokusz,widgetek);
                 for(Widget *w : widgetek)
                 {
                     w->rajzol();
                 }
                gout<<refresh;
            }
            if(ev.keycode==key_pgup && fokusz!=-1)
            {
                widgetek[0]->torol();
                widgetek[fokusz]->handle(10);
                sz->ellenorzes(fokusz,widgetek);
                for(Widget *w : widgetek)
                {
                     w->rajzol();
                }
                gout<<refresh;
            }
            if(ev.type==ev_mouse)
            {
                for(int i = 0; i < widgetek.size(); i++)
                {
                    if(widgetek[i]->felette(ev.pos_x, ev.pos_y))
                    {
                        fokusz = i;
                    }
                }
            }
            if(ev.button==btn_wheeldown && fokusz!=-1 &&widgetek[fokusz]->felette(ev.pos_x,ev.pos_y))
            {
                widgetek[fokusz]->handle(2);
                widgetek[0]->torol();
                sz->ellenorzes(fokusz,widgetek);
                for(Widget *w : widgetek)
                {
                     w->rajzol();
                }
                gout<<refresh;
            }
            if(ev.button==btn_wheelup && fokusz!=-1&&widgetek[fokusz]->felette(ev.pos_x,ev.pos_y))
            {
                widgetek[fokusz]->handle(0);
                widgetek[0]->torol();
                sz->ellenorzes(fokusz,widgetek);
                for(Widget *w : widgetek)
                {
                     w->rajzol();
                }
                gout<<refresh;
            }
    }
}
