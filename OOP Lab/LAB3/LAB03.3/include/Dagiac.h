#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

class Point
{
    private:
        int x;
        int y;
    public:
        Point()
        {
            x=0;
            y=0;
        };
        void Nhap();
        void Xuat();
        int getHoanhdo();
        int getTungdo();
        void setHoanhdo(int x);
        void setTungdo(int y);
        void setxy(float,float);
        void TinhTien(float, float);
        void Quay(float);

        ~Point();
};
class Dagiac
{
    private:
        int n;
        Point A[MAXN];
    public:
        Dagiac()
        {
            n=0;
        }
        void nhapDG();
        void xuatDG();
        void tinhtien(float, float);
        void quay(float);
        void thuphong(float);
        ~Dagiac();
};
