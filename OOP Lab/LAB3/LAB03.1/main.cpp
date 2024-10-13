#include "Point.h"
int main()
{
    Point B;
    Point C;
    B.Import();
    C= B.Translation(B);
    cout<<"Diem tinh tien la: ";
    C.Export();


}
