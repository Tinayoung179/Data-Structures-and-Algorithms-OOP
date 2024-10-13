#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#define MAXN 100


using namespace std;
// Tao cau truc node cho cay
struct Node
{
    float data; // gia tri
    Node* pLeft; // cho ve trai
    Node* pRight;// cho ve phai
};

//khoi tao node cho chay
Node* CreateNode(int x)
{
    Node * p= new Node;
    if (p== NULL)// node rong
        return NULL;
    p->data = x;// gan gia tri p->data = x
    p->pLeft = NULL;
    p->pRight = NULL;
    return p; // tra ve node moi
}

// tao cau truc cay
struct Tree
{
    Node* root;
};
// khoi tao cay
void CreateTree(Tree& T)
{
    T.root = NULL; //tao node root
}
//ham in node cua cay
//input
//+Node* p
//output
//cac gia tri lan luot cua cay
void PrintNode(Node* p)
{
    if (p == NULL)
        return;
    if (p->pLeft != NULL)
    {
        cout << "Node trai: " << p->pLeft << endl;// chen nhanh trai
    }
    else
    {
        cout <<"\nnhanh trai rong \n";//nhanh trai rong
    }
    if (p->pRight != NULL)
    {
        cout << "Node phai: " << p->pRight << endl;//chen nhanh phai
    }
    else
    {
        cout <<"\nnhanh phai rong \n";//nhanh phai rong
    }
}
// ham in cay nhi phan
void PrintTree(Tree& T)
{
    cout << T.root << endl;
}

//Cau 1: HAM CHEN NODE CO GIA TRI
/*
input:
+Cay nhi phan ban dau
+Node can chen
output:
node da chen vao vi tri
*/
void addNode(Tree& T, Node* p)
{
	cout << p->data;
	if (T.root == NULL)
    {

		T.root = p;// cay rong chen vao node roo cua cay
		cout << "\n +Chen vao root: " << T.root << '\n';
	}

    Node*i = T.root;
	while (i != NULL)
	{
		if (p->data < i->data)
		{
			if (i->pLeft == NULL)// chen trai cay
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
			if (i->pRight == NULL)// chen ve phia phai cua cay
			{
				i->pRight = p;
				cout << "\n +Chen phai node: " << i << '\n';
				break;
			}
			else
				i = i->pRight;
		}
		else if (p->data == i->data) // gia tri chen da ton tai
        {
			cout << "\nDa ton tai gia tri vua nhap tren cay!\tNhap lai!\n";
			return;
		}

	}
};

// Cau 2: Ham nhap tu dong gia tri cho cay
/*
input
+ tu don tao gia tri va so luong phan tu
output
+hien thi ra danh sach node duoc nhap vao cay
*/
void Input_auto(Tree& T, float b)
{
    int n;
    cout << "Tao tu dong so luong gia tri la: ";
    n = 12 + rand() % 18;// so luong phan tu tao tu don
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        b = -59 + rand()% 155; // gia tri tao tu dong
        Node* p = CreateNode((b)); // khoi tao node moi
        addNode(T, p); // them node vao vi tri duoi
    }
}

