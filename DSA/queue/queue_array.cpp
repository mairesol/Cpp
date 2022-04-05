#include <iostream>

using namespace std;

class Queue
{
private:
    int Front, Rear;
    int capacity;
    int *arr;

public:
    Queue(int = 10);
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
Queue::Queue(int c)
{
    capacity = c;
    arr = new int[capacity];
    Front = Rear = -1;
}
Queue::~Queue()
{
    delete[] arr;
}
bool Queue::empty()
{
    return (Front == -1);
}
int Queue::size()
{
    if (empty())
        return 0;
    return Rear - Front + 1;
}
void Queue::enqueue(int x)
{
    int f, r;
    if (Rear - Front + 1 <= capacity) // Nếu queue không đầy thật
    {
        if (empty()) // Nếu queue rỗng thật
            Front = 0;
        if (Rear == capacity - 1) // Nếu queue đầy ảo
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
    if (!empty()) // Nếu queue không rỗng
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
int &Queue::front()
{
    return arr[Front];
}
int &Queue::back()
{
    return arr[Rear];
}
void Queue::clear()
{
    Front = Rear = -1;
}
