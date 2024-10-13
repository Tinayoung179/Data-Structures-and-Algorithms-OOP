#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class QuanLy
{
    protected:
        string Hoten;//ho ten chua nha vien
        int HeSo;
        int Luong;
    public:
        QuanLy()
        {
            Hoten = ' ';
            HeSo = 0;
        };
        void Nhap();
        void Xuat();
        virtual int TinhLuong(); //ham tinh tien luong cho nhan vien
        ~QuanLy();
};




