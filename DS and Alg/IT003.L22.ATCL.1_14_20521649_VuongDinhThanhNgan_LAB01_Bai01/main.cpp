#include <bits/stdc++.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAXN 200

using namespace std;

struct DonThuc
{
    int HeSo;
    int SoMu;
};

void NhapDaThuc1(DonThuc DT[],int &x)
{
    for(int i=0; i<x; i++)
    {
        cout<<"Nhap he so thu: "<<i+1<<" = ";
        cin>>DT[i].iHeSo;

        cout<<"Nhap so mu thu: "<<i+1<<" = "<<endl;
        cin>>DT[i].SoMu;

    }
}
void NhapDaThuc2(DonThuc DT[], int &t)
{
    t= 1+ rand()%10;
    cout<<"So luong phan tu tu dong la: "<< t;

    for(int i=0; i<t; i++)
    {
        DT[i].HeSo=39+rand()%41;
        DT[i].SoMu=rand()%10;
    }
}
void Xuat(DonThuc DT)
{
    cout << DT.HeSo;
    if(DT.SoMu==1) cout << "x";
    if(DT.SoMu>1) cout << "x^" << DT.SoMu<<" ";
}
void XuatDaThuc(DonThuc DT[], int t)
{
    bool D=false;
    cout<<"y = f(x) = ";
    if(t>0 && DT[0].HeSo==0) D=true;
    for(int i=0; i<t; i++)
    {
        if(DT[i].HeSo==0) continue;
        if(i==0)
        {
            Xuat(DT[i]);
            continue;
        }

        if (DT[i].HeSo>0 && D!=true)
        {
            cout << " + ";
        }
        if(D==true) D=false;
        Xuat(DT[i]);
    }
}
void SapXepDaThuc(DonThuc DT[], int &t)
{
    for(int i=0; i<t; i++)
        for(int j=0; j<t-i-1; j++)
        {
            if(DT[j].SoMu < DT[j+1].SoMu)
                swap(DT[j].SoMu, DT[j+1].SoMu);
        }
    for(int i=t-1; i>=0; i--)
    {
        while(DT[i].SoMu==DT[i-1].SoMu)
        {
            DT[i-1].HeSo+=DT[i].HeSo;
            i--;
            if(i==0) break;

        }
    }
    XuatDaThuc(DT, t);

}
int TongDaThuc(DonThuc DT[],int x, const int X)
{
    long int Sum=0;

    for(int i=0; i<x ; i++)
    {
        Sum += (DT[i].HeSo*pow(X, DT[i].SoMu));
    }
    return Sum;
}
void BacLonNhat(DonThuc DT[], int t)
{
    int max = DT[0].SoMu, x;
    for(int i=0; i<t; i++)
    {
        if(max < DT[i].SoMu)
        {
            x=i;
            max=DT[i].SoMu;
        }
    }
   Xuat(DT[x]);

}
void BacNhoNhat(DonThuc DT[], int t)
{
    int min = DT[0].SoMu, a=0;
    for(int i=0; i<t; i++)
    {
        if(min >  DT[i].SoMu)
        {
            a = i;
            min = DT[i].SoMu;
        }
    }
    Xuat(DT[a]);
}
int TongDonThuc(DonThuc DT[], int x, const int X)
{
    DonThuc max, min;
    int a, b, S=0;
    if(DT[0].SoMu < DT[1].SoMu)
    {
        max.SoMu = DT[1].SoMu;
        a=1;
        min.SoMu = DT[0].SoMu;
        b=0;
    }
    else
    {
        max.iSoMu = DT[0].SoMu;
        a=0;
        min.iSoMu = DT[1].SoMu;
        b=1;
    }
    for(int i=2; i<x; i++)
    {
        if( DT[i].SoMu % 2 == 0 && DT[i].SoMu > max.SoMu)
        {
            max.SoMu = DT[i].SoMu;
            a = i;
        }
    }
    for(int i=2; i<x; i++)
    {
        if( DT[i].SoMu % 2 != 0 && DT[i].SoMu < min.SoMu)
        {
            min.SoMu = DT[i].SoMu;
            b = i;
        }
    }
    S = DT[a].HeSo*pow(X, max.SoMu) + DT[b].HeSo*pow(X, min.SoMu);
    return S;
}
float ThuongDonThuc(DonThuc DT[], int x, const int X)
{
    DonThuc max, min;
    int a, b;
    float S=0;
    if(DT[0].SoMu < DT[1].SoMu)
    {
        max.SoMu = DT[1].SoMu;
        a=1;
        min.SoMu = DT[0].SoMu;
        b=0;
    }
    else
    {
        max.SoMu = DT[0].SoMu;
        a=0;
        min.SoMu = DT[1].SoMu;
        b=1;
    }
    for(int i=2; i<x; i++)
    {
        if( DT[i].SoMu > max.SoMu)
        {
            max.SoMu = DT[i].SoMu;
            a = i;
        }
    }
    for(int i=2; i<x; i++)
    {
        if( DT[i].SoMu < min.SoMu)
        {
            min.SoMu = DT[i].SoMu;
            b = i;
        }
    }
    S = (DT[a].HeSo*pow(X, max.SoMu)) /(float) (DT[b].HeSo*pow(X, min.SoMu));
    return S;
}

