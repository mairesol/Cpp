#include <iostream>

using namespace std;

#define max 1000

class Queue
{
private:
    int arr[max];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void de_queue(int &);
    void en_queue(int);
};

int main()
{

    return 0;
}
void Queue::de_queue(int &x)
{
    if (front != -1) // Nếu queue không rỗng
    {
        x = arr[front];
        front++;
        if (front > rear) // Queue có 1 phần tử
        {
            front = -1;
            rear = -1;
        }
    }
}
void Queue::en_queue(int x)
{
    int f, r;
    if (rear - front + 1 == max) // Queue đầy thật
        return;
    else
    {
        if (front == -1) // Nếu queue rỗng
            front = rear = 0;
        if (rear == max - 1) // Queue đầy ảo
        {
            f = front;
            r = rear;
            for (int i = f; i <= r; i++)
                arr[i - f] = arr[i];
            front = 0;
            rear = r - f;
        }
        rear++;
        arr[rear] = x;
    }
}
