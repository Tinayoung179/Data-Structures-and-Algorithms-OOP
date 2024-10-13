#include "Dagiac.h"

Point::~Point(){}

Dagiac::~Dagiac(){}

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
void Dagiac::nhapDG()
{
    cout<<"So diem da giac: ";
    cin>>n;
    {
        if(n<3)
        {
            cout<<"Moi nhap lai"<<endl;
            cin>>n;
        }
    }
    cout<< endl;
    for(int i=1; i<=this->n; i++)
    {
        A[i].Nhap();
        cout<< endl;
    }
}
void Dagiac::xuatDG()
{
    cout<<"Da giac: ";
    for( int i=1; i<=this->n;i++)
    {
        this->A[i].Xuat();
    }
}
void Dagiac::tinhtien(float m,float n)
{
     for(int i=1; i<=this->n; i++)
     {
         this->A[i].TinhTien(m,n);
     }

}
void Dagiac::quay(float rad)
{
     for(int i=1; i<=n; i++)
     {
         A[i].Quay(rad);
     }
}
void Dagiac::thuphong(float k)
{
     for(int i=1; i<=n; i++)
     {
         A[i].setxy(A[i].getHoanhdo()*k,A[i].getTungdo()*k);
     }
}
