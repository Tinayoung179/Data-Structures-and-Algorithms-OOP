#include <iostream>
#define MAXN 100
#include<stdlib.h>
#include<time.h>

using namespace std;

struct Node
{
    double  data;
    Node* pLeft;
    Node* pRight;
};

struct Tree
{
    Node* root;
};

Node* CreateNode(double  x)
{
    Node* p;
    p = new Node;
    p->pLeft = NULL;
    p->pRight = NULL;
    p->data = x;
    return p;
}

void CreateTree(Tree& T)
{
    T.root = NULL;
}
//Cau 1 chen node chua gia tri kieu so thuc vao cay
void addNode(Tree& T, Node* p)
{
    if (T.root == NULL){
        T.root = p;
        cout << "Chen vao Node root\n";

    }
    else {
    Node* i = T.root;
    Node* f = NULL;
    while (i != NULL)
    {
        f = i;
        if (p->data < i->data)
        {
            i = i->pLeft;
        }
        else if (p->data > i->data)
        {
            i = i->pRight;
        }
        else
        {
            cout << "Bi trung gia tri nen BO QUA\n";
            return ;
        }
    }
    if (p->data > f->data)
    {
        cout << "Chen phai" << f << '\n';
        f->pRight = p;
    }
    if (p->data < f->data)
    {
        cout << "Chen trai" << f << '\n';
        f->pLeft = p;
    }
    }
}
void print(Node* p)
{
    if (p == NULL)
        return;
    if (p->pLeft != NULL)
    {
        cout << p->pLeft << endl;
    }
    else
    {
        cout << "Left rong" << endl;
    }
    if (p->pRight != NULL)
    {
        cout << p->pRight << endl;
    }
    else
    {
        cout << "Right rong" << endl;
    }
}
// cau 2 tao cay tu dong
void Inputauto(Tree &T)
{
    int  n;
    double  a;
    n = 50 + rand() % 11;
    for (int i = 0; i < n; i++)
    {
        a = double(rand() % 211) + 512.001 + double((rand() % 1000) / 1000.0);
        Node* p = CreateNode(a);
        cout << a << '\n';
        addNode(T, p);
    }
}

