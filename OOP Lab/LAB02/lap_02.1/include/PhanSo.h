#include <iostream>
using namespace std;
class PhanSo {
private:
	int TuSo, MauSo;
public:
	void Nhap();
	void Xuat();
	PhanSo CongPS(PhanSo a);
	PhanSo TruPS(PhanSo a);
	PhanSo NhanPS(PhanSo a);
	PhanSo ChiaPS(PhanSo a);
	PhanSo RutGonPS(PhanSo a);
};
