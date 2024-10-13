#include "Ctime.h"

// Ham nhap thoi gian
void CTime::Nhap() {
	do
	{
		cout << "Nhap gio: ";
		cin >> this->Gio;
		if (this->Gio > 24)
		{
			cout << "Moi nhap gio lai vi gio khong the lon hon 24: ";
			cin >> this->Gio;
		}
	} while (this->Gio > 24);

	cout << "Nhap phut: ";
	cin >> this->Phut;
	cout << "Nhap giay: ";
	cin >> this->Giay;

	this->Kiem_Tra_Thoi_Gian();
}

// Ham kiem tra thoi gian, luon dam bao 0 < gio <= 24, 0 < Phut <= 60, 0 < Giay <=60
void CTime::Kiem_Tra_Thoi_Gian() {
	if (this->Giay >= 60)
	{
		this->Phut += 1;
		this->Giay = this->Giay - 60;
	}

	if (this->Giay < 0)
	{
		cout << "Giay: " << this->Giay;
		this->Phut -= 1;
		this->Giay = 60 + this->Giay;
	}

	if (this->Phut >= 60)
	{
		this->Gio += 1;
		this->Phut = this->Phut - 60;
	}
	if (this->Phut < 0)
	{
		this->Gio -= 1;
		this->Phut = 60 + this->Phut;
	}
}

// Ham xuat thoi gian
void CTime::Xuat()
{
	cout << this->Gio << "h:" << this->Phut << "m:" << this->Giay << "s" << endl;
}

// Ham tang 1 giay
void CTime::Tang_1_Giay()
{
	this->Giay += 1;
	this->Kiem_Tra_Thoi_Gian();
}

// Ham giam 1 giay
void CTime::Giam_1_Giay()
{
	this->Giay -= 1;
	this->Kiem_Tra_Thoi_Gian();
}

// Ham tang so giay theo luong nhap vao
void CTime::Tang_Nhieu_Giay(int SoGiayCanTang)
{
	this->Giay = this->Giay + SoGiayCanTang;
	this->Kiem_Tra_Thoi_Gian();
}

// Ham giam so giay theo luong nhap vao
void CTime::Giam_Nhieu_Giay(int SoGiayCanGiam)
{
	this->Giay = this->Giay - SoGiayCanGiam;
	this->Kiem_Tra_Thoi_Gian();
}

// Ham tru 2 thoi gian
CTime CTime::Tru_2_Thoi_Gian(CTime ThoiGianCanTru)
{
	if (this->Gio < ThoiGianCanTru.Gio)
	{
		cout << "Khong the tru duoc vi thoi gian tru lon hon thoi gian co";
	}
	else
	{
		CTime KQua;
		KQua.Gio = this->Gio - ThoiGianCanTru.Gio;
		KQua.Phut = this->Phut - ThoiGianCanTru.Phut;
		KQua.Giay = this->Giay - ThoiGianCanTru.Giay;
		KQua.Kiem_Tra_Thoi_Gian();
		return KQua;
	}

}

