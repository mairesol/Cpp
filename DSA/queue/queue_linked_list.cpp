#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0);
};

class Queue
{
public:
    Node *head;
    Node *tail;
    Queue();
    ~Queue();
    bool empty();
    void enqueue(Node *);
    void dequeue(int &);
    int &front();
    int &back();
    void clear();
};

int main()
{
    return 0;
}
Node::Node(int d)
{
    data = d;
    next = NULL;
}
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
void Queue ::enqueue(Node *p)
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
        Node *p = head;
        head = head->next;
        x = p->data;
        delete p;
        if (empty()) // Nếu sau khi xoá queue rỗng
            tail = NULL;
    }
}
int &Queue::front()
{
    return head->data;
}
int &Queue::back()
{
    return tail->data;
}
void Queue ::clear()
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
