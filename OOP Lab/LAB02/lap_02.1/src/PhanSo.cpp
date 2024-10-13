#include "PhanSo.h"

void PhanSo::Nhap() {
	cout << "Nhap tu so va mau so: ";
	cout<< endl;

	cin >> TuSo;

	cout<< endl;
	cin >> MauSo;
}
void PhanSo::Xuat() {
	cout << TuSo << "/" << MauSo <<endl;
}

PhanSo PhanSo::CongPS(PhanSo a) {
	PhanSo kq;
	kq.MauSo = MauSo * a.MauSo;
	kq.TuSo = TuSo * a.MauSo + a.TuSo * MauSo;
	return kq;
}

PhanSo PhanSo::TruPS(PhanSo a) {
	PhanSo kq;
	kq.MauSo = MauSo * a.MauSo;
	kq.TuSo = TuSo * a.MauSo - a.TuSo * MauSo;
	return kq;
}

PhanSo PhanSo::NhanPS(PhanSo a) {
	PhanSo kq;
	kq.MauSo = MauSo * a.MauSo;
	kq.TuSo = TuSo * a.TuSo;
	return kq;
}

PhanSo PhanSo::ChiaPS(PhanSo a) {
	PhanSo kq;
	kq.MauSo = MauSo * a.TuSo;
	kq.TuSo = TuSo * a.MauSo;
	return kq;
}

PhanSo PhanSo::RutGonPS(PhanSo a){
    PhanSo kq;
    int MIN;
    MIN = min(a.TuSo, a.MauSo);
    int UCLN;
    if ( MIN < 0) MIN = -MIN;
    {   for ( int i=1; i<= MIN; i++)
        {
            if( a.TuSo%i==0 && a.MauSo%i==0)
            UCLN=i;
        }
        kq.TuSo=a.TuSo/UCLN;
        kq.MauSo=a.MauSo/ UCLN;
        return kq;
    }
}
