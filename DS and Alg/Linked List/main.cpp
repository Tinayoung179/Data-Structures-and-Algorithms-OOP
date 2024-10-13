#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node* pNext;
};


Node* CreateNode(int x)
{
    Node* p = new Node;
    if(p == NULL)
        return NULL;
    p->data = x;
    p->pNext =NULL;
    return p;
}

struct List
{
    Node* pHead;
    Node* pTail;
};

void CreateList(List& L)
{
    L.pHead = L.pTail = NULL;
}
// Ham chen dau
void addHead(List& L, Node* p)
{
    if(L.pHead == L.pTail && L.pHead == NULL )
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }

}

//Ham chen cuoi
void addTail(List& L, Node* p)
{
    if(L.pHead == L.pTail && L.pTail == NULL)
    {
        L.pTail = L.pHead = p;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

//Nhap gia tri thu cong cho danh sanh
void Input(List& L)
{
    int x;
    char n;
    do
    {
        cout<<"\nNhap gia tri: ";
        cin >> n;
        cin >> x;
        Node* p = CreateNode(x);
        addHead(L, p);
        cout <<"\nNhap c de tiep tuc, e de dung lai: ";
        cin >> n;
    }while(n != 'e');
}
//Nhap danh sach theo kieu tu dong
void Input_auto(List& L)
{
    int n;
    int a;
    n = 10 + rand()% 20;
    cout << "random so luong phan tu la: " << n;
    for(int i=0; i < n; i++)
    {

        a = 40 + rand()%50;
        cout <<"\nGia tri la: "<< a << " " ;
        Node* p= CreateNode(a);
        addTail(L,p);

    }
}

//Xoa node dau
void Delete_head(List& L)
{
  if (L.pHead == NULL)
		cout << "\nKhong the xoa";
	else if (L.pHead->pNext == NULL)
	{
		Node* p;
		p = L.pHead;
		delete p;
		L.pHead = L.pTail = NULL;
	}
	else
	{
		Node* p;
		p = L.pHead;
		L.pHead = L.pHead->pNext;
		delete p;
		cout << "\nDa xoa";
	}
}

//Xoa cuoi
void Delete_tail(List& L)
{
	if (L.pHead == NULL)
		cout << "\nKhong the xoa";
	if (L.pHead == L.pTail)
	{
		Node* p;
		p = L.pTail;
		delete p;
		L.pHead = L.pTail = NULL;
	}
	else
	{
		Node* p;
		for (Node* i = L.pHead; i != NULL; i = i->pNext)
		{
			if (i->pNext == L.pTail)
			{
				p = L.pTail;
				i->pNext = NULL;
				L.pTail = i;
				delete p;
				break;
			}
		}


		cout << "\nDa xoa";
	}
}
//Xoa 1 node bat ky
void Delete_X(List& L)
{
	int x;
	Node* temp = CreateNode(0);

	cout << "Nhap gia tri X muon xoa: ";
	cin >> x;

	if (x == L.pHead->data)
	{
		Delete_head(L);
		return;
	}
	else
	{
		for (Node* i = L.pHead; i != NULL; i = i->pNext)
		{
			if (i->pNext == NULL && x == L.pTail->data)
			{
				Delete_tail(L);
				return;
			}
			else if (i->pNext == NULL)
			{
				cout << "\nKhong tim duoc gia tri can xoa!\n";
			}
			if (i->pNext->data == x)
			{
				temp = i->pNext;
				i->pNext = i->pNext->pNext;
				delete temp;
				break;
			}
		}
	}
}
//Ham in danh sach
void Print_list(List& L)
{
    for (Node* i = L.pHead; i != NULL; i = i->pNext)
    {
        cout << i->data << " ";
    }
    cout << endl;
}


//Ham chen node bat ky
void Insert_X(List& L,Node* i)
{

    int vt;
    cout <<"\nNhap vi tri can chen: ";
    cin>> vt;
    int k;
    cout <<"\nNhap gia tri can chen: ";
    cin >> k;

    Node* q;
    q = CreateNode(k);

    if(L.pHead == NULL)
    {
        L.pHead = L.pTail =NULL;
    }
    else
    {
        for(i = L.pHead;i != NULL;i = i->pNext)
        {
            if(i->pNext == NULL && vt == L.pTail->data)
            {
                addTail(L,q);
            }
            else
            {
                if(i->data == vt)
                {
                    q->pNext = i->pNext;
                    i->pNext =q;
                    break;
                }
            }
        }
    }
}



//Ham tinh tong chan
int Sum_even(List& L,int& s)
{
    for (Node* i = L.pHead; i != NULL; i = i->pNext)
    {
        if(i->data % 2 == 0)
            s = s + i->data;
    }
    return s;
}
//Dem so luong cac node
int Count_node(List& L, int& dem)
{
    dem = 0;
    for(Node*i = L.pHead; i != NULL;i = i->pNext)
    {
        dem++;
    }
    return dem;
}
int main()
{
    Node* p;
    List L;
    CreateList(L);
    srand(time(0));

    Input_auto(L);
    cout <<endl;;

    int dem = 0;
    cout <<Count_node(L, dem);

    cout << endl;
    //Print_list(L);

    return 0;
}