// tao mang gon n phan tu
void Array(int n, float a[])
{
    cin >> n;
    for( int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

//Cau 3: ham nhap cay tu mang mot chieu
/*input:
+ Cay rong
+ Truyen mang gia tri
+ Truyen so luong phan tu
Output
+Xuat ra cay nhi pha

*/
void Input_A(Tree& T, float a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        Node*p = CreateNode(abs(a[i]));// Khoi tao node moi
        addNode(T, p);
    }

}

//Cau 4: Duyet cau theo 3 kieu

/*Input
+ Truyen vao du Node
Output
+ Cay da duoc duyet theo cac kieu
*/
//Duyet NLR
void NLR(Node* p)
{
    if(p != NULL)
    {
        cout << p->data <<'\n' << "pleft: " << p->pLeft <<'\t' <<"pright: " << p->pRight;// duyet tu Node root

        NLR(p->pLeft);//Duyet trai

        NLR(p->pRight);//Duyet phai

    }
}
//Duyet LNR
void LNR(Node* p)
{
    if(p != NULL)
    {
        LNR(p->pLeft); // Duyet qua trai

        cout << p->data <<'\n' << "pleft: " << p->pLeft <<'\t' <<"pright: " << p->pRight;

        LNR(p->pRight);// Duyet qua phai
    }
}

//Duyet LRN


void LRN(Node* p)
{
    if(p != NULL)
    {
        LNR(p->pLeft);//Duyet qua tra

        LNR(p->pRight);//Duyet qua phai

        cout << p->data <<'\n' << "pleft: " << p->pLeft <<'\t' <<"pright: " << p->pRight;
    }
}
/*
//Cau 5: Ham tim kiem gia tri X do nguoi dung nhap
// input: Cây t mà ta cần tìm kiếm, x là giá trị cần tìm kiếm trên cây
// output: tra ve co xuat hien hoac khong
int SearchNode(Tree &t, int x)
{

	if (t.root == NULL)
		return NULL;

	Node* p = t.root;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return -1;
		}
		else if (p->data > x)
		{
			p = p->pLeft;
		}
		else
		{
			p = p->pRight;
		}
	}
	return 0;
}

//Cau 7:
//Dem cac node nhanh con lai tu 1 node nhap vao
//Input
//+Truyen cay vao
//+Truyên gia tri can tim
//output:
//+ so luong node
void Count_rest(Tree& T, float x)
{
	Node* p = T.root;
     if (p==NULL)
		 return;

	while (p != NULL)
	{
		if (x < p->data)
			p = p->pLeft;// Tim sang trai
		else if (x > p->data)
			p = p->pRight;//Tim sang phai
		else{
			LRN(p);//Duyet theo LRN
			break;
		}
	}
}

//cau 9:Dem chan le
//Input
//+Truyen vao node dau
//output:
//+so luong node

// Dem node chan
int Count_even(Node* p)
{
    if( p == NULL)
        return 0;
    else
    {
        int x = Count_even(p->pLeft);//dem ve phai
        int y = Count_even(p->pRight);//dem ve trai
        if( int (p->data) % 2 == 0)
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
	int x = Count_odd(p->pLeft);//dem ve phai
	int y = Count_odd(p->pRight);//dem va trai
	if (int (p->data) % 2 != 0)
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



*/

int main()
{
    Node* p;
    Tree T;
    CreateTree(T);
    srand(time(0));

    int chon;
    while(chon != 0)
    {
        cout <<"============================================MENU=========================================\n"
             <<"=0.Exit                                                                                 =\n"
             <<"=1.Ham chen Node chua gia tri                                                           =\n"
             <<"=2.Ham tao cay tu don voi so luong phan tu va gia tri phan tu nam trong khoang cho truoc=\n"
             <<"=3.Ham tao cay tu dong tu mang 1 chieu                                                  =\n"
             <<"=4.Ham duyet cay theo 3 kieu NLR, LRN, LNR                                              =\n"
             <<"=5.Ham tim kiem gia tri X do nguoi dung nhap                                            =\n"
             <<"=6.Ham dem cac Node khong phai node la                                                  =\n"
             <<"=7.Ham xuat ra ca nhanh con lai tu mot Node nhap vao                                    =\n"
             <<"=8.Ham sao chep cac gia tri trong cay thanh cay moi                                     =\n"
             <<"=9.Viet ham dem cac Node chan le                                                        =\n"
             <<"============================================END==========================================\n";
             cout <<"Moi chon so: ";
             cin >> chon;
             {
                 if(chon == 0)
                 {
                     cout <<"\nThoat chuong trinh";
                     break;
                 }
                 else
                 {
                     switch(chon)
                     {
                         case 1:
                            {
                                addNode(T,p);
                                break;
                            }
                         case 2:
                            {
                                float b;
                                Input_auto(T, b);
                                PrintNode(T.root);
                                break;
                            }
                         case 3:
                            {
                                float a[]={-50.1, 75.2, -25.3, 30.4, -10.5, 90.5, -70.1, 60.2, 30.4,-70.7, 90.5};
                                Input_A(T, a, 11);
                                PrintNode(T.root);
                            }
                        case 4:
                            {
                                break;
                            }
                            break;
                     }
                    }
             }


    }
}


