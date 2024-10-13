#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cmath>
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
    Node * p= new Node;
    if (p== NULL)
        return NULL;
    p->data = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
struct Tree
{
    Node* root;
};

void CreateTree(Tree& T)
{
    T.root = NULL;
}
//ham in node cua cay

void PrintNode(Node* p)
{
    if (p == NULL)
        return;
    if (p->pLeft != NULL)
    {
        cout << "Node trai: " << p->pLeft << endl;
    }
    else
    {
        cout <<"\nnhanh trai rong \n";
    }
    if (p->pRight != NULL)
    {
        cout << "Node phai: " << p->pRight << endl;
    }
    else
    {
        cout <<"\nnhanh phai rong \n";
    }
}
// ham in cay nhi phan
void PrintTree(Tree& T)
{
    cout << T.root << endl;
}

//HAM CHEN NODE CO GIA TRI

void addNode(Tree& T, Node* p)
{
	cout << p->data;
	if (T.root == NULL){

		T.root = p;
		cout << "\n +Chen vao root: " << T.root << '\n';
	}

    Node*i = T.root;
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
};

// ham nhap thu cong cho cay

void Input(Tree& T)
{
    char n;
    int a;
    do
    {
        cout << "Nhap gia tri: ";
        cin >> a;
        Node* p;
        p = CreateNode(a);
        addNode(T, p);
        cout << "\nTiep tuc nhap 'c', thoat ra chon 'e': ";
        cin >> n;
    }while(n != 'e');
}

// tao mang
void Array(int n, int a[])
{
    cin >> n;
    for( int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
// Ham nhap tu mang 1 chieu tu dong
void Input_array(int a[], Tree& T)
{
    int n;
    cout << "Mang gia tri tao tu dong\nn la: ";
    n = 10 + rand()%20;
    for( int i = 0; i < n; i++)
    {
        a[i] =rand()%50 + 1;
        Node* p = new Node;
        p = CreateNode(abs(a[i]));
        addNode(T, p);
    }
}

// ham nhap cay tu mang mot chieu
void Input_A(Tree& T, int a[])
{
    int n;
    cout << "Nhap so luong gia tri: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "\nNhap gia tri: ";
        cin >> a[i];
        Node*p = CreateNode(abs(a[i]));
        addNode(T, p);
    }

}

// Ham nhap tu dong gia tri cho cay
void Input_auto(Tree& T, int b)
{
    int n;
    cout << "Tao tu dong so luong gia tri la: ";
    n = 10 + rand() % 10;
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        b = rand()%50 + 40;
        Node* p = CreateNode((b));
        addNode(T, p);
    }
}

//Ham dem node cua cay
int Count_Node(Node* p)
{
    if(p == NULL) // viết 1 cáu
        return 0;
    int a = Count_Node(p->pLeft);
    int b = Count_Node(p->pRight);
    if(p != NULL)
    {
        return (a + b + 1);
    }
    else
    {
        return (a + b);
    }
}

