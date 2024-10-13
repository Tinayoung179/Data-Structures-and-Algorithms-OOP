#include "hinhVuong.h"

hinhVuong::~hinhVuong(){};

//nhap hinh vuong
void hinhVuong::Nhap()
{
    cout<<"Nhap toa do cac diem: ";
    cin>>  this->A.x>>  this->A.y;
    cout<< endl;
    cin>>  this->B.y;
    cout<< endl;
}
void hinhVuong::Dientich()
{
    float s;
    s= ( this->B.y- this->A.y) * ( this->B.y- this->A.y);
    if(s<0)
    {
        s=-s;
    }
    cout<<"Dien tich la: "<< s;
    cout<< endl;
}
//void hinhVuong::Vehinh()
//{
//}
void hinhVuong::Xuat()
{
    int k;
    k=  this->B.y- this->A.y;
    cout<<"Hinh vuong ";
    cout<< endl;
    cout<<"Diem 1: "<< "( "<<  this->A.x<<","<<  this->A.y<<")";
    cout<< endl;
    cout<<"Diem 2: "<<"( "<<  this->A.x<<","<<  this->B.y<<")";
    cout<< endl;
    cout<<"Diem 3: "<<"( "<<  this->B.x+ k<<","<<  this->B.y<<")";
    cout<< endl;
    cout<<"Diem 4: "<<"( "<< this->A.x+ k <<","<<  this->A.y<<")";
    cout<< endl;
}
