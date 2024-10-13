#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAXN 50
#define M 7

using namespace std;

struct Node
{
    int data;
    Node* pNext;

};
struct List
{
    Node* pHead;
    Node* pTail;
};

Node* CreateNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void CreateList(List& L)
{
    L.pHead = L.pTail = NULL;
}

void Printlist(List L)
{
    for (Node* i = L.pHead; i != NULL; i = i->pNext)
    {
        cout << i->data << " ";
    }
    cout << endl;
}

void addTail(Node* p, List& L)
{
    if (L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
    Printlist(L);
}
struct Hashtable
{
    List bucket[M];
};


// cau 1 ham bam theo phuong phap chia

int Hashfunc(int data)
{
    return data % M;
}


void Insert_Bucket(Hashtable& h, int data)
{
    int b = Hashfunc(data);
    // để tránh tình trạng data là số âm dẫn đến bucket bị âm, ta sẽ lấy trị tuyệt đối
    // của bucket tìm được
    b = abs(b);
    Node* p = CreateNode(data);
    addTail(p, h.bucket[b]);
}

void Init_hashtable(Hashtable& h)
{
    for (int i = 0; i < M; i++)
    {
        CreateList(h.bucket[i]);
    }
}


// Cau 2 khoi tao gia tri cho bang bam theo phong phap tu dong

void Inputauto(Hashtable& h)
{
    int a;
    int n;
    n = 45 + rand() % 20;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 988 - rand() % 856;
        Insert_Bucket(h, a);
    }

}

//cau 3 khoi tao gia tri ham bam tu mang 1 chieu

