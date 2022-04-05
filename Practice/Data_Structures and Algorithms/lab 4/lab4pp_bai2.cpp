#include <iostream>
#include <string>

using namespace std;

bool menu_yet = false;
int menu();

class NodeI
{
public:
    int data;
    NodeI *next;
    NodeI(int = 0);
};
class ListI
{
public:
    NodeI *head;
    NodeI *tail;

public:
    ListI();
    ListI(NodeI *, NodeI *);
    ~ListI();
    bool empty();
    int size();
    void insert_tail(NodeI *);
    void erase_head();
    void erase_after(NodeI *);
    bool erase(int);
    NodeI *search(int);
    void clear();
};

class Queue
{
private:
    NodeI *head;
    NodeI *tail;

public:
    Queue();
    ~Queue();
    bool empty();
    void enqueue(NodeI *);
    void dequeue(int &);
    void clear();
};

class NodeC
{
public:
    int number;
    string name;
    NodeC *next;
    NodeC(int = 0, string = "");
};
class ListC
{
public:
    NodeC *head;
    NodeC *tail;

public:
    ListC();
    ListC(NodeC *, NodeC *);
    ~ListC();
    bool empty();
    void insert_tail(NodeC *);
    void erase_head();
    void erase_after(NodeC *);
    bool erase(int);
    void clear();
    void selection_sort_seat();
    void output();
};
int main()
{
    int n;
    cout << "Nhap so ghe: ";
    do
    {
        cin >> n;
    } while (n <= 0);

    ListI A;
    for (int i = 1; i <= n; i++)
        A.insert_tail(new NodeI(i));

    Queue B;
    ListC C;
    int choice, number, ord = 0;
    string name;
    bool flag = true;
    while (flag)
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            ord++;
            B.enqueue(new NodeI(ord));
            cout << "\nSo xep hang vua lay: " << ord;
            break;
        case 2:
            if (B.empty())
                cout << "\nHien tai khong co khach dang cho mua ve.";
            else if (A.empty())
                cout << "\nHien tai khong con ghe trong.";
            else
            {
                B.dequeue(number);
                cin.ignore(256, '\n');
                cout << "\nTen: ";
                getline(cin, name);
                cout << "\nSo ghe: ";
                while (true)
                {
                    cin >> number;
                    if (A.search(number) != NULL)
                        break;
                    cout << "Ghe so " << number << " da co nguoi mua.";
                    cout << "\nNhap lai: ";
                }
                A.erase(number);
                C.insert_tail(new NodeC(number, name));
                C.selection_sort_seat();
            }
            break;
        case 3:
            cout << "\nSo ghe cua ve can huy: ";
            cin >> number;
            if (C.erase(number))
                A.insert_tail(new NodeI(number));
            break;
        case 4:
            C.output();
            break;
        case 5:
            ::menu_yet = false;
            break;
        case 6:
            cout << "Chuong trinh ngung hoat dong.\n";
            flag = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }
}

// ------------------------------------ListI------------------------------------ //
NodeI::NodeI(int d)
{
    data = d;
    next = NULL;
}
ListI::ListI()
{
    head = tail = NULL;
}
ListI::ListI(NodeI *h, NodeI *t)
{
    head = h;
    tail = t;
}

ListI::~ListI()
{
    clear();
}
bool ListI ::empty()
{
    return (head == NULL);
}
void ListI ::insert_tail(NodeI *p)
{
    if (empty()) // Nếu list rỗng
        head = tail = p;
    else // Nếu list không rỗng
    {
        tail->next = p;
        tail = p;
    }
}
void ListI ::erase_head()
{
    if (!empty()) // Nếu list không rỗng
    {
        NodeI *p = head;
        head = head->next;
        delete p;
        if (empty()) // Nếu sau khi xoá list rỗng
            tail = NULL;
    }
}
void ListI ::erase_after(NodeI *q)
{
    if (q != NULL)
    {
        NodeI *p = q->next;
        if (p != NULL) // Nếu q không là tail
        {
            q->next = p->next;
            if (p == tail) // Nếu p la tail
                tail = q;
            delete p;
        }
    }
}
bool ListI ::erase(int x)
{
    NodeI *p = head, *q = NULL;
    while (p != NULL && p->data != x)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL) // Nếu list không có x
        return false;
    else
    {
        if (q != NULL) // Nếu head không chứa x
            erase_after(q);
        else // Nếu head chứa x
            erase_head();
        return true;
    }
}
NodeI *ListI ::search(int x)
{
    NodeI *p = head;
    while (p != NULL && p->data != x)
        p = p->next;
    return p;
}

