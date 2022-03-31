#include <iostream>

using namespace std;

class CTimeSpan
{
private:
    int hour, minute, second;

public:
    CTimeSpan(int h = 0, int m = 0, int s = 0)
    {
        hour = (h < 0 || h > 23) ? 0 : h;
        minute = (m < 0 || m > 59) ? 0 : m;
        second = (s < 0 || s > 59) ? 0 : s;
    }
    ~CTimeSpan();
    void nhap()
    {
        cin >> hour >> minute >> second;
    }
    void xuat()
    {
        if (hour < 0 || minute < 0 || second < 0)
            cout << "Error time";
        else
        {
            cout << (hour < 10 && hour >= 0 ? "0" : "") << hour
                 << ":" << (minute < 10 && minute >= 0 ? "0" : "") << minute
                 << ":" << (second < 10 && second >= 0 ? "0" : "") << second;
        }
    }
};

int main()
{
    return 0;
}