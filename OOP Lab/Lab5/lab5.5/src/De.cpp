#include "De.h"

int De::getSoLitSua()
{
	return LitSua;
}
void De::Nhap()
{
	cout << "Nhap so luong De: ";
	cin >> Soluong;
}
void De::KeuKhiDoi() {
	TiengKeu = "Dee";
	for (int i = 0; i < Soluong; i++)
		cout << TiengKeu << "\t";
}
void De::SinhCon() {
	int Soluong1consinh;
	for (int i = 0; i < Soluong; i++)
    {
		Soluong1consinh = 1 + rand() % 15;
		SoConSinh = SoConSinh + Soluong1consinh;
	}
}
int De::ChoSua() {
	int SoSua1concho;
	for (int i = 0; i < Soluong; i++)
    {
		SoSua1concho = rand() % 11;
		LitSua = LitSua + SoSua1concho;
	}
	return LitSua;
}
void De::ThongKe() {
	this->SinhCon();
	cout << "So luong De sau luot sinh la: " << SoConSinh + Soluong;
	cout<< endl;
}
