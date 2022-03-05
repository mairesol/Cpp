#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main()
{
    int A, B, C, D, E, F, G, H;
    cin >> A >> B >> C >> D >> E >> F >> G >> H;

    if (A > C)
        swap(A, C);
    if (B > D)
        swap(B, D);
    if (E > G)
        swap(E, G);
    if (F > H)
        swap(F, H);

    // Dien tich hinh chu nhat 1
    ull s1 = (C - A) * (D - B);
    // Dien tich hinh chu nhat 2
    ull s2 = (G - E) * (H - F);
    // Xet be ngang:
    ull ngang;
    if (C <= E || G <= A)
        ngang = 0;
    else if (A <= E && C <= G)
        ngang = C - E;
    else if (E <= A && G <= C)
        ngang = G - A;
    else if (A < E && G < C)
        ngang = G - E;
    else if (E < A && C < G)
        ngang = C - A;
    // Xet be doc:
    ull doc;
    if (B >= H || D <= F)
        doc = 0;
    else if (B >= F && D >= H)
        doc = H - B;
    else if (H >= D && F >= B)
        doc = D - F;
    else if (F < B && D < H)
        doc = D - B;
    else if (B < F && H < D)
        doc = H - F;
    cout << ngang * doc;
    return 0;
}
