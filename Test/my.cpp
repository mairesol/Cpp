#include <iostream>
#include <algorithm>

using namespace std;

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
    ~Node()
    {
        this->data = 0;
        delete next;
    }
};

class List
{
public:
    Node *head;
    Node *tail;
    List();
    List(Node *h, Node *t);
    ~List()
    {
        clear();
    };
    bool empty();
    void insert_head(Node *);
    void insert_tail(Node *);
    void insert_after(Node *, Node *);
    int erase_head();
    int erase_after(Node *);
    int find_and_erase_after(int);
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

List::List()
{
    head = tail = NULL;
}
List::List(Node *h, Node *t)
{
    head = h;
    tail = t;
}

bool List ::empty()
{
    return (head == NULL);
}
void List ::insert_head(Node *node)
{
    if (empty())
        head = tail = node;
    else
    {
        node->next = head;
        head = node;
    }
}
void List ::insert_tail(Node *node)
{
    if (empty())
        head = tail = node;
    else
    {
        tail->next = node;
        tail = node;
    }
}
void List ::insert_after(Node *benode, Node *node)
{
    if (benode == NULL)
        insert_head(node);
    else
    {
        node->next = benode->next;
        benode->next = node;
        if (tail == benode)
            tail = node;
    }
}
int List ::erase_head()
{
    if (empty())
        return 0;
    else
    {
        Node *node = head;
        head = node->next;
        delete node;
        if (empty())
            tail = NULL;
        return 1;
    }
}
int List ::erase_after(Node *benode)
{
    if (benode == NULL)
        return 0;
    else
    {
        Node *node = benode->next;
        if (node != NULL)
        {
            benode->next = node->next;
            if (node == tail)
                tail = benode;
            delete node;
        }
        return 1;
    }
}
int List ::find_and_erase_after(int x)
{
    Node *node = head, *benode = NULL;
    while (node != NULL && node->data != x)
    {
        benode = node;
        node = node->next;
    }
    if (node == NULL)
        return 0;
    if (benode != NULL)
        erase_after(benode);
    else
        erase_head();
    return 1;
}
Node *List ::search(int x)
{
    Node *node = head;
    while (node != NULL && node->data != x)
        node = node->next;
    return node;
}

void List ::clear()
{
    Node *node;
    while (!empty())
    {
        node = head;
        head = node->next;
        delete node;
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