#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
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
    void insert_head(Node *);
    void insert_tail(Node *);
    void insert_after(Node *, Node *);
    void insert_before(Node *, Node *);
    void erase_head();
    void erase_tail();
    void erase_after(Node *);
    void erase_before(Node *);
    void erase(int);
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
    l.selection_sort();
    l.output();
    return 0;
}
Node::Node(int d)
{
    data = d;
    next = NULL;
    prev = NULL;
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
    return (head == NULL || tail == NULL);
}
void List ::insert_head(Node *p)
{
    if (empty()) // Nếu list rỗng
        head = tail = p;
    else // Nếu list không rỗng
    {
        p->next = head;
        head->prev = p;
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
        p->prev = tail;
        tail = p;
    }
}
void List ::insert_after(Node *q, Node *p)
{
    if (empty()) // Nếu list rỗng
        head = tail = p;
    else // Nếu list không rỗng
    {
        p->next = q->next;
        p->prev = q;
        q->next = p;
        if (tail == q) // Nếu q là tail
            tail = p;
        else // Nếu q không là tail
            p->next->prev = p;
    }
}
void List ::insert_before(Node *q, Node *p)
{
    if (empty()) // Nếu list rỗng
        head = tail = p;
    else // Nếu list không rỗng
    {
        p->prev = q->prev;
        p->next = q;
        q->prev = p;
        if (head == q) // Nếu q là head
            head = p;
        else // Nếu q không là head
            p->prev->next = p;
    }
}
void List ::erase_head()
{
    if (!empty()) // Nếu list không rỗng
    {
        Node *p = head;
        head = head->next;
        head->prev = NULL;
        delete p;
        if (empty()) // Nếu sau khi xoá list rỗng
            tail = NULL;
    }
}
void List ::erase_tail()
{
    if (!empty()) // Nếu list không rỗng
    {
        Node *p = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete p;
        if (empty()) // Nếu sau khi xoá list rỗng
            head = NULL;
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
            if (p == tail) // Nếu p la tail
                tail = q;
            else // Nếu p khong la tail
                p->next->prev = q;
            delete p;
        }
    }
}
void List ::erase_before(Node *q)
{
    if (q != NULL) // Nếu list không rỗng
    {
        Node *p = q->prev;
        if (p != NULL) // Nếu q không là head
        {
            q->prev = p->prev;
            if (p == head) // Nếu p la head
                head = q;
            else // Nếu p khong la head
                p->prev->next = q;
            delete p;
        }
    }
}
void List ::erase(int x)
{
    Node *p = head, *q = NULL;
    while (p != NULL && p->data != x)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL) // Nếu list không có x
        return;
    if (q != NULL) // Nếu head không chứa x
        erase_after(q);
    else // Nếu head chứa x
        erase_head();
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
            swap(p->data, min->data);
        }
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