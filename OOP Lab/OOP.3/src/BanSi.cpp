#include "BanSi.h"

void BanSi::Nhap()
{
    DonHang::Nhap();

    cout <<"\nNhap ma khac hang: ";
    cin >> this->MaKhachhang;

    cout <<"\Nhap ten khach hang: ";
    cin.ignore();
    getline(cin, this->TenKhachhang);
    fflush(stdin);

    cout <<"\Nhap dia chi khach hang: ";
    cin.ignore();
    getline(cin, this->DiachiKhach);
    fflush(stdin);

    cout <<"\nNhap so dien thoai khach hang: ";
    cin >> Sodiethoai;

    cout <<"\nNhap ma don hang: ";
    cin>> this->Madonhang;

}

int BanSi::Tiendon()
{
    this->Giatien = this->Giatien * this->Soluongmathang;

    return this->Giatien;
}

void BanSi::Xuat()
{
    DonHang::Xuat();
    cout <<"\nThong tin khach hang";
    cout <<"\nMa khach hang: " << this->MaKhachhang << endl;
    cout <<"Ten khach hang: " << this->TenKhachhang << endl;
    cout <<"Dia chi khac hang: " << this->DiachiKhach << endl;
    cout <<"So dien thoai khach hang: " << this->Sodiethoai << endl;

    cout <<"Thong tin san pham" << endl;

    cout <<"Ma don hang: " << this->Madonhang <<endl;

    cout <<"Ma san pham: " << this->MaSP << endl;

    cout <<"Ten san pham: ";
    cin.ignore();
    cin >> this->TenSP;
    fflush(stdin);

    cout <<"Don gia: " << this->Tiendon() << endl;

    cout <<"Loai san pham: ";
    if(this->LoaiSP == 1)
    {
        cout << "\nThuc an" << endl;
        cout <<"Khoi luong: " << this->khoiluong;
    }
    if(this->LoaiSP == 2)
    {
        cout <<"\nDo uong" << endl;
        cout <<"Dung tich: " << this->dungtich;
        int nhap;
        int nongdo;
        if(nhap == 2)
        {
            cout <<"Nong do: " << nongdo;
        }
    }

    cout <<"\nSo luong san pham duoc mua: ";
    cin >> this->Soluongmathang;

}
