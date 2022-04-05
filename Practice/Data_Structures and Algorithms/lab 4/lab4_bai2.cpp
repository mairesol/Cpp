#include <iostream>

using namespace std;

bool menu_yet = false;
int menu1();
int menu2();

class StackA
{
private:
    int Top;
    int capacity;
    int *arr;

public:
    StackA(int = 10);
    ~StackA();
    bool empty();
    bool full();
    int size();
    void push(int);
    void pop(int &);
    void clear();
    friend void program(StackA &);
};
class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0);
};

class StackL
{
private:
    Node *head;
    Node *tail;

public:
    StackL();
    ~StackL();
    bool empty();
    int size();
    void push(Node *);
    void pop(int &);
    void clear();
    friend void program(StackL &);
};

int main()
{
    int choice, ans;
    bool flag = true;
    while (flag)
    {
        choice = menu1();
        StackA sA;
        StackL sL;
        switch (choice)
        {
        case 1:
            cout << "\n============ Stack bang array ============";
            program(sA);
            break;
        case 2:
            cout << "\n============ Stack bang linked list ============";
            program(sL);
            break;
        case 3:
            cout << "Xin chao, hen gap lai lan sau.\n";
            flag = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }
    return 0;
}
// ------------------------------------Program------------------------------------ //
void program(StackA &sA)
{
    int x, choice;
    bool flag = true;
    while (flag)
    {
        choice = menu2();
        switch (choice)
        {
        case 1:
            cout << "\nPush: ";
            cin >> x;
            sA.push(x);
            break;
        case 2:
            cout << "\nPop: ";
            if (!sA.empty())
            {
                sA.pop(x);
                cout << x;
            }
            break;
        case 3:
            if (sA.empty())
                cout << "\nStack rong.";
            else
                cout << "\nStack khong rong";
            break;
        case 4:
            cout << "\nStack co " << sA.size() << " phan tu.";
            break;
        case 5:
            sA.clear();
            cout << "\nDa xoa tat ca phan tu cua stack.";
            break;
        case 6:
            ::menu_yet = false;
            break;
        case 7:
            sA.clear();
            cout << "\nDa dung thao tac voi stack.";
            flag = ::menu_yet = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }
}
void program(StackL &sL)
{
    int x, choice;
    bool flag = true;
    while (flag)
    {
        choice = menu2();
        switch (choice)
        {
        case 1:
            cout << "\nPush: ";
            cin >> x;
            sL.push(new Node(x));
            break;
        case 2:
            cout << "\nPop: ";
            if (!sL.empty())
            {
                sL.pop(x);
                cout << x;
            }
            break;
        case 3:
            if (sL.empty())
                cout << "\nStack rong.";
            else
                cout << "\nStack khong rong";
            break;
        case 4:
            cout << "\nStack co " << sL.size() << " phan tu.";
            break;
        case 5:
            sL.clear();
            cout << "\nDa xoa tat ca phan tu cua stack.";
            break;
        case 6:
            ::menu_yet = false;
            break;
        case 7:
            sL.clear();
            cout << "\nDa dung thao tac voi stack.";
            flag = ::menu_yet = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }
}
// ------------------------------------Program------------------------------------ //

// ------------------------------------Node------------------------------------ //
Node::Node(int d)
{
    data = d;
    next = NULL;
}
// ------------------------------------Node------------------------------------ //

// ------------------------------------StackA------------------------------------ //
StackA::StackA(int c)
{
    capacity = c;
    arr = new int[capacity];
    Top = -1;
}
StackA::~StackA()
{
    delete[] arr;
}
bool StackA::empty()
{
    return (Top == -1);
}
bool StackA::full()
{
    return (Top == capacity - 1);
}
int StackA::size()
{
    return Top + 1;
}
void StackA::push(int x)
{
    if (!full())
    {
        Top++;
        arr[Top] = x;
    }
}
void StackA::pop(int &x)
{
    if (!empty())
    {
        x = arr[Top];
        Top--;
    }
}
void StackA::clear()
{
    Top = -1;
}
// ------------------------------------StackA------------------------------------ //

// ------------------------------------StackL------------------------------------ //
StackL::StackL()
{
    head = tail = NULL;
}
StackL::~StackL()
{
    clear();
}
bool StackL ::empty()
{
    return (head == NULL);
}
int StackL::size()
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
void StackL ::push(Node *p)
{
    if (empty()) // Nếu stack rỗng
        head = tail = p;
    else // Nếu stack không rỗng
    {
        p->next = head;
        head = p;
    }
}
void StackL ::pop(int &x)
{
    if (!empty()) // Nếu stack không rỗng
    {
        Node *p = head;
        head = head->next;
        x = p->data;
        delete p;
        if (empty()) // Nếu sau khi xoá stack rỗng
            tail = NULL;
    }
}
void StackL ::clear()
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
// ------------------------------------StackL------------------------------------ //

// ------------------------------------menu------------------------------------ //
int menu1()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon loai stack de lam viec:";
    cout << "\n 1. Stack bang mang.";
    cout << "\n 2. Stack bang DSLK.";
    cout << "\n 3. Thoat chuong trinh.";
    cout << "\n ================================";
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}

int menu2()
{
    int choice;
    if (!::menu_yet)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon thao tac lam viec voi stack:";
        cout << "\n 1. Push.";
        cout << "\n 2. Pop.";
        cout << "\n 3. Kiem tra stack co rong hay khong.";
        cout << "\n 4. Dem so luong phan tu trong stack.";
        cout << "\n 5. Xoa tat ca phan tu trong stack.";
        cout << "\n 6. Xem lai menu.";
        cout << "\n 7. Dung thao tac voi stack.";
        cout << "\n ================================";
        ::menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
// ------------------------------------menu------------------------------------ //