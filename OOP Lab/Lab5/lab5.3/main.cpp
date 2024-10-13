
#include "hinhtron.h"
#include "hinhelip.h"

int main()
{
    int Chonhinh;

    hinhtron T;

    hinhelip E;

    cout<<"0 la hinh tron"<< endl;
    cout<<"1 la hinh elip"<< endl;
    cin>> Chonhinh;
    if (Chonhinh==0)
    {
        T.Nhap();
        T.Xuat();

    }
    if (Chonhinh==1)
    {
        E.Nhap();
        E.Xuat();
    }

    return 0;
}
