#include <iostream>
using namespace std;

class CTime {
	private:
		int Gio, Phut, Giay;
	public:
		void Nhap();
		void Xuat();
		void Tang_1_Giay();
		void Giam_1_Giay();
		void Tang_Nhieu_Giay(int);
		void Giam_Nhieu_Giay(int);
		CTime Tru_2_Thoi_Gian(CTime);
		void Kiem_Tra_Thoi_Gian();
};