void Array(int& n, int a[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Input_array(Hashtable& h, int a[])
{
    for (int i = 0; i < M; i++)
    {
        Insert_Bucket(h, a[i]);
    }
}

// in bang
void PrintHash(Hashtable& h)
{

    for (int i = 0; i < M; i++)
    {
        cout << "\nbucket " << i << " is: " << endl;
        Printlist(h.bucket[i]);
    }
}
//cau 4 nhap gia tri cho bang bam theo phuong phap thu cong
void Input(Hashtable& h)
{
    char n;
    int x;
    do
    {
        cout << "Nhap gia tri: ";
        cin >> x;

        Node* p = CreateNode(x);
        Insert_Bucket(h, x);
        cout << p << endl;;
        cout << "Nhap 'e' de ngung tao gia tri, nhap 'c' de tiep tuc\n";
        cin >> n;
    } while (n != 'e');
}

// cau 5 Kiem tra ham bam rong hay khong
bool Test_bucket(List bucket)
{
    if (bucket.pHead == bucket.pTail && bucket.pHead == NULL)
        return true;
    return false;
}

bool Test_hashtable(Hashtable& h)
{
    for (int i = 0; i < M; i++)
    {
        if (Test_bucket(h.bucket[i]) == true)
            return true;
    }
    return false;
}
// cau 6 ham dem gia tri luu tru trong bang

int Count_value(Hashtable& h)
{
    int Count = 0;
    for (int i = 0; i < M; i++)
    {
        int d = 0;
        if (Test_bucket(h.bucket[i]) == true)
            return NULL;
        else
        {
            List L = h.bucket[i];
            for (Node* p = L.pHead; p != NULL; p = p->pNext)
            {
                d++;
            }
        }
        Count = Count + d;
    }
    return Count;
}

// cau 7 tim gia tri X trong bang bam

int Search_X(int x, Hashtable& h)
{
    int a = Hashfunc(x);

    List L = h.bucket[a];

    for (Node* p = L.pHead; p != NULL; p = p->pNext)
    {
        if (p->data = x)
            return true;
    }
    return false;
}

//cau 8 Tim gia tri max min trong bang bam
void min_max(Hashtable& h, int& Max, int& Min)
{
    for (int i = 0; i < M; i++)
    {
        // tìm min max của từng bucket
        int tmp_min = 99999;
        int tmp_max = -99999;
        for (Node* p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if (p->data > Max)
                tmp_max = p->data;
            if (p->data < Min)
                tmp_min = p->data;
        }

        // so sánh min max của từng bucket với của toàn bộ hash table
        if (tmp_min < Min)
        {
            Min = tmp_min;

        }
        if (tmp_max > Max)
        {
            Max = tmp_max;

        }
    }
     cout <<"Gia tri MIN: "<< Min << endl;
     cout <<"Gia tri MAX: " << Max << endl;
}

//cau 9 Dem gia tri chan va le trong bang bam, sau do so sanh so luong

int Count_even(Hashtable& h)
{
    int dem = 0;
    for (int i = 0; i < M; i++)
    {
        List L = h.bucket[i];
        for (Node* p = L.pHead; p != NULL; p = p->pNext)
        {
            if (p->data % 2 == 0)
                dem++;
        }
        return dem;
    }
}

int Count_odd(Hashtable& h)
{
    int dem = 0;
    for (int i = 0; i < M; i++)
    {
        List L = h.bucket[i];
        for (Node* p = L.pHead; p != NULL; p = p->pNext)
        {
            if (p->data % 2 != 0)
                dem++;
        }
        return dem;
    }
}

void Compare(int even, int odd)
{
    if (even > odd)
        cout << "true";
    if (even = odd)
        cout << "1";
    if (even > odd)
        cout << "false";
}

int main()
{
    Hashtable h;
    Init_hashtable(h);
    int a[MAXN];

    int chon = 1;
    {
        while(chon != 0)
        {
            cout << "---------------------------------------------MENU------------------------------------------------\n"
                "|1. Viet bang bam theo phuong phap chia                                                         |\n"
                "|2. Ham khoi tao gia tri tu dong cho bang bam theo khoang so luong va gia tri cho truoc         |\n"
                "|3. Ham khoi tao gia tri bang bang tu mang 1 chieu                                              |\n"
                "|4. Ham nhap gia tri theo kieu thu cong cho bang bam                                            |\n"
                "|5. Ham kiem tra bang bam co rong hay khong                                                     |\n"
                "|6. Ham dem cac gia tri duoc luu tru trong bam                                                  |\n"
                "|7. Ham tim gia tri X trong bang bam                                                            |\n"
                "|8. Ham tim min max trong bang bam                                                              |\n"
                "|9. Ham dem gia tri chan va le trong bang bam, so sanh so luong                                 |\n"
                "---------------------------------------------END------------------------------------------------|\n";
            cout << "Moi ban chon: ";
            cin >> chon;

            switch (chon)
            {
            case 1:
                cout << "Da lam trong bai!\n";
                break;

            case 2:
                Inputauto(h);
                PrintHash(h);
                break;
            case 3:
                int n;
                Array(n, a);
                Input_array(h, a);
                PrintHash(h);
                break;

            case 4:
            {
                Input(h);
                PrintHash(h);
                break;
            }
            case 5:
            {
                cout << "Neu mang rong tra ve 1, nguoc lai tra ve 0: \n";
                cout << Test_hashtable(h)<< endl;
                break;
            }
            case 6:
            {
                Inputauto(h);
                PrintHash(h);
                cout << "Gia tri luu trong bang: \n";
                cout << Count_value(h) << endl;
                break;
            }
            case 7:
            {
                int x;
                cout << "Nhap x: ";
                cin >> x;
                cout << "Neu khong tim thay tra ve 0, nguoc lai tra ve 1: ";
                cout << '\n' << Search_X(x, h) << endl;
                break;
            }
            case 8:
            {
                int Min = 99999;
                int Max = -99999;
                Inputauto(h);
                min_max(h, Max, Min);
                cout << endl;
                break;
            }
            case 9:
            {
                cout << "So luong gia tri chan trong bang la: " << Count_even(h) << endl;

                cout << "So luong gia tri le trong bang la: " << Count_odd(h) << endl;

                cout << "So sanh hai so luong:";
                Compare(Count_even(h), Count_odd(h));
                break;
            }
            default:
                break;
            }
        }

    return 0;
}
}
