#include <iostream>
#include <string>
#include <cmath>
#include "QuanLy.h"
using namespace std;

class GiangVien:
    public QuanLy
{
    private:
        string Khoa;
        int Trinhdo;// nhap theo 1 2 3 tuong duong voi cac chu vu cu nhan, thac si, tien si
        int SoTiet;
    public:
        GiangVien()
        {
            Khoa = ' ';
            Trinhdo = 0;
            SoTiet = 0;
        };
        void Nhap();
        void Xuat();
        int TinhLuong();
};



