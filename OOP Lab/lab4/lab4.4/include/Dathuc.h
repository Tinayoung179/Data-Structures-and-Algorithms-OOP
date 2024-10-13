#include<bits/stdc++.h>

using namespace std;
class Dathuc
{
    private:
        int n;//bac cua da thuc
        int *a;//mang chua he so da thuc
    public:
        Dathuc()
        {
            n=0;
            a=NULL;
        }
        Dathuc(int n1)
        {
            n=n1;
            a = new int [n];
        }
        ~Dathuc()
        {
            n=0;
            delete a;
        }
        void nhap();
        void xuat();
        Dathuc phepcong(Dathuc d);
        Dathuc pheptru(Dathuc d);
};