void ListI ::clear()
{
    NodeI *p;
    while (!empty())
    {
        p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
}
// ------------------------------------ListI------------------------------------ //

// ------------------------------------Queue------------------------------------ //
Queue::Queue()
{
    head = tail = NULL;
}
Queue::~Queue()
{
    clear();
}
bool Queue ::empty()
{
    return (head == NULL);
}
void Queue ::enqueue(NodeI *p)
{
    if (empty()) // Nếu queue rỗng
        head = tail = p;
    else // Nếu queue không rỗng
    {
        tail->next = p;
        tail = p;
    }
}
void Queue ::dequeue(int &x)
{
    if (!empty()) // Nếu queue không rỗng
    {
        NodeI *p = head;
        head = head->next;
        x = p->data;
        delete p;
        if (empty()) // Nếu sau khi xoá queue rỗng
            tail = NULL;
    }
}
void Queue ::clear()
{
    NodeI *p;
    while (!empty())
    {
        p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
}
// ------------------------------------Queue------------------------------------ //

// ------------------------------------ListC------------------------------------ //
NodeC::NodeC(int nu, string na)
{
    number = nu;
    name = na;
    next = NULL;
}
ListC::ListC()
{
    head = tail = NULL;
}
ListC::ListC(NodeC *h, NodeC *t)
{
    head = h;
    tail = t;
}

ListC::~ListC()
{
    clear();
}
bool ListC ::empty()
{
    return (head == NULL);
}
void ListC ::insert_tail(NodeC *p)
{
    if (empty()) // Nếu list rỗng
        head = tail = p;
    else // Nếu list không rỗng
    {
        tail->next = p;
        tail = p;
    }
}
void ListC ::erase_head()
{
    if (!empty()) // Nếu list không rỗng
    {
        NodeC *p = head;
        head = head->next;
        delete p;
        if (empty()) // Nếu sau khi xoá list rỗng
            tail = NULL;
    }
}
void ListC ::erase_after(NodeC *q)
{
    if (q != NULL)
    {
        NodeC *p = q->next;
        if (p != NULL) // Nếu q không là tail
        {
            q->next = p->next;
            if (p == tail) // Nếu p la tail
                tail = q;
            delete p;
        }
    }
}
bool ListC::erase(int x)
{
    NodeC *p = head, *q = NULL;
    while (p != NULL && p->number != x)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "\nKhong co ai dat ve nay.";
        return false;
    }
    else
    {
        cout << "\nDa xoa ve co ghe so " << x << ".";
        if (q == NULL)
            erase_head();
        else
            erase_after(q);
        return true;
    }
}
void ListC ::clear()
{
    NodeC *p;
    while (!empty())
    {
        p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
}
void ListC ::selection_sort_seat()
{
    NodeC *min;
    for (NodeC *p = head; p != tail; p = p->next)
    {
        min = p;
        for (NodeC *q = p->next; q != NULL; q = q->next)
        {
            if (q->number < min->number)
                min = q;
        }
        swap(p->number, min->number);
        p->name.swap(min->name);
    }
}
void ListC::output()
{
    cout << "\nDanh sach ve da ban:";
    NodeC *p = head;
    while (p != NULL)
    {
        cout << "\n"
             << p->number << ". " << p->name;
        p = p->next;
    }
}
// ------------------------------------ListC------------------------------------ //

// ------------------------------------menu------------------------------------ //
int menu()
{
    int choice;
    if (!::menu_yet)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon cac chuc nang sau:";
        cout << "\n 1. Lay so xep hang.";
        cout << "\n 2. Mua ve.";
        cout << "\n 3. Huy ve.";
        cout << "\n 4. Hien thi.";
        cout << "\n 5. Xem lai menu.";
        cout << "\n 6. Thoat chuong trinh.";
        cout << "\n ================================";
        ::menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
// ------------------------------------menu------------------------------------ //