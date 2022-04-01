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
    void enqueue(int);
    void dequeue(int &);
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
void Queue::enqueue(int x)
{
    int f, r;
    if (Rear - Front + 1 == max) // Nếu queue đầy thật
        return;
    else
    {
        if (Front == -1) // Nếu queue rỗng
            Front = 0;
        if (Rear == max - 1) // Queue đầy ảo
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
    if (Front != -1) // Nếu queue không rỗng
    {
        x = arr[Front];
        Front++;
        if (Front > Rear) // Queue có 1 phần tử
        {
            Front = -1;
            Rear = -1;
        }
    }
}
