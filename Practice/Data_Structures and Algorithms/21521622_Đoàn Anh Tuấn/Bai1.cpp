#include <iostream>
#include <string>
#include <vector>

using namespace std;

int menu();

class MatHang
{
public:
    int ma_sp;
    string ten;
    int so_luong;
    int nam_sx;
    int don_gia;
    MatHang *next;

    MatHang(int = 0, string = "", int = 0, int = 0, int = 0);
};
void Swap(MatHang *, MatHang *);

class List
{
public:
    MatHang *head;
    MatHang *tail;

    List();
    ~List();

    bool empty();
    void clear();

    void insert_tail(MatHang *);

    void input();
    void output();

    MatHang *don_gia_cao_nhat();

    void sap_xep_ma_sp();
};
int main()
{
    List l;
    bool flag = true;
    int choice;
    while (flag)
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            flag = false;
            cout << "\nKet thuc chuong trinh!";
            break;
        case 1:
            l.input();
            l.output();
            break;
        case 2:
            cout << "\nMat hang co gia cao nhat: ";
            cout << l.don_gia_cao_nhat()->ten;
            break;
        case 3:
            l.sap_xep_ma_sp();
            cout << "\nSau khi sap xep theo ma san pham: ";
            l.output();
            break;
        default:
            cout << "\nKhong hop le ";
            break;
        }
    }
    return 0;
}
// MatHang
MatHang::MatHang(int a, string b, int c, int d, int e)
{
    ma_sp = a;
    ten = b;
    so_luong = c;
    nam_sx = d;
    don_gia = e;
    next = NULL;
}
void swap(MatHang *p, MatHang *q)
{
    swap(p->ma_sp, q->ma_sp);
    swap(p->ten, q->ten);
    swap(p->so_luong, q->so_luong);
    swap(p->nam_sx, q->nam_sx);
    swap(p->don_gia, q->don_gia);
}

// List
List::List()
{
    head = tail = NULL;
}
List::~List()
{
    clear();
}
bool List::empty()
{
    return (head == NULL);
}
void List ::clear()
{
    MatHang *p;
    while (!empty())
    {
        p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
}

void List ::insert_tail(MatHang *p)
{
    if (empty()) // Nếu list rỗng
        head = tail = p;
    else // Nếu list không rỗng
    {
        tail->next = p;
        tail = p;
    }
}

void List::input()
{
    clear();
    int n;
    cout << "\nSo luong mat hang: ";
    cin >> n;

    int a, c, d, e;
    string b;
    for (int i = 1; i <= n; i++)
    {
        cout << "\nMat hang thu " << i << ": ";
        cout << "\nMa san pham: ";
        cin >> a;
        cin.ignore(256, '\n');
        cout << "\nTen san pham: ";
        getline(cin, b);
        cout << "\nSo luong: ";
        cin >> c;
        cout << "\nNam san xuat: ";
        cin >> d;
        cout << "\nDon gia: ";
        cin >> e;
        MatHang *p = new MatHang(a, b, c, d, e);
        if (p != NULL)
            insert_tail(p);
    }
}
void List::output()
{
    cout << "\n\nThong tin cua cac mat hang: ";

    MatHang *p = head;

    int i = 1;
    while (p != NULL)
    {
        cout << "\n\nMat hang thu " << i << ": ";
        cout << "\nMa san pham: " << p->ma_sp;
        cout << "\nTen san pham: " << p->ten;
        cout << "\nSo luong: " << p->so_luong;
        cout << "\nNam san xuat: " << p->nam_sx;
        cout << "\nDon gia: " << p->don_gia;

        i++;
        p = p->next;
    }
}

MatHang *List::don_gia_cao_nhat()
{
    MatHang *p = head, *p_max = head;

    while (p != NULL)
    {
        if (p->don_gia > p_max->don_gia)
            p_max = p;
        p = p->next;
    }
    return p_max;
}
void List::sap_xep_ma_sp()
{
    MatHang *min;
    for (MatHang *p = head; p != tail; p = p->next)
    {
        min = p;
        for (MatHang *q = p->next; q != NULL; q = q->next)
            if (q->ma_sp < min->ma_sp)
                min = q;
        swap(p, min);
    }
}

// Menu
int menu()
{
    cout << "\n\nChon chuc nang: ";
    cout << "\n0. Thoat chuong trinh.";
    cout << "\n1. Nhap va xuat.";
    cout << "\n2. Tim mat hang co gia cao nhat.";
    cout << "\n3. Sap xep tang dan theo ma san pham.";

    int choice;
    cout << "\nLua chon: ";
    cin >> choice;
    return choice;
}