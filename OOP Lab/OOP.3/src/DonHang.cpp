#include "DonHang.h"

DonHang::~DonHang()
{

};

void DonHang::Nhap()
{
    cout <<"Nhap thong tin don hang! \n";

    cout <<"Nhap ma don hang: ";
    cin >> this->Madon;

    cout <<"\nNhap loai don hang: ";
    cin >> this->Loaihang;// 1 doi voi ban le, 2 doi voi ban si

    cout <<"\nNhap ngay dat: ";
    cin.ignore();
    getline(cin,this->Ngaydat);
    fflush(stdin);

    cout <<"\nNhap ngay nhan: ";
    cin.ignore();
    getline(cin,this->Ngaynhan);
    fflush(stdin);

    cout <<"\nNhap dia chi giao hang: ";
    cin.ignore();
    getline(cin,this->Diachigao);
    fflush(stdin);

    cout <<"\nNhap ma san pham: ";
    cin.ignore();
    cin >> this->MaSP;
    fflush(stdin);

    cout <<"\nNhap gia tien: ";
    cin >> this->Giatien;

    cout <<"\nNhap noi san xuat: ";
    cin >> this->NoiSX;

    cout <<"\nNhap loai san pham: ";
    cin >> this->LoaiSP;
    if (this->LoaiSP == 1)
    {
        cout << "\nNhap khoi luong tinh: ";
        cin >> this->khoiluong;
    }
    if(this->LoaiSP == 2)
    {
        cout << "\n Nhap dung tich: ";
        cin >> this->dungtich;

        int Nongdo;
        int nhap;
        cout <<"\nNhap 1 neu la nuoc giai khat, 2 neu ra ruou!"<< endl;
        cin >> nhap;
        if(nhap == 2 )
        {
            cout << "Nhap nong do";
            cin >> Nongdo;
        }

    }

    cout <<"\nNhap so luong mat hang: ";
    cin >> this->Soluongmathang;
}

void DonHang::Xuat()
{
    cout <<"\nDON HANG";
    cout <<"\nMa don hang: " << this->Madon << endl;

    cout <<"Loai don hang: " << this->Loaihang << endl;

    cout <<"Gia don hang: " << this->Giatien << endl;

    cout <<"Ngay dat hang: " << this->Ngaydat << endl;

    cout <<"Ngay nhan hang: "<< this->Ngaynhan << endl;
}
int DonHang::Tiendon()
{
    return this->Giatien;
}
