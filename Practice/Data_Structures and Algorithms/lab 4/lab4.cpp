#include <iostream>

using namespace std;

#define max 100

int menu(char);
int menu2(char);
bool menu_yet_q = false;
bool menu_yet_s = false;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0);
};

class QueueA
{
private:
    int arr[max];
    int Front, Rear;

public:
    QueueA();
    bool isEmpty();
    int size();
    void enqueue(int);
    void dequeue(int &);
    void clear();
};

class QueueL
{
public:
    Node *head;
    Node *tail;
    QueueL();
    ~QueueL();
    bool empty();
    int size();
    void enqueue(Node *);
    void dequeue(int &);
    int &front();
    int &back();
    void clear();
};

class StackA
{
private:
    int arr[max];
    int Top;

public:
    StackA();
    bool isEmpty();
    bool isFull();
    int size();
    void push(int);
    void pop(int &);
    int &top();
    void clear();
};

class StackL
{
public:
    Node *head;
    Node *tail;
    StackL();
    ~StackL();
    bool empty();
    int size();
    void push(Node *);
    void pop(int &);
    int &top();
    void clear();
};

int main()
{
    int x;
    bool act = true;
    bool flag = true;
    int choice;
    char c;
    while (act)
    {
        cout << "Chon loai cau truc du lieu de lam viec: q/s/esc";
        do
        {
            cin >> c;
        } while (c != 'q' && c != 's' && c != 27);
        if (c == 27)
        {
            cout << "Xin chao, hen gap lai lan sau.\n";
            break;
        }
        choice = menu1(c);
        switch (choice)
        {
        case 1:           // Thao tac voi mang
            if (c == 'q') // Thao tac voi queue
            {
                QueueA q;
                while (flag)
                {
                    choice = menu2(c);
                    switch (choice)
                    {
                    case 1:
                        cin >> x;
                        q.enqueue(x);
                        break;
                    case 2:
                        q.dequeue(x);
                        break;
                    case 3:
                        if (q.isEmpty())
                            cout << "\nQueue rong.";
                        else
                            cout << "\nQueue khong rong.";
                        break;
                    case 4:
                        cout << "\nQueue co " << q.size() << " phan tu.";
                        break;
                    case 5:
                        q.clear();
                        cout << "\nDa xoa tat ca phan tu cua queue.";
                        break;
                    case 6:
                        q.clear();
                        cout << "\nDa dung thao tac queue.";
                        flag = false;
                        break;
                    default:
                        cout << "Lua chon khong dung, vui long nhap lai.";
                        break;
                    }
                }
            }
            if (c == 's') // Thao tac voi stack
            {
                StackA s; // Thao tac voi mang
                while (flag)
                {
                    choice = menu2(c);
                    switch (choice)
                    {
                    case 1:
                        cin >> x;
                        s.push(x);
                        break;
                    case 2:
                        s.pop(x);
                        break;
                    case 3:
                        if (s.isEmpty())
                            cout << "\nStack rong.";
                        else
                            cout << "\nStack khong rong.";
                        break;
                    case 4:
                        cout << "\nStack co " << s.size() << " phan tu.";
                        break;
                    case 5:
                        s.clear();
                        cout << "\nDa xoa tat ca phan tu cua stack.";
                        break;
                    case 6:
                        s.clear();
                        cout << "\nDa dung thao tac stack.";
                        flag = false;
                        break;
                    default:
                        cout << "Lua chon khong dung, vui long nhap lai.";
                        break;
                    }
                }
            }
            break;

        case 2:           // Thao tac voi DSLK
            if (c == 'q') // Thao tac voi queue
            {
                QueueL q;
                while (flag)
                {
                    choice = menu2(c);
                    switch (choice)
                    {
                    case 1:
                        cin >> x;
                        q.enqueue(new Node(x));
                        break;
                    case 2:
                        q.dequeue(x);
                        break;
                    case 3:
                        if (q.empty())
                            cout << "\nQueue rong.";
                        else
                            cout << "\nQueue khong rong.";
                        break;
                    case 4:
                        cout << "\nQueue co " << q.size() << " phan tu.";
                        break;
                    case 5:
                        q.clear();
                        cout << "\nDa xoa tat ca phan tu cua queue.";
                        break;
                    case 6:
                        q.clear();
                        cout << "\nDa dung thao tac queue.";
                        flag = false;
                        break;
                    default:
                        cout << "Lua chon khong dung, vui long nhap lai.";
                        break;
                    }
                }
            }
            if (c == 's') // Thao tac voi stack
            {
                StackL s;
                while (flag)
                {
                    choice = menu2(c);
                    switch (choice)
                    {
                    case 1:
                        cin >> x;
                        s.push(new Node(x));
                        break;
                    case 2:
                        s.pop(x);
                        break;
                    case 3:
                        if (s.empty())
                            cout << "\nStack rong.";
                        else
                            cout << "\nStack khong rong.";
                        break;
                    case 4:
                        cout << "\nStack co " << s.size() << " phan tu.";
                        break;
                    case 5:
                        s.clear();
                        cout << "\nDa xoa tat ca phan tu cua stack.";
                        break;
                    case 6:
                        s.clear();
                        cout << "\nDa dung thao tac stack.";
                        flag = false;
                        break;
                    default:
                        cout << "Lua chon khong dung, vui long nhap lai.";
                        break;
                    }
                }
            }
            break;
        case 3:
            cout << "Xin chao, hen gap lai lan sau.\n";
            act = false;
            break;
        default:
            break;
        }
    }
    return 0;
}
// ------------------------------------Node------------------------------------ //
Node::Node(int d)
{
    data = d;
    next = NULL;
}
// ------------------------------------Node------------------------------------ //

