#include "ComplexNumbers.h"
int main()
{
    ComplexNumbers a,b;
    a.Input();
    b.Input();

    a.Output();
    b.Output();

    ComplexNumbers c;
    cout<< endl;
    cout<<"Tong hai so phuc: ";
    c=a.Plus(b);
    c.Output();

    cout<<"Hieu hai so phuc: ";
    c=a.Subtraction(b);
    c.Output();

    cout<<"Tich hai so phuc: ";
    c=a.Subtraction(b);
    c.Output();

    cout<<"Chia hai so phuc: ";
    c=a.Divide(b);
    c.Output();

    return 0;
}
