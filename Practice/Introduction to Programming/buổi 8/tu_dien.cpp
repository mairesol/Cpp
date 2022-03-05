#include <iostream>
#include <string.h>

#define MAXROW 1000
#define MAXCOL 11

struct Dictionary
{
    char english[MAXCOL];
    char strange[MAXCOL];
};

using namespace std;
int main()
{
    int m, n;

    cin >> m >> n;

    // Từ điển
    Dictionary dict[MAXROW];
    for (int i = 0; i < n; i++)
        cin >> dict[i].english >> dict[i].strange;

    // Tra cứu
    char search[MAXCOL];
    for (int i = 0; i < m; i++)
    {
        cin >> search;
        bool flag = 0;
        for (int j = 0; j < n; j++) // Quét trong từ điển
            if (strcmp(search, dict[j].strange) == 0)
            {
                cout << dict[j].english << endl;
                flag = 1;
                break;
            }
        if (flag == 0)
            cout << "eh" << endl;
    }

    return 0;
}
