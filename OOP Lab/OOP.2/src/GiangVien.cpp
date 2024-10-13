#include "GiangVien.h"

void GiangVien::Nhap()
{
    QuanLy::Nhap();
    cout <<"Nhap so tiet: ";
    cin >> this->SoTiet;

    cout <<"Nhap ten khoa: ";
    cin.ignore();
    getline(cin, this->Khoa);

    //bang chon trinh do, nhap trinh do theo so
    cout <<"Chon so phu hop voi trinh do\n";
    cout <<"===================================\n"
         <<"=1.Cu nhan                        =\n"
         <<"=2.Thac si                        =\n"
         <<"=3.Tien si                        =\n"
         <<"===================================\n";
    cout <<"Muc trinh do: ";
    cin >> this->Trinhdo;

}

int GiangVien::TinhLuong() //tien luong = he so luong *730 + phu cap theo trinh do + so tiet day * 45
{
    if(Trinhdo == 1)// trinh do cu nha, phu cap duoc tinh la 300
    {
        this->Luong = (this->HeSo * 730) + 300 + (this->SoTiet * 45);
    }
     if(Trinhdo == 2)// trinh do thac si, phu cap duoc tinh la 500
    {
        this->Luong = (this->HeSo * 730) + 500 + (this->SoTiet * 45);
    }
    if(Trinhdo == 3)// trinh do tien si, phu cap duoc tinh la 1000
    {
        this->Luong = (this->HeSo * 730) + 1000 + (this->SoTiet * 45);
    }

    return this->Luong;
}

void GiangVien::Xuat()
{
    QuanLy::Xuat();
    cout <<endl <<"\nTen khoa: ";
    cout << this->Khoa;

    cout <<"\nTrinh do: ";
    if(Trinhdo == 1)
    {
        cout <<"Cu Nhan";
    }
    if(Trinhdo == 2)
    {
        cout <<"Thac si";
    }
    if(Trinhdo == 3)
    {
        cout <<"Tien si";
    }

    cout <<"\nTien luong la: ";

    cout << this->TinhLuong()<< endl;

}
