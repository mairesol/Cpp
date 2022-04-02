#include <iostream>

using namespace std;

#define max 100

class Stack
{
private:
    int arr[max];
    int Top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
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
Stack::Stack()
{
    Top = -1;
}
bool Stack::isEmpty()
{
    return (Top == -1);
}
bool Stack::isFull()
{
    return (Top == max - 1);
}
int Stack::size()
{
    return Top + 1;
}
void Stack::push(int x)
{
    if (!isFull())
    {
        Top++;
        arr[Top] = x;
    }
}
void Stack::pop(int &x)
{
    if (!isEmpty())
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
    Top = -1;
}
