#include "CDate.h"


int main()
{
	CDate A;
	CDate B;
	A.Nhap();
	B.Nhap();
	cout << A.CachHaiNgay(B);
	return 0;
}
