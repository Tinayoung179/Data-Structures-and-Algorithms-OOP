#include "Dathuc.h"

int main()
{
    Dathuc a,b,c;

    a.nhap();
    b.nhap();

    c=a.phepcong(b);
    c.xuat();

    c=a.pheptru(b);
    c.xuat();
    return 0;
}
