#include <iostream>
#include <cmath>
#define MAXN 200

using namespace std;
void Input(int a[], int& n)
{
	cout << "Nhap so luong: ";
	cin >> n;
	cout << "\nNhap gia tri: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << endl;
}

void Heapify(int a[], int n, int i)
{
	int large = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[large])
	{
		large = l;
	}
	if (r<n && a[r]>a[large])
	{
		large = r;
	}

	if (large != i)
	{
		swap(a[i], a[large]);
		Heapify(a, n, large);
	}


}

void HeapSort(int a[], int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		Heapify(a, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		Heapify(a, i, 0);
	}
}

void Output(int a[], int n)
{

	cout << "Mang sau khi Sort: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int main()
{
	int n;
	int a[MAXN];
	Input(a, n);

	HeapSort(a, n);

	Output(a, n);
	return 0;
}