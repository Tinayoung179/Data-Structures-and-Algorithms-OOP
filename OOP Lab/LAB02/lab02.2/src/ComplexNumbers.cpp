#include "ComplexNumbers.h"

// nhap gia tri
void ComplexNumbers:: Input()
{
    cin>> real;
    cin>> Virtual;
}
// xuat gia tri
void ComplexNumbers:: Output()
{
    cout<<"Nhap so phuc: ";
    cout<<this->real<<" ";
    if( this->Virtual>0)
    {
        cout<<"+ ";
        cout<< this->Virtual<<"i"<< endl;
    }
    else
    {
        cout<< this->Virtual<<"i"<< endl;
    }
}
// cong so phuc
ComplexNumbers ComplexNumbers::Plus(ComplexNumbers a)
{
    ComplexNumbers kq;
    kq.real= this->real + a.real;
    kq.Virtual = this->Virtual + a.Virtual;
    return kq;
}
// tru so phuc
ComplexNumbers ComplexNumbers::Subtraction(ComplexNumbers a)
{
    ComplexNumbers kq;
    kq.real= this->real - a.real;
    kq.Virtual = this->Virtual - a.Virtual;
    return kq;
}
// nhan so phuc
ComplexNumbers ComplexNumbers::multiplication(ComplexNumbers a)
{
    ComplexNumbers kq;
	kq.real = this->Virtual * a.real - this->Virtual * a.Virtual;
	kq.Virtual = this->real*a.Virtual + this->Virtual*a.real;
	return kq;
}
// chia so phuc
ComplexNumbers ComplexNumbers::Divide(ComplexNumbers a)
{
    ComplexNumbers kq;
    kq.real= (this->real* a.real + this->Virtual*a.Virtual)/ (a.real * a.Virtual);
    kq.Virtual= (a.real * this->Virtual - a.real* this->Virtual)/ (a.real * a.Virtual);
    return kq;
}