//Ham dem node la
int Count_leaf(Node* p, int& dem)
{

    if (p == NULL)
        return 0;
    if (p-> pLeft == NULL)
    {

        if(p-> pRight == NULL)
        dem++;
    }
    Count_leaf(p->pLeft, dem);

    Count_leaf(p->pRight, dem);

    return dem;
}
// Dem node chan
int Count_even(Node* p)
{
    if( p == NULL)
        return 0;
    else
    {
        int x = Count_even(p->pLeft);
        int y = Count_even(p->pRight);
        if( p->data % 2 == 0)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

// Dem node le
int Count_odd(Node* p)
{
    if (p == NULL)
        return 0;
	int x = Count_odd(p->pLeft);
	int y = Count_odd(p->pRight);
	if (p->data % 2 != 0)
	{
		return x + y + 1;
	}
	else
	{
		return x + y;
	}
}

// So sanh so luong node chan le
void Compare(int even, int odd)
{
    if( even > odd)
        cout << "Chan nhieu hon le";
    if( even < odd)
        cout << "chan it hon le";
    if( even == odd)
        cout <<"Chan bang le";
}

//DUYET 6 KIEU

//Duyet theo NLR
void NLR(Node* p)
{
    if(p != NULL)
    {
        cout << p->data;

        NLR(p->pLeft);

        NLR(p->pRight);
    }
}

//Duyet theo NRL
void NRL(Node* p)
{
    if(p != NULL)
    {
        cout << p->data;

        NRL(p->pRight);

        NRL(p->pLeft);
    }
}

//Duyet theo LNR
void LNR(Node* p)
{
    if(p != NULL)
    {
        LNR(p->pLeft);

        cout << p->data <<'\n' << "pleft: " << p->pLeft <<'\t' <<"pright: " << p->pRight;

        LNR(p->pRight);
    }
}

// Duyet theo RNL

void RNL(Node* p)
{
    if(p != NULL)
    {
        RNL(p->pRight);

        cout << p->data;

        RNL(p->pRight);
    }
}

//Duyet theo LRN

void LRN(Node* p)
{
    if(p != NULL)
    {
        LNR(p->pLeft);

        LNR(p->pRight);

        cout << p->data;

    }
}
//Duyet theo RLN
void RLN(Node* p)
{
    if(p != NULL)
    {
        RLN(p->pRight);

        RLN(p->pLeft);

        cout << p->data;
    }
}

//Dem cac node nhanh con lai tu 1 node nhap vao
void Count_rest(Tree& T, float x)
{
	Node* p = T.root;
     if (p==NULL)
		 return;

	while (p != NULL)
	{
		if (x < p->data)
			p = p->pLeft;
		else if (x > p->data)
			p = p->pRight;
		else{
			LRN(p);
			break;
		}
	}
}

//Dem cac node lon hon X
int Count_more(int x, Node* p)
{
    if( p == NULL)
        return 0;
    int a = Count_more(x, p->pLeft);
    int b = Count_more(x, p->pRight);
    if( p->data > x)
    {
        return a + b + 1;
    }
    else
    {
        return a + b;
    }

}


// Ham dem node lon hon X be hon Y
int Count_XY(int X, int Y, Node* p)
{
    if(p == NULL)
        return 0;
    int a = Count_XY(X, Y, p->pLeft);
    int b = Count_XY(X, Y, p->pRight);

    if( p->data > X && p->data < Y )
    {
        return (a + b + 1);
    }
    else
    {
        return (a + b);
    }
}

//Ham dem  node co gia tri bang k
int Count_K(int k, Node* p)
{
    if(p == NULL)
        return 0;
    int a = Count_K(k, p->pLeft);
    int b = Count_K(k, p->pRight);

    if(p->data == k)
    {
        return a + b + 1;
    }
    else
    {
        return a + b;
    }
}

//TIM THEO YEU CAU
//Ham tim
Node* Find_X(Node* p, int m)
{
    if(p == NULL)
        return NULL;
    if(p != NULL)
    {
        if( p->data = m)
            return p;
        if( p->data > m)
             Find_X(p->pLeft, m);
        else
             Find_X(p->pRight,m);
    }
}

//Ham tim node max
int Find_MAX(Node* p, int& Max)
{
    if(p !=NULL)
    {
        if(p->data > Max)
        {
            Max = p->data;
        }
        Find_MAX(p->pLeft, Max);
        Find_MAX(p->pRight, Max);
    }
    return Max;
}
//Ham tim node co gtri min
int Find_MIN(Node* p, int& Min)
{
    if(p !=NULL)
    {

        if(p->data < Min)
        {
            Min = p->data;
        }
        Find_MIN(p->pLeft, Min);
        Find_MIN(p->pRight, Min);
    }
    return Min;
}
//HAM XOA

//Ham xoa mot node X tren cay
Node* ValueNode(Node* p)
{
	Node* Replace = p;
	while (Replace&& Replace->pLeft!=NULL)
		Replace = Replace->pLeft;
	return Replace;
}

Node* Delete_X(Node* p, int h)
{
	if (p->data > h)
		p->pLeft = Delete_X(p->pLeft, h);
	else if (p->data < h)
		p->pRight = Delete_X(p->pRight, h);
	else
	{
		if (p->pLeft == NULL && p->pRight == NULL)
			return NULL;
		if (p->pLeft == NULL)
		{
			Node* temp = p->pRight;
			delete(p);
			return temp;
		}
		else if (p->pRight == NULL)
		{
			Node* temp = p->pLeft;
			delete(p);
			return temp;
		}
		Node* temp1 = ValueNode(p->pRight);
		p->data = temp1->data;
		p->pRight = Delete_X(p->pRight, temp1->data);
	}
	return p;
}

//Ham xoa toan bo node

void Delete_all(Node* p)
{
    if(p == NULL)
        return;
    if(p != NULL)
    {
        if(p->pLeft)
            Delete_all(p->pLeft);
        if(p->pRight)
            Delete_all(p->pRight);
    }
    delete p;
    //p = NULL;
}

//Ham xoa node dau tien
void Delete_first(Node* p,Tree& T)
{
    if(p == NULL)
    {
        cout<<"Da xoa!";
    }
    else
    {
        T.root = p;
        delete p;
    }

    p = NULL;
}

//TINH

//Tinh tong cac node trong cay

int Total_node(Node*p, int& s)
{

    if(p == NULL)
        return 0;
    int a = Total_node(p->pLeft, s);
	int b = Total_node(p->pRight, s);
	if (p != NULL)
	{
	 s= p->data;
	 return a + b + s;
	}
	return a+b;
}

//Tinh tong cac node chan
int Sum_even(Node* p, int& S)
{
    if(p == NULL)
    {
        return 0;
    }
    int a = Sum_even(p->pLeft, S);
    int b = Sum_even(p->pRight, S);
    if(p != NULL && p->data % 2 == 0)
    {
        S = p->data;
        return a + b + S;
    }
    return a + b;
}


//Tinh tong node le
int Sum_odd(Node* p, int& sum)
{
    if(p == NULL)
    {
        return 0;
    }
    int a = Sum_odd(p->pLeft, sum);
    int b = Sum_odd(p->pRight, sum);
    if(p != NULL && p->data % 2 == 0)
    {
        sum = p->data;
        return a + b + sum;
    }
    return a + b;
}


int main()
{
    Node* p;
    Tree T;
    CreateTree(T);
    srand(time(0));
    int a[MAXN];
    int b;
        int chon;
    while(chon != 0)
    {
        cout <<"-------------------------------Menu------------------------------------------"
               "\n1.Ham chen node\n"
               "2.Ham nhap thu cong\n"
               "3.Ham nhap mang\n"
               "4.Ham nhap mang thu cong\n"
               "5.Ham nhap tu dong\n"
               "6.Dem node\n"
               "7.Dem node la\n"
               "8.Dem node chan\n"
               "9.Dem node le\n"
               "10.So sanh so luong chan le\n"
               "11.Dem node con lai\n"
               "12.Dem node lon hon\n"
               "13.Dem node lon hon X be hon Y\n"
               "14.Dem gia tri bang k\n"
               "15.Tim kiem va dia node co gia tri giong\n"
               "16.Tim gia tri lon nhat\n"
               "17.Tim gia tri lon nhat\n"
               "18.Xoa 1 node X\n"
               "19.Xoa het node\n"
               "20.Xoa node dau"
               "21.Tinh tong cac node\n"
               "0.Exit\n";
        cout<<"-------------------------------------------------------------------------------\n";
        cout<<"Moi chon: ";
        cin>> chon;
        {
            if(chon == 0)
            {
                cout << "Thoat chong trinh";
                break;
            }
            else
            {
                switch(chon)
                {
                    case 1:
                        addNode(T, p);
                        break;
                    case 2:
                        Input(T);
                        break;
                    case 3:
                        int n;
                        Input_array(a, T);
                        break;
                    case 4:
                        Input_A(T, a);
                        break;
                    case 5:
                        int b;
                        Input_auto(T, b);
                        break;
                    case 6:
                        cout << Count_Node(T.root);
                        break;
                    case 7:
                       {
                        int dem =0;
                        cout <<"So node la: ";
                        cout<< Count_leaf(T.root, dem);
                        break;
                       }

                    case 8:
                        cout <<"So luong node chan la: ";
                        cout << Count_even(T.root);

                        break;
                    case 9:
                        cout<<"So luong node le la: ";
                        cout << Count_odd(T.root);
                        break;
                    case 10:
                        Compare(Count_even(T.root), Count_odd(T.root));
                        break;
                    case 11:
                        {
                            int m;
                            cout <<" Nhap m: ";
                            cin>> m;
                            Node* q = CreateNode(m);
                            Count_rest(T, m);
                            break;
                        }
                    case 12:
                        int x;
                        Count_more(x, T.root);
                        break;

                    case 13:
                        int X, Y;
                        cout << "Nhap gia tri x va y: ";
                        cin >> X >> Y;
                        cout << Count_XY(X, Y, T.root);
                        break;
                    case 14:
                        int k;
                        cout <<"Nhap gia tri k: ";
                        cin >> k;
                        cout << Count_K(k, T.root) << endl;
                    case 15:
                        int m;
                        cout << "Nhap gia can tim: ";
                        cin >> m;
                        cout << Find_X(T.root, m);
                        break;
                    case 16:
                        {
                            int Max =T.root->data;
                            cout << "\nGia tri lon nha la: ";
                            cout << Find_MAX(T.root,Max);
                            break;
                        }
                    case 17:
                        {
                            cout <<"Gia tri min la: ";
                            int Min = T.root->data;
                            cout << Find_MIN(T.root, Min);
                            break;
                        }
                    case 18:
                        {
                            int h;
                            cout <<"Nhap gia tri can xoa: ";
                            cin>> h;
                            Delete_X(T.root, h);
                            PrintNode(T.root);
                            break;
                        }
                    case 19:
                        Delete_all(T.root);
                        break;
                    case 20:
                        Delete_first(T.root,T);
                        break;
                    case 21:
                        {
                            int s = 0;
                            cout <<"\nTong cac node: ";
                            cout << Total_node(T.root, s) << endl;
                            break;
                        }
                    case 22:
                        {
                            int S;
                            cout <<"\nTong gia tri chan la: ";
                            cout << Sum_even(T.root, S) << endl;
                            break;
                        }
                    case 23:
                        int sum;
                        cout <<"\nTong gia tri le la: ";
                        cout << Sum_odd(T.root, sum) << endl;
                        break;
                    break;
                }

            }
        }
    }


    return 0;
}

