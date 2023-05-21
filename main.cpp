//#include "graphics.hpp"
#include "widget.hpp"
#include "szamoswidget.hpp"
#include "szovegwidget.hpp"
#include "gomb.hpp"
#include "window.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>

//using namespace genv;
using namespace std;



struct Ablak: public Window
{
    //SzovegWidget *w10;
    //SzovegWidget *w11;
    Gomb *w2;
    Ablak() : Window(800,600)
    {
        ifstream f("sudoku.txt");
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int ertek=0;
                f>>ertek;
                if(ertek==0)SzamosWidget *w=new SzamosWidget(this,0,9,j,i);
                else SzamosWidget *w=new SzamosWidget(this,ertek,ertek,j,i);

            }
        }
		/*vector<string> szov={"szilva", "ribizli", "barack", "alma", "meggy"};
        w10=new SzovegWidget(this,szov,XX/4,4);
		szov={"medve", "hal", "kenguru", "macska", "kakadu"};
		w11=new SzovegWidget(this,szov,XX/2,3);*/
        w2=new Gomb(this,[this](){
                this->valami();
        },3*YY/4);
    }
    void valami()
    {
        string nev="sudoku" + to_string(rand()% 3 + 2) + ".txt";
        cout<<nev<<endl;
        ifstream f(nev);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int ertek=0;
                f>>ertek;
                if(ertek==0)widgetek[j+i*9]=new SzamosWidget(this,0,9,j,i);
                else widgetek[j+i*9]=new SzamosWidget(this,ertek,ertek,j,i);

            }
        }
    }
};

int main()
{
    Ablak a;
    a.eventciklus();
    return 0;
}
