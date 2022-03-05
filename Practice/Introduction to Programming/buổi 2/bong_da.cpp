#include <iostream>
using namespace std;

int main()
{
    int t1gf1, t1ga1, t1yr1;
    int t1gf2, t1ga2, t1yr2;
    int t1gf3, t1ga3, t1yr3;
    int t2gf1, t2ga1, t2yr1;
    int t2gf2, t2ga2, t2yr2;
    int t2gf3, t2ga3, t2yr3;

    cin >> t1gf1 >> t1ga1 >> t1yr1;
    cin >> t1gf2 >> t1ga2 >> t1yr2;
    cin >> t1gf3 >> t1ga3 >> t1yr3;
    cin >> t2gf1 >> t2ga1 >> t2yr1;
    cin >> t2gf2 >> t2ga2 >> t2yr2;
    cin >> t2gf3 >> t2ga3 >> t2yr3;

    // Doi 1
    int point_t1 = 0, goaldiff_t1 = 0, goalf_t1 = 0, yellow_t1 = 0;
    // Diem
    if (t1gf1 > t1ga1)
        point_t1 += 3;
    else if (t1gf1 == t1ga1)
        point_t1 += 1;
    else
        point_t1 += 0;
    if (t1gf2 > t1ga2)
        point_t1 += 3;
    else if (t1gf2 == t1ga2)
        point_t1 += 1;
    else
        point_t1 += 0;
    if (t1gf3 > t1ga3)
        point_t1 += 3;
    else if (t1gf3 == t1ga3)
        point_t1 += 1;
    else
        point_t1 += 0;
    // Hieu so ban thang
    goaldiff_t1 = (t1gf1 - t1ga1) + (t1gf2 - t1ga2) + (t1gf3 - t1ga3);
    // So ban thang
    goalf_t1 = t1gf1 + t1gf2 + t1gf3;
    // So the vang
    yellow_t1 = t1yr1 + t1yr2 + t1yr3;
    // cout << point_t1 << " " << goaldiff_t1 << " " << goalf_t1 << " " << yellow_t1 << endl;
    /*
    
    */
    // Doi 2
    int point_t2 = 0, goaldiff_t2 = 0, goalf_t2 = 0, yellow_t2 = 0;
    // Diem
    if (t2gf1 > t2ga1)
        point_t2 += 3;
    else if (t2gf1 == t2ga1)
        point_t2 += 1;
    else
        point_t2 += 0;
    if (t2gf2 > t2ga2)
        point_t2 += 3;
    else if (t2gf2 == t2ga2)
        point_t2 += 1;
    else
        point_t2 += 0;
    if (t2gf3 > t2ga3)
        point_t2 += 3;
    else if (t2gf3 == t2ga3)
        point_t2 += 1;
    else
        point_t2 += 0;
    // Hieu so ban thang
    goaldiff_t2 = (t2gf1 - t2ga1) + (t2gf2 - t2ga2) + (t2gf3 - t2ga3);
    // So ban thang
    goalf_t2 = t2gf1 + t2gf2 + t2gf3;
    // So the vang
    yellow_t2 = t2yr1 + t2yr2 + t2yr3;
    // cout << point_t2 << " " << goaldiff_t2 << " " << goalf_t2 << " " << yellow_t2 << endl;

    // Thanh tich
    if (point_t1 > point_t2) // Diem so
        cout << point_t1 << " " << goaldiff_t1 << " " << goalf_t1 << " " << yellow_t1 << endl;
    else if (point_t1 < point_t2)
        cout << point_t2 << " " << goaldiff_t2 << " " << goalf_t2 << " " << yellow_t2 << endl;
    else // Hieu so ban thang
    {
        if (goaldiff_t1 > goaldiff_t2)
            cout << point_t1 << " " << goaldiff_t1 << " " << goalf_t1 << " " << yellow_t1 << endl;
        else if (goaldiff_t1 < goaldiff_t2)
            cout << point_t2 << " " << goaldiff_t2 << " " << goalf_t2 << " " << yellow_t2 << endl;
        else // So ban thang
        {
            if (goalf_t1 > goalf_t2)
                cout << point_t1 << " " << goaldiff_t1 << " " << goalf_t1 << " " << yellow_t1 << endl;
            else if (goalf_t1 < goalf_t2)
                cout << point_t2 << " " << goaldiff_t2 << " " << goalf_t2 << " " << yellow_t2 << endl;
            else // Chi so fair play
            {
                if (yellow_t1 < yellow_t2)
                    cout << point_t1 << " " << goaldiff_t1 << " " << goalf_t1 << " " << yellow_t1 << endl;
                else if (yellow_t1 > yellow_t2)
                    cout << point_t2 << " " << goaldiff_t2 << " " << goalf_t2 << " " << yellow_t2 << endl;
            }
        }
    }
    return 0;
}