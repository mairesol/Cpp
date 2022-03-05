// dataType arrayName[arraySize];
// khi truy xuất một phần tử mảng, luôn đảm bảo chỉ số của phần tử đó là hợp lệ trong phạm vi của mảng. //
#include <iostream>
using namespace std;
// Dung & để chỉnh tham tri thanh tham chieu
void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int numbers[n];
    double sum = 0;
    double count = 0;
    double average;

    cout << "Enter 5 numbers: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << ": ";
        cin >> numbers[i];
        if (numbers[i] != 0)
        {
            count++;
        }
    }

    cout << "The numbers are: ";
    for (int i = 0; i < n; ++i)
    {
        cout << numbers[i] << "  ";
        sum += numbers[i];
    }

    average = sum / count;
    cout << "\nSum: " << sum << endl;
    cout << "Average: " << average << endl;

    // Sap xep tu be den lon cac phan tu
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (numbers[i] > numbers[j])
                swap(numbers[i], numbers[j]);
        }
    }
    cout << "Sort: ";
    for (int i = 0; i < n; ++i)
    {
        cout << numbers[i] << "  ";
    }
    return 0;
}