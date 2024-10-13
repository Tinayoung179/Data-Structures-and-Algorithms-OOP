#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAXN 100

using namespace std;

void NhapMang_X(int a[], int &x)
{
    x=30+rand()%51;
    cout<<"So luong phan tu mang = "<<x;
    for(int i=0; i<x; i++)
    {
        a[i]=100+rand()%1000;
    }
}
void NhapMang_Y(int a[], int &y)
{
    y= 30+rand()%51;
    cout<<"So luong phan tu mang = "<<y;

    a[0] = 100+rand()%131;
    for(int i=1; i<y; i++)
    {
        a[i] = a[i-1] + rand()%16;
    }
}
void XuatMang( int a[], int t)
{
    for(int i=0; i<t; i++)
    {
        cout<<a[i]<<" ";
    }
}
//tìm kiếm tuyến tính

int TimTuyenTinh_X( int a[], int t, int X)
{

    for(int i=0; i<t; i++)
    {
        if(a[i]==X) return i;

    }
    return -1;
}
int TimTuyenTinh_X( int a[], int t, int X, int &dem1)
{

    for(int i=0; i<t; i++)
    {
        if(a[i]==X) return i;
        dem1++;

    }
    return -1;
}
//tìm kiếm nhị phân

int TimNhiPhan_X( int a[], int t, int X, int &dem2)
{
    int left=0, right= t-1, mid;
    while(left<=right)
    {
        dem2++;
        mid=left +(right-left)/2;
        if(X==a[mid])
            return mid;
        if(X<a[mid])
            right=mid-1;
        else
            left=mid+1;
    }
    return -1;
}
/*tìm kiếm nội suy:
mid= L+((R+L)/(a[R]-a[L]))* (X-a[L])*/

int TimNoiSuy_X(int a[], int t, int X, int &dem3)
{
    int left=0, right= t-1, mid;

    while(left<=right)
    {
        if(left==right || a[left]==a[right]) return -1;
        mid= left+((right+left)/(a[right]-a[left]))* (X-a[left]);
        if(a[mid]==X)
            return mid;

        else if (a[mid] < X)
        {
            left=mid+1;
            dem3++;
        }
        else if (a[mid] > X)
        {
            right= mid-1;
            dem3++;
        }
    }

    return -1;
}

int main()
{
    int  arrayX[MAXN], arrayY[MAXN];
    int x, y, n, X ;
    int dem1=0, dem2=0, dem3=0 ;
    srand(time(NULL));
    do
    {
        cout<<'\n'<<"============================ MENU ====================================="<<'\n';
        cout<<"=  0,Exit.                                                            ="<<'\n';
        cout<<"=  1,Nhap mang tu dong arrayX.                                        ="<<'\n';
        cout<<"=  2,Nhap mang tu dong tang dan arrayY theo dieu kien de bai.         ="<<'\n';
        cout<<"=  3,Xuat mang.                                                       ="<<'\n';
        cout<<"=  4,Tim kiem tuyen tinh phan tu X cho mang arrayX, arrayY.           ="<<'\n';
        cout<<"=  5,Tim kiem nhi phan phan tu X cho mang arrayY.                     ="<<'\n';
        cout<<"=  6,Tim kiem noi suy phan tu X cho mang arrayY.                      ="<<'\n';
        cout<<"=  7,So sanh so lan tim kiem cua 4, 5, 6 ap dung cho mang arrayY      ="<<'\n';
        cout<<"======================================================================="<<'\n';
        cout<<"                             Choose : ";

        cin>> n;

        switch(n)
        {
        case 1:
        {
            cout<<"Nhap mang tu dong X!";
            NhapMang_X(arrayX, x);
        }
        break;
        case 2:
        {
            cout<<"Nhap mang tu dong Y!";
            NhapMang_Y(arrayY, y);
        }
        break;
        case 3:
        {
            cout<<"Xuat mang X : ";
            XuatMang(arrayX, x);
            cout<<'\n'<<"Xuat mang Y : ";
            XuatMang(arrayY, y);
        }
        break;
        case 4:
        {
            cout<<"Nhap gia tri X can tim : ";
            cin>>X;
            cout<<"Vi tri cua X o mang X : "<<TimTuyenTinh_X(arrayX, x, X);
            cout<<'\n'<<"Vi tri cua X o mang Y : "<<TimTuyenTinh_X(arrayY, y, X, dem1);
        }
        break;
        case 5:
        {
            cout<<"Nhap gia tri X can tim : ";
            cin>>X;
            cout<<"Vi tri cua X o mang Y : "<<TimNhiPhan_X(arrayY, y, X, dem2);
        }
        break;
        case 6:
        {
            cout<<"Nhap gia tri X can tim : ";
            cin>>X;
            cout<<"Vi tri cua X o mang Y : "<<TimNoiSuy_X(arrayY, y, X, dem3);
        }
        break;
        case 7:
        {
            cout<<"So lan tim kiem cua cau 4, 5, 6 theo thu tu :";
            cout<<dem1<<", "<<dem2<<", " <<dem3<<'\n';
        }
        }
    }
    while(n!=0);
    return 0;
}
