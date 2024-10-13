#include "Ctime.h"

int main()
{
	CTime Time1, Time2, Re;
	Time1.Nhap();
	Time1.Xuat();
	Time2.Nhap();
	Time2.Xuat();
	Re = Time1.Tru_2_Thoi_Gian(Time2);
	Re.Xuat();
	return 0;
}
