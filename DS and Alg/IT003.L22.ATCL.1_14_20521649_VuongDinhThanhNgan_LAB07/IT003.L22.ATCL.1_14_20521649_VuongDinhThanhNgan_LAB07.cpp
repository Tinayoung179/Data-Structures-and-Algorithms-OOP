#include <iostream>
#include<stdlib.h>
#include<time.h>

// MSSV 20521649

// STT 14

// VUONG DINH THANH NGAN

//ATCL LOP .1
using namespace std;
// cau 1
struct NODE{
    int data;
    NODE* pLeft;
    NODE* pRight;

};
struct tree
{
    NODE * root;
};

NODE* createNode(int x)
{
    NODE * p= new NODE;
    if (p== NULL)
        return NULL;
    p->data = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;

}
void CreateTree(tree &t)
{
    t.root = NULL;
}

void print(NODE *p)
{
	if(p==NULL)
		return;
    if(p->pLeft != NULL)
	{
	    cout<<p->pLeft<<endl;
	}
	else
    {
        cout<<"Left rong"<< endl;
    }
	if(p->pRight != NULL)
    {
        cout<<p->pRight<<endl;
    }
    else
    {
       cout<<"Right rong"<< endl;
    }
}// hàm in danh sách cây

void printT(tree t)
{
	cout<<t.root;
}// in cả cây nhị phân

// cau 2 ham chen them node cho cay
NODE* AddNode(tree &t, NODE *p)
{
    {
    if (t.root == NULL)
    {
        t.root= p;
        cout<<"Chen vao root: "<< t.root<<'\n';
    }
    NODE* i = t.root;
    NODE* f = p;//f la vi tri
    while (p != NULL)
    {
        f = i;
        if (p->data > i->data)
        {
            i = i->pLeft;
        }
        if (p->data== i->data)
        {
            cout<<"Bi trung gia tri";
            return 0;
        }
        else
        {
            i = i->pRight;
        }
    }
    return f;
    if (p->data < f->data)
		{
			cout << "\t\t +Chen trai node: " << f << '\n';
			f->pLeft = p;
		}
		else if (p->data > f->data)
		{
			cout << "\t\t +Chen phai node: " << f << '\n';
			f->pRight = p;
		}
	}
}

// cau 3 nhap gia tri cho cay theo thu cong
void Nhapthucong(tree t)
{
   int a;
	char n;
	do {
		cout << "Nhap a: ";
		cin >> a;
		NODE* p = createNode(a);
		AddNode(t, p);
		cout << "\nNhap 'e' de thoat!\nNhap 'c' de tiep tuc!\n";
		cin >> n;

	} while (n!= 'e');
}
// cau 4 nhap tu dong cho cay
void Nhaptudong(tree t)
{
    int n, a;
	n = 10 + rand() % 11;
	for (int i = 0; i < n; i++)
	{
		a = rand() % 1359-rand()%1359;
		NODE* p = createNode(a);
		cout << a<<'\n';
		AddNode(t, p);
	}
}
//cau 5 duyet cay
void NLR(NODE* p)
{
    if (p!= NULL)
    {
        // Xử lý nút gốc (root)
        NLR(p->pLeft);
        NLR(p->pRight);
    }
}
void LNR(NODE* p)
{
    if (p!=NULL)
    {
        LNR(p->pLeft);
        // Xử lý nút gốc (root)
            cout << p->data << '\t'<<p<<"\tpleft: "<<p->pLeft<<"\t\tpright: "<<p->pRight<<'\n';
        LNR(p->pRight);
    }
}
void LRN(NODE* p)
{
    if (p!=NULL)
    {
        LRN(p->pLeft);
        LRN(p->pRight);

        // Xử lý nút gốc (root)
    }
}
//cau 6 ham tim kiem gia tri X
NODE* timkiem(NODE*p, int x)
{
    if(p== NULL)
    {
        return NULL;
    }
	if (p != NULL)
	{
		if (p->data == x)
        {
            return p;
        }
		if (p->data > x)
        {
            timkiem(p->pLeft, x);
        }
		else
        {
            timkiem(p->pRight, x);
        }
	}
	return 0;
}

//Cau 7 ham xoa mot gia tri X tren cay

