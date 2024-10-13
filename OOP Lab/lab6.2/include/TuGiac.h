#include <iostream>
#define MAXN 50
#include "DaGiac.h"

using namespace std;


class TuGiac:
    public DaGiac
{
     public:
        TuGiac()
        {
            n = 4;
            N[0].a = 0;
            N[0].b = 0;
            N[1].a = 0;
            N[1].b = 0;
            N[2].a = 0;
            N[2].b = 0;
            N[3].a = 0;
            N[3].b = 0;
        };
        void Input();
        void Output();
        void Tinhtien();
};
