#include <iostream>

using namespace std;

class Ctimespan
{
    private:
        int hour, day, minute, second, Total;

    public:
        Ctimespan()
        {
            hour=0;
            day=0;
            minute=0;
            second=0;
            Total=0;
        };
        void Nhap();
        void Xuat();
        void GetTotal(Ctimespan a);
        Ctimespan phepcong(Ctimespan a);
        Ctimespan pheptru(Ctimespan a);
        void Kiem_Tra_Thoi_Gian();
        bool phepbang(Ctimespan a) ;
        bool phepkhac(Ctimespan a);
        bool phepbe(Ctimespan a);
        bool pheplon(Ctimespan a);
        bool LonHonBang(Ctimespan a);
        bool NhoHonBang(Ctimespan a);
        ~Ctimespan();

};