void Timnode(NODE*& p, NODE*& q)
{
    if(q->pLeft!= NULL)
    {
        Timnode(p, q);
    }
    else
    {
        p->data = q->data;
        p = q;
        q = q->pRight;
    }
}
int Xoanode(NODE*p, int x)
{
    if(p == NULL )
    {
        return 0;
    }
    if( x < p->data)
    {
        Xoanode(p-> pLeft, x);
    }
    if( x > p->data)
    {
        Xoanode(p->pRight, x);
    }
    else
    {
        NODE* a= p;
        if(p-> pLeft== NULL)
        {
            p = p-> pRight;
        }
        if(p-> pRight==NULL)
        {
            p= p->pLeft;
        }
        else
        {
            Timnode(a, p);
        }
        delete a;
    }
}

// cau 8 xoa tat ca cac node
int Xoacacnode(NODE*p)
{
    if(p== NULL)
        return 0;
    if(p->pLeft)
        Xoacacnode(p->pLeft);
    if(p->pRight)
        Xoacacnode(p->pRight);
    delete p;
    p=NULL;
}

//cau 9 dem cac node
int Demnode(NODE*p)
{
    if(p == NULL)
        return 0;
    int a = Demnode(p->pLeft);
    int b = Demnode(p->pRight);
    return a + b + 1;
}

// cau 10 ham dem node la cua cay
void Demnodela(NODE* p, int& dem)
{
    if (p == NULL)
        return;
    if (p-> pLeft == NULL)
    {
        if(p-> pRight == NULL)
        dem++;
    }
    Demnodela(p->pLeft, dem);

    Demnodela(p->pRight, dem);
}

//cau 11 ham in ra cac node nhanh NLR
void inNodenhanh(NODE* p, NODE* q)
{
    int d = 0;

	if (p != NULL)
	{
		if (p->data > q->data)
            inNodenhanh(p->pLeft, q);
		if (p->data < q->data)
            inNodenhanh(p->pRight, q);
		if (p->data == q->data)
		{
			d = 1;
		}
		if (d != 0)
        {
			NLR(p);
		}
	}

	else cout << "Khong tim thay node!\n";
}
// cau 12 Den node co gia tri nho hon X
int demNodebe(NODE* p, int x)
{
    if ( p== NULL)
        return 0;
    int a= demNodebe(p->pLeft, x);
    int b= demNodebe(p->pRight, x);
    if(x > p->data)
    {
        return a + b +1;
    }
    else
        return a + b;
}

// cau 13 Den node co gia tri be hon X

int demNodelon(NODE* p, int x)
{
    if ( p== NULL)
        return 0;
    int a= demNodebe(p->pLeft, x);
    int b= demNodebe(p->pRight, x);
    if(x < p->data)
    {
        return a + b +1;
    }
    else
    {
        return a + b;
    }
}

// cau 14 dem node có gia tri nho hon X lon hon Y
int demNode(NODE* p, int x, int y)
{
    if (p == NULL) return 0;
	int a = demNode(p->pLeft, x, y);
	int b = demNode(p->pRight, x, y);
	if (p->data > x && p->data < y)
	{
		return a + b + 1;
	}
	else
	{
		return a + b;
	}
}

