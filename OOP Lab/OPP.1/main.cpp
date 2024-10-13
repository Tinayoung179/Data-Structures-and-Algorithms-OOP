#include <iostream>
#include <cmath>
using namespace std;

class PhanSo
{
    private:
        int Tu;
        int Mau;
    public:
        PhanSo()
        {
            Tu = 0;
            Mau = 1;
        };
        int getTuso(int);
        int getMauso(int);
        int setTuso();
        int setMauso();
        PhanSo operator+(const PhanSo& a);
        PhanSo operator-(const PhanSo& a);
        PhanSo operator*(const PhanSo& a);
        PhanSo operator/(const PhanSo& a);
        bool operator>(PhanSo a);
        bool operator<(PhanSo a);
        bool operator=(PhanSo a);
        friend istream& operator>>(istream &in, PhanSo& a);
        friend ostream& operator<<(ostream &out, PhanSo& a);
        ~PhanSo();
};
PhanSo::~PhanSo()
{

};

int PhanSo::getTuso(int x)
{
    this->Tu = x;
    return this->Tu;
}


int PhanSo::getMauso(int y)
{
    this->Mau = y;
    return this->Mau;
}

int PhanSo::setTuso()
{
    return this->Tu;
}

int PhanSo::setMauso()
{
    return this->Mau;
}

istream& operator>>(istream &in, PhanSo& a)
{
    cout << "Nhap tu so: ";
    in >> a.Tu;
    cout << "\nNhap mau so: ";
    in >> a.Mau;
    cout << endl;
}

PhanSo PhanSo::operator+(const PhanSo& a)
{
    PhanSo c;
    c.Tu = (a.Tu* this->Mau) + (this->Tu * a.Mau);
    c.Mau = (this->Mau * a.Mau);
    return c;
}

PhanSo PhanSo::operator-(const PhanSo& a)
{
    PhanSo c;
    c.Tu = (a.Tu)* this->Mau - this->Tu * a.Mau;
    c.Mau = this->Mau * a.Mau;
    return c;
}

PhanSo PhanSo::operator*(const PhanSo& a)
{
    PhanSo c;
    c.Tu = a.Tu * this->Tu;
    c.Mau = a.Mau * this->Mau;
    return c;
}

PhanSo PhanSo::operator/(const PhanSo& a)
{
    PhanSo c;
    c.Tu = a.Mau * this->Tu;
    c.Mau = a.Tu * this->Mau;
    return c;
}

bool PhanSo::operator<(PhanSo a)
{
    float c, d;
    c = a.Tu / a.Mau;
    d = this->Tu / this->Mau;
    if(c < d)
        return true;
    return false;
}

bool PhanSo::operator>(PhanSo a)
{
    float c, d;
    c = a.Tu / a.Mau;
    d = this->Tu / this->Mau;
    if(c > d)
        return true;
    return false;
}

bool PhanSo::operator=(PhanSo a)
{
    float c, d;
    c = a.Tu / a.Mau;
    d = this->Tu / this->Mau;
    if(c = d)
        return true;
    return false;
}
ostream& operator<<(ostream& out,PhanSo& a)
{
    out << a.setTuso() <<"/" << a.setMauso();
    return out;
}

class DayPS
{
    private:
        int a;// so luong phan so
        PhanSo A[a];// mang cac phan so
    public:
        DayPS()
        {
            a = 0;
            A[0] = 0;
        };


};

int main()
{
    PhanSo A, B;

    cin >> A;

    cin >> B;

    PhanSo E = A + B;
    cout <<"\nCong phan so: "  << E;

    PhanSo K = A - B;
    cout <<"\nTru phan so: "  << K;

    PhanSo C =A * B;
    cout <<"\nNhan phan so: " << C ;

    PhanSo D=A / B;
    cout <<"\nChia phan so: " << D <<endl ;

    cout <<"\nSo sanh be: ";
    cout << A.operator<(B);

    cout <<"\nSo sanh lon: ";
    cout << A.operator>(B);

    cout <<"\nSo sanh bang: ";
    cout << A.operator=(B);

    return 0;
}
