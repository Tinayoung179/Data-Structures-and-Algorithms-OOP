#include "QuanLy.h"

QuanLy::~QuanLy()
{

};

void QuanLy::Nhap()
{
    cout <<"Nhap ho va ten: ";
    cin.ignore();
    getline(cin,this->Hoten);//nhap vao ten cu nhan vien
    fflush(stdin);

    cout <<"Nhap he so luong: ";
    cin >> this->HeSo;

}
int QuanLy::TinhLuong()
{
    return this->Luong;
}
void QuanLy::Xuat()
{
    cout <<"Ho va ten: ";
    cout << this->Hoten;
    fflush(stdin);
}
