#include "hinhThang.h"

hinhThang::~hinhThang() {};
//ham nhap hinh thang
void hinhThang::Nhap()
{
    cout<<"Nhap toa do cac diem: ";
    cin>> this->A.x >> this->A.y;
    cout<< endl;
    cin>> this->B.x >> this->B.y;
    cout<< endl;
    cin>> this->C.x;
    cout<< endl;
    cin>> this->D.x;
    cout<< endl;
}

// xuat hinh thang
void hinhThang::Xuat()
{
    cout<<"Hinh thang";
    cout<< endl;
    cout<<"Diem 1: "<< "( "<<this->A.x<<","<< this->A.y<<")";
    cout<< endl;
    cout<<"Diem 2: "<< "( "<<this->B.x<<","<< this->B.y<<")";
    cout<< endl;
    cout<<"Diem 3: "<< "( "<<this->C.x<<","<< this->B.y<<")";
    cout<< endl;
    cout<<"Diem 4: "<< "( "<<this->D.x<< ","<<this->A.y<<")";
    cout<< endl;
}
// tinh dien tich hinh thang
void hinhThang::Dientich()
{
    float s;

    s=((this->C.x-this->B.x)+(this->D.x- this->A.x))/2 * (this->B.y-this->A.y);
    if(s<0)
    {
        s=-s;
    }
    cout<<"Dien tich la: "<< s;
    cout<< endl;
}
