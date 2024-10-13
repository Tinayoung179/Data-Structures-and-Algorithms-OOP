#include <iostream>

using namespace std;
class CDate
{
private:
	int day;
	int month;
	int year;
public:
	CDate()
	{
	    day=0;
	    month=0;
	    year=0;
	};
	~CDate();
	void Nhap();
	void Xuat();
	CDate NgayKeTiep();
	CDate NgayHomQua();
	int CachHaiNgay(CDate x);
	void Setday(int x);
	void Setmonth(int x);
	void Setyear(int x);
	int Getday();
	int Getmonth();
	int Getyear();
	int SoNgay();
};
