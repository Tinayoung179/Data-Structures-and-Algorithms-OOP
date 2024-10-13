#include <iostream>
#include <cmath>
#define MAXN 100

using namespace std;

void Input(int a[], int& n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	cout <<"\nNhap gia tri :" ;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << endl;
}
/*
void QuickSort(int a[], int left, int right)
{
	int i, j;
	int x = a[(left + right) / 2];
	i = left;
	j = right;
	do
	{
		while (a[i] < x )
		{
			i++;
		}
		while (a[j] > x)
		{
			j--;
		}
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);

}*/
void QuickSort2(int a[], int left, int right)
{
	int x, j, i;
	x = a[right];
	j = left;
	i = right;
	do
	{
		while (a[j] < x)
		{
			j++;
		}
		while (a[i] > x)
		{
			i--;
		}
		if (j <= i)
		{
			swap(a[j], a[i]);
			j++;
			i--;
		}
	} while (j <= i);
	if (left < i)
		QuickSort2(a, left, i - 1);
	if(right > j)
		QuickSort2(a, j + 1, right);
}
void Output(int a[], int n)
{
	cout << "Mang da Sort: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] <<" ";
	}
}

int main()
{
	int a[MAXN];
	int n;

	Input(a, n);
	QuickSort2(a, 0, n - 1);
	Output(a, n);

	return 0;
}
