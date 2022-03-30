#include <iostream>

using namespace std;

#define max 1000

class Stack
{
private:
    int arr[max];
    int t;

public:
    Stack()
    {
        t = -1;
    }
    bool isEmpty();
    bool isFull();
    void push(int);
    void pop(int &);
    int top();
};

int main()
{

    return 0;
}

bool Stack::isEmpty()
{
    return (t == -1);
}
bool Stack::isFull()
{
    return (t >= max);
}
void Stack::push(int x)
{
    if (!isFull())
    {
        t++;
        arr[t] = x;
    }
}
void Stack::pop(int &x)
{
    if (!isEmpty())
    {
        x = arr[t];
        t--;
    }
}
int Stack::top()
{
    return arr[t];
}
