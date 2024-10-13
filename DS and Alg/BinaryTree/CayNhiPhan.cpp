#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#define MAXN 100

using namespace std;

struct Node
{
	int data;
	Node* pLeft;
	Node* pRight;
};

Node* CreateNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

struct Tree
{
	Node* root;
};

void CreateTree(Tree& t)
{
	t.root = NULL;
}
 //ham in node cay
void PrintNode(Node* p)
{
	if (p == NULL)
		return;
	if (p->pLeft != NULL)
	{
		cout << "Node trai la: " << p->pLeft << endl;
	}
	else
	{
		cout << "\nKhong co Node trai!" << endl;
	}
	if (p->pRight != NULL)
	{
		cout << "Node trai la: " << p->pRight <<endl ;
	}
	else
	{
		cout << "\nKhong co node phai!" << endl;
	}
}
//Ham in cay
void PrintTree(Tree& t)
{
	cout << t.root << endl;
}
//Ham chen node
void addNode(Tree& T, Node* p)
{
	cout << p->data;
	if (T.root == NULL) {

		T.root = p;
		cout << "\n +Chen vao root: " << T.root << '\n';
	}

	Node* i = T.root;
	while (i != NULL)
	{
		if (p->data < i->data)
		{
			if (i->pLeft == NULL)
			{
				i->pLeft = p;
				cout << "\n +Chen trai node: " << i << '\n';
				break;
			}
			else
				i = i->pLeft;
		}
		else if (p->data > i->data)
		{
			if (i->pRight == NULL)
			{
				i->pRight = p;
				cout << "\n +Chen phai node: " << i << '\n';
				break;
			}
			else
				i = i->pRight;
		}
		else if (p->data == i->data) {
			cout << "\nDa ton tai gia tri vua nhap tren cay!\tNhap lai!\n";
			return;
		}

	}
}
/*
// Ham nhap cay thu cong
void NhapThucong(Tree& t)
{
	char n;
	int a;
	do
	{
		cout << "Nhap gia tri: ";
		cin >> a;
		Node* p;
		p = CreateNode(a);
		addNode(t, p);
		cout << "\nTiep tuc chon 'c', dung lai chon 'e': ";
		cin >> n;
	} while (n != 'e');
}
*/
void Array(int a[],int n)
{
	cout << "Nhap so luong: ";
	cin >> n;
	cout << "\nNhap gia tri: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void InputArray(Tree& T, int a[])
{
	int n;
	cout << "Nhap so luong gia tri: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap gia tri: ";
		cin >> a[i];
		Node* p = CreateNode(a[i]);
		addNode(T, p);
	}
}

void Print2( Node* p)
{
	if (p != NULL)
	{
		if (p->pLeft == NULL && p->pRight != NULL)
		{
			cout << "Node can tim:" << p->data;
		}
		if (p->pLeft != NULL && p->pRight == NULL)
		{
			cout << "Node can tim:" << p->data;
		}
		else
		{
			cout << "Khong co";
		}
	}
}
int main()
{
	int a[MAXN], n;
	Node* p;
	Tree t;
	CreateTree(t);
	InputArray(t, a);
	PrintTree(t);
	return 0;
}