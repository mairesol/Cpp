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
    void push(Node *);
    void pop(int &);
    void clear();
};

int main()
{
    int n, x;
    Stack s;
    cout << "Input: ";
    do
    {
        cin >> n;
    } while (n < 0);

    while (n > 0)
    {
        s.push(new Node(n % 2));
        n /= 2;
    }
    cout << "Result: ";
    while (!s.empty())
    {
        s.pop(x);
        cout << x;
    }
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