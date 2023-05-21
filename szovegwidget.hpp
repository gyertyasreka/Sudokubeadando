#ifndef SZOVEGWIDGET_HPP_INCLUDED
#define SZOVEGWIDGET_HPP_INCLUDED

#include "widget.hpp"
#include "graphics.hpp"

class SzovegWidget : public Widget
{
protected:
    std::vector<std::string> szoveg;
    std::vector<int> sor;
    std::vector<int> szin;
    int meret;
public:
    SzovegWidget(Window*w,std::vector<std::string> szov, int x_,int meret_);
    void rajzol();
    bool felette(int ex,int ey);
    void handle(int b);
    void egerhandle(int evx,int evy);
};

#endif // SZOVEGWIDGET_HPP_INCLUDED
