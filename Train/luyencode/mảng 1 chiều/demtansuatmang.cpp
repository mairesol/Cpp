#include <bits/stdc++.h>

using namespace std;

void input(vector<int> &vect)
{
    int a;
    for (auto it = vect.begin(); it != vect.end(); it++)
    {
        cin >> a;
        *it = a;
    }
}
int find(vector<int> &vect, vector<int>::iterator x)
{
    for (auto it = vect.begin(); it != vect.end(); it++)
    {
        if (*it == *x)
            return it - vect.begin();
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vect(n);
    input(vect);

    vector<int> key;
    vector<int> value;
    for (auto it = vect.begin(); it != vect.end(); it++)
    {
        if (find(key, it) == -1)
        {
            key.push_back(*it);
            value.push_back(0);
        }
        value.at(find(key, it))++;
    }
    cout << key.size() << endl;
    for (int i = 0; i < key.size(); i++)
    {
        cout << key.at(i) << " " << value.at(i) << endl;
    }
    return 0;
}