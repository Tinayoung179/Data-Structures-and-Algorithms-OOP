#include <iostream>
#include <cmath>
#define MAXN 100

using namespace std;

void Input(int a[], int& n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	cout << "\nNhap gia tri: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << endl;
}

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n-1; j>i; j--)
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
			}
	}
}

void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void InsertionSort(int a[], int n)
{
	int k;
	int j;
	for (int i = 1; i < n; i++)
	{
		k = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j+1] = k;
	}
}
void SelectionSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
				swap(a[i], a[min]);
			}
		}
	}
}
void BinarySort(int a[], int n)
{
	int l, r, m, i;
	int x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		l = 0;
		r = i - 1;

		while (l <= r)
		{
			m = (l + r) / 2;
			if (x < a[m])
			{
				r = m + 1;
			}
			else
				l = m - 1;

		}
		for (int j = i - 1; j <= l; j--)
		{
			a[j + 1] = a[j];
			a[l] = x;
		}

	}

}
void Output(int a[], int n)
{
	cout << "Mang da sort: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

}

int main()
{
	int a[MAXN], n;
	Input(a, n);

	BinarySort(a, n);

	Output(a, n);
	return 0;
}