void QuickSort(DonThuc DT[], int left, int right, int x)
{	int	i, j, t;
	t = DT[(left+right)/2].SoMu;
	i = left; j = right;
  	do
	{
	     	while(DT[i].SoMu > t) i++;
	     	while(DT[j].SoMu < t) j--;
     		if(i <= j)
		{
			swap(DT[i].SoMu, DT[j].SoMu);
			swap(DT[i].HeSo, DT[j].HeSo);
       		i++ ; j--;
	 	}
	} while(i <= j);

	if(left<j)
		QuickSort(DT, left, j, x);
	if(i<right)
		QuickSort(DT, i, right, x);
}

int main()
{
    DonThuc DT[MAXN];
    int n, X, x;
     srand(time(NULL));



    do
    {
        cout<<'\n'<<"============================ MENU ==============================="<<'\n';
        cout<<"=  0,Exit.                                                      ="<<'\n';
        cout<<"=  1,Nhap da thuc .                           ="<<'\n';
        cout<<"=  2,Nhap da thuc tu cong.                            ="<<'\n';
        cout<<"=  3,Xuat da thuc .                                             ="<<'\n';
        cout<<"=  4,Xuat da thuc voi so mu giam dan.                          ="<<'\n';
        cout<<"=  5,Tinh gia tri y=f(x).                                       ="<<'\n';
        cout<<"=  6,Tim don thuc co bac lon nhat trong da thuc.           ="<<'\n';
        cout<<"=  7,Tim don thuc co bac nho nhat trong da thuc.           ="<<'\n';
        cout<<"=  8,Ham tinh tong hai don thuc(chan lon va le nho nhat).  ="<<'\n';
        cout<<"=  9,Ham tinh thuong hai don thuc(lon va nho nhat).        ="<<'\n';
        cout<<"=  10,Sap xep don thuc theo so mu gian dan.                      ="<<'\n';
        cout<<"================================================================="<<'\n';
        cout<<"                  Chon so : ";

        cin>>n;


        switch(n)
        {
        case 1:
        {
            cout<<"Nhap so luong phan tu co trong da thuc : ";
            cin>>x;
            NhapDaThuc1(DT, x);
        }
        break;
        case 2:
        {
            NhapDaThuc2(DT, x);

        }
        break;
        case 3:
        {
            XuatDaThuc(DT, x);
        }
        break;
        case 4:
        {
            cout<<"Da thuc theo so mu giam dan : "<<'\n';
            SapXepDaThuc(DT, x);
        }
        break;
        case 5:
        {
            cout<<'\n'<<"Nhap gia tri X cua da thuc : ";
            cin>>X;
            cout<<"Tong da thuc theo gia tri X = "<<X<<" la : y = f("<<X<<") = "<<TongDaThuc(DT, x, X) ;
        }
        break;
        case 6:
        {
            cout<<"Don thuc co bac lon nhat la : ";
            BacLonNhat(DT, x) ;
        }
        break;
        case 7:
        {
            cout<<"Don thuc co bac nho nhat la : ";
            BacNhoNhat(DT, x);
        }
        break;
        case 8:
        {

            cout<<"Tong 2 don thuc trong da thuc (bac chan max va bac le min) la : ";
            cout<<TongDonThuc(DT, x, X);
        }
        break;
        case 9:
        {
            cout<<"Thuong 2 don thuc trong da thuc la (max va mim): ";
            cout<<ThuongDonThuc(DT, x, X);
        }
        break;
        case 10:
            {
                cout<<"Da thuc duoc sap xep theo so mu giam dan : "<<'\n';
                QuickSort(DT, 0 , x-1, x);
                        XuatDaThuc(DT, x);

            }
        }
    }
    while(n!=0);

    return 0;
}
