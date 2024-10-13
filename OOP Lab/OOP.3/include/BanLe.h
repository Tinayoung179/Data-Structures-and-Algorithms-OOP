#include <iostream>
#include <string>
#include <cmath>
#include "DonHang.h"

using namespace std;

class BanLe:
    public DonHang
{
    protected:
        int MaKhachhang;
        string TenKhachhang;
        string DiachiKhach;
        int Sodiethoai;

    public:
        Banle()
        {
            MaKhachhang = 0;
            TenKhachhang = ' ';
            DiachiKhach = ' ';
            Sodiethoai = 0;
        }

        void Nhap();
        void Xuat();
        int Tiendon();
};






