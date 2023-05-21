#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

//const int XX=800;
//const int YY=600;

struct Window;

class Widget
{
protected:
    Window* _w;
    int x, y;
    int sx,sy;
    int a=-1;
    int szin=0;
    int id=0;
public:
    Widget(Window* w);
    virtual void rajzol(){};
    void torol();
    virtual void handle(int b){};
    virtual void egerhandle(int evx, int evy){};
    virtual bool felette(int ex, int ey);
    int ertek() {return a;}
    void alapszin(int szin_);
    virtual void idfv(int id_);
    int idvissza(){return id;}
};

#endif // WIDGET_HPP_INCLUDED
