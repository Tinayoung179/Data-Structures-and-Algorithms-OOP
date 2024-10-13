#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>

#define MAXN 100

using namespace std;

// cau 1
void NhapMangThuCong(float a[], int &n)
{
    cin>> n;
    for (int i=0; i<n; i++)
    {
        cin>> a[i];
    }

}
// cau 2
void NhapMangTuDong(float a[], int &n)
{
    srand(time(NULL));
    n= rand();
    cout<< "Xuat mang tu dong";
    for (int i=0; i<n; i++)
    {
        a[i]=(float)(rand()%100000)/(float)(1+rand()%100000);
        cout<< a[i]<< endl;
    }
}
// cau 3
void NhapMang_2(float a[], int &n)
{
    srand(time(NULL));
    n= rand();
    cout<< " Xuat mang 2";
    for (int i=0; i<n; i++)
    {
        a[i]=(float)(rand()%100000)/(float)(1+rand()%100000);
        cout<< a[i]<< endl;
    }
}
// cau 4
void XuatMang(float a[], int n)
{
    cout<<"Xuat mang"<< endl;
    for (int i=0; i<n; i++)
        {
            cout<< a[i]<<" ";
        }
}
// cau 5 chon truc tiep
void SelectionSort(float a[], int n, bool asc)
{
    int i,j,tmp;
	for(i=0;i<n-1;i++)
	{
	    if (asc == false)
		{
            int Min=i;
            for(j=i+1;j<n;j++)
            {
                if (a[j]<a[Min])
                    Min=j;
                tmp=a[i];
                a[i]=a[Min];
                a[Min]=tmp;
            }
        }
        else
        {
            int Max=i;
            for(j=i+1;j<n;j++)
            {
                if (a[j]<a[Max])
                    Max=j;
                tmp=a[i];
                a[i]=a[Max];
                a[Max]=tmp;
            }
        }
	}
}

// cau 6
double timeSelection(float a[], int n)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    SelectionSort(a, n, true);
    end = clock();
    cpu_time_used=((double(end-start))/CLOCKS_PER_SEC);
    return cpu_time_used;
}
// cau 7 chen truc tiep
void InsertionSort(float a[], int n)
{
    int tmp,j;
    for(int i=1; i<n; i++)
    {
        tmp= a[i];
        j=i;
        {
            while( j>0 && a[j-1]>tmp)
            {
                a[j]=a[j-1];
                j--;
            }
            a[j]=tmp;
        }
        {
            while(j>0 && a[j-1]< tmp)
            {
                a[j]=a[j-1];
                j--;
            }
            a[j]=tmp;
        }
    }
}
// cau 8
double timeInsertion(float a[], int n)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    InsertionSort(a, n);
    end = clock();
    cpu_time_used=((double(end-start))/CLOCKS_PER_SEC);
    cout << cpu_time_used;
    return cpu_time_used;
}
// cau 9
void Compare()
{
    for(int i=0; i<15; i++)
    {
        int Size = (rand() % (110000 + 1 - 100000)) + 100000;
        float a[Size];
        for (int j = 0; j < Size; j++)
        {
            a[j] = rand();
        }
        double time1 = timeInsertion(a, Size);
        double time2 = timeSelection(a, Size);
        //if( time1 > time 2)
          //  cout<< "O lan chay thu: " << i << " " << "voi mang co: " << Size << " " <<"thi chen truc tiep co thoi gian chay lau hon chon truc tiep";
        //else
          //  cout<< cout<< "O lan chay thu: " << i << " " << "voi mang co: " << Size << " " << "thi chon truc tiep co thoi gian chay lau hon chen truc tiep";
    }
}
int main()
{
    float a[MAXN];
    int n, b;

    cout<<"--------------------------------MENU--------------------------------------"<<endl;
    cout<<"=1.Nhap gia tri cho mang theo phuong phap thu cong                       ="<<endl;
    cout<<"=2.Khoi tao phan tu tu dong cho mang                                     ="<<endl;
    cout<<"=3.Khoi tao tu dong cac phan tu thuoc khoang gia tri                     ="<<endl;
    cout<<"=4.Xuat cac gia tri trong mang                                           ="<<endl;
    cout<<"=5.Sap xep mang theo Selection Sort                                      ="<<endl;
    cout<<"                 A.Tang dan                                              ="<<endl;
    cout<<"                 B.Giam dan                                              ="<<endl;
    cout<<"=6.Tinh thoi gian thuc hien xap xep mang tang/ giam da( Selection Sort)  ="<<endl;
    cout<<"=7.Sap xep mang theo Insertion Sort                                      ="<<endl;
    cout<<"                 A.Tang dan                                              ="<<endl;
    cout<<"                 B.Giam dan                                              ="<<endl;
    cout<<"=8.Tinh thoi gian thuc hien xap xep mang tang/ giam dan( Insertion Sort) ="<<endl;
    cout<<"=9.So anh thoi gian thuc hien sap xep mang cua hai thuat toan            ="<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<" CHON SO: ";
    cin>> b;
    switch(b)
    {
        case 1:
            {
                cout<<"Nhap Mang: ";
                NhapMangThuCong(a, n);
            }
        case 2:
            {
                cout<<"Mang tu dong: ";
                NhapMangTuDong(a, n);
            }
        case 3:
            {
                cout<<"Mang tu dong co cac phan tu nam trong khoang cho truoc: ";
                 NhapMang_2(a, n);
            }
        case 4:
            {
                cout<<"Xuat mang: ";
                XuatMang(a, n);
            }
        case 5:
            {
                cout<<"Chon truc tiep: ";
                int chon;
                switch (chon){
                    cout << "Chon 1 de tang dan, chon 2 de giam dan";
                    case 1: SelectionSort(a, n, true);
                    case 2: SelectionSort(a, n, false);
                }
            }
        case 6:
            {
                cout<<"Thoi gian chay cua Selection Sort: ";
                 timeSelection(a, n);
            }
        case 7:
            {
                cout<<"Chen truc tiep: ";
                InsertionSort(a,n);
            }
        case 8:
            {
                cout<<"Thoi gian chay cuar Insertion Sort: ";
                 timeInsertion(a, n);
            }
        case 9:
            {
                cout<<"So sanh thoi gian chay hai Sort: ";
                Compare();
            }
    }
    return 0;
}
