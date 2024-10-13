#include "hinhBinhhanh.h"

hinhBinhhanh::~hinhBinhhanh(){};
// nhap hinh binh hanh
void hinhBinhhanh::Nhap()
{
    Point A,B,C;
    cout<<"Nhap toa do cac diem: ";
    cout<< endl;
    cin>>  this->A.x>> this-> A.y;
    cout<< endl;
    cin>>  this->B.x >>  this->B.y;// hinh binh ke thua tu hinh thanh co 2 day bang nhau neen khong nhap D
    cout<< endl;
    cin>>  this->C.x;
}
void hinhBinhhanh::Dientich()
{
    float s;
    Point A,B,C;
    s = ( this->C.x- this->B.x) * ( this->B.y- this->A.y);
    if(s<0)
    {
        s=-s;
    }
    cout<<"Dien tich la: "<< s;
    cout<< endl;
}
//void hinhBinhhanh::Vehinh()
//{
//}
// xuat hinh binh hanh
void hinhBinhhanh::Xuat()
{
    int d;
    d=  this->C.x- this->B.x;
    cout<<"Hinh binh hanh ";
    cout<< endl;
    cout<<"Diem 1: "<< "( "<<  this->A.x<<","<<  this->A.y<<")";
    cout<< endl;
    cout<<"Diem 2: "<<"( "<<  this->B.x<<","<<  this->B.y<<")";
    cout<< endl;
    cout<<"Diem 3: "<<"( "<<  this->C.x<<","<<  this->B.y<<")";
    cout<< endl;
    cout<<"Diem 4: "<<"( "<< this->A.x+ d<<","<<  this->A.y<<")";
    cout<< endl;
}
