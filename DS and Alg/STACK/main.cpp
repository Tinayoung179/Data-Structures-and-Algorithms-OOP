#include <iostream>

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
    p->pNext =NULL;
    p->data = x;
    return p;
}

struct Stack
{
    Node* top;
    int Size;
};

void CreateStack(Stack& s)
{
    s.top = NULL;
}


bool Isfull(Stack& s)
{
    int dem = 0;
    cin >> s.Size;
    if(s.top == NULL)
        return false;
    else
    {
        for(Node* p = s.top;p != NULL; p = p->pNext)
        {
            dem++;
            cout << dem;
        }
        dem = s.Size;
        return true;
    }
}

bool Isempty(Stack s)
{
    if(s.top = NULL)
        return true;
    return false;
}

void Push(Stack& s, Node* p)
{
    if(s.top == NULL)
    {
        s.top = p;
    }
    else
    {
        s.top->pNext = p;
        s.top = p;
    }
}

void POP(Stack& s, int& x)
{
    if( s.top == NULL)
        cout <<"Rong";
    Node* p = s.top;
    s.top = s.top->pNext;
    x = p->data;
    delete p;
    cout << x;

}

void Input(Stack&s)
{
    char n;
    int x;
    do
    {
        cout << "\nNhap gia tri x: ";
        cin >> x;

        Node* p = CreateNode(x);
        Push(s, p);
        cout <<"\nNhap 'e' de ngung lai, 'c' de tiep tuc! ";
        cin >> n;
    }while(n != 'e');
}


void Print(Stack& s)
{
    for(Node* i = s.top;i != NULL;i = i->pNext)
    {
        cout << i->data <<" ";
    }
    cout << endl;
}

int main()
{
    Node* p;
    Stack s;
    CreateStack(s);

    Input(s);

    int x = 0;
    POP(s,x);
    cout <<"kkkkkkkk";



    Print(s);
    return 0;
}
