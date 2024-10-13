#include "TestCandidate.h"

//nhap du lieu hoc sinh
void Candidate::Input()
{
    cout<<"Ma so sinh vien: ";
    cin>> this->code;
    cout<<"Ngay sinh: ";
    cin>> this->date;
    cout<<"Ho va ten: ";
    cin>> this->name;
    cout<<"Diem toan: ";
    cin>> this->math;
    cout<<"Diem van: ";
    cin>> this->literature;
    cout<<"Diem anh: ";
    cin>> this->english;
}
// diem trung binh
float Candidate::Average()
{
    float sum;
    sum = this->literature + this->math + this->english;
    return sum;
}
// xuat du lieu
void Candidate::Output()
{
    cout << this->code<<endl;
    cout << this->name<< endl;
    cout << this->date<< endl;
    cout << this->literature<< endl;
    cout << this->math<< endl;
    cout << this->english<< endl;
}
// nhap so luong sv
void TestCandidate::Import()
 {
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        sum[i].Input();
    }
}
// xuat so luong sv diem tong tren 15
void TestCandidate::Export()
{
    for (int i = 0; i < n; i++)
    {
        if (sum[i].Average() > 15)
            sum[i].Output();
    }
}
