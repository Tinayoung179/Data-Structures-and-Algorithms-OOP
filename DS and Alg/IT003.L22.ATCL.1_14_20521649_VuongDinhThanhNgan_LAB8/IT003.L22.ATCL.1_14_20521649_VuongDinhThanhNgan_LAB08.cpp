#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAXN 50
#define M 7
//Ho va ten: Vuong Dinh Thanh Ngan
// MSSV: 20521649
// ATCL Lop.1

using namespace std;

//buoc 1 tao cau truc NODE
struct NODE
{
    int Data;
    NODE* pNEXT;
};
// buoc 2 tao ds lien ket don
struct LIST
{
    NODE* head;
    NODE* tail;
};
// buoc 3 khoi tao NODE tu mot gia tri
NODE* createNODE(int x)
{
    NODE* p;
    p = new NODE;
    if (p == NULL)
        return NULL;
    p->Data = x;
    p->pNEXT = NULL;
    return p;
}
//buoc 4 khoi tao danh sach l
void createLIST(LIST& L)
{
    L.head = NULL;
    L.tail = NULL;
}
void indanhsach(LIST& L)
{
    for (NODE* i = L.head; i != NULL; i = i->pNEXT)
    {
        cout << i->Data << "\t";
    }
    cout << endl;

}
void addTail(NODE* p, LIST& L)
{
    if (L.head == NULL)
        L.head = L.tail = p;
    else
    {
        L.tail->pNEXT = p;
        L.tail = p;
    }
    indanhsach(L);
}

// tao cau truc bang bam
struct HASHTABLE
{
    LIST bucket[M];
};
//cau 1 bang bam theo phuong phap chia
int Hashfunc(int data)
{
    return data % M;
}

// khoi dong bang bam
void InitBuckets(HASHTABLE& h)
{
    for (int i = 0; i < M; i++)
    {
        createLIST(h.bucket[i]);
    }
}

void Insert(HASHTABLE& h, int data)
{
    int b = Hashfunc(data);

    b = abs(b);
    NODE* p = createNODE(data);
    addTail(p, h.bucket[b]);
}
// cau 1 hàm tao du lieu tu dong cho bang bam trong khoang theo de
// Tao tu dong ra tung gia tri sau do xep cac gia tri moi vao bang bam
void Nhapauto(HASHTABLE& h)
{
    int b;
    int n;
    n = 45 + rand() % 51;
    for (int i = 0; i < n; i++)
    {
        b = rand() % 988 - rand() % 856;
        Insert(h, b);
    }
}
void Mang(int &n, int a[])
{
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap gia tri: ";
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
    }
}

// cau 2 ham tao du lieu cho bang bam tu bang 1 chieu

void NhapMang(HASHTABLE& h, int n,int a[])
{

    for (int i = 0; i < n; i++)
    {
        Insert(h, a[i]);
    }
}


// cau 3 ham tao du lieu thu cong nhap tu ban phim

void Nhapthucong(HASHTABLE& h)
{
    int a;
    char n;

    do
    {
        cout << "Nhap a: ";
        cin >> a;

        NODE* p = createNODE(a);
        Insert(h, a);
        cout <<'\n' << p << endl;

        cout << "Nhap 'e' de thoat \n Nhap 'c' de tiep tuc \n";
        cin >> n;
    } while (n != 'e');
}

// Cau 4 ham in bang bam
void inBang(HASHTABLE& H)
{

    for (int i = 0; i < M; i++)
    {
        cout << "\nbucket " << i << " is: " << endl;
        indanhsach(H.bucket[i]);
    }
}


// Cau 5 ham xoa gia tri trong bang bam

int Xoagiatri(HASHTABLE& h, int k)
{
    NODE* p;
    int b = Hashfunc(k);
    LIST L = h.bucket[b];
    if (L.head == L.tail && L.head == NULL)
        return 0;
    if (L.head->Data == L.tail->Data && L.head->Data == k)
    {
        NODE* p = L.head = L.tail;
        L.head = L.tail = NULL;
        delete p;
    }
    if (p->Data == k && p->pNEXT == L.tail)
    {
        NODE* q = p->pNEXT;
        p->pNEXT = p->pNEXT->pNEXT;
        L.tail = p;
        delete p;
    }

    if (p->Data == k && p == L.head)
    {
        NODE* q = L.head;
        L.head = p->pNEXT;
        delete p;
    }
    if (p != NULL)
    {
        for (p = L.head; p != NULL; p = p->pNEXT)
        {
            if (p->Data == k)
            {
                NODE* q;
                p->pNEXT = q;
                q->Data = k;
                p->pNEXT = q->pNEXT;
                delete q;
            }
        }
    }
}


// cau 6 tim mot gia tri trong bang bam

NODE* Timkiem(HASHTABLE& h, int k)
{
    int b = Hashfunc(k);
    LIST L = h.bucket[b];

    for (NODE* p = L.head; p != NULL; p = p->pNEXT)
    {
        if (k = p->Data)
            return p;
    }
    return 0;

}

