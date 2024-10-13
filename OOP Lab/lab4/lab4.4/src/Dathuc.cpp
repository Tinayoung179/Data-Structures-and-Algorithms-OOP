#include "Dathuc.h"

void Dathuc::nhap()
{
    cout<<"Bac da thuc n= ";
    cin>>n;
    a = new int[n+1];
    cout<<endl;
    cout<<"Nhap cac he so cua da thuc: ";
    for(int i=0;i<=n;i++)
    {
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
        cout<<endl;
    }
}
void Dathuc::xuat()
{
    cout<<"Da thuc: ";

    for(int i=0;i<=n;i++)
    {
        cout<<a[i]<<"x^"<<i;
        if(i!=n)
            cout<<" + ";
    }
}
 Dathuc Dathuc::phepcong(Dathuc d)
{
    int nmax = (n>d.n)?n:d.n;
    int nmin = (n<d.n)?n:d.n;
    Dathuc sum(nmax);
    for(int i=nmax;i>nmin;i--) sum.a[i]=(n==nmax)?a[i]:d.a[i];
    for(int i=0;i<=nmin;i++) sum.a[i]=a[i]+d.a[i];
    return sum;
}
Dathuc Dathuc::pheptru(Dathuc d)
{
    int nmax = (n>d.n)?n:d.n;
    int nmin = (n<d.n)?n:d.n;
    Dathuc sub(nmax);
    for(int i=0;i<=nmin;i++) sub.a[i]=a[i]-d.a[i];
    for(int i=nmax;i>nmin;i--) sub.a[i]=(n==nmax)?a[i]:d.a[i];
    return sub;
}
