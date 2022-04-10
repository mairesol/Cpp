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
private:
    Node *head;
    Node *tail;

public:
    Queue();
    ~Queue();
    bool empty();
    int size();
    void enqueue(int);
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
int Queue ::size()
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
void Queue ::enqueue(int x)
{
    Node *p = new Node(x);
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
