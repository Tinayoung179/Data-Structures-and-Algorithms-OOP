#include "TamGiac.h"
#include "DaGiac.h"


void TamGiac::Input()
{
    cout<<"Nhap toa 3 dinh cua tam giac: "<<endl;
    cin>>this->N[0].a >> this->N[0].b;
    cout<< endl;

    cin>>this->N[1].a >> this->N[1].b;
    cout<< endl;

    cin>>this->N[2].a >> this->N[2].b;
    cout<< endl;

}
void TamGiac::Tinhtien()
{
    Vector A;
    cout<<"Nhap gia tri vector: ";
    cin>> A.x >> A.y;
    this->N[0]= TinhtienPoint(A, this->N[0]);
    this->N[1]= TinhtienPoint(A, this->N[1]);
    this->N[2]= TinhtienPoint(A, this->N[2]);
}
void TamGiac::Output()
{
    cout<<"Ba dinh tam giac: \n";

    cout<<"("<< this->N[0].a <<"," << this->N[0].b <<")"<<'\n';

    cout<<"("<< this->N[1].a <<"," << this->N[1].b <<")"<<'\n';

    cout<<"("<< this->N[2].a <<"," << this->N[2].b <<")"<<'\n';
}
