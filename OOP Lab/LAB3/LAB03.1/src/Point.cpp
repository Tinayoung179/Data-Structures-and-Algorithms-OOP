#include "Point.h"
Point::~Point(){}
void Point::Import()
{
    cout<<"Nhap hoanh do diem: "<< endl;
    cin>>this->x;
    cout<<"Nhap tung do diem: "<< endl;
    cin>>this->y;
}
void Point::Export()
{
    cout<<"Toa do diem la: "<<endl;
    cout<<"("<<x <<","<<y<<")"<< endl;
}
Point Point::Translation(Point A)
{
    int a, b;
    cout<<"Tinh tien theo vecto (a,b)"<< endl;
    cin>> a>>b;
    A.x= this->x + a;
    A.y= this->y +b;
    return A;
}
