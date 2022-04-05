#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0);
};

class Stack
{
private:
    Node *head;
    Node *tail;

public:
    Stack();
    ~Stack();
    bool empty();
    int size();
    void push(Node *);
    void pop(int &);
    int &top();
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
Stack::Stack()
{
    head = tail = NULL;
}
Stack::~Stack()
{
    clear();
}
bool Stack ::empty()
{
    return (head == NULL);
}
int Stack::size()
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
void Stack ::push(Node *p)
{
    if (empty()) // Nếu stack rỗng
        head = tail = p;
    else // Nếu stack không rỗng
    {
        p->next = head;
        head = p;
    }
}
void Stack ::pop(int &x)
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
int &Stack::top()
{
    return head->data;
}
void Stack ::clear()
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
