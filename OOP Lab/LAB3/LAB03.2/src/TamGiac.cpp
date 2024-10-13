#include "TamGiac.h"

Point::~Point(){}
TamGiac::TamGiac(Point x,Point y,Point z)
{
    A=x;
    B=y;
    C=z;
}
TamGiac::~TamGiac(){}
void Point::setHoanhdo(int x)
{
    x=this->x;
}
void Point::setTungdo(int y)
{
    y=this->y;
}
int Point::getHoanhdo()
{
    return x;
}
int Point::getTungdo()
{
    return y;
}
void Point::setxy(float a,float b)
{
    x=a;
    y=b;
}
void Point::Nhap()
{
    cout<<"Nhap diem hoanh do diem: "<< endl;
    cin>> this->x;
    cout<<"Nhap tung do diem: "<<endl;
    cin>> this->y;
    cout<<endl;
}
void Point::Xuat()
{
    cout<<"Toa do diem: "<<endl;
    cout<<"("<< this->x<<","<< this->y<<")"<<endl;
}

void Point::TinhTien(float a, float b)
{
    cout<<"Nhap hoanh do: "<<endl;
    cin>>a;
    cout<<"Nhap tung do: "<<endl;
    cin>>b;
    x=this->x + a;
    y=this->y + b;
}
void Point::Quay(float rad)
{
    x=x*cos(rad)+y*sin(rad);
    y=x*sin(rad)+y*cos(rad);
}
void TamGiac::Nhaptamgiac()
{
    cout<<"Ba diem tam giac: ";
    cout<< endl;
    A.Nhap();
    cout<< endl;
    B.Nhap();
    cout<<endl;
    C.Nhap();
    cout<< endl;
}
void TamGiac::Xuattamgiac()
{
    cout<<"Tam giac: ";
    A.Xuat();
    B.Xuat();
    C.Xuat();
}
void TamGiac::tinhtien(float m,float n)
{
     A.TinhTien(m,n);
     B.TinhTien(m,n);
     C.TinhTien(m,n);

}
void TamGiac::quay(float rad)
{
     A.Quay(rad);
     B.Quay(rad);
     C.Quay(rad);
}
void TamGiac::thuphong(float k)
{
     A.setxy(A.getHoanhdo()*k,A.getTungdo()*k);
     B.setxy(B.getHoanhdo()*k,B.getTungdo()*k);
     C.setxy(C.getHoanhdo()*k,C.getTungdo()*k);
}
