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
    Hàm bạn là một hàm có thể truy cập đến các thành viên private (gồm cả các biến thành viên và các hàm thành viên) của một class,
    như thể nó là một thành viên của class đó. Ngoại trừ đặc điểm ở trên ra thì hàm bạn hoàn toàn giống với hàm bình thường.
    Một hàm bạn có thể chỉ là một hàm bình thường, hoặc là một hàm thành viên của một class khác. Để khai báo một hàm bạn,
    chỉ cần sử dụng từ khóa friend ở trước phần nguyên mẫu (prototype) của hàm mà bạn muốn nó trở thành bạn của class.
    Có thể khai báo hàm bạn bên trong phần public (công khai) hoặc phần private (riêng tư) của class đều được.
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