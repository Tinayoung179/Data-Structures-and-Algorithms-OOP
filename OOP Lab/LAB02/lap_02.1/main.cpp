#include "PhanSo.h"
int main() {
	PhanSo a,b,c;
	a.Nhap();
	a.Xuat();
	b.Nhap();
	b.Xuat();

	c = a.CongPS(b);
    c = c.RutGonPS(c);
	cout << "Tong 2 phan so la: ";

	c.Xuat();
	c = a.TruPS(b);
	c = c.RutGonPS(c);
	cout << "Hieu 2 phan so la: ";

	c.Xuat();
	c = a.NhanPS(b);
    c = c.RutGonPS(c);
	cout << "Nhan 2 phan so la: ";

	c.Xuat();
	c = a.ChiaPS(b);
    c = c.RutGonPS(c);
	cout << "Chia 2 phan so la: ";

	c.Xuat();

}

