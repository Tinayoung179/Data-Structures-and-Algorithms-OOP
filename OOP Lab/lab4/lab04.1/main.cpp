#include "Ctimespan.h"
int main()
{
    Ctimespan a,c,b;

    a.Nhap();
    b.Nhap();

    c=a.phepcong(b);
    c.Xuat();

    c=a.pheptru(b);
    c.Xuat();

    cout<<endl;
    cout<<a.phepbang(a);

    cout<<endl;
    cout<<a.phepbe(a);

    cout<<endl;
    cout<<a.pheplon(a);

    cout<<endl;
    cout<<a.LonHonBang(a);

    cout<<endl;
    cout<<a.NhoHonBang(a);
    return 0;
}
