#include <iostream>
#include <string.h>

using namespace std;

class CString
{
private:
    char *str;
    int size;

public:
    CString(const char *);
    CString(int = 256, char = 0);
    ~CString();

    CString operator+(const CString &);
    CString &operator=(const CString &);

    bool operator==(const CString &);
    bool operator!=(const CString &);
    bool operator>(const CString &);
    bool operator>=(const CString &);
    bool operator<(const CString &);
    bool operator<=(const CString &);

    char &operator[](int);
    friend istream &operator>>(istream &, CString &);
    friend ostream &operator<<(ostream &, const CString &);
};

int main()
{
    return 0;
}
CString::CString(const char *s)
{
    size = strlen(s);
    str = new char[size];
    memcpy(str, s, size);
}
CString::CString(int t, char c)
{
    size = t;
    str = new char[size];
    memset(str, c, size);
}
CString::~CString()
{
    delete[] str;
    str = NULL;
}

CString CString::operator+(const CString &obj)
{
    CString sa = *this;
    sa.size += obj.size;
    strncat(sa.str, obj.str, obj.size);
    return sa;
}
CString &CString::operator=(const CString &obj)
{
    size = obj.size;
    memcpy(str, obj.str, size);
    return *this;
}

bool CString::operator==(const CString &obj)
{
    if (strcmp(str, obj.str) == 0)
        return true;
    return false;
}
bool CString::operator!=(const CString &obj)
{
    return !(*this == obj);
}
bool CString::operator>(const CString &obj)
{
    if (strcmp(str, obj.str) > 0)
        return true;
    return false;
}
bool CString::operator>=(const CString &obj)
{
    return !(*this < obj);
}
bool CString::operator<(const CString &obj)
{
    if (strcmp(str, obj.str) < 0)
        return true;
    return false;
}
bool CString::operator<=(const CString &obj)
{
    return !(*this > obj);
}

char &CString::operator[](int t)
{
    return str[t];
}
istream &operator>>(istream &is, CString &obj)
{
    cin.getline(obj.str, obj.size);
    return is;
}
ostream &operator<<(ostream &os, const CString &obj)
{
    cout << obj.str;
    return os;
}
