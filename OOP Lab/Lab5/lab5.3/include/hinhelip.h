#pragma once
#include <bits/stdc++.h>


using namespace std;
struct Point
{
    int x;
    int y;
};
class hinhelip
{
    protected:
        Point O;
        int a;// truc dai
        int b;// truc ngan
        int c;// tieu cu
    public:
        hinhelip()
        {
            O.x =0;
            O.y =0;
            a=0;
            b=0;
            c=0;
        };
        void Nhap();
        void Xuat();
        ~hinhelip();
};
