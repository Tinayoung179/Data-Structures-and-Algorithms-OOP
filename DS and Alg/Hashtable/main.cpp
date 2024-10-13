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

//Ham tao thu cong bang
void Input(Hashtable& H)
{
    char n;
    int x;
    do
    {
        cout << "Nhap gia tri: ";
        cin >> x;

        Node* p = CreateNode(x);
        Insert_node(H, x);
        cout << p << endl;
        cout << "Nhap 'e' de ngung tao gia tri, nhap 'c' de tiep tuc\n";
        cin >> n;
    } while (n != 'e');
}

//Ham tao bang tu mang
void Array(int n, int a[])
{
    cout <<"Nhap so luong: ";
    cin >> n;

    cout <<"Nhap gia tri: ";
    for( int i = 0; i < n; i++)
    {
         cin >> a[i];
    }
}

void Input_array(Hashtable& H, int a[])
{
    for(int i = 0; i < M; i++)
    {
        Insert_node(H, a[i]);
    }
}

// Dem node co gia tri x
void Count_X(Hashtable& H, int x, int& dem)
{
    dem = 0;
    cout<< "Nhap x: ";
    cin>>x;
    cout <<"\nSo luong la: ";
    int c = Hash_funtion(x);
    for(Node*p = H.bucket[c].pHead; p != NULL; p = p->pNext)
    {
        if(p->data == x)
            dem++;
    }
    cout<< dem;
}
//Dem node co gia tri nho hon y lon hon x
void Count_XY(int x, int y, int& d, Hashtable& H)
{
    cout <<"Nhap x, y: ";
    cin>> x>> y;
    cout <<"\nSo luong la: ";
    d = 0;
    for(int i = 0; i < M; i++)
    {
        int dem = 0;
        for(Node*p = H.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if(p->data > x && p->data < y )
                dem++;
        }
        d = d + dem;
    }
    cout << d;
}

//Dem node chan
void Count_even(Hashtable& H, int& Dem)
{
    Dem = 0;
    cout <<"\nSo luong chan la: ";
    for(int i = 0; i < M; i++)
    {
        int dem = 0;
        for(Node*p = H.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if(p->data % 2 == 0 )
                dem++;
        }
        Dem = Dem + dem;
    }
    cout << Dem;
}

//Dem node le
void Count_odd(Hashtable& H, int& Count)
{
    Count = 0;
    cout <<"\nSo luong le la: ";
    for(int i = 0; i < M; i++)
    {
        int dem = 0;
        for(Node*p = H.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if(p->data % 2 != 0 )
                dem++;
        }
        Count = Count + dem;
    }
    cout << Count;
}

// Dem tong so luong node
void Count_all(Hashtable& H, int& D)
{
    D = 0;
    cout<<"\nTong so luong la: ";
    for(int i = 0; i < M; i ++)
    {
        int dem = 0;
        for(Node* p = H.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            dem++;
        }
        D = D + dem;
    }
    cout << D;
}


//Tim mot gia X

int Find_X(Hashtable& H, int X)
{
    cout <<"Nhap gia tri can tim: ";
    cin>>X;
    Node* p;
    int b = Hash_funtion(X);
    for( p= H.bucket[b].pHead; p != NULL; p = p->pNext)
    {
        if(p->data == X)
            return true;
         return false;

    }

}
//Tim max min

void Max_min(int& Max, int& Min, Hashtable& H)
{
    for(int i = 0; i < M; i++)
    {
        for(Node* p = H.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if(p->data < Min)
            {
                Min = p->data;

            }
        }

    }
    cout<<"\nMin la: "<< Min << endl;

    for(int i = 0; i < M; i++)
    {
        for(Node* p = H.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if(p->data > Max)
            {
                Max = p->data;

            }
        }

    }
    cout <<"Max la: "<< Max<< endl;

}

//Xoa mot gia tri X
int Delete_X(Hashtable& H, int k)
{
	Node* p;

	for (int i = 0; i < M; i++)
	{
		for (Node* j = H.bucket[i].pHead; j != NULL; j = j->pNext)
		{
			if (j->data == k)
			{
				//1 Node trong bucket
				if (j == H.bucket[i].pHead && j->pNext == NULL)
				{
					p = j;
					delete p;
					H.bucket[i].pHead = NULL;
					H.bucket[i].pTail = NULL;
					break;
				}
				else if (j == H.bucket[i].pHead && j->pNext != NULL)
				{
					p = j;
					H.bucket[i].pHead = j->pNext;
					delete p;
					break;
				}
			}
			if (j->pNext!=NULL)
			{
				if (j->pNext->data == k)
				{
					if (j->pNext == H.bucket[i].pTail)
					{
						p = j->pNext;
						H.bucket[i].pTail = j;
						j->pNext = NULL;
						delete p;
						break;
					}
					else
					{
						p = j->pNext;
						j->pNext = j->pNext->pNext;
						delete p;
						break;
					}
				}
			}

		}
	}

}

