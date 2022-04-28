#include <iostream>
#include <algorithm>

using namespace std;

int menu();
bool menu_yet = false;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;
    List();
    ~List();
    bool empty();
    int size();
    void insert_head(Node *);
    void insert_tail(Node *);
    void insert_after(Node *, Node *);
    void erase_head();
    void erase_after(Node *);
    bool erase(int);
    void erase_tail();
    int search(int);
    void clear();

    void input_head();
    void input_tail();
    void output();

    void routput();
};
void to_tail(Node *);

int main()
{
    List l;
    bool flag = true;
    int x, n;
    Node *p;
    int result;
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
            l.routput();
            break;
        case 4:
            cout << "So luong nut: " << l.size();
            break;
        case 5:
            cout << "Nhap X: ";
            cin >> x;
            result = l.search(x);
            if (result == -1)
                cout << "Khong tim that X trong danh sach.";
            else
                cout << "X o nut thu " << result + 1;
            break;
        case 6:
            l.erase_head();
            l.output();
            break;
        case 7:
            l.erase_tail();
            l.output();
            break;
        case 8:
            cout << "Nhap X: ";
            cin >> x;
            result = l.erase(x);
            if (result == false)
                cout << "Khong tim thay X trong danh sach de xoa.";
            else
                l.output();
            break;
        case 9:
            cout << "Nhap X: ";
            do
            {
                cin >> x;
            } while (x <= 0);
            p = new Node(x);
            cout << "Nhap n: ";
            do
            {
                cin >> n;
            } while (n < 0 || n > l.size());
            if (n == 0)
                l.insert_head(p);
            else
            {
                Node *q = l.head;
                while (--n)
                {
                    q = q->next;
                }
                l.insert_after(q, p);
            }
            l.output();
            break;
        case 10:
            ::menu_yet = false;
            break;
        case 11:
            flag = false;
            cout << "Xin chao.\n";
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }
    return 0;
}

List::List()
{
    head = tail = NULL;
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
void List ::insert_after(Node *q, Node *p)
{
    if (q == NULL) // Nếu list rỗng
        insert_head(p);
    else // Nếu list không rỗng
    {
        p->next = q->next;
        q->next = p;
        if (tail == q) // Nếu q là tail
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
bool List ::erase(int x)
{
    Node *p = head, *q = NULL;
    while (p != NULL && p->data != x)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL) // Nếu list không có x
    {
        return false;
    }
    else
    {
        if (q != NULL) // Nếu head không chứa x
            erase_after(q);
        else // Nếu head chứa x
            erase_head();
        return true;
    }
}
void List ::erase_tail()
{
    if (!empty()) // Nếu list không rỗng
    {
        Node *p = head;
        if (p == tail) // Nếu list có 1 nút
            erase_head();
        else // Nếu list có nhiều nút
        {
            while (p->next->next != NULL)
            {
                p = p->next;
            }
            delete p->next;
            p->next = NULL;
            tail = p;
        }
    }
}
int List ::search(int x)
{
    int pos = -1;
    Node *p = head;
    while (p != NULL)
    {
        pos++;
        if (p->data == x)
            return pos;
        p = p->next;
    }
    return -1;
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
    cout << "Nhap n: ";
    cin >> n;
    clear();
    for (int i = 0; i < n; i++)
    {
        int x;
        do
        {
            cin >> x;
        } while (x <= 0);
        Node *p = new Node(x);
        if (p != NULL)
            insert_head(p);
    }
}
void List::input_tail()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    clear();
    for (int i = 0; i < n; i++)
    {
        int x;
        do
        {
            cin >> x;
        } while (x <= 0);
        Node *p = new Node(x);
        if (p != NULL)
            insert_tail(p);
    }
}
void List::output()
{
    cout << "Danh sach: ";
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void to_tail(Node *p)
{
    if (p != NULL)
    {
        to_tail(p->next);
        cout << p->data << " ";
    }
}
void List::routput()
{
    cout << "Danh sach theo chieu cuoi: ";
    to_tail(head);
}
int menu()
{
    int choice;
    if (::menu_yet == false)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon cac chuc nang sau:";
        cout << "\n 1. Nhap vao va xuat ra n phan tu vao danh sach bang cach them vao dau danh sach va in ra danh sach vua nhap.";
        cout << "\n 2. Nhap vao va xuat ra n phan tu vao danh sach bang cach them vao cuoi danh sach va in ra danh sach vua nhap.";
        cout << "\n 3. In ra danh sach theo chieu cuoi ma khong dung mang phu hay danh sach phu.";
        cout << "\n 4. Dem so nut trong danh sach lien ket don.";
        cout << "\n 5. Tim mot nut co thanh phan du lieu bang X duoc nhap vao tu ban phim.";
        cout << "\n 6. Xoa nut dau danh sach.";
        cout << "\n 7. Xoa nut cuoi danh sach.";
        cout << "\n 8. Xoa nut co truong du lieu bang X, neu khong co thi thong bao khong co.";
        cout << "\n 9. Chen 1 nut co truong du lieu bang X vao vi tri thu n duoc nhap vao ban phim.";
        cout << "\n 10. Xem menu.";
        cout << "\n 11. Thoat chuong trinh.";
        cout << "\n ================================";
        menu_yet = true;
    }
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}