#include <iostream>

using namespace std;

class Box
{
private:
    double length;
    double width;
    double height;

public:
    Box(double length, double width, double height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    double Volume()
    {
        return length * width * height;
    }

    int Compare(Box box)
    {
        if (this->Volume() > box.Volume())
            return 1;
        else if (this->Volume() > box.Volume())

            return 0;
        else
            return -1;
    }
};

int main(void)
{
    Box box1 = Box(2.5, 4, 2);
    Box box2 = Box(4.5, 2, 3);

    if (box1.Compare(box2) == 1)
    {
        cout << "Box1 co the tich lon hon Box2" << endl;
    }
    else if (box1.Compare(box2) == 0)
    {
        cout << "Box1 co the tich bang Box2" << endl;
    }
    else
    {
        cout << "Box1 co the tich nho hon Box2" << endl;
    }
    return 0;
}