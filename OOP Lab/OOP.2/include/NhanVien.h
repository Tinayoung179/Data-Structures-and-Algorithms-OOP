#include <iostream>
#include <string>
#include <cmath>
#include "QuanLy.h"
using namespace std;


class NhanVien:
    public QuanLy
{
    private:
        string PhongBan;
        int Chucvu;// chuc vu nhap theo co 1 2 3 tuong duong voi truong phong, pho phong, nhan vien
        int SoNgay;
    public:
        NhanVien()
        {
            PhongBan = ' ';
            Chucvu = 0;
            SoNgay = 0;
        };
        void Nhap();
        void Xuat();
        int TinhLuong();
};


