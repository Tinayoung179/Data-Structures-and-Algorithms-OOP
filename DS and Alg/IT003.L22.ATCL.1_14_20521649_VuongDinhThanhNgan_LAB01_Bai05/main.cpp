#include <bits/stdc++.h>
#include <iostream>
#define MAX 1000

using namespace std;

int A[MAX];
// tao danh sach Node
struct Node
{
    int Data;
    Node *pNext;
};
// tao sanh sach cac
struct List
{
    Node *pHead;
    Node *pTail;
    Node *Ptr;
    int soLuong;
};

Node *TaoNode(int x)
{
    Node *p;
    p->Data = x;
    p->pNext = NULL;
    return p;
}
Node *TaoNode()
{
    int n;
    cout << "Nhap Gia tri cua Node: ";
    cin>> n;
    return TaoNode(n);
}
void TaoList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
// Ham chen 1 Node vao dau danh sach
// Input: danh sach l va node p
// Output: danh sach l co Node p o dau danh sach
void ChenVaoDau(List &l, Node *p)
{
    if(l.pHead == NULL)
    l.pHead = l.pTail = p;
    else
    {
        p->pNext= l.pHead;
        l.pHead = p;
    }
    l.soLuong ++;
}
// Ham chen 1 Node vao cuoi danh sach
// Input: danh sach l va node p
// Output: danh sach l co Node p o cuoi danh sach
void ChenVaoCuoi(List &l, Node *p)
{
    if(l.pHead == NULL)
    l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
    l.soLuong ++;
}
// Ham Nhap thu cong
// Input: danh sach l
// Output danh sach l co n Node do nguoi dung nhap
void NhapThuCong(List &l)
{
    cout << "Nhap so luong Node: ";
    int n;
    cin >> n;
    for(int i =0 ; i < n; i++)
    {
        cout << "Nhap gia tri cua Node: \n\t";
        int x;
        cin >> x;
        ChenVaoDau(l, TaoNode(x));
    }
}
// Ham Nhap thu cong
// Input: danh sach l
// Output danh sach l co n Node
void NhapTuDong(List &l)
{
    srand(time(NULL));
    int n = rand() % 21 + 39;
    for(int i =0; i < n; i ++)
        {
            ChenVaoCuoi(l, TaoNode(rand() %189 -99));
        }
}
// ham nhap mang
// Input: 1 mang va n so luong phan tu can nhap
// Output 1 mang co n phan tu, gia tri do nguoi dung nhap
void NhapMang(int a[], int &n)
{
    cout << "Nhap so luong Phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

}
// ham nhap n Node tu mang 1 chieu
// danh sach lien ket don trong , 1 mang 1 chieu so luong phan tu
// danh sach lien ket don ddc nhap tu mang
void NhapTuMang(List &l, int A[], int n)
{
    for(int i =0; i < n; i++)
    {
        ChenVaoDau(l, TaoNode(A[i]));
    }
}

void ChenSauNodeQ(List &l, Node *p, Node *q)
{
    if(l.pHead == NULL) ChenVaoDau(l, p);
    else
    {
        p ->pNext = q->pNext;
        q->pNext == p;
    }
    l.soLuong ++;
}

void ChenVaoGiua(List &l, Node *p)
{
        {
            for(int i =0; i < (l.soLuong -1)/2; i++)
            l.Ptr = l.Ptr->pNext;
            ChenSauNodeQ(l, l.Ptr ,p);
        }

}

void DoiVTNode(List &l, Node *p, Node *q)
{
    p = q->pNext;
    q->pNext = p;

}

void ChenXSauY(List &l, int x, int y)
{
    l.Ptr = l.pHead;
    for(int i =0; i < l.soLuong; i++ )
    {
        if(l.Ptr->Data == y)
            ChenSauNodeQ(l, l.Ptr, TaoNode(x));
    }
}

void ChenXTruocY(List &l, int x, int y)
{
    l.Ptr = l.pHead;
    for(int i =0; i < l.soLuong; i++ )
    {
        if(l.Ptr->Data == y)
            {
            ChenSauNodeQ(l, l.Ptr, TaoNode(x));
            DoiVTNode(l, l.Ptr, l.Ptr->pNext );
            break;
            }
    }
}

