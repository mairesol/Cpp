#include <iostream>
#include <algorithm>
#include <math.h>
typedef unsigned long long ull;
using namespace std;
int main()
{
    ull money;
    cin >> money;
    money /= 10000;
    ull cnt = 0, less_notes = 0;
    for (long note50 = 0; note50 <= money / 50; note50++)
    {
        ull remain_without_50 = money - 50 * note50;
        for (long note20 = 0; note20 <= remain_without_50 / 20; note20++)
        {
            ull remain_without_20 = remain_without_50 - 20 * note20;
            for (long note10 = 0; note10 <= remain_without_20 / 10; note10++)
            {
                ull remain_without_10 = remain_without_20 - 10 * note10;
                for (long note5 = 0; note5 <= remain_without_10 / 5; note5++)
                {
                    ull remain_without_5 = remain_without_10 - 5 * note5;
                    if (remain_without_5 % 2 == 0)
                    {
                        cnt++;
                        ull notes = (note50 + note20 + note10 + note5 + remain_without_5 / 2);
                        if (less_notes != 0)
                            less_notes = min(less_notes, notes);
                        else
                            less_notes = notes;
                    }
                }
            }
        }
    }
    cout << cnt << " " << less_notes;
    return 0;
}
