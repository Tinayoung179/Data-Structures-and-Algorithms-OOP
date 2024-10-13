#include "QuanLy.h"
#include "GiangVien.h"
#include "NhanVien.h"


int main()
{
    GiangVien GV[100];// tao 1 mang tinh chua toi da 100 giang vien
    NhanVien NV[100];// tao 1 mang tinh chua toi da 100 nhan vien
    int chon;
    int n;
    int Max = 0;
    cout <<"Nhap so luong can bo: ";
    cin>> n;
    int TongLuong = 0;
    for(int i = 0;i < n; i++ )
    {
        int TienLuongCuaNguoiHienTai;
        cout <<"=======================MENU====================\n"
             <<"=0.Exit                                       =\n"
             <<"=1.Giang vien                                 =\n"
             <<"=2.Nhan vien hanh chinh                       =\n"
             <<"===============================================\n";
        cout <<"Moi chon: ";
        cin >> chon;
        switch(chon)
        {
            case 0:
                {
                    break;
                }
            case 1:
                {
                    GV[i].Nhap();
                    TienLuongCuaNguoiHienTai = GV[i].TinhLuong();
                    GV[i].Xuat();


                    break;
                }
            case 2:
                {
                    NV[i].Nhap();
                    TienLuongCuaNguoiHienTai = NV[i].TinhLuong();
                    NV[i].Xuat();
                    break;
                }
            break;
        }
        TongLuong += TienLuongCuaNguoiHienTai;

    }
    cout <<"Tong tien luong can chi tra la: ";
    cout <<TongLuong;

    return 0;
}
