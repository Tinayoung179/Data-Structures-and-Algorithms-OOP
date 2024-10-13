#include <iostream>
#include <cmath>
#include <string>

using namespace std;


class Ngay
{
    protected:
        int Ngay;
        int Thang;
        int Nam;
    public:
        Ngay()
        {
            Ngay = 0;
            Thang = 0;
            Nam = 0;
        };
        ~Ngay();
        bool operator>(Ngay& A);
        friend istream &operator>>(istream& in, Ngay& a);
        friend ostream &operator<<(ostream& out,Ngay& a);
};


