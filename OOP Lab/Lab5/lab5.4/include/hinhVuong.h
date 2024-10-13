#include <bits/stdc++.h>
#include <graphics.h>
#include "hinhChunhat.h"

using namespace std;

class hinhVuong:
    public hinhChunhat
{
    protected:
        Point A;
    public:
        hinhVuong()
        {
            A.x=0;
            A.y=0;
            B.x=0;
            B.y=0;
        };
        void Nhap();
        void Xuat();
        //void Vehinh();
        void Dientich();
        ~hinhVuong();
};
