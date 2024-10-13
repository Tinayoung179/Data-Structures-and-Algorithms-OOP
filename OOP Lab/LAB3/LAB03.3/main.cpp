#include "Dagiac.h"

int main()
{
    float a,b,rad,k;
    int n;
     Dagiac A;
     A.nhapDG();
     A.xuatDG();
     cout<<"tinh tien theo vector: ";
     cout<<endl;
     A.tinhtien(a,b);
     A.xuatDG();
     cout<<"quay goc: rad= ";
     cin>>rad;
     A.quay(rad);
     A.xuatDG();
     cout<<"nhap he so thu phong k=";
     cin>>k;
     A.thuphong(k);
     A.xuatDG();

    return 0;
}
