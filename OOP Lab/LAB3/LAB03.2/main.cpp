#include "TamGiac.h"
int main()
{
     float a,b,rad,k;
     TamGiac A;
     A.Nhaptamgiac();
     A.Xuattamgiac();
     cout<<"tinh tien theo vector: ";
     cout<<endl;
     A.tinhtien(a,b);
     A.Xuattamgiac();
     cout<<"quay goc: rad= ";cin>>rad;
     A.quay(rad);
     A.Xuattamgiac();
     cout<<"\nnhap he so thu phong k=";cin>>k;
     A.thuphong(k);
     A.Xuattamgiac();
    return 0;
}
