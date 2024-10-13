#include "DonHang.h"
#include "BanSi.h"
#include "BanLe.h"

int main()
{
    //DonHang A;

    BanLe A[100];
    BanSi B[100];
    int n;
    cout <<"So luong danh sach: ";
    cin >> n;
    cout <<"\n=Chon a la ban le, chon b la ban si=";

    char chon;
    for(int i = 0; i < n;i++)
    {
        cout << "\nMoi chon: ";
        cin >> chon;
        switch(chon)
        {
                case 'a':
            {
                A[i].Nhap();
                A[i].Xuat();
                break;
            }
            case 'b':
            {
                B[i].Nhap();
                B[i].Xuat();
                break;
            }
            break;
        }
    }


    return 0;
}
