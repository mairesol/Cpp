#include <iostream>
using namespace std;

int main()
{
    int nama1, nama2, namb1, namb2;
    int ngaa1, ngaa2, ngab1, ngab2;

    cin >> nama1 >> nama2 >> namb1 >> namb2;
    cin >> ngaa1 >> ngaa2 >> ngab1 >> ngab2;
    float average_nam = static_cast<float>(nama1 + nama2 + namb1 + namb2) / 2;
    float average_nga = static_cast<float>(ngaa1 + ngaa2 + ngab1 + ngab2) / 2;
    if (float(average_nam) > float(average_nga))
        cout << "Nam";
    else if (float(average_nam) < float(average_nga))
        cout << "Nga";
    else
        cout << "Tie";
    return 0;
}