void InDanhSach(List l)
{
    l.Ptr = l.pHead;
    for(int i =0; i < l.soLuong ; i++)
        {
            cout << l.Ptr << endl;
        }
}

void InKemDiaChi(List l)
{
    l.Ptr = l.pHead;
    for(int i =0; i < l.soLuong ; i++)
        {
            cout << l.Ptr <<" <" << l.Ptr << ">" << endl;
        }
}

void InDauCuoi(List l)
{
    cout << l.pHead <<" <" << l.Ptr << ">" << endl;
    cout << l.pTail <<" <" << l.Ptr << ">" << endl;
}

bool KiemTraRong(List l)
{
    if(l.pHead == NULL) return 1;
    return 0;
}

Node *NodeThuN(List l, int n)
{
    l.Ptr = l.pHead;
    for(int i =0; i < n; i++)
    {
        l.Ptr = l.Ptr->pNext;
    }
    return l.Ptr;
}

Node *TimNode_I(List l, int x)
{
    l.Ptr = l.pHead;
    for(int i =0; i < l.soLuong ; i++)
    {
        if(l.Ptr->Data == x) return l.Ptr;
        break;
    }
    return NULL;
}

void TimNode_II(List l, int x)
{
    l.Ptr = l.pHead;
    for(int i =0; i < l.soLuong ; i++)
    {
        if(l.Ptr->Data == x) cout << l.Ptr;
    }
}

int TongCacNode(List l)
{
    l.Ptr = l.pHead;
    int s =0;
    for(int i =0; i < l.soLuong; i++)
    {
        s += l.Ptr->Data;
        l.Ptr = l.Ptr ->pNext;

    }
    return s;
}

int DoDaiNode(List l)
{
    return l.soLuong;
}

int DemNodeChan(List l)
{
    l.Ptr = l.pHead;
    int dem =0;
    for(int i =0; i < l.soLuong; i++)
    {
        if(l.Ptr->Data % 2 == 0) dem++;
        l.Ptr = l.Ptr ->pNext;
    }
    return dem;
}

int DemNodeLe(List l)
{
    return l.soLuong - DemNodeChan(l);
}

int DemNodeDuong(List l)
{

       l.Ptr = l.pHead;
        int dem =0;
        for(int i =0; i < l.soLuong; i++)
            {
        if(l.Ptr->Data  >  0) dem++;
        l.Ptr = l.Ptr ->pNext;
            }
     return dem;
}

int DemNodeAm(List l)
{
       l.Ptr = l.pHead;
        int dem =0;
        for(int i =0; i < l.soLuong; i++)
            {
        if(l.Ptr->Data  <  0) dem++;
        l.Ptr = l.Ptr ->pNext;
            }
     return dem;
}

int NodeLonNhat(List l)
{
        l.Ptr = l.pHead;
        Node *Max =l.pHead;
        for(int i =0; i < l.soLuong; i++)
        {
        if(l.Ptr->Data  > Max->Data)
        Max = l.Ptr;
        l.Ptr = l.Ptr ->pNext;
        }
     return Max->Data;
}

int NodeNhoNhat(List l)
{
        l.Ptr = l.pHead;
        Node *Min =l.pHead;
        for(int i =0; i < l.soLuong; i++)
        {
        if(l.Ptr->Data  > Min->Data)
        Min = l.Ptr;
        l.Ptr = l.Ptr ->pNext;
        }
     return Min->Data;
}

void TimMaxSoAmVaMinSoLe(List l)
{
    l.Ptr = l.pHead;
        Node *Min =l.pHead;
        Node *Max = l.pHead;
        for(int i =0; i < l.soLuong; i++)
        {
        if(l.Ptr->Data  < Max->Data && Max->Data < 0)
        Max = l.Ptr;
        if(l.Ptr -> Data % 2 !=0 && Min->Data > l.Ptr->Data )
        Min = l.Ptr;
        l.Ptr = l.Ptr ->pNext;
        }
    cout << "Min so le la: " << Min->Data;
    cout << "Max so am la: " << Max->Data;
}

