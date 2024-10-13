#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Giasuc
{
    protected:
        int Soluong;
        string TiengKeu;
        int SoConSinh;
        int LitSua;
    public:
        Giasuc();
        ~Giasuc() {};
        int getSoLitSua();
        void Nhap() {};
        void KeuKhiDoi() {};
        void SinhCon() {};
        int ChoSua() {};
        void ThongKe() {};
};
