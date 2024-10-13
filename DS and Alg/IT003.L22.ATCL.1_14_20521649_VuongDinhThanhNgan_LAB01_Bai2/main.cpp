#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 100

using namespace std;
// Cau 1
void NhapMang(int arrayX[], int &x)
{
    for(int i=0; i<x; i++)
    {
        cin>>arrayX[i];
    }
}
// Cau 2
void NhapMangTuDong(int arrayX[], int &x)
{
    x= 10+rand()%41;
    for(int i=0; i<x; i++)
    {
        arrayX[i] = 100+rand()%1000;
    }
}
// Cau 3
void XuatMang(int arrayX[], int x)
{
    for(int i=0; i<x; i++)
    {
        cout<<arrayX[i]<<" ";
    }
}
// Cau 4
int KiemTra(int arrayX[],int x,int i)
{
    int t=arrayX[i];

    for (int j=0; j<i; j++)
    {
        if (t==arrayX[j])return 0;
    }
    return 1;
}
int Dem_1(int arrayX[],int x,int i)
{
    int t=arrayX[i],j=0;

    for (; i<x; i++)
    {
        if (t==arrayX[i]) j++;
    }
    return (j);
}
void DemSoLanXuatHien(int arrayX[], int x)
{
    for (int i=0; i<x; i++)
    {
        if (KiemTra(arrayX,x,i))

            cout<<" Phan tu "<<arrayX[i]<<" xuat hien "<<Dem_1(arrayX,x,i)<<" lan. "<<'\n';
    }
}
// Cau 5
int Dem_X(int arrayX[], int k, int x)
{
    int dem=0;
    for(int i=0; i<x; i++)
    {
        if(arrayX[i]==k)
            dem++;
    }
    return dem;
}
int XuatHienNhieuNhat_1(int arrayX[], int x)
{
    int max=0;
    int dem, a;
    for(int i= x-1; i>=0; i--)
    {
        if(i>0)
            while(arrayX[i] == arrayX[i-1])
                i--;
        dem = Dem_X(arrayX, arrayX[i], x);;
        if(max<=dem)
        {
            a=arrayX[i];
        }
    }
    return a;
}
// Cau 6
int max(int arrayX[], int x)
{
    int max=0;
    int dem, a;
    for(int i= x-1; i>=0; i--)
    {
        if(i>0)
            while(arrayX[i] == arrayX[i-1])
                i--;
        dem = Dem_X(arrayX, arrayX[i], x);;
        if(max<=dem)
        {
            max=dem;
        }
    }
    return max;
}
void XuatHienNhieuNhat_2(int arrayX[], int x)
{
    for(int i=0; i<x; i++)
    {
        if (KiemTra(arrayX,x,i))
        {
            if(Dem_X(arrayX, arrayX[i], x)==max(arrayX, x))
                cout<<arrayX[i]<<" ";
        }
    }
}
// Cau 7
void XuatHienLeNhieuNhat_1(int arrayX[], int x)
{
    for(int i=0; i<x; i++)
    {
        if (arrayX[i]%2==1 && KiemTra(arrayX,x,i))
        {
            if(Dem_X(arrayX, arrayX[i], x)==max(arrayX, x))
                cout<<arrayX[i]<<" ";
        }
    }
}


int main()
{
    int arrayX[MAXN];
    int n, x;
    //srand(time(NULL));
    do
    {
        // Cau 8
        cout<<'\n'<<"---------------------------- MENU -----------------------------"<<endl;
        cout<<"  0.Exit.                                                            "<<endl;
        cout<<"  1.Nhap day cac so nguyen thu cong.                                 "<<endl;
        cout<<"  2.Nhap day cac so nguyen tu dong.                                  "<<endl;
        cout<<"  3.Xuat day cac so nguyen tu dong.                                  "<<endl;
        cout<<"  4.Ham thong ke so luong cac phan tu co trong day.                  "<<endl;
        cout<<"  5/Phan tu xuat hien nhieu nhat trong mang (tra ve gia tri dau neu  "<<endl;
        cout<<"    lan xuat hien cac phan tu trung nhau.                            "<<endl;
        cout<<"  6.Phan tu xuat hien nhieu nhat trong mang (tra ve het gia tri neu  "<<endl;
        cout<<"    lan xuat hien cac phan tu trung nhau).                           "<<endl;
        cout<<"  7.Phan tu le xuat hien nhieu nhat trong mang (tra ve gia tri dau   "<<endl;
        cout<<"    neu lan xuat hien cac phan tu trung nhau).                       "<<endl;
        cout<<"----------------------------------------------------------------------"<<endl;
        cout<<"                             Choose : ";

        cin>> n;

        switch(n)
        {
        case 1:
        {
            cout<<"Nhap so luong phan tu : ";
            cin>>x;
            NhapMang(arrayX, x);
        }
        break;
        case 2:
        {
            cout<<"Nhap mang tu dong.";
            NhapMangTuDong(arrayX, x);
        }
        break;
        case 3:
        {
            cout<<"Mang so nguyen : ";
            XuatMang(arrayX, x);
        }
        break;
        case 4:
        {
            DemSoLanXuatHien(arrayX, x);
        }
        break;
        case 5:
        {
            cout<<"Phan tu xuat hien nhieu nhat trong mang "<<'\n'<<"(tra ve gia tri dau neu trung nha tra ve gia tri dau tien :"<< XuatHienNhieuNhat_1(arrayX, x);
        }
        break;
        case 6:
        {
            XuatHienNhieuNhat_2(arrayX, x);
        }
        break;
        case 7:
        {
            XuatHienLeNhieuNhat_1(arrayX, x);
        }
        break;
        }
    }
    while(n!=0);

    return 0;
}





