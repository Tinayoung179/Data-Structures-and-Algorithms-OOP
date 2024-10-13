#include "Giasuc.h"
#include "De.h"
#include "Cuu.h"
#include "Bo.h"


int main() {
	srand(time(0));
	int tong=0;
	De a;
	Cuu b;
	Bo c;
// Cau a
    cout<<"Tieng keu khi doi:"<<'\n';
	a.Nhap();
	a.KeuKhiDoi();

	b.Nhap();
	b.KeuKhiDoi();

	c.Nhap();
	c.KeuKhiDoi();

	cout<<"Tong so lit sua gia suc cho: "<<'\n';
	tong= a.ChoSua()+ b.ChoSua()+ c.ChoSua();

	cout<<"Thong ke"<<'\n';
	a.ThongKe();
	b.ThongKe();
	c.ThongKe();

    return 0;
}