// cau 15 ham so sanh gia tri cau 11 va 12
void Sosanh(int a, int b)// a la gia cau 11, b la gia tri cau 12
{
    if (a > b) cout << "So luong node co gia tri nho hon X 'lon hon' so luong node co gia tri lon hon X\n";
	if(a < b)  cout << "So luong node co gia tri nho hon X 'be hon' so luong node co gia tri lon hon X\n";
	if (a == b)  cout << "So luong node co gia tri nho hon X 'bang' so luong node co gia tri lon hon X\n";
}
//cau 16 viet ham dem node chan le va so sanh gia tri
int demChan(NODE* p)
{
	if (p == NULL)
        return 0;
	int a = demChan(p->pLeft);
	int b = demChan(p->pRight);
	if (p->data % 2 == 0)
	{
		return a + b + 1;
	}
	else
	{
		return a + b;
	}
}
int demLe(NODE* p)
{
	if (p == NULL) return 0;
	int a = demLe(p->pLeft);
	int b = demLe(p->pRight);
	if (p->data % 2 != 0)
	{
		return a + b + 1;
	}
	else
	{
		return a + b;
	}
}
void sosanhChanle(int chan, int le)
{
	if (chan > le) cout << "So luong node co gia tri chan 'LON HON' so luong node co gia tri le\n";
	if (chan < le)  cout << "So luong node co gia tri chan 'BE HON' so luong node co gia tri le\n";
	if (chan == le)  cout << "So luong node co gia tri chann 'BANG'  so luong node co gia tri le X\n";
}
// cau 17 tinh tong cac node tren cay
int tinhTong(NODE* p)
{
    int s = 0;
	if (p == NULL) return 0;
	int a = tinhTong(p->pLeft);
	int b = tinhTong(p->pRight);
	if (p != NULL)
	{
	 s= p->data;
	 return a + b + s;
	}
	return a+b;
}
// cau 18 tinh tong cai node chan
int tongNodechan(NODE* p)
{
    int s = 0;
	if (p == NULL) return 0;
	int a = tongNodechan(p->pLeft);
	int b = tongNodechan(p->pRight);
	if (p != NULL && p->data %2 == 0)
	{
	 s= p->data;
	 return a + b + s;
	}
	return a+b;
}
// cau 19 hàm tinh tong cac node le
int tongNodele(NODE *p)
{
    int s = 0;
	if (p == NULL) return 0;
	int a = tongNodechan(p->pLeft);
	int b = tongNodechan(p->pRight);
	if (p != NULL && p->data %2 != 0)
	{
	 s= p->data;
	 return a + b + s;
	}
	return a+b;
}
// cau 20 so sanh gia tri cai 18 va 19
void sosanh1819(int chan, int le)
{
    if (chan > le) cout << "Tong node co gia tri chan 'LON HON' tong node co gia tri le\n";
	if (chan < le)  cout << "Tong node co gia tri chan 'BE HON' tong node co gia tri le\n";
	if (chan == le)  cout << "Tong node co gia tri chann 'BANG' tong node co gia tri le X\n";

}
// cau 22 tim node co gia tri lon nha va mho nha
void timMax(NODE* p, int& max)
{
	if (p != NULL)
	{
		if (max < p->data)
		{
			max = p->data;
		}
		timMax(p->pLeft, max);
		timMax(p->pRight, max);
	}
}
void timMin(NODE* p, int& min)
{
	if (p != NULL)
	{
		if (min > p->data)
		{
			min = p->data;
		}
		timMin(p->pLeft, min);
		timMin(p->pRight, min);
	}
}


