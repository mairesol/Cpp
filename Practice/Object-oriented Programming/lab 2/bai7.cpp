#include <iostream>

using namespace std;

class Time
{
private:
    int hour, minute, second;

public:
    Time(int = 0, int = 0, int = 0);
    void input();
    void output();
    void incre_1_s();
};

int main()
{
    return 0;
}

Time::Time(int h, int m, int s)
{
    hour = h % 24;
    minute = m % 60;
    second = s % 60;
}
void Time::input()
{
    cin >> hour >> minute >> second;
}
void Time::output()
{
    cout << (hour < 10 ? "0" : "") << hour << ":"
         << (minute < 10 ? "0" : "") << minute << ":"
         << (second < 10 ? "0" : "") << second;
}
void Time::incre_1_s()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
    }
    if (minute == 60)
    {
        minute = 0;
        hour++;
    }
    if (hour == 24)
        hour = 0;
}
