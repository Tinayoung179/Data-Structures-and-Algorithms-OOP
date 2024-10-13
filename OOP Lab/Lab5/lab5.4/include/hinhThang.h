#pragma once
#include <bits/stdc++.h>

using namespace std;

// struct diem
struct Point
{
    int x;
    int y;
};
class hinhThang
{
    protected:
        Point A,B,C,D;
    public:
        hinhThang()
        {
            A.x=0;
            A.y=0;
            B.x=0;
            B.y=0;
            C.x=0;
            C.y=0;
            D.x=0;
            D.y=0;
        };
        void Nhap();
        void Xuat();
        void Dientich();
        ~hinhThang();
};
