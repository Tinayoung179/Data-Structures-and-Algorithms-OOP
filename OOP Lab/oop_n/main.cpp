#include <bits/stdc++.h>
#include <cmath>


using namespace std;

class ThoiGian
{
    protected:
         int hour, day, minute, second, Total;

    public:
        ThoiGian()
        {
            hour=0;
            day=0;
            minute=0;
            second=0;
        };
        ~ThoiGian();
        ThoiGian(int , int , int, int );
        ThoiGian operator+(const ThoiGian &a);
        ThoiGian operator-(const ThoiGian &a);
        void Kiem_Tra_Thoi_Gian();
        bool operator==(ThoiGian a) ;
        bool operator<(ThoiGian a);
        bool operator>(ThoiGian a);

        friend istream& operator >>(istream& input, ThoiGian& a);
        friend ostream& operator <<(ostream& os, ThoiGian a);

};
ThoiGian::~ThoiGian(){};
ThoiGian::ThoiGian(int a, int b, int c, int d)
{
	hour = a;
	second = b;
	minute = c;
	day = d;
}
istream &operator>>(istream &input, ThoiGian& a )
{
    cout<<"Nhap so ngay: ";
    input>>a.day;
    cout<<endl;
    cout<<"Nhap so gio: ";
    input>>a.hour;
    cout<<endl;
    cout<<"Nhap so phut: ";
    input>>a.minute;
    cout<<endl;
    cout<<"Nhap so giay: ";
    input>>a.second;
    cout<<endl;
    a.Total = a.day * 24 * 60 * 60 + a.hour * 60 * 60 + a.minute * 60 + a.second;
}

// Ham kiem tra thoi gian, luon dam bao 0 < gio <= 24, 0 < Phut <= 60, 0 < Giay <=60
void ThoiGian::Kiem_Tra_Thoi_Gian() {
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

ThoiGian ThoiGian::operator+(const ThoiGian& a)
{

    ThoiGian b;
    b.day=this->day +a.day;
    b.hour=this->hour +a.hour;
    b.second=this->second +a.second;
    b.minute=this->minute +a.minute;
    return b;
}
ThoiGian ThoiGian::operator-(const ThoiGian& a)
{
    ThoiGian b;

    {
        b.day= abs(this->day -a.day);
        b.hour=abs( this->hour -a.hour );
        b.second= abs(this->second -a.second);
        b.minute= abs(this->minute -a.minute);
        return b;
    }
}
bool ThoiGian::operator==(ThoiGian a)
{
    if(this->day==a.day && this->hour==a.hour && this->second==a.second && this->minute==a.minute)
        return true;
    return false;
}

bool ThoiGian::operator>(ThoiGian a)
{
	this->Total > a.Total;
        return 1;
    return 0;
}

bool ThoiGian::operator<(ThoiGian a)
{
	return this->Total <  a.Total ? 1 : 0;
}
ostream& operator << (ostream& os, ThoiGian a)
{
	os << "Thoi gian: " << a.day << " : " << a.hour << " : " << a.minute << " : " << a.second ;
	return os;
}
int main()
{
    ThoiGian a, b;
    cin>> a ;

    cin>> b;

    cout<<"Cong thoi gian\n";

    cout<< a + b;

    cout << endl;

    cout<<"Tru thoi gian\n";

    cout<< a - b;

    cout<<endl;
    cout<<"So sanh bang nhau: ";
    cout<<a.operator==(b);

    cout<<endl;

    cout<<"So sanh be hon: ";
    cout<<a.operator<(b);

    cout<<endl;

    cout<<"So sanh lon hon: ";
    cout<<a.operator>(b);

    return 0;
}
