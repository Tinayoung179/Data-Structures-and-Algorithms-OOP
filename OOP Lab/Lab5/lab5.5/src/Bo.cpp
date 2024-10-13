#include "Bo.h"


int Bo::getSoLitSua() {
	return LitSua;
}
void Bo::Nhap()
{
    cout<<endl;
	cout << "Nhap so luong Bo: ";
	cin >> Soluong;
}
void Bo::KeuKhiDoi() {
	TiengKeu = "Boo";
	for (int i = 0; i < Soluong; i++)
		cout << TiengKeu << "\t";
}
void Bo::SinhCon() {
	int Soluong1consinh;
	for (int i = 0; i < Soluong; i++)
    {
		Soluong1consinh = 1 + rand() % 10;
		SoConSinh = SoConSinh + Soluong1consinh;
	}
}
int Bo::ChoSua() {
	int SoSua1concho;
	for (int i = 0; i < Soluong; i++)
    {
		SoSua1concho = rand() % 21;
		LitSua = LitSua + SoSua1concho;
	}
	return LitSua;
}
void Bo::ThongKe() {
	this->SinhCon();
	cout << "So luong Bo sau luot sinh la: " << SoConSinh + Soluong << "\n";
}
