#include "DaGiac.h"
#include "TamGiac.h"
#include "TuGiac.h"
#include "Point.h"

int main()
{
    Point N[MAXN];

    TamGiac B;

    TuGiac C;

    int chon;
    cout<<"Chon 1 de nhap tam giac \n";

    cout<<"Chon 2 de nhap tu giac \n";

    cin>> chon;
    if(chon==1)
    {
        B.Input();
        B.Tinhtien();
        B.Output();

    }
    if(chon==2)
    {
        C.Input();
        C.Tinhtien();
        C.Output();
    }

    return 0;
}