//Ham xoa toan bo bang
Node* Delete_All(Hashtable& H)
{
    for(int i = 0; i < M; i++)
    {
        List L = H.bucket[i];
       for(Node* p = L.pHead; p != NULL; p = p->pNext)
       {
           Node* Temp = p;
            delete Temp;
       }
    }
}


//Ham bang rong hay khong
bool Test_list(List Bucket)
{
    if(Bucket.pHead == NULL && Bucket.pHead == Bucket.pTail)
        return true;
    return false;
}

bool Test_hash(Hashtable& H)
{
    for(int i = 0; i < M; i++)
    {
        if(Test_list(H.bucket[i]) == true)
            return false;

    }

    return true;
}


// Tinh tong chan
int Sum_even(Hashtable& H, int& s)
{
    for(int i = 0; i < M; i++)
    {
        int d;
        for(Node* p = H.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if (p->data % 2 == 0)
            {
                d = p->data;
            }
        }
        s = s + d;

    }
}

//Tinh tong tat ca
int Sum_all(Hashtable& H, int& S)
{
    for(int i = 0; i < M; i++)
    {
        int d;
        for(Node* p = H.bucket[i].pHead; p != NULL; p = p->pNext)
        {
                d = p->data;
        }
        S = S + d;

    }
}
int main()
{
    Hashtable H;
    Init_Hash(H);
    int chon;
    while(chon)
    {
        int chon;
    cout<<"==========================================menu==============================\n"
        "1.Tao bang tu dong \n"
        "2.Tao bang thu cong \n"
        "3.Tao bang tu mang \n"
        "4.Dem node cac gia tri x \n"
        "5.Dem node co gia tri lon hon x nho hon y \n"
        "6.Dem node chan \n"
        "7.Dem node le \n"
        "8.Dem tong node \n"
        "9.Tim X \n"
        "10.Tim Max Min \n"
        "11.Xoa node bat ky \n"
        "12.Xoa toan bo node \n"
        "13.Kiem tra rong \n"
        "14.Tong chan \n"
        "15.Tong all \n"
        "=============================================================================\n";

        cout<<"moi chon: ";
        cin >> chon;
        if(chon == 0)
        {
            break;
        }
        else
        {
            switch(chon)
            {
                case 1:
                    Input_auto(H);
                    Print_Hash(H);
                    break;
                case 2:
                    Input(H);
                    Print_Hash(H);
                    break;
                case 3:
                    int a[MAXN];
                    int n;
                    Array(n, a);
                    Input_array(H, a);
                    Print_Hash(H);
                    break;
                case 4:
                    {
                        int x;
                        int dem =0;
                        Count_X(H, x, dem);
                        break;
                    }
                case 5:
                    {
                        int d =0;
                        int x, y;
                        Count_XY(x, y, d, H);
                        break;
                    }
                case 6:
                    {
                        int Dem = 0;
                        Count_even( H,  Dem);
                        break;
                    }
                case 7:
                    {
                        int Count = 0;
                        Count_odd(H,Count);
                        break;
                    }
                case 8:
                    {
                        int D = 0;
                        Count_all(H, D);
                        break;
                    }
                case 9:
                    {
                        int X;
                        cout << Find_X(H, X);
                        break;
                    }
                case 10:
                    {
                        int Max = -9999;
                        int Min = 9999;
                        Max_min(Max, Min, H);
                        break;
                    }
                case 11:
                    {
                        int k;
                        cin >> k;
                        cout << Delete_X(H, k);
                        cout <<"kkkkkkkkk";
                    }
                    break;
               /* case 13:
                    cout <<"\nMang rong tra ve 1 , nguoc lai 0 : " << Test_hash(H);
                    break;
                */
                case 14:
                     {
                         int s =0;
                        cout <<"\nTong chan: ";
                        cout << Sum_even(H, s);
                        break;
                     }
                case 15:
                    {
                        int S;
                        cout <<"\nTong: ";
                        cout << Sum_all(H, S);
                        break;
                    }

                break;
            }
        }

    }

    return 0;
}