void Array(int& n, double a[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

// cau 3 tao cay tu dong tu 1 mang
void Input_array(Tree &T)
{
    int n;
    double a;
    n = 10 + rand() % 100;
    for (int i = 0; i < n; i++)
    {
        a = float(rand() % 211) + 512.001 + float((rand() % 1000) / 1000.0);
        Node* p = CreateNode(a);
        cout << a << '\n';
        addNode(T, p);
    }
}
// cau 4 Duyet cay theo RNL, LNR. NRL

void LRN(Node* p)
{
    if (p != NULL)
    {
        LRN(p->pLeft);// duyet phai

        LRN(p->pRight);// Duyet trai

        cout << p->data << '\t' << p << " pLeft:" << p->pLeft << " pRight:" << p->pRight;
    }
}

void RNL(Node* p)
{
    if (p == NULL)
        return;

        RNL(p->pRight); // duyet phai

        cout << p->data << '\t' << p << " pLeft:" << p->pLeft << " tpRight:" << p->pRight;

        RNL(p->pLeft); // duyet trai


}

void NRL(Node* p)
{
    if (p != NULL)
    {
        cout << p->data << '\t' << p << " pLeft:" << p->pLeft << " pRight:" << p->pRight;

        NRL(p->pRight); // duyet phai

        NRL(p->pLeft); // duyet trai

    }

}

// cau 5 tim gia tri X

Node* TimKiem(Tree& T, double data)
{
    if (T.root == NULL)
        return NULL;

    Node* temp = new Node;
    temp = CreateNode(0);

    for (Node* i = T.root; i != NULL;)
    {
        if (data < i->data)
            if (i->pLeft == NULL)
                return NULL;
            else
                i = i->pLeft;
        else if (data > i->data)
            if (i->pRight == NULL)
                return NULL;
            else
                i = i->pRight;
        else if (data == i->data)
        {
            temp = i;
            temp->data = data;
            return temp;
        }
    }
    return NULL;
};
// cau 6 dem toan bo so node cua cay
int Count_node(Node* p)
{
    if (p == NULL)
        return 0;
    int a = Count_node(p->pLeft);
    int b = Count_node(p->pRight);
    return a + b + 1;
}

// cau 7 in cac node nhanh con lai tu mot node nhap vao, duyet LNR
void Node_rest(Node* p, Node* q)
{
    double  x = 0;

    if (p == NULL)
    {
        cout << "Khong tim thay";
    }
    else
    {
        if (p->data > q->data)
        {
            Node_rest(p->pLeft, q);
        }
        if (p->data < q->data)
        {
            Node_rest(p->pRight, q);
        }
        if (p->data == q->data)

        {
            x = 1;
        }
        if (x != 0)
        {
            LRN(p);
        }
    }

}

// cau 8 dem so node co gia tri lon hon X nho hon Y
int  Count_XY(Node* p, int x, int y)
{
    if (p == NULL) return 0;
    int a = Count_XY(p->pLeft, x, y);
    int b = Count_XY(p->pRight, x, y);
    if (p->data > x && p->data < y)

        return a + b + 1;
    else

        return a + b;

}

//cau 9 Tim cac gia tri chan le trong cay

int Count_even(Node* p)
{
    if (p == NULL)
        return 0;
    else
    {
        int  x = Count_even(p = p->pLeft);
        int  y = Count_even(p = p->pRight);

        if (int(p->data) % 2 == 0)
            return x + y + 1;
        else
        {
            return x + y;
        }

    }
    return 0;
}

int Count_odd(Node* p)
{
    if (p == NULL)
        return 0;
    else
    {
        int x = Count_odd(p = p->pLeft);
        int y = Count_odd(p = p->pRight);

        if (int(p->data) % 2 != 0)
            return x + y + 1;
        else
        {
            return x + y;
        }

    }
    return 0;
}

void Compare_even_odd(int even, int odd)
{
    if (even < odd)
        cout << " -1\n";
    if (even == odd)
        cout << "0\n";
    if (even > odd)
        cout << " 1\n";
}
// cau 10 lam menu
int main()
{
    double a[MAXN];
    int Choose;
    Node* p;
    Tree T;
    CreateTree(T);
    srand(time(0));
    char nhap;
    double x;
    {
        while (true)
        {
        cout << "------------------------------------------------------MENU--------------------------------------------------\n"
                "|1. Ham tao cay tu dong, cac so luong va gia duoc chon ngau nhien trong khoang cho truoc                   |\n"
                "|2. Ham tao cay tu dong tu mang n phan tu                                                                  |\n"
                "|3. Ham dyet cay theo RNL, LRN, NRL                                                                        |\n"
                "|4. Ham tim kiem gia tri X                                                                                 |\n"
                "|5. Ham dem toan bo so Node cua cay                                                                        |\n"
                "|6. Ham in ra cac Node nhanh con lai tu mot Node duoc nhap vao                                             |\n"
                "|7. Ham dem so node co gia tro lon hon X nho hon Y                                                         |\n"
                "|8. Ham dem cac Node chan le va so sanh so luong Node chan va Node le + so sanh ( cau 9)                   |\n"
                "|0. EXIT                                                                                                   |\n"
                "------------------------------------------------------END---------------------------------------------------\n"
                "Moi ban chon so: ";
            cin >> Choose;
            if (Choose == 0)
            {
                break;
            }
            switch (Choose)
            {
            case 1:
            {
                Inputauto(T);
                break;
            }

            case 2:
            {
                int n;
                Array(n, a);
                Input_array(T);
                break;
            }
            case 3:
            {
                cout << "Duyet RNL\n";
                RNL(T.root);

                cout << "\nDuyet LRN\n";
                LRN(T.root);

                cout << "\nDuyet NRL\n";
                NRL(T.root);

                break;
            }

            case 4:
            {
                do {
                    cout << "\n=           Menu cau 4         =\n"
                        << "=    a. X do nguoi dung nhap.    = \n"
                        << "=    b. X trong khoang = \n"
                        << "=    c. Thoat.                   =\n";
                    cout << "\nChon: ";
                    cin >> nhap;
                    switch (nhap)
                    {
                    case 'a':
                    {
                        cout << "Nhap gia tri can tim kiem X= ";
                        cin >> x;
                        cout << TimKiem(T, x);
                        break;
                    }

                    case 'b':
                    {
                        x = 300 + rand() % 501;
                        cout << "X can tim X=" << x << '\n';
                        cout << "Khong tim thay!\n";
                    default:
                        break;
                    }
                    }
                } while (nhap != 'c');
            }
            break;
            case 5:

                cout << "So luong nood tren cay la: ";
                cout << Count_node(T.root) << '\n';
                break;


            case 6:
            {
            Node* q = NULL;
            cin >> x;
            q =TimKiem(T, x);
                cout << "In cac Node nhanh: ";
                Node_rest(T.root, q) ;
                cout << endl;
                break;
            }


            case 7:
            {
                int k, h;
                cout << "Nhap gia tri cho khoang [X, y] can dem so node:\n";
                cout << "Nhap X= ";
                cin >> k;
                cout << "Nhap Y= ";
                cin >> h;
                cout << "So luong X < node < Y la: ";
                cout << Count_XY(T.root, k, h) << '\n';
            }
            case 8:
            {
                cout << "So luong Node co gia tri chan: " << Count_even(T.root) << endl;

                cout << "So luong Node co gia tri le: " << Count_odd(T.root) << endl;

                Compare_even_odd(Count_even(T.root), Count_odd(T.root));
                break;
            }

            default:
            break;
            }
        }

    }
    return 0;

}
