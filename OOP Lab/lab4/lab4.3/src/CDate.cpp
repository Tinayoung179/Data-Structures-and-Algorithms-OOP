#include "CDate.h"

void CDate::Setday(int x)
{
	this->day += x;
}

void CDate::Setmonth(int x)
{
	this->month += x;
}

void CDate::Setyear(int x)
{
	this->year += x;
}
CDate::~CDate(){}
void CDate::Nhap()
{
	cout << "Nhap Ngay: ";
	cin >> this->day;
	while (day <= 0 || day > 31)
	{
		cout << "Nhap lai ngay: ";
		cin >> day;
	}
	cout<<endl;
	cout << "Nhap thang: ";
	cin >> month;
	while (month > 12 || month < 0)
	{
		cout << "Nhap lai thang: ";
		cin >> month;
	}
	while (day > 29 && month == 2)
	{
		cout << "Nhap lai ngay : ";
		cin >> this->day;
	}
	cout<<endl;
	cout << "Nhap Nam: ";
	cin >> this->year;
	while (year < 0)
	{
		cout << "Nhap lai Nam: ";
		cin >> year;

	}
}
void CDate::Xuat()
{
	cout <<"Ngay: "<< this->day;
	cout << endl;
	cout<< "thang: "<< this->month;
	cout << endl;
	cout <<"nam: "<<this->year;
	cout << endl;

}

int CDate::Getday()
{
	return this->day;
}

int CDate::Getmonth()
{
	return this->month;
}

int CDate::Getyear()
{
	return this->year;
}

bool Kiemtranam(int year)
{

	if (year % 400 == 0)
		return true;
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;

}
CDate CDate::NgayKeTiep()
{
	CDate a;
	a.Setday(this->day);
	a.Setmonth(this->month);
	a.Setyear(this->year);
	int x = 0;

		switch (a.Getmonth())
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if (a.Getday() == 31)
			{
				a.Setday(-30);
				a.Setmonth(1);
			}
			else a.Setday(1);
			break;
		case 12:
			if (a.Getday() == 31)
			{
				a.Setday(-30);
				a.Setyear(1);
				a.Setmonth(-11);
			}
			break;
		case 2:
		{
			if (Kiemtranam(a.Getyear())) x = 29;
			else x = 28;
			if (a.Getday() == x)
			{
				a.Setday(-x +1);
				a.Setmonth(1);
			}
		}
			break;
		default:
			a.Setday(1);
			break;
		}
		return a;
}

CDate CDate::NgayHomQua()
{
	CDate a;
	a.Setday(this->day);
	a.Setmonth(this->month);
	a.Setyear(this->year);
	int x = 0;
	switch (a.Getmonth())
	{
	case 1:
	{
		if (a.Getday() == 1)
		{
			a.Setday(30);
			a.Setmonth(11);
			a.Setyear(-1);
		}
	}
	case 5:
	case 7:
	case 8:
	case 10:
		if (a.Getday() == 1)
		{
			a.Setday(29);
			a.Setmonth(-1);
		}
		break;
	case 3:
	{
		if(Kiemtranam(a.Getyear())) x  =29;
		else x =28;
		if (a.Getday() == 1)
		{
			a.Setday(x - 1);
			a.Setmonth(-1);
		}
	}
	break;
	case 2:
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (a.Getday() == 1)
		{
			a.Setday(30);
			a.Setmonth(-1);
		}
	}
	default:
		a.Setday(-1);
		break;
	}
	return a;
}
int CDate::SoNgay()
{
	int x;
	int SoNgay = 0;
	if (Kiemtranam(this->year))  x = 29;
	else  x = 28;
	for(int i = 1; i < this->month; i++)
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			SoNgay += 31;
			break;
		case 2:
			SoNgay += x;
			break;
		default:
			SoNgay += 30;
			break;
		}
	SoNgay += this->day;
	return SoNgay;
}
int CDate::CachHaiNgay(CDate b)
{
	CDate a;
	a.Setday(this->day);
	a.Setmonth(this->month);
	a.Setyear(this->year);
	int khoangcach = 0;
	int songay1 = 0;
	int songay2 = 0;
	if (a.Getyear() > b.Getyear())
	{
		for (int i = b.Getyear(); i < a.Getyear(); i++)
			if (Kiemtranam(i)) songay2 += 366;
			else songay2 += 365;
		songay2 += b.SoNgay();
		songay1 = a.SoNgay();
		khoangcach = songay2 - songay1;
	}
	else

		if (a.Getyear() < b.Getyear())
		{
			for (int i = a.Getyear(); i < b.Getyear(); i++)
				if (Kiemtranam(i)) songay1 += 366;
				else songay1 += 365;
			songay1 += b.SoNgay();
			songay2 = a.SoNgay();
			khoangcach = songay1 - songay2;
		}
		else
		{
			if (a.SoNgay() > b.SoNgay()) khoangcach = a.SoNgay() - b.SoNgay();
			else  khoangcach = b.SoNgay() - a.SoNgay();
		}

	return khoangcach;
}
