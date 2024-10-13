#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Giasuc.h"
using namespace std;


class De :
    public Giasuc
{
    public:
        De() {};
        ~De() {};
        int getSoLitSua();
        void Nhap();
        void KeuKhiDoi();
        void SinhCon();
        int ChoSua();
        void ThongKe();
};
