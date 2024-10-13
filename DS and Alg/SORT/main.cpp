#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 50
#define M 7

using namespace std;

struct Node
{
    int data;
    Node* pNext;
};

Node* CreateNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->pNext = NULL;
    return p;
}

struct List
{
    Node* pHead;
    Node* pTail;
};
void CreateList(List& T)
{
    T.pHead = T.pTail = NULL;
}

//Ham in danh sach
void Print_list(List L)
{
    for (Node* i = L.pHead; i != NULL; i = i->pNext)
    {
        cout << i->data << " ";
    }
    cout << endl;
}


//Chen node

void Add_tail(Node* p, List& L)
{
    if (L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }

}


struct Hashtable
{
    List bucket[M];
};

int Hash_funtion(int data)
{
    return data % M;
}



// them mot gia tri vao bang
void Insert_node(Hashtable& H, int data)
{
    int b = Hash_funtion(data);
    b = abs(b);
    Node* p = CreateNode(data);
    Add_tail(p, H.bucket[b]);
}

//Khoi dong bang bam

void Init_Hash(Hashtable& H)
{
     for (int i = 0; i < M; i++)
    {
        CreateList(H.bucket[i]);
    }

}


//Ham in bang

void Print_Hash(Hashtable& H)
{
     for (int i = 0; i < M; i++)
    {
        cout << "\nBucket so " << i << ": " << endl;
        Print_list(H.bucket[i]);
    }
}

//Ham tao bang tu dong
void Input_auto(Hashtable& H)
{
    int a;
    int n;
    n = 45 + rand() % 20;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 988 - rand() % 856;
        Insert_node(H, a);
    }
}
void Inchange(List& L, Hashtable& H)
{
    for(int i = 0; i < M; i++)
    {
        L = H.bucket[i];
        for(Node* i = L.pHead; i != NULL ;i = i->pNext)
        {
            for(Node* j = i->pNext;j != NULL; j = j->pNext)
                if( i->data > j->data)
                swap(i->data, j->data);
        }
    }
}

void Selection(List& L, Hashtable& H)
{
    Node* min;
    for(int a = 0 ; a < M; a++)
    {
        L = H.bucket[a];
        for(Node* i = L.pHead; i!=NULL; i=i->pNext)
        {
            min = i;
            for(Node*j = i->pNext; j!=NULL; j = j->pNext)
            {
                if(j->data < i->data)
                    min = j;
            }
            if (min != i)
                swap(min->data, i->data);
        }
    }
}

void Quicksort()
/*
void DuyetNguoc(Node *p)
{
     if (p==NULL) return;
     else DuyetNguoc(p->pNext);
     cout<<p->data<<" ";
}
*/
int main()
{
    srand(time(0));
    Hashtable H;
    List L;
    Init_Hash(H);
    Input_auto(H);
    Selection(L, H);
    Print_Hash(H);

    return 0;
}
