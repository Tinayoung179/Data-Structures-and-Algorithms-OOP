#include <iostream>
#define MAXN 50

#include "DaGiac.h"

using namespace std;

class TamGiac :
    public DaGiac
{
    public:
        TamGiac()
        {
            n = 3;
            N[0].a = 0;
            N[0].b = 0;
            N[1].a = 0;
            N[1].b = 0;
            N[2].a = 0;
            N[2].b = 0;
        };
        void Input();
        void Output();
        void Tinhtien();

};
