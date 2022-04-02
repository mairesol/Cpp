#include <iostream>

using namespace std;

#define max 100

class Queue
{
private:
    int arr[max];
    int Front, Rear;

public:
    Queue();
    bool isEmpty();
    int size();
    void enqueue(int);
    void dequeue(int &);
    void clear();
};

int main()
{
    return 0;
}
Queue::Queue()
{
    Front = -1;
    Rear = -1;
}
bool Queue::isEmpty()
{
    return (Front == -1);
}
int Queue::size()
{
    if (isEmpty())
        return 0;
    return Rear - Front + 1;
}
void Queue::enqueue(int x)
{
    int f, r;
    if (Rear - Front + 1 == max) // Nếu queue đầy thật
        return;
    else
    {
        if (isEmpty()) // Nếu queue rỗng
            Front = 0;
        if (Rear == max - 1) // Nếu queue đầy ảo
        {
            f = Front;
            r = Rear;
            for (int i = f; i <= r; i++)
                arr[i - f] = arr[i];
            Front = 0;
            Rear = r - f;
        }
        Rear++;
        arr[Rear] = x;
    }
}
void Queue::dequeue(int &x)
{
    if (!isEmpty()) // Nếu queue không rỗng
    {
        x = arr[Front];
        Front++;
        if (Front > Rear) // Nếu queue có 1 phần tử
        {
            Front = -1;
            Rear = -1;
        }
    }
}
void Queue::clear()
{
    Front = Rear = -1;
}
