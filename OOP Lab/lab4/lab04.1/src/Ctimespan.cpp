#include "Ctimespan.h"


Ctimespan::~Ctimespan(){};

void Ctimespan::Nhap()
{
    cout<<"Nhap so ngay: ";
    cin>>day;
    cout<<endl;
    cout<<"Nhap so gio: ";
    cin>>hour;
    cout<<endl;
    cout<<"Nhap so phut: ";
    cin>>minute;
    cout<<endl;
    cout<<"Nhap so giay: ";
    cin>>second;
    cout<<endl;
    this->Total = this->day * 24 * 60 * 60 + this->hour * 60 * 60 + this->minute * 60 + this->second;
}
void Ctimespan::GetTotal(Ctimespan a)
{
    a.Total=this->day * 24 * 60 * 60 + this->hour * 60 * 60 + this->minute * 60 + this->second;
}
// Ham kiem tra thoi gian, luon dam bao 0 < gio <= 24, 0 < Phut <= 60, 0 < Giay <=60
void Ctimespan::Kiem_Tra_Thoi_Gian() {
	if (this->minute >= 60)
	{
		this->second += 1;
		this->minute = this->minute - 60;
	}

	if (this->minute < 0)
	{
		this->second -= 1;
		this->minute = 60 + this->minute;
	}

	if (this->second >= 60)
	{
		this->hour += 1;
		this->second = this->second - 60;
	}
	if (this->second < 0)
	{
		this->hour -= 1;
		this->second = 60 + this->second;
	}
}

Ctimespan Ctimespan::phepcong(Ctimespan a)
{

    Ctimespan b;
    b.day=this->day +a.day;
    b.hour=this->hour +a.hour;
    b.second=this->second +a.second;
    b.minute=this->minute +a.minute;
    return b;
}
Ctimespan Ctimespan::pheptru(Ctimespan a)
{
    Ctimespan b;
    b.day=this->day -a.day;
    b.hour=this->hour -a.hour;
    b.second=this->second -a.second;
    b.minute=this->minute -a.minute;
    return b;
}
bool Ctimespan::phepbang(Ctimespan a)
{
    if(this->day==a.day && this->hour==a.hour && this->second==a.second && this->minute==a.minute)
        return true;
    return false;
}

bool Ctimespan::phepkhac(Ctimespan a)
{
    if(this->day!=a.day || this->hour!=a.hour  || this->second!=a.second || this->minute!=a.minute)
        return true;
    return false;
}

bool Ctimespan::pheplon(Ctimespan a)
{
	this->Total > a.Total;
        return 1;
    return 0;
}

bool Ctimespan::LonHonBang(Ctimespan a)
{
	this->Total >= a.Total;
        return 1;
	return 0;
}
bool Ctimespan::phepbe(Ctimespan a)
{
	return this->Total <  a.Total ? 1 : 0;
}
bool Ctimespan::NhoHonBang(Ctimespan a)
{
	return this->Total <= a.Total ? 1 : 0;
}
void Ctimespan::Xuat()
{
    cout<<"Ngay: ";
    cout<< day;
    cout<<endl;
    cout<<"Gio: ";
    cout<< hour;
    cout<<endl;
    cout<<"phut: ";
    cout<< second;
    cout<<endl;
    cout<<"Giay: ";
    cout<< minute;
    cout<<endl;
}
