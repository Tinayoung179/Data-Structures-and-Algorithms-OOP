#include "NhanVien.h"

void NhanVien::Nhap()
{
    QuanLy::Nhap();
    cout <<"Nhap ten phong ban: ";

    cin.ignore();
    getline(cin,this->PhongBan);
    fflush(stdin);
    //bang chon chuc vu, chuc vu theo so, nhap chuc vu duoi dang int
    cout<<"Chon so phu hop voi chuc vu\n";
    cout <<"----------------------------------------\n"
         <<"|1.Truong phong                        |\n"
         <<"|2.Pho phong                           |\n"
         <<"|3.Nhan vien                           |\n"
         <<"---------------------------------------|\n";

    cout <<"\nNhap chuc vu: ";
    cin >> this->Chucvu;

}

int NhanVien::TinhLuong() //tien luong= he so luong* 730 + phu cap + so ngay cong * 200
{
    if(this->Chucvu == 1)// truong phong, voi muc phu cap 2000
    {
        this->Luong = (this->HeSo * 730) + 2000 + (this->SoNgay * 200);
    }
    if(this->Chucvu == 2) // pho phong phu cap 1000
    {
        this->Luong = (this->HeSo * 730) + 1000 + (this->SoNgay * 200);
    }
    if(this->Chucvu == 3)// nhan vien, phu cap 500
    {
        this->Luong = (this->HeSo * 730) + 500 + (this->SoNgay * 200);
    }
    return this->Luong;
}


void NhanVien::Xuat()
{
    QuanLy::Xuat();

    cout <<"\nPhong ban: " << this->PhongBan;

    cout <<"\nChu vu: ";
    if(this->Chucvu == 1)
    {
        cout <<"Trong phong\n";
    }
    if(this->Chucvu == 2)
    {
        cout <<"Pho phong\n";
    }
    if(this->Chucvu == 3)
    {
        cout <<"Nhan vien\n";
    }

    int sum = 0;
    cout <<"Tien luong: " << this->TinhLuong()<< endl;

}