// ------------------------------------QueueA------------------------------------ //
bool QueueA::isEmpty()
{
    return (Front == -1);
}
int QueueA::size()
{
    if (isEmpty())
        return 0;
    return Rear - Front + 1;
}
QueueA::QueueA()
{
    Front = -1;
    Rear = -1;
}
void QueueA::enqueue(int x)
{
    int f, r;
    if (Rear - Front + 1 == max) // Nếu queue đầy thật
        return;
    else
    {
        if (Front == -1) // Nếu queue rỗng
            Front = 0;
        if (Rear == max - 1) // Queue đầy ảo
        {
            f = Front;
            r = Rear;
            for (int i = f; i <= r; i++)
                arr[i - f] = arr[i];
            Front = 0;
            Rear = r - f;
        }
        Rear++;
        arr[Rear] = x;
    }
}
void QueueA::dequeue(int &x)
{
    if (Front != -1) // Nếu queue không rỗng
    {
        x = arr[Front];
        Front++;
        if (Front > Rear) // Nếu queue có 1 phần tử
        {
            Front = -1;
            Rear = -1;
        }
    }
}
void QueueA::clear()
{
    Front = Rear = -1;
}

// ------------------------------------QueueA------------------------------------ //

// ------------------------------------QueueL------------------------------------ //
QueueL::QueueL()
{
    head = tail = NULL;
}
QueueL::~QueueL()
{
    clear();
}
bool QueueL ::empty()
{
    return (head == NULL);
}
int QueueL ::size()
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
void QueueL ::enqueue(Node *p)
{
    if (empty()) // Nếu queue rỗng
        head = tail = p;
    else // Nếu queue không rỗng
    {
        tail->next = p;
        tail = p;
    }
}
void QueueL ::dequeue(int &x)
{
    if (!empty()) // Nếu queue không rỗng
    {
        Node *p = head;
        head = head->next;
        x = p->data;
        delete p;
        if (empty()) // Nếu sau khi xoá queue rỗng
            tail = NULL;
    }
}
int &QueueL::front()
{
    return head->data;
}
int &QueueL::back()
{
    return tail->data;
}
void QueueL ::clear()
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
// ------------------------------------QueueL------------------------------------ //

// ------------------------------------StackA------------------------------------ //
StackA::StackA()
{
    Top = -1;
}
bool StackA::isEmpty()
{
    return (Top == -1);
}
bool StackA::isFull()
{
    return (Top == max - 1);
}
int StackA::size()
{
    return Top + 1;
}
void StackA::push(int x)
{
    if (!isFull())
    {
        Top++;
        arr[Top] = x;
    }
}
void StackA::pop(int &x)
{
    if (!isEmpty())
    {
        x = arr[Top];
        Top--;
    }
}
int &StackA::top()
{
    return arr[Top];
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
int &StackL::top()
{
    return head->data;
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

// -------------------------------------menu------------------------------------ //
int menu1(char c)
{
    int choice;
    if (c == 'q')
    {
        cout << "\n ================================";
        cout << "\n Vui long chon loai queue de lam viec:";
        cout << "\n 1. Queue bang mang.";
        cout << "\n 2. Queue bang DSLK.";
        cout << "\n 3. Thoat chuong trinh.";
        cout << "\n ================================";
    }
    if (c == 's')
    {
        cout << "\n ================================";
        cout << "\n Vui long chon loai stack de lam viec:";
        cout << "\n 1. Stack bang mang.";
        cout << "\n 2. Stack bang DSLK.";
        cout << "\n 3. Thoat chuong trinh.";
        cout << "\n ================================";
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
int menu2(char c)
{
    int choice;
    if (c == 'q')
    {
        cout << "\n ================================";
        cout << "\n Vui long chon thao tac lam viec voi queue:";
        cout << "\n 1. Enqueue.";
        cout << "\n 2. Dequeue.";
        cout << "\n 3. Kiem tra queue co rong hay khong.";
        cout << "\n 4. Dem so luong phan tu trong queue.";
        cout << "\n 5. Xoa tat ca phan tu trong queue.";
        cout << "\n 6. Dung thao tac voi queue.";
        cout << "\n ================================";
    }
    if (c == 's')
    {
        int choice;
        cout << "\n ================================";
        cout << "\n Vui long chon thao tac lam viec voi stack:";
        cout << "\n 1. Push.";
        cout << "\n 2. Pop.";
        cout << "\n 3. Kiem tra stack co rong hay khong";
        cout << "\n 4. Dem so luong phan tu trong stack.";
        cout << "\n 5. Xoa tat ca phan tu trong stack.";
        cout << "\n 6. Dung thao tac voi stack.";
        cout << "\n ================================";
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
// ------------------------------------menu------------------------------------ //