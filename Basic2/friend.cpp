#include <iostream>

using namespace std;

class Box
{
private:
    int length;

public:
    Box(int length = 0)
    {
        this->length = length;
    }
    friend int printLength(Box);
    /*
    Hàm không nằm trong phạm vi của lớp mà nó đã được khai báo là friend.
    Nó không thể được gọi bằng cách sử dụng đối tượng vì nó không nằm trong phạm vi của lớp đó.
    Nó có thể được gọi như một hàm bình thường mà không cần sử dụng đối tượng.
    Nó không thể truy cập trực tiếp vào tên thành viên và phải sử dụng tên đối tượng và dấu chấm toán tử với tên thành viên.
    Nó có thể được khai báo trong phần private hoặc public.
    */
};

int printLength(Box b)
{
    b.length += 10;
    return b.length;
}

class A
{
    int x = 5;
    friend class B;
};
class B
{
public:
    void display(A &a)
    {
        cout << "Gia tri cua x la: " << a.x;
    }
};
int main()
{
    Box c;
    cout << "Chieu dai cua box: " << printLength(c) << endl;

    A a;
    B b;
    b.display(a);
    return 0;
}