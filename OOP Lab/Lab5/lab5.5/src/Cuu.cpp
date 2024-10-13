#include "Cuu.h"

int Cuu::getSoLitSua()
{
	return LitSua;
}
void Cuu::Nhap()
{
    cout<<endl;
	cout << "Nhap so luong Cuu: ";
	cin >> Soluong;
}
void Cuu::KeuKhiDoi() {
	TiengKeu = "Bee";
	for (int i = 0; i < Soluong; i++)
		cout << TiengKeu << "\t";
}
void Cuu::SinhCon() {
	int Soluong1consinh;
	for (int i = 0; i < Soluong; i++)
    {
		Soluong1consinh = 1 + rand() % 9;
		SoConSinh = SoConSinh + Soluong1consinh;
	}
}
int Cuu::ChoSua() {
	int SoSua1concho;
	for (int i = 0; i < Soluong; i++)
    {
		SoSua1concho = rand() % 6;
		LitSua = LitSua + SoSua1concho;
	}
	return LitSua;
}
void Cuu::ThongKe() {
	this->SinhCon();
	cout << "So luong Cuu sau luot sinh la: " << SoConSinh + Soluong;
	cout<< endl;
}

