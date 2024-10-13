#include <iostream>
#include <string>

using namespace std;
class Nhanvien
{
    protected:
        char hoten[100];
        char ngaysinh[100];
        //cdate ngay sinh
        float luong;
    public:
        Nhanvien()
        {
            hoten[' '];
            ngaysinh[' '];
            luong=0;
        }
        void Nhap();
        void Xuat();
        ~Nhanvien();

};

Nhanvien::~Nhanvien()
{

};
void Nhanvien::Nhap()
{
    cout<<"Nhap ho ten nhan vien: ";
    gets(this->hoten);
    fflush(stdin);
    cout<<endl;
    cout<<"Nhap ngay thang nam sinh: ";
    gets(this->ngaysinh);
    fflush(stdin);
    cout<<endl;
    cout<<"Luong: ";
    cin>>this->luong;
    cout<< endl;

}
void Nhanvien::Xuat()
{
    cout<<"Ho va ten nhan vien: ";
    puts(this->hoten);
    fflush(stdin);
    cout<< endl;
    cout<<"Ngay thang nam sinh: ";
    puts(this->ngaysinh);
    fflush(stdin);
    cout<< endl;
    cout<<"Luong: ";
    cout<< this->luong;
}
class Phicong:
    public Nhanvien
{
    protected:
        float Luongcoban;
        float Sogiobay;
    public:
        Phicong()
        {
            Luongcoban=0;
            Sogiobay=0;
        };
        void Xuat();
        void Nhap();
        void Tinhluong(Phicong PC);
        ~Phicong();
};
Phicong::~Phicong()
{

};
void Phicong::Nhap()
{
    Nhanvien::Nhap();
    cout<<"Nhap luong co ban la: ";
    cin>> this->Luongcoban;
    cout<< endl;
    cout<<"Nhap so gio bay: ";
    cin>> this->Sogiobay;
    cout<< endl;
}
void Phicong::Xuat()
{
    int a;
    Nhanvien::Nhap();
    cout<<"Luong co ban la: ";
    cout<< this->Luongcoban;
    cout<< endl;
    cout<<"So gio bay: ";
    cout<< this->Sogiobay;
    cout<< endl;
}
void Phicong::Tinhluong(Phicong PC)
{
    cout<<"Tien luong phi cong: ";
    int a= (this->Luongcoban) + (this->Sogiobay *2000000);
    cout<<a<<endl;
}

class Tiepvien:
    public Nhanvien
{
    protected:
        int Sochuyenbay;
    public:
        Tiepvien()
        {
            Sochuyenbay=0;
        }
        ~Tiepvien();
        void Nhap();
        void Xuat();
        void Tienluong(Tiepvien TV);
};

Tiepvien::~Tiepvien()
{

};
void Tiepvien::Nhap()
{
    Nhanvien:Nhap();
    cout<<"Nhap so chuyen bay: ";
    cin>>this->Sochuyenbay;
}
void Tiepvien::Xuat()
{
    Nhanvien::Nhap();
    cout<<"So chuyen bay: ";
    cout<< this->Sochuyenbay;
}
void Tiepvien::Tienluong(Tiepvien TV)
{
    cout<<"Tien luong tiep vien: ";
    int a=this->Sochuyenbay * 3000000;
    cout<<a<<endl;
}
int main()
{
   Phicong PC;

   PC.Nhap();
   PC.Tinhluong(PC);
   PC.Xuat();

   Tiepvien TV;
   TV.Nhap();
   TV.Tienluong(TV);
   TV.Xuat();


    return 0;
}
