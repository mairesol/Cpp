#include <bits/stdc++.h>
using namespace std;

bool menu_yet = false;
int menu();

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction
{
public:
    int num, den;
    Fraction(int num = 0, int den = 1)
    {
        this->num = num;
        this->den = den;
    }
    ~Fraction()
    {
        this->num = 0;
        this->den = 0;
    }
    void input();
    void simplify();
    void standard();
    void output();
    Fraction operator+(Fraction p)
    {
        Fraction ans;
        ans.num = num * p.den + p.num * den;
        ans.den = den * p.den;
        ans.standard();
        return ans;
    }
    Fraction operator-(Fraction p)
    {
        Fraction ans;
        ans.num = num * p.den - p.num * den;
        ans.den = den * p.den;
        ans.standard();
        return ans;
    }
    Fraction operator*(Fraction p)
    {
        Fraction ans;
        ans.num = num * p.num;
        ans.den = den * p.den;
        ans.standard();
        return ans;
    }
    Fraction operator/(Fraction p)
    {
        Fraction ans;
        ans.num = num * p.den;
        ans.den = den * p.num;
        ans.standard();
        return ans;
    }
    bool operator<(Fraction p)
    {
        return (num * p.den < p.num * den);
    }
    bool operator>(Fraction p)
    {
        return (num * p.den > p.num * den);
    }
};

void swap(Fraction &, Fraction &);
Fraction max(Fraction, Fraction);
Fraction max_element(Fraction *, int);

void input(Fraction *, int);
void output(Fraction *, int);

int main()
{
    Fraction p, p1, p2;
    Fraction ans;
    Fraction *arr;
    bool flag = true;

    while (flag)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            // Nhap 2 phan so, tim phan so lon nhat va xuat ket qua ra man hinh
            cout << "Nhap phan so thu nhat: ";
            p1.input();
            cout << "Nhap phan so thu hai: ";
            p2.input();
            cout << "Phan so lon nhat: ";
            ans = max(p1, p2);
            ans.output();
            break;
        case 2:
            // Nhap 1 phan so, rut gon phan so va xuat ket qua ra man hinh
            cout << "Nhap phan so: ";
            p.input();
            p.simplify();
            cout << "Phan so rut gon: ";
            p.output();
            break;
        case 3:
            // Nhap 2 phan so, tinh tong, hieu, tich, thuong giua chung va xuat ket qua ra man hinh
            cout << "Nhap phan so thu nhat: ";
            p1.input();
            cout << "Nhap phan so thu hai: ";
            p2.input();
            ans = p1 + p2;
            cout << "Tong: ";
            ans.output();
            ans = p1 - p2;
            cout << "\nHieu: ";
            ans.output();
            ans = p1 * p2;
            cout << "\nTich: ";
            ans.output();
            ans = p1 / p2;
            cout << "\nThuong: ";
            ans.output();
            break;
        case 4:
            // Nhap vao day n phan so, tim va xuat ra man hinh phan so lon nhat. Sap xep day tang, giam dan
            int n;
            cout << "Nhap n: ";
            cin >> n;
            arr = new Fraction[n];
            input(arr, n);
            ans = max_element(arr, n);
            cout << "Phan so lon nhat: ";
            ans.output();
            cout << endl;
            // Tang dan
            cout << "Tang dan: ";
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                    if (arr[j] < arr[i])
                        swap(arr[i], arr[j]);
            }
            output(arr, n);
            cout << endl;
            // Giam dan
            cout << "Giam dan: ";
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                    if (arr[j] > arr[i])
                        swap(arr[i], arr[j]);
            }
            output(arr, n);
            delete[] arr;
            arr = NULL;
            break;
        case 5:
            flag = false;
            cout << "Xin chao.\n";
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }

    return 0;
}
int menu()
{
    int choice;
    if (::menu_yet == false)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon cac  chuc nang sau:";
        cout << "\n 1. Nhap 2 phan so, tim phan so lon nhat va xuat ket qua ra man hinh.";
        cout << "\n 2. Nhap 1 phan so, rut gon phan so va xuat ket qua ra man hinh.";
        cout << "\n 3. Nhap 2 phan so, tinh tong, hieu, tich, thuong giua chung va xuat ket qua ra man hinh.";
        cout << "\n 4. Nhap vao day n phan so, tim va xuat ra man hinh phan so lon nhat. Sap xep day tang, giam dan.";
        cout << "\n 5. Thoat chuong trinh.";
        cout << "\n ================================";
        menu_yet = true;
    }
    cout << "\n Lua chon cua ban: ";
    cin >> choice;
    return choice;
}
void Fraction::input()
{
    cin >> num >> den;
}
void Fraction::simplify()
{
    while (gcd(num, den) != 1)
    {
        int temp = num;
        num /= gcd(num, den);
        den /= gcd(temp, den);
    }
}
void Fraction::standard()
{
    this->simplify();
    if ((num < 0 && den < 0) || (num > 0 && den < 0))
    {
        num = -num;
        den = -den;
    }
}
void Fraction::output()
{
    this->standard();
    if (num == 0)
        cout << 0;
    else if (den == 1)
        cout << num;
    else
        cout << num << "/" << den;
}

void swap(Fraction &p1, Fraction &p2)
{
    Fraction temp = p1;
    p1 = p2;
    p2 = temp;
}

Fraction max(Fraction p1, Fraction p2)
{
    Fraction ans;
    if (p1.num * p2.den > p2.num * p1.den)
    {
        ans.num = p1.num;
        ans.den = p1.den;
    }
    else
    {
        ans.num = p2.num;
        ans.den = p2.den;
    }
    ans.standard();
    return ans;
}
Fraction max_element(Fraction *arr, int n)
{
    Fraction ans = *arr;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, *arr);
        arr++;
    }
    ans.standard();
    return ans;
}

void input(Fraction *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << ": ";
        arr->input();
        arr++;
    }
}
void output(Fraction *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr->output();
        arr++;
        cout << " ";
    }
}