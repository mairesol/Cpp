#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int menu();
bool menu_yet = false;

class SinhVien
{
private:
    string hoten;
    string maso;
    int namsinh;
    double dtb;

public:
    SinhVien(string = "", string = "", int = 0, double = 0);
    SinhVien(const SinhVien &);
    SinhVien &operator=(const SinhVien &);
    double get_dtb();
    void input();
    void output();
    friend void output_dtb_lessthan_5(const SinhVien &);
    friend bool before_2000(const SinhVien &);
};

class Node
{
public:
    SinhVien data;
    Node *next;
    Node(SinhVien);
};

class List
{
public:
    Node *head;
    Node *tail;
    List();
    List(Node *, Node *);
    ~List();
    bool empty();
    int size();
    void insert_head(Node *);
    void insert_tail(Node *);
    void erase_head();
    void erase_after(Node *);
    void selection_sort_dtb();
    void clear();

    void input_head();
    void input_tail();
    void output();
};
void output_dtb_lessthan_5(List &);
void erase_before_2000(List &);
int main()
{
    List l;
    bool flag = true;
    while (flag)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            l.input_head();
            l.output();
            break;
        case 2:
            l.input_tail();
            l.output();
            break;
        case 3:
            output_dtb_lessthan_5(l);
            break;
        case 4:
            erase_before_2000(l);
            cout << "----Sau khi xoa sinh vien sinh truoc nam 2000----\n";
            l.output();
            break;
        case 5:
            l.selection_sort_dtb();
            cout << "----Sau khi sap xep theo diem trung binh----\n";
            l.output();
            break;
        case 6:
            l.output();
            l.clear();
            cout << "\n----Da xoa toan bo danh sach----";
            break;
        case 7:
            ::menu_yet = false;
            break;
        case 8:
            flag = false;
            cout << "Xin chao, hen gap lai lan sau.\n";
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }
    return 0;
}
SinhVien::SinhVien(string h, string m, int n, double d)
{
    hoten = h;
    maso = m;
    namsinh = n;
    dtb = d;
}
SinhVien::SinhVien(const SinhVien &A)
{
    hoten = A.hoten;
    maso = A.maso;
    namsinh = A.namsinh;
    dtb = A.dtb;
}
SinhVien &SinhVien::operator=(const SinhVien &A)
{
    hoten = A.hoten;
    maso = A.maso;
    namsinh = A.namsinh;
    dtb = A.dtb;
    return *this;
}
double SinhVien::get_dtb()
{
    return dtb;
}
void SinhVien::input()
{
    cin.ignore(256, '\n');
    cout << "\nNhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap ma so: ";
    getline(cin, maso);
    cout << "Nhap nam sinh: ";
    cin >> namsinh;
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
}
void SinhVien::output()
{
    cout << "\n"
         << hoten << "\t" << maso << "\t" << namsinh << "\t" << dtb;
}
void output_dtb_lessthan_5(const SinhVien &A)
{
    if (A.dtb < 5.0)
        cout << "\n"
             << A.hoten << "\t" << A.maso << "\t" << A.namsinh << "\t" << A.dtb;
}
bool before_2000(const SinhVien &A)
{
    return (A.namsinh < 2000);
}
Node::Node(SinhVien d)
{
    data = d;
    next = NULL;
}
List::List()
{
    head = tail = NULL;
}
List::List(Node *h, Node *t)
{
    head = h;
    tail = t;
}
List::~List()
{
    clear();
}
bool List ::empty()
{
    return (head == NULL);
}
int List::size()
{
    int size = 0;
    Node *p = head;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}
void List ::insert_head(Node *p)
{
    if (empty()) // Nếu list rỗng
        head = tail = p;
    else // Nếu list không rỗng
    {
        p->next = head;
        head = p;
    }
}
void List ::insert_tail(Node *p)
{
    if (empty()) // Nếu list rỗng
        insert_head(p);
    else // Nếu list không rỗng
    {
        tail->next = p;
        tail = p;
    }
}

void List ::erase_head()
{
    if (!empty()) // Nếu list không rỗng
    {
        Node *p = head;
        head = head->next;
        delete p;
        if (empty()) // Nếu sau khi xoá list rỗng
            tail = NULL;
    }
}
void List ::erase_after(Node *q)
{
    if (q != NULL) // Nếu list không rỗng
    {
        Node *p = q->next;
        if (p != NULL) // Nếu q không là tail
        {
            q->next = p->next;
            if (p == tail) // Nếu p là tail
                tail = q;
            delete p;
        }
    }
}
void List ::selection_sort_dtb()
{
    Node *min;
    for (Node *p = head; p != tail; p = p->next)
    {
        min = p;
        for (Node *q = p->next; q != NULL; q = q->next)
            if (q->data.get_dtb() < min->data.get_dtb())
                min = q;
        swap(p->data, min->data);
    }
}
void List ::clear()
{
    Node *p;
    while (!empty())
    {
        p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
}

void List::input_head()
{
    int n;
    cout << "Nhap N: ";
    cin >> n;
    clear();
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":";
        SinhVien x;
        x.input();
        Node *p = new Node(x);
        if (p != NULL)
            insert_head(p);
    }
}
void List::input_tail()
{
    int n;
    cout << "Nhap N: ";
    cin >> n;
    clear();
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":";
        SinhVien x;
        x.input();
        Node *p = new Node(x);
        if (p != NULL)
            insert_tail(p);
    }
}
void List::output()
{
    cout << "Danh sach sinh vien: ";
    Node *p = head;
    while (p != NULL)
    {
        p->data.output();
        p = p->next;
    }
}
void output_dtb_lessthan_5(List &l)
{
    cout << "Danh sach sinh vien co diem trung binh nho hon 5: ";
    Node *p = l.head;
    while (p != NULL)
    {
        output_dtb_lessthan_5(p->data);
        p = p->next;
    }
}
void erase_before_2000(List &l)
{
    while (true)
    {
        Node *p = l.head, *q = NULL;
        while (p != NULL && !before_2000(p->data))
        {
            q = p;
            p = p->next;
        }
        if (p == NULL) // Nếu không còn sinh viên sinh trước năm 2000
            break;
        if (q == NULL)
            l.erase_head();
        else
            l.erase_after(q);
    }
}

int menu()
{
    int choice;
    if (::menu_yet == false)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon cac chuc nang sau:";
        cout << "\n 1. Nhap danh sach N sinh vien tu ban phim bang thao tac them vao dau DSLK va xuat ra thong tin vua nhap.";
        cout << "\n 2. Nhap danh sach N sinh vien tu ban phim bang thao tac them vao cuoi DSLK va xuat ra thong tin vua nhap.";
        cout << "\n 3. In ra danh sach sinh vien co diem trung binh nho hon 5.";
        cout << "\n 4. Xoa cac sinh vien co nam sinh truoc nam 2000 trong danh sach vua nhap.";
        cout << "\n 5. Sap xep sinh vien theo tang dan cua diem trung binh.";
        cout << "\n 6. Xoa tat ca danh sach sinh vien voi yeu cau truoc khi xoa in ra danh sach thong tin sinh vien.";
        cout << "\n 7. Xem menu.";
        cout << "\n 8. Thoat chuong trinh.";
        cout << "\n ================================";
        menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}