
#include "hinhThang.h"
#include "hinhBinhhanh.h"
#include "hinhChunhat.h"
#include "hinhVuong.h"

int main()
{
    cout<<"Cac diem cua hinh xet theo chieu kim dong ho, voi A la diem thap o ben goc trai";
    cout<< endl;

    hinhThang N;
    hinhBinhhanh M;
    hinhChunhat P;
    hinhVuong T;

    int chon;

    cout<<"So 1 la hinh thang";
    cout<< endl;
    cout<<"So 2 la hinh binh hanh ";
    cout<< endl;
    cout<<"So 3 la hinh chu nhat ";
    cout<< endl;
    cout<<"So 4 la hinh vuong ";
    cout<< endl;
    cout<<"Moi chon so: ";
    cin>> chon;
    //tao mang

    for(int i=1; i<=4; i++)
    {
        switch (chon)
        {
        case 1:
            {
                N.Nhap();
                N.Dientich();
                N.Xuat();
            }
            break;
        case 2:
            {
                M.Nhap();
                M.Xuat();
            }
            break;
        case 3:
            {
                P.Nhap();
                P.Xuat();
            }
            break;
        case 4:
            {
                T.Nhap();
                T.Xuat();
            }
            break;
        }
        break;
    }


    return 0;
}
//