void CapNhatMotGiaTri_I(List &l, int x, int y)
{
        l.Ptr = l.pHead;
        Node *Min =l.pHead;
        for(int i =0; i < l.soLuong; i++)
        {
        if(l.Ptr->Data == x)
        {
            l.Ptr->Data = y;
            break;
        }
        l.Ptr = l.Ptr ->pNext;
        }
}

void CapNhatMotGiaTri_II(List &l, int x, int y)
{
        l.Ptr = l.pHead;
        Node *Min =l.pHead;
        for(int i =0; i < l.soLuong; i++)
        {
        if(l.Ptr->Data == x)
        {
            l.Ptr->Data = y;
        }
        l.Ptr = l.Ptr ->pNext;
        }
}

int SoSanhChanLe(List l)
{
    l.Ptr = l.pHead;
    int tongChan =0;
    int TongLe =0;
        Node *Min =l.pHead;
        for(int i =0; i < l.soLuong; i++)
        {
        if(l.Ptr->Data % 2 == 0)
        {
            tongChan+= l.Ptr->Data;
        }
        else TongLe += l.Ptr->Data;
        l.Ptr = l.Ptr ->pNext;
        }

        if(tongChan < TongLe) return 1;
        else if (tongChan > TongLe) return 0;
        else return 0;
}

Node *TimNodeDungTruoc(List l, int x)
{
        l.Ptr = l.pHead;
        Node *Temp =l.pHead;
        for(int i =0; i < l.soLuong; i++)
        {
            Temp = l.Ptr;
            if(l.Ptr->Data = x)  return Temp;
            l.Ptr = l.Ptr ->pNext;

        }
        return NULL;
}

List DaoNguoc(List l)
{
    List a;
    TaoList(a);
    l.Ptr = l.pHead;
        Node *Min =l.pHead;
        for(int i =0; i < l.soLuong; i++)
        {
            ChenVaoCuoi(a, l.Ptr);
         l.Ptr = l.Ptr ->pNext;
        }
    return a;
}

int   RemoveHead(List &l)
	{	Node *p;
		if(l.pHead!=NULL)
		{	p=l.pHead;
			l.pHead=l.pHead->pNext;
			delete p;
			if(l.pHead==NULL)
				l.pTail=NULL;
			return 1;
		}
		return 0;
	}

    int RemoveAfterQ(List &l, Node *q)
	{	Node *p;
		if(q!=NULL)
		{	p=q->pNext; //p là nút cần xoá
			if(p!=NULL) // q không phài là nút cuối
			{	if(p==l.pTail) //nút cần xoá là nút cuối cùng
					l.pTail=q;// cập nhật lạ pTail
				q->pNext=p->pNext;
				delete p;
			}
			return 1;
		}
		else
		     return 0;	}



    int RemoveX(List &l, int x)
{	Node *p,*q = NULL; p=l.pHead;
	while((p!=NULL)&&(p->Data!=x)) //tìm
	{	q=p;
		p=p->pNext;
	}
	if(p==NULL) //không tìm thấy phần tử có khoá bằng x
		return 0;
	if(q!=NULL)//tìm thấy phần tử có khoá bằng x
		RemoveAfterQ(l,q);
	else //phần tử cần xoá nằm đầu List
		RemoveHead(l);
	return 1;
}

int XoaAll(List &l)
{

    while(l.pHead != NULL) RemoveHead(l);
    return 1;
}



