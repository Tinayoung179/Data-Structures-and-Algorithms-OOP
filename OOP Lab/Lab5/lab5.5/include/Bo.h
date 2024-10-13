#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Giasuc.h"
using namespace std;

class Bo:
    public Giasuc
{
    public:
        Bo() {};
        ~Bo() {};
        int getSoLitSua();
        void Nhap();
        void KeuKhiDoi();
        void SinhCon();
        int ChoSua();
        void ThongKe();
};