// cau 7 tinh tong cac gia tri le trong bang bam
int Tinhtong(HASHTABLE& h, int s)
{
    s = 0;
    for (int i = 0; i < M; i++)
    {
        LIST L = h.bucket[i];
        for (NODE* p = L.head; p != NULL; p = p->pNEXT)
        {
            if (p->Data % 2 != 0)
                s = s + p->Data;
        }
        return s;
    }
}

// cau 8 ham kiem tra bang co rong hay khong
// kiem tra danh sach rong
bool kiemtrabucket(LIST bucket)
{
    if (bucket.head == bucket.tail && bucket.head == NULL)
        return true;
    return false;
}
// kiem tra bang rong
bool kiemtrabang(HASHTABLE& h)
{
    for (int i = 0; i < M; i++)
    {
        if (kiemtrabucket(h.bucket[i]) == true)
            return true;
    }
    return false;
}

// cau 9 ham lam theo mot dieu kiem ( lay vi du la ham dem)
int Dem(HASHTABLE& h)
{
    int dem = 0;
    for (int i = 0; i < M; i++)
    {
        NODE* p = h.bucket[i].head;
        while (p != NULL)
        {
            dem++;
            p = p->pNEXT;
        }
    }
    return dem;
}

int main()
{
    HASHTABLE h;
    InitBuckets(h);
    int arr[MAXN];

    int chon ;
    while(chon != 0)
    {
        cout <<"\n====================================MENU======================================\n";
        cout << "=1.Ham tao du lieu tu dong cho bang bam                                      =\n";
        cout << "=2.Ham tao du lieu cho bang bam bang mang mot chieu                          =\n";
        cout << "=3.Ham tao du lieu cho bang bam bang cach nhap thu cong                      =\n";
        cout << "=4.Ham in bang bam                                                           =\n";
        cout << "=5.Ham xoa gia tri trong bang bam                                            =\n";
        cout << "=6.Ham tim mot gia tri trong bang bam                                        =\n";
        cout << "=7.Ham tinh tong cac gia tri le tron bang bam                                =\n";
        cout << "=8.Ham kiem tra bang bam rong                                                =\n";
        cout << "=9.Ham xu ly theo dieu kien( ham dem)                                        =\n";
        cout << "=0.Exit                                                                      =\n";
        cout << "====================================END=======================================\n";
        cout << "MOI BAN CHON SO: ";
        cin >> chon;

        switch (chon)
        {
        case 0:
            cout <<"Thoat ra";
            break;
        case 1:

            Nhapauto(h);
            inBang(h);
            break;
        case 2:
            int n;
            Mang(n, arr);
            NhapMang(h,n, arr);
            inBang(h);
            break;
        case 3:
            Nhapthucong(h);
            inBang(h);
            break;
        case 4:
            char nhap;
            cout << "=================MENU CAU 4================\n"
                    "a.Nhap gia tri bang thu cong               \n"
                    "b.Nhap gia tri bang theo mot mang mot chieu\n"
                    "c.Nhap gia tri bang tu dong                \n"
                    "===========================================\n";
            cout << "Moi ban chon cach nhap gia tri: ";
            cin >> nhap;
            switch (nhap)
            {
                case 'a':
                    Nhapthucong(h);
                    inBang(h);
                    break;

                case 'b':
                    int n;
                    Mang(n, arr);
                    NhapMang(h, n , arr);
                    inBang(h);
                    break;
                case 'c':
                    Nhapauto(h);
                    inBang(h);
                    break;
            }
                default:
                    break;

        case 5:
            char choose;
            cout << "=================MENU CAU 4================\n"
                    "a.Nhap gia tri bang thu cong               \n"
                    "b.Nhap gia tri bang theo mot mang mot chieu\n"
                    "c.Nhap gia tri bang tu dong                \n"
                    "===========================================\n";
            cout << "Moi ban chon cach nhap gia tri: ";
            cin >> choose;
            switch (choose)
            {
                case 'a':
                    Nhapthucong(h);
                    int k;
                    cout << "Nhap gia tri k: ";
                    cin >> k;
                    cout<<"\nDa xoa";
                    Xoagiatri(h, k);

                    break;
                case 'b':
                    int n;
                    Mang(n, arr);
                    NhapMang(h, n , arr);

                    int m;
                    cout << "Nhap gia tri m: ";
                    cin >> m;
                    Xoagiatri(h, m);
                    cout<<"\nDa xoa";
                    break;
                case 'c':
                    cout << "Nhap gia tri f: ";
                    int f;

                    cin >> f;
                    cout <<"Hien 0 la khong tim thay gia tri\n";
                    cout << Xoagiatri(h, f)<< endl;

                    break;

            }
                    break;

        case 6:
            cout <<"Nhap mang: ";

            Mang(n, arr);


            NhapMang(h, n,arr);

            int k;
            cout<<"Nhap k: ";
            cin>> k;

            cout << Timkiem(h, k);

            break;
        case 7:
            cout << "Tong la: ";
            int s;

            cout << Tinhtong(h, s);
            break;
        case 8:
            cout<<"Mang tra ve 1 la rong, khong rong tra ve 0:\n";
            cout <<"Khiem tra mang: ";
            cout << kiemtrabang(h);
            break;
        case 9:
            {
                cout<<"\nSo luong: ";
                cout << Dem(h);
                break;
            }


            break;
    }
    }

    return 0;
}
