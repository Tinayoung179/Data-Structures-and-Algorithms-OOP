#include "DaGiac.h"
#include "Point.h"


DaGiac::~DaGiac() {};
void DaGiac::Input()
{
    cout<<"Nhap vao so dinh cua da giac: ";

    cin>> n;
    for( int i =0; i<n; i++)
        {
            cin>> N[i].a >> N[i].b;
        }
}
void DaGiac::Output()
{
    cout<<"Toa do cac dinh cua da giac: ";

    for( int i =0; i<n; i++)
        {
            cout<< N[i].a <<"," <<N[i].b<<'/n';
        }
}
