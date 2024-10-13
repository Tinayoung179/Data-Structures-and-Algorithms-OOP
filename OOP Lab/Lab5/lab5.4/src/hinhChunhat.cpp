#include "hinhChunhat.h"

hinhChunhat::~hinhChunhat() {};

void hinhChunhat::Nhap()
{
    cout<<"Nhap toa do cac diem: ";
    cin>>  this->A.x>>  this->A.y;
    cout<< endl;
    cin>>  this->B.y;
    cout<< endl;//Hình chữ nhật: thừa kế hình bình hành và có AB thẳng đứng. Như vậy bạn khỏi phải nhập xB.
    cin>>  this->C.x;
    cout<< endl;
}
void hinhChunhat::Dientich()
{
    float s;
    s= ( this->C.x- this->A.x) * ( this->B.y- this->A.y);
    if(s<0)
    {
        s=-s;
    }
    cout<<"Dien tich la: "<< s;
    cout<< endl;
}
//void hinhChunhat::Vehinh()
//{

//}
void hinhChunhat::Xuat()
{
    Point A,B,C;
    cout<<"Hinh chu nhat ";
    cout<< endl;
    cout<<"Diem 1: "<< "( "<<  this->A.x<<","<<  this->A.y<<")";
    cout<< endl;
    cout<<"Diem 2: "<<"( "<<  this->A.x<<","<<  this->B.y<<")";
    cout<< endl;
    cout<<"Diem 3: "<<"( "<<  this->C.x<<","<<  this->B.y<<")";
    cout<< endl;
    cout<<"Diem 4: "<<"( "<< this->C.x <<","<<  this->A.y<<")";
    cout<< endl;
}
