#include "hinhelip.h"

hinhelip::~hinhelip()
{

};

void hinhelip::Nhap()
{
    cout<<"Nhap do dai truc dai: ";
    cin>> this->a;
    cout<< endl;

    cout<<"Nhap do dai truc ngan: ";
    cin>> this->b;
    cout<< endl;

    cout<<"Nhap toa do tam: ";
    cin>>this->O.x>> this->O.y;
    cout<< endl;

    cout<<"Nhap tieu cu: ";
    cin>> this->c;
    cout<< endl;

}
void hinhelip::Xuat()
{
    cout<<"Toa do tam: ";
    cout<< endl;

    cout<<"Truc dai: ";
    cout<< endl;

    cout<<"Truc ngan:";
    cout<< endl;

    cout<<"Do dai tieu cu: "<< this->c;
    cout<< endl;
}
