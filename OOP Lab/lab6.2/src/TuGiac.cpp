#include "TuGiac.h"
#include "DaGiac.h"


void TuGiac::Input()
{
    cout<<"Nhap toa 4 dinh cua tu giac: "<<endl;
    cin>>this->N[0].a >> this->N[0].b;
    cout<< endl;

    cin>>this->N[1].a >> this->N[1].b;
    cout<< endl;

    cin>>this->N[2].a >> this->N[2].b;
    cout<< endl;

    cin>>this->N[3].a >> this->N[3].b;
    cout<< endl;

}
void TuGiac::Tinhtien()
{
    Vector A;
    cout<<"Nhap gia tri vector: ";

    cin>> A.x >> A.y;

    this->N[0]= TinhtienPoint(A, this->N[0]);
    this->N[1]= TinhtienPoint(A, this->N[1]);
    this->N[2]= TinhtienPoint(A, this->N[2]);
    this->N[3]= TinhtienPoint(A, this->N[3]);
}
void TuGiac::Output()
{
    cout<<"Bon dinh tu giac: \n";

    cout<<"("<< this->N[0].a <<"," << this->N[0].b <<")"<<'\n';

    cout<<"("<< this->N[1].a <<"," << this->N[1].b <<")"<<'\n';

    cout<<"("<< this->N[2].a <<"," << this->N[2].b <<")"<<'\n';

    cout<<"("<< this->N[3].a <<"," << this->N[3].b <<")"<<'\n';
}
