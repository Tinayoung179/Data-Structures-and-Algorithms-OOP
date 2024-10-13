#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class DonHang
{
    protected:
        int Loaihang;
        int Madon;
        string Ngaydat;
        string Ngaynhan;
        string Diachigao;
        int Soluongmathang;
        int Sanpham;
        int MaSP;
        string TenSP;
        int Giatien;
        string NoiSX;
        int LoaiSP;
        int khoiluong;
        int dungtich;
    public:
        DonHang()
        {
            Loaihang = 0;// 1 la ban le, 2 ban si
            Madon = 0;
            Ngaydat =' ';
            Ngaynhan = ' ';
            Diachigao = ' ';
            Soluongmathang = 0;
            Sanpham = 0;
            MaSP = 0;
            TenSP = ' ';
            Giatien = 0;
            NoiSX = ' ';
            LoaiSP = 0;//1 la do uong, 2 la do an
            khoiluong = 0;
            dungtich = 0;
        };
        void Nhap();
        void Xuat();
        virtual int Tiendon();
        ~DonHang();


};


