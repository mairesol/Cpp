#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long int ul;

using namespace std;
class Product
{
private:
    int quantity;
    float price;

public:
    Product(int q, float p)
    {
        quantity = p;
        price = q;
    }
};
typedef Product P;

struct codelearn
{
    void print()
    {
        cout << "code learn" << endl;
    }
};
typedef codelearn cl;

#define number int
#define loop(i, a, n) for (int i = a; i < n; i++)
#define pub push_back
#define pob pop_back
#define PI = 3.14159
int main()
{
    ll val = 100000000;
    db val1 = 1.1;
    ul val2 = 1000000000;
    cout << val << endl;
    cout << val1 << endl;
    cout << val2 << endl;

    P p1(5, 3.99);
    cl cl1;
    cl1.print();

    number n; // khai báo biến n kiểu int
    cout << "N = ";
    cin >> n;
    vector<int> arr; // tạo 1 vector arr kiểu int
    // tạo giá trị cho các phần tử của vector
    loop(i, 0, n)
    {
        arr.pub(i);
    }
    arr.pob(); // xóa phần tử cuối cùng của vector arr
    // in ra các giá trị của vector arr
    loop(i, 0, arr.size())
    {
        cout << arr[i] << " ";
    }
    return 0;
}
