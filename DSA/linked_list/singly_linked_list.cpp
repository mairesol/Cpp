#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int = 0);
};

class List
{
public:
    Node *head;
    Node *tail;
    List();
    List(Node *, Node *);
    List(List &);
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
    Node *search(int);
    void clear();
    void selection_sort();

    void input();
    void output();
};
int main()
{
    List l;
    l.input();
    l.clear();
    return 0;
}
Node::Node(int d)
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
List::List(List &l)
{
    head = l.head;
    tail = l.tail;
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
        head = tail = p;
    else // Nếu list không rỗng
    {
        tail->next = p;
        tail = p;
    }
}
void List ::insert_after(Node *q, Node *p)
{
    if (q != NULL)
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
    if (q != NULL)
    {
        Node *p = q->next;
        if (p != NULL) // Nếu q không là tail
        {
            q->next = p->next;
            if (p == tail) // Nếu p la tail
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
    if (p != NULL) // Nếu list không có x
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
Node *List ::search(int x)
{
    Node *p = head;
    while (p != NULL && p->data != x)
        p = p->next;
    return p;
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

void List ::selection_sort()
{
    Node *min;
    for (Node *p = head; p != tail; p = p->next)
    {
        min = p;
        for (Node *q = p->next; q != NULL; q = q->next)
        {
            if (q->data < min->data)
                min = q;
        }
        swap(p->data, min->data);
    }
}
void List::input()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *p = new Node(x);
        if (p != NULL)
            insert_tail(p);
    }
}
void List::output()
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}