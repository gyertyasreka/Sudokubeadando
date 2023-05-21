//#include "graphics.hpp"
#include "szovegwidget.hpp"

using namespace genv;

SzovegWidget::SzovegWidget(Window *w,std::vector<std::string> szov, int x_,int meret_): Widget(w)
    {
        y=100;
        szoveg=szov;
        for(int i=0;i<5;i++)
        {
            sor.push_back(y+i*sy-5);
        }
        x=x_;
        szin={0,0,0,0,0};
        meret=meret_;
    }
bool SzovegWidget::felette(int ex,int ey)
{
    return(ex>x && ex<x+sx && ey>y && ey<y+meret*sy);
}
void SzovegWidget::rajzol()
{
    for(int i=0;i<meret;i++)
    {
        gout<<color(0,0,0)<<move_to(x,sor[i])<<box(sx,sy)
        <<color(255,255-szin[i],255-szin[i])<<move_to(x+2,sor[i]+2)<<box(sx-4,sy-4)
        <<color(0,0,0)<<move_to(x+5,sor[i]+sy-25)<<text(szoveg[i]);
    }
}
void SzovegWidget::egerhandle(int evx,int evy)
{
    for(int i=0; i < szoveg.size(); i++)
    {
        if(evx>x && evx<x+sx)
        {
            if(evy>sor[i] && evy<sor[i]+sy)
            {
                szin[i]=100;
            }
            else szin[i]=0;
        }
    }
}
void SzovegWidget::handle(int b)
{
    int s;
    std::string sz;
    if(b==2)
    {
        s=szin[0];
        sz=szoveg[0];
        for(int i=0;i < szin.size()-1; i++)
        {
            szin[i]=szin[i+1];
            szoveg[i]=szoveg[i+1];
        }
        szin[szin.size()-1]=s;
        szoveg[szin.size()-1]=sz;
    }

    else
    {
        s=szin[szin.size()-1];
        sz=szoveg[szoveg.size()-1];
        for(int i=sor.size()-1;i > 0; i--)
        {
            szin[i]=szin[i-1];
            szoveg[i]=szoveg[i-1];
        }
        szin[0]=s;
        szoveg[0]=sz;
    }

}

