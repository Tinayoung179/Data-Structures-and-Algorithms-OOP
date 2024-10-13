#include <iostream>
#include <string.h>
using namespace std;

class ConNguoi
{
	protected:
		string Ten;
		string NgaySinh;
	public:
		void EnterInfor();

		void PrintInfor();
};
void ConNguoi::EnterInfor()
{
    cout << "Nhap ten: ";
    cin >> this->Ten;
    cout << "Nhap ngay thang nam sinh: ";
    cin >> this->NgaySinh;
};
void ConNguoi::PrintInfor()
{
    cout << "Ho va ten: " << this->Ten;
    cout<<endl;
    cout << "Ngay thang nam sinh la: " << this->NgaySinh;
};

class SinhVien : public ConNguoi
{
	private:
		int MSSV;
	public:
		void EnterInfor();
		void PrintInfor();
};
void SinhVien::EnterInfor()
{
    ConNguoi::EnterInfor();
    cout << "Nhap MSSV: ";
    cin >> this->MSSV;

};
void SinhVien::PrintInfor()
{
    ConNguoi::PrintInfor();
    cout<<endl;
    cout << "MSSV: " << this->MSSV;
    cout<<endl;
}
class HocSinh : public ConNguoi
{
	private:
		string Lop;
	public:
		void EnterInfor();
		void PrintInfor();

};
void HocSinh::EnterInfor()
{
    ConNguoi::EnterInfor();
    cout << "Nhap lop: ";
    cout<<endl;
    cin >> this->Lop;
};
void HocSinh::PrintInfor()
{
    ConNguoi::PrintInfor();
    cout << "MSSV: " << this->Lop;
    cout<<endl;
}
class CongNhan : public ConNguoi
{
	private:
		int MaSoCongNhan;
		int Luong;
	public:
		void EnterInfor();
		void PrintInfor();
};
void CongNhan::EnterInfor()
{
    ConNguoi::EnterInfor();
    cout << "Nhap ma so cong nhan: ";
    cin >> this->MaSoCongNhan;
    cout << "Nhap tien luong: ";
    cin >> this->Luong;
}
void CongNhan::PrintInfor()
{
    ConNguoi::PrintInfor();
    cout << "Ma so cong nhan: " << this->MaSoCongNhan;
    cout<<endl;
    cout << "Tien luong: " << this->Luong;
    cout<<endl;
}
class NgheSi: public ConNguoi
{
	private:
		string CTy;
		int Luong;
	public:
		void EnterInfor();
		void PrintInfor();
};
void NgheSi::EnterInfor()
 {
    ConNguoi::EnterInfor();
    cout << "Nhap ten cong ty cua nghe si: ";
    cin >> this->CTy;
    cout << "Nhap tien luong: ";
    cin >> this->Luong;
};
void NgheSi::PrintInfor()
{
    ConNguoi::PrintInfor();
    cout << "Nghe si thuoc cong ty " << this->CTy;
    cout<<endl;
    cout << "Tien luong: " << this->Luong;
    cout<<endl;
}
class CaSi : public ConNguoi
{
	private:
		string CTy;
		int Luong;
		string NgQuanLi;
	public:
		void EnterInfor();
		void PrintInfor();
};
void CaSi::EnterInfor()
{
    ConNguoi::EnterInfor();
    cout << "Nhap ten cong ty cua ca si: ";
    cin >> this->CTy;
    cout << "Nhap ten nguoi quan li cua ca si: ";
    cin >> this->NgQuanLi;
    cout << "Nhap tien luong: ";
    cin >> this->Luong;
};
void CaSi::PrintInfor()
{
    ConNguoi::PrintInfor();
    cout << "Ca si thuoc cong ty: " << this->CTy;
    cout<<endl;
    cout << "Ten quan li cua ca si: " << this->NgQuanLi;
    cout<<endl;
    cout << "Tien luong: " << this->Luong;
}
int main()
{
    int n, nganhnghe;
    cin>>n;
	SinhVien A[100];
	HocSinh C[100];
	CongNhan B[100];
	NgheSi D[100];
	CaSi E[100];
	for(int i=0; i<=n; i++)
	{
	    cout<<"Nhap nganh nghe: ";
	    cout<<endl;
        cout<<"1 là nganh Nghe si";
        cout<<endl;
        cout<<"2 là nganh Cong nhan";
        cout<<endl;
        cout<<"3 là nganh Hoc sinh";
        cout<<endl;
        cout<<"4 là nganh Ca si";
        cout<<endl;
        cout<<"5 là nganh Sinh vien";
        cout<<endl;
        cin>>nganhnghe;
        cout<<endl;
        switch(nganhnghe)
            {
        case 1:
            {
                A[i].EnterInfor();
                A[i].PrintInfor();
                break;
            }
        case 2:
            {
                B[i].EnterInfor();
                B[i].PrintInfor();
                break;
            }
        case 3:
            {
                C[i].EnterInfor();
                C[i].PrintInfor();
                break;
            }
        case 4:
            {
                D[i].EnterInfor();
                D[i].PrintInfor();
                break;
            }
        case 5:
            {
                E[i].EnterInfor();
                E[i].PrintInfor();
                break;
            }
        }
	}
    return 0;
}
