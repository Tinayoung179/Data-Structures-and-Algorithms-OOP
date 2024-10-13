
#include <bits/stdc++.h>
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
class TamGiac
{
    private:
        Point A,B,C;
    public:
         TamGiac()
         {
             Point A;
         };
         TamGiac(Point, Point, Point);
          ~TamGiac(void);
         void Nhaptamgiac();
         void Xuattamgiac();
         void tinhtien(float ,float);
         void quay(float);
         void thuphong(float);
};
