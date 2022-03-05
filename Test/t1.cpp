#include <iostream>
#include <vector>
using namespace std;
class POINT
{
private:
    int x;
    int y;

public:
    void input()
    {
        cin >> x >> y;
    }
    int square_distance(POINT temp)
    {
        return (temp.x - x) * (temp.x - x) + (temp.y - y) * (temp.y - y);
    }
};

class CIRCLE
{
private:
    POINT center;
    int radius;

public:
    bool contain(POINT temp)
    {
        return center.square_distance(temp) < radius * radius;
    }
    void input()
    {
        center.input();
        cin >> radius;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<POINT> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].input();
    }
    CIRCLE C;
    C.input();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (C.contain(arr[i]))
        {
            count += 1;
        }
    }
    cout << count;
}