int main()
{
	int chon = 1;
	char aORb = 'a';
	NODE* p = NULL;
	tree t;
	CreateTree(t);
	srand(time(0));
	int x, i;
	int T;
	int dem=0;

	while (chon!=0) {
		cout << "\n========================== MENU =======================\n"
			<< "= 1.Ham chen node chua gia tri vao cay.                  =\n"
			<< "= 2.Nhap thu cong.                                       =\n"
			<< "= 3.Nhap tu dong.                                        =\n"
			<< "= 4.Ham duyet cay theo NLR, LNR, LRN.                    =\n"
			<< "= 5.Tim X.                                               =\n"
			<< "=     a. X do nguoi dung nhap.                           =\n"
			<< "=     b. X trong khoang[300;800].                        =\n"
			<< "= 6. Ham xoa mot gia tri X.                              =\n"
			<< "= 7. Ham xoa tat ca cac node.                            =\n"
			<< "= 8. Ham dem toan bo so node.                            =\n"
			<< "= 9. Ham dem so node la cua cay.                         =\n"
			<< "= 10. Ham in ra (NLR) tu 1 node nhap tu ban phim.        =\n"
			<< "= 11. Ham dem so node co gia tri nho hon X.              =\n"
			<< "= 12. Ham dem so node co gia tri lon hon X.              =\n"
			<< "= 13. Ham dem so node ma 'X < node < Y'                  =\n"
			<< "= 14. Ham so sanh hai gia tri dem node o #11 va #12.     =\n"
			<< "= 15. Ham dem node chan, le. So sanh hai gia tri dem duoc=\n"
			<< "= 16. Ham tinh tong cac node.                            =\n"
			<< "= 17. Ham tinh tong cac node chan.                       =\n"
			<< "= 18. Ham tinh tong cac node le.                         =\n"
			<< "= 19. Ham so sanh ket qua cau #17 va #18.                =\n"
			<< "= 20. Ham tim node co gia tri max, min.                  =\n"
			<< "= 0. EXIT(thoat).                                        =\n"
			<< "========================= END =========================\n";
		cout << "Moi chon so:";
		cin >> chon;
		switch (chon)
		{
		case 1: cout << "Da tao trong bai lam!\n";
            break;
		case 2:
			Nhapthucong(t);
			break;
		case 3:
			Nhaptudong(t);
			break;
		case 4:
		{
		cout << "Duyet cay theo LNR:\n";
		LNR(t.root);
		cout << "\nDuyet cay theo NLR:\n ";
		NLR(t.root);
		cout << "\nDuyet cay theo LRN:\n ";
		LRN(t.root);
		}
		break;
		case 5:
		{
			do {
				cout <<"\n=         ->Menu cau 5<-         =\n"
					<< "=    a. X do nguoi dung nhap.    = \n"
					<< "=    b. X trong khoang[300;800]. = \n"
					<< "=    e. Thoat.                   =\n";
				cout << "\nChon: ";
				cin >> aORb;
				switch (aORb)
				{
				case 'a':
				{
					cout << "Nhap gia tri can tim kiem X= ";
				cin >> x;
				timkiem(t.root, x);
				if (timkiem(t.root, x) != NULL) {
					cout << "Tim thay X= " << x << '\n';
					print(timkiem(t.root, x));
				}
				else cout << "Khong tim thay!\n";
				}
				break;
				case 'b':
				{
					x = 300 + rand() % 501;
					cout << "X can tim X=" << x<<'\n';
					timkiem(t.root, x);
				if (timkiem(t.root, x) != NULL) {
					cout << "Tim thay X= " << x << '\n';
					print(timkiem(t.root, x));
				}
				else cout << "Khong tim thay!\n";
				}
				default:
					break;
				}

			} while (aORb != 'e');
		}break;
		case 6:
		{
			cout << "Nhap gia tri can xoa X= ";
			cin >> x;
			Xoanode(t.root, x);
			if (Xoanode(t.root, x) == 0)
				cout << "Da xoa X!\n";
		}break;
		case 7:
		{
			cout << "Da xoa!\n";
			Xoacacnode(t.root);
		}break;
		case 8:
		{
			cout << "So luong node tren cay la: " << Demnode(t.root) << '\n';
		}break;
		case 9:
		{
			Demnodela(t.root, dem);
			cout << "So luong la tren cay la: " << dem << '\n';
		}break;
		case 10:
		{
			NODE* q = NULL;
			cout << "Nhap gia tri cho node can in ra NLR: ";
			cin >> i;
			q = createNode(i);
			inNodenhanh(t.root, q);
		}break;
		case 11: case 12:
		{
			cout << "Nhap gia tri can dem node tu X= ";
			cin >> T;
			do {
				cout << "\n=         ->Menu cau 11, 12<-         =\n"
					<< "=    a. Ham dem so node co gia tri nho hon X.  = \n"
					<< "=    b. Ham dem so node co gia tri lon hon X.. = \n"
					<< "=    e. Quay lai menu chinh.                   =\n";
				cout << "\nChon: ";
				cin >> aORb;
				switch (aORb)
				{
				case 'a':	cout << "So luong node nho hon X= " << T << " la: " << demNodebe(t.root, T) << '\n';
					break;
				case 'b':	cout << "So luong node nho hon X= " << T << " la: " << demNodelon(t.root, T) << '\n';
					break;
				}
			} while (aORb != 'e');
				}break;
		case 13:
		{
			int k, h;
			cout << "Nhap gia tri cho khoang [X, y] can dem so node:\n";
			cout << "Nhap X= ";
			cin >> k;
			cout << "Nhap Y= ";
			cin >> h;
			cout << "So luong X < node < Y la: " << demNode(t.root, k, h) << '\n';
		}break;
		case 14:
		{
			Sosanh(demNodebe(t.root, T), demNodelon(t.root, T));
		}break;
		case 15:
		{
			cout << "So luong node co gia tri chan: " << demChan(t.root)<<'\n';
			cout << "So luong node co gia tri le: " << demLe(t.root) << '\n';
			sosanhChanle(demChan(t.root), demLe(t.root));
		}
		break;
		case 16:
		{
			cout << "Tong so gia tri so node tren cay la: " << tinhTong(t.root) << '\n';
		}break;
		case 17:
		{
			cout << "Tong so node co gia tri chan la: " << tongNodechan(t.root) << '\n';
		}break;
		case 18:
		{
			cout << "Tong so node co gia tri le la: " << tongNodele(t.root) << '\n';
		}break;
		case 19:
		{
			sosanh1819(tongNodele(t.root), tongNodechan(t.root));
		}break;
		case 20:

		{
		    int max = 0, min = 0;
			timMax(t.root, max);
			cout << "Node co gia tri lon nhat la: " << max;
            timMin(t.root, min);
			cout << "\nNode co gia tri be nhat la: " << min << '\n';

		}
		default:
			break;
		}
	}
}
int Count_Node(Node* p)
{
    int a,b;
    if(p == NULL)
        return 0;
    a = Count_Node(p->pLeft);
    b = Count_Node(p->pRight);

    return a + b + 1;
}
