#include "hinhtron.h"

hinhtron::~hinhtron()
{

};
void hinhtron::Nhap()
{
    cout<<"Nhap ban kinh: ";
    cin>>this->r;
    cout<< endl;

    cout<<"Nhap toa do tam: ";
    cin>> this->O.x>> this-> O.y;
    cout<< endl;

}
void hinhtron::Xuat()
{
    cout<<"Ban kinh la: "<< this->r;
    cout<< endl;
    cout<<"Toa do tam la: :"<< "("<< this->O.x<<","<< this->O.y<< ")";
    cout<< endl;
}

