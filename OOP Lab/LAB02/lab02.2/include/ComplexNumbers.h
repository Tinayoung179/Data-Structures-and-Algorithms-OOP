#include <bits/stdc++.h>

using namespace std;

class ComplexNumbers
{
    private:
        float real;
        float Virtual;
    public:
        void Input();
        void Output();
        ComplexNumbers Value(ComplexNumbers A);
        ComplexNumbers Plus(ComplexNumbers A);
        ComplexNumbers Subtraction(ComplexNumbers A);
        ComplexNumbers Divide(ComplexNumbers A);
        ComplexNumbers multiplication(ComplexNumbers A);
};
