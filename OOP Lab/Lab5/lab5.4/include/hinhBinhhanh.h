#pragma once
#include <bits/stdc++.h>
#include <graphics.h>
#include "hinhThang.h"

using namespace std;
class hinhBinhhanh:
    public hinhThang
{
    protected:
        Point A,B,C;
    public:
        hinhBinhhanh()
        {
            A.x=0;
            A.y=0;
            B.x=0;
            B.y=0;
            C.x=0;
            C.y=0;
        };
        void Nhap();
        void Xuat();
        void Dientich();
        ~hinhBinhhanh();

};
