#include <iostream>

using namespace std;

bool menu_yet = false;
int menu1();
int menu2();

class QueueA
{
private:
    int Front, Rear;
    int capacity;
    int *arr;

public:
    QueueA(int = 10);
    ~QueueA();
    bool empty();
    int size();
    void enqueue(int);
    void dequeue(int &);
    void clear();
    friend void program(QueueA &);
};

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0);
};

class QueueL
{
private:
    Node *head;
    Node *tail;

public:
    QueueL();
    ~QueueL();
    bool empty();
    int size();
    void enqueue(Node *);
    void dequeue(int &);
    void clear();
    friend void program(QueueL &);
};

int main()
{
    int choice;
    bool flag = true;
    while (flag)
    {
        choice = menu1();
        QueueA qA;
        QueueL qL;
        switch (choice)
        {
        case 1:
            cout << "\n============ Queue bang array ============";
            program(qA);
            break;
        case 2:
            cout << "\n============ Queue bang linked list ============";
            program(qL);
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
void program(QueueA &qA)
{
    int x, choice;
    bool flag = true;
    while (flag)
    {
        choice = menu2();
        switch (choice)
        {
        case 1:
            cout << "\nEnqueue: ";
            cin >> x;
            qA.enqueue(x);
            break;
        case 2:
            cout << "\nDequeue: ";
            if (!qA.empty())
            {
                qA.dequeue(x);
                cout << x;
            }
            break;
        case 3:
            if (qA.empty())
                cout << "\nQueue rong.";
            else
                cout << "\nQueue khong rong";
            break;
        case 4:
            cout << "\nQueue co " << qA.size() << " phan tu.";
            break;
        case 5:
            qA.clear();
            cout << "\nDa xoa tat ca phan tu cua queue.";
            break;
        case 6:
            ::menu_yet = false;
            break;
        case 7:
            qA.clear();
            cout << "\nDa dung thao tac voi queue.";
            flag = ::menu_yet = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }
}
void program(QueueL &qL)
{
    int x, choice;
    bool flag = true;
    while (flag)
    {
        choice = menu2();
        switch (choice)
        {
        case 1:
            cout << "\nEnqueue: ";
            cin >> x;
            qL.enqueue(new Node(x));
            break;
        case 2:
            cout << "\nDequeue: ";
            if (!qL.empty())
            {
                qL.dequeue(x);
                cout << x;
            }
            break;
        case 3:
            if (qL.empty())
                cout << "\nQueue rong.";
            else
                cout << "\nQueue khong rong";
            break;
        case 4:
            cout << "\nQueue co " << qL.size() << " phan tu.";
            break;
        case 5:
            qL.clear();
            cout << "\nDa xoa tat ca phan tu cua queue.";
            break;
        case 6:
            ::menu_yet = false;
            break;
        case 7:
            qL.clear();
            cout << "\nDa dung thao tac voi queue.";
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

// ------------------------------------QueueA------------------------------------ //
QueueA::QueueA(int c)
{
    capacity = c;
    arr = new int[capacity];
    Front = Rear = -1;
}
QueueA::~QueueA()
{
    clear();
}
bool QueueA::empty()
{
    return (Front == -1);
}
int QueueA::size()
{
    if (empty())
        return 0;
    return Rear - Front + 1;
}
void QueueA::enqueue(int x)
{
    int f, r;
    if (Rear - Front + 1 <= capacity) // Nếu queue không đầy thật
    {
        if (empty()) // Nếu queue rỗng thật
            Front = 0;
        if (Rear == capacity - 1) // Nếu queue đầy ảo
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
    if (!empty()) // Nếu queue không rỗng
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
    if (!empty())
        delete[] arr;
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

// ------------------------------------menu------------------------------------ //
int menu1()
{
    int choice;
    cout << "\n ================================";
    cout << "\n Vui long chon loai queue de lam viec:";
    cout << "\n 1. Queue bang mang.";
    cout << "\n 2. Queue bang DSLK.";
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
        cout << "\n Vui long chon thao tac lam viec voi queue:";
        cout << "\n 1. Enqueue.";
        cout << "\n 2. Dequeue.";
        cout << "\n 3. Kiem tra queue co rong hay khong.";
        cout << "\n 4. Dem so luong phan tu trong queue.";
        cout << "\n 5. Xoa tat ca phan tu trong queue.";
        cout << "\n 6. Xem lai menu.";
        cout << "\n 7. Dung thao tac voi queue.";
        cout << "\n ================================";
        ::menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}