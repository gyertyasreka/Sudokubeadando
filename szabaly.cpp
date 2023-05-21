#include "szabaly.hpp"
#include <vector>

void Szabaly::ellenorzes(int fokusz_,std::vector<Widget *> &widgetek_)
{
    bool van=false;
    for(int i = 0; i < widgetek_.size(); i++)
    {
        if(i!=fokusz_ && widgetek_[fokusz_]->ertek()>0 && (i % 9 == fokusz_ % 9 || i/9==fokusz_/9 || widgetek_[fokusz_]->idvissza()==widgetek_[i]->idvissza()))
        {
            if(widgetek_[i]->ertek()==widgetek_[fokusz_]->ertek())
            {
                van=true;
            }
        }
    }
    if(van)widgetek_[fokusz_]->alapszin(100);
    else if(widgetek_[fokusz_]->ertek()!=-1) widgetek_[fokusz_]->alapszin(0);
}
