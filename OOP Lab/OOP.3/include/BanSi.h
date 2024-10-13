#include <iostream>
#include <string>
#include <cmath>
#include "DonHang.h"

using namespace std;

class BanSi:
 public DonHang
{
    protected:
        int MaKhachhang;
        string TenKhachhang;
        string DiachiKhach;
        int Sodiethoai;
        int Madonhang;

    public:
        BanSi()
        {
            MaKhachhang = 0;
            TenKhachhang = ' ';
            DiachiKhach = ' ';
            Sodiethoai = 0;
            Madonhang = 0;
        }

        void Nhap();
        void Xuat();
        int Tiendon();
};

;

