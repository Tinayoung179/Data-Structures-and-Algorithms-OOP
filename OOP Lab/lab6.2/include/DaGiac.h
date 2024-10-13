#include <iostream>
#define MAXN 50
#pragma once
#include "Point.h"

using namespace std;
struct Vector
{
    int x;
    int y;
};

class DaGiac
{
    protected:
        int n;
        Point N[MAXN];
    public:
        DaGiac()
        {
            n = 0;
        }
        virtual void Input();
        virtual void Output();
        void Tinhtien();
        ~DaGiac();

};
