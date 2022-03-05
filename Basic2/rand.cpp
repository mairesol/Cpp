/* rand example: guess the number */
#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using namespace std;
void random_range(int &iSecret, int &minN, int &maxN)
{
    cout << "Range: ";
    cin >> minN >> maxN;
    iSecret = minN + rand() % (maxN + 1 - minN);
}
int main()
{
    int iSecret, iGuess;
    int minN, maxN;
    /* initialize random seed: */
    srand(time(NULL));
    /* choose range to generate secret number*/
    random_range(iSecret, minN, maxN);
    do
    {
        cout << "Guess the number from " << minN << " to " << maxN << ": ";
        cin >> iGuess;
        if (iSecret < iGuess)
            puts("The secret number is lower");
        else if (iSecret > iGuess)
            puts("The secret number is higher");
    } while (iSecret != iGuess);
    puts("Congratulations!");
    return 0;
}