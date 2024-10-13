#include "Ngay.h"

Ngay::~Ngay()
{

};

istream& operator>>(istream& in, Ngay& a)
{
    cout <<"Nhap ngay: ";
    in >> a.Ngay;'
    cout <<"\nNhap thang: ";
    in >> a.Thang;
    cout <<"\nNhap nam: ";
    in >> a.Nam;
}

ostream& operator<<(ostream& out, Ngay& a)
{
    cout <<"nNgay thang nam la: ";
    out << a.Ngay <<"/" << a.Ngay <<"/" << a.Nam;
    return out;
}
