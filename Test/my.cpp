#include <iostream>
#include <vector>

using namespace std;

class DaThuc
{
private:
    int *ptr;
    int bacdathuc;

public:
    DaThuc(int = 0);
    DaThuc(const DaThuc &);
    ~DaThuc();
    friend bool operator==(const DaThuc &, const DaThuc &);
    friend bool operator!=(const DaThuc &, const DaThuc &);
    const DaThuc &operator=(const DaThuc &);
};

int main()
{
    return 0;
}
DaThuc::DaThuc(int b)
{
    bacdathuc = b;
    ptr = new int[bacdathuc + 1];
    for (int i = 0; i <= bacdathuc; i++)
        ptr[i] = 0;
}
DaThuc::DaThuc(const DaThuc &rhs)
{
    bacdathuc = rhs.bacdathuc;
    ptr = new int[bacdathuc + 1];
    for (int i = 0; i <= bacdathuc; i++)
        ptr[i] = rhs.ptr[i];
}
DaThuc::~DaThuc()
{
    delete[] ptr;
}
bool operator==(const DaThuc &lhs, const DaThuc &rhs)
{
    if (lhs.bacdathuc != rhs.bacdathuc)
        return false;
    for (int i = 0; i <= lhs.bacdathuc; i++)
        if (lhs.ptr[i] != rhs.ptr[i])
            return false;
    return true;
}
bool operator!=(const DaThuc &lhs, const DaThuc &rhs)
{
    return !(lhs == rhs);
}
const DaThuc &DaThuc::operator=(const DaThuc &rhs)
{
    if (*this != rhs)
    {
        if (bacdathuc != rhs.bacdathuc)
        {
            delete[] ptr;
            bacdathuc = rhs.bacdathuc;
            ptr = new int[bacdathuc];
        }
        for (int i = 0; i <= bacdathuc; i++)
            ptr[i] = rhs.ptr[i];
    }
    return *this;
}
