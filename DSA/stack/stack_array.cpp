#include <iostream>

using namespace std;

class Stack
{
private:
    int Top;
    int capacity;
    int *arr;

public:
    Stack(int = 10);
    ~Stack();
    bool empty();
    bool full();
    int size();
    void push(int);
    void pop(int &);
    int &top();
    void clear();
};

int main()
{
    return 0;
}
Stack::Stack(int c)
{
    capacity = c;
    arr = new int[capacity];
    Top = -1;
}
Stack::~Stack()
{
    clear();
}
bool Stack::empty()
{
    return (Top == -1);
}
bool Stack::full()
{
    return (Top == capacity - 1);
}
int Stack::size()
{
    return Top + 1;
}
void Stack::push(int x)
{
    if (!full())
    {
        Top++;
        arr[Top] = x;
    }
}
void Stack::pop(int &x)
{
    if (!empty())
    {
        x = arr[Top];
        Top--;
    }
}
int &Stack::top()
{
    return arr[Top];
}
void Stack::clear()
{
    if (!empty())
        delete[] arr;
    Top = -1;
}