// Tao 1 Menu lua chon
void Menu()
{
    int a,b;
    List l;
    TaoList(l);
    int x;
    int n;
    do
    {
        cout << "****************  Menu  ****************************\n";
        cout <<"1. Chen Node vao dau danh sach.\n";
        cout <<"2. Chen Node vao cuoi danh sach.\n";
        cout << "3. Nhap gia tri cho danh sach.\n";
        cout << "4. Nhap gia tri cho danh sach auto.\n";
        cout << "5. Nhap gia tri cho danh sach tu mang 1 chieu.\n";
        cout << "6. Chen Node vao giua danh sach.\n";
        cout << "7. Chen them gia tri x vao sau gia tri y.\n";
        cout << "8. Chen them 1 gia tri x vao truoc gia tri y.\n";
        cout << "9. In danh sach da nhap.\n";
        cout << "10. In danh sach da nhap kem theo dia chi.\n";
        cout << "11. In hai Node dau/ cuoi kem dia chi.\n";
        cout << "12. Kiem tra mang co rong hay khong.\n";
        cout << "13. viet ham tra ve Node thu N.\n";
        cout << "14. Tim kiem 1 Node trong danh sach(tra ve dia chi dau tien).\n";
        cout << "15. Tim Node co gia tri x trong danh sach.\n";
        cout << "16. Tinh tong cac Node trong danh sach.\n";
        cout << "17. Tính do dai cua danh sach.\n";
        cout << "18. Dem so luong Node chan/ le trong danh sach.\n";
        cout << "19. Dem so luong Node am/ duong trong danh sach.\n";
        cout << "20. Tim Node Min/ Max trong danh sach.\n";
        cout << "21. Tim Node am lon nhat/ Node le nho nhat.\n";
        cout << "22. Tim Max so am/ Min so le.\n";
        cout << "23. Cap nhat cho 1 Node X bang gia tri y.\n";
        cout << "24. Cap nhat tat ca cac Node x bang gia tri y.\n";
        cout << "25. Viet ham tinh tong cac so chan/ tinh tong cac so le va so sanh.\n";
        cout << "26. Tim Node dung truoc 1 Node co gia tri x.\n";
        cout << "27. Viet ham dao nguoc danh sach.\n";
        cout << "28. Tach hai danh sach tai vi tri giua.\n";
        cout << "29. Tach danh sach lien ket.\n";
        cout << "30. Xoa Node dau tien.\n";
        cout << "31. Xoa Node cuoi danh sach.\n";
        cout << "32. Xoa Node co gia tri x(Node dau tien tim thay).\n";
        cout << "33. Noi hai danh sach.\n";
        cout << "34. Xoa tat ca cac Node co gia tri x trong danh sach.\n";
        cout << "35. Xoa toan bo Node trong danh sach.\n";
        cout << "36. Sap Xep danh sach tang giam. \n";
        cout << "Nhap 0 de thoat.\n";
        cout << "**********************************************\n  ";
        cout << " \t \t Nhap lua chon: ";
        cin >> x;
        switch (x)
        {
        case 1:
            ChenVaoDau(l, TaoNode());
            break;
        case 2:
        ChenVaoCuoi(l, TaoNode());
        break;
        case 3:
        NhapThuCong(l);
        break;
        case 4:
        NhapTuDong(l);
        break;
        case 5:
        NhapTuMang(l,A, n);
        case 6:
        ChenVaoGiua(l, TaoNode());
        break;
        case 7:
        ChenXSauY(l, a, b);
        break;
        case 8:
        ChenXTruocY(l, a,b);
        break;
        case 9:
        InDanhSach(l);
        break;
        case 10:
        InKemDiaChi(l);
        break;
        case 11:
        InDauCuoi(l);
        break;
        case 12:
        cout << KiemTraRong(l);
        break;
        case 13:
        cout << NodeThuN(l,n)->Data<< "<"<< NodeThuN(l,n) <<">" << endl;
        break;
        case 14:
        TimNode_I(l,x);
        break;
        case 15:
        TimNode_II(l, x);
        break;
        case 16:
        cout << TongCacNode(l);
        break;
        case 17:
        cout << DoDaiNode(l);
        break;
        case 18:
        cout << DemNodeChan(l) << "   "<< DemNodeLe(l);
        break;
        case 19:
        cout << DemNodeAm << "\t\t" << DemNodeDuong(l);
        break;
        case 20:
        cout << NodeLonNhat(l) << "\t" << NodeNhoNhat(l);
        break;
        case 21:
        TimMaxSoAmVaMinSoLe(l);
        break;
        case 22:
        TimMaxSoAmVaMinSoLe(l);
        break;
        case 23:
        CapNhatMotGiaTri_I(l, a,b);
        break;
        case 24:
        CapNhatMotGiaTri_II(l, a,b);
        break;
        case 25:
        SoSanhChanLe(l);
        break;
        case 26:
        TimNodeDungTruoc(l, n);
        break;
        case 27:
        l = DaoNguoc(l);
        break;
        default:
            break;

        }
    }
    while(x);

}

int main()
{
    Menu();
}
