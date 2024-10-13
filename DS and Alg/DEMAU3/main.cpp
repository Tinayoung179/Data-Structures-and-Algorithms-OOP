#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>


using namespace std;

struct SinhVien
{
    string Name;
    int ID;
    float GPA;
};


struct Node
{
    SinhVien SV;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

Node* CreateNode(SinhVien SV)
{
    Node* p;
    p = new Node;
    if(p == NULL)
        return NULL;
    p->SV =SV;
    p->pNext = NULL;
    return p;
}

void CreateList(List& L)
{
    L.pHead = L.pTail = NULL;
}

void addHead(List& L, Node* p)
{
    if(L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

void addTail(List& L, Node* p)
{
    if(L.pHead == NULL)
    {
        L.pTail = L.pHead = p;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
void Input(List& L)
{
    char n;
    SinhVien SV;

    do
    {
        cout <<"Nhap ID: ";
        cin >> SV.ID;

        cout <<"\nNhap ho va ten: ";

        cin.ignore();
        getline(cin, SV.Name);
        fflush(stdin);

        cout <<"\nNhap GPA: ";
        cin >> SV.GPA;

        Node* p = CreateNode(SV);

        addTail(L , p);

        cout <<"\nThoat ra nha 'e', tiep tuc nhap 'c'!:  ";

        cin >> n;
    }while(n != 'e');

}
void Print_list(List& L)
{
    for(Node* i = L.pHead;i != NULL;i = i->pNext)
    {
        cout << endl << (i->SV.Name) << endl;
        cout <<i->SV.ID << endl;
        cout <<i->SV.GPA;
    }
    cout << endl;
}
int main()
{
    srand(time(0));
    Node* p;
    List L;
    CreateList(L);

    Input(L);
    cout << endl;

    //Delete_X(L);

    Print_list(L);

    //string a;
    //cin >> a;
    //cout << a;
    return 0;
}
