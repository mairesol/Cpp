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

class PS
{
public:
    int tu, mau;
    PS(int tu = 0, int mau = 1)
    {
        this->tu = tu;
        this->mau = mau;
    }
    ~PS()
    {
        this->tu = 0;
        this->mau = 0;
    }
    void input()
    {
        cin >> tu >> mau;
    }
    void simplify()
    {
        while (gcd(tu, mau) != 1)
        {
            int temp = tu;
            tu /= gcd(tu, mau);
            mau /= gcd(temp, mau);
        }
    }
    void output()
    {
        this->simplify();
        if (tu == 0)
            cout << 0;
        else if (mau == 0)
            cout << tu;
        else
            cout << tu << "/" << mau;
    }
    PS operator+(PS p)
    {
        PS ans;
        ans.tu = tu * p.mau + p.tu * mau;
        ans.mau = mau * p.mau;
        ans.simplify();
        return ans;
    }
    PS operator-(PS p)
    {
        PS ans;
        ans.tu = tu * p.mau - p.tu * mau;
        ans.mau = mau * p.mau;
        ans.simplify();
        return ans;
    }
    PS operator*(PS p)
    {
        PS ans;
        ans.tu = tu * p.tu;
        ans.mau = mau * p.mau;
        ans.simplify();
        return ans;
    }
    PS operator/(PS p)
    {
        PS ans;
        ans.tu = tu * p.mau;
        ans.mau = mau * p.tu;
        ans.simplify();
        return ans;
    }
    bool operator<(PS p)
    {
        return (tu * p.mau < p.tu * mau);
    }
    bool operator>(PS p)
    {
        return (tu * p.mau > p.tu * mau);
    }
};

PS max(PS p1, PS p2)
{
    PS ans;
    if (p1.tu * p2.mau > p2.tu * p1.mau)
    {
        ans.tu = p1.tu;
        ans.mau = p1.mau;
    }
    else
    {
        ans.tu = p2.tu;
        ans.mau = p2.mau;
    }
    ans.simplify();
    return ans;
}
void swap(PS &p1, PS &p2)
{
    PS temp = p1;
    p1 = p2;
    p2 = temp;
}

void input(PS *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << ": ";
        arr->input();
        arr++;
    }
}
PS max(PS *arr, int n)
{
    PS ans = *arr;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, *arr);
        arr++;
    }
    return ans;
}
void output(PS *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr->output();
        arr++;
        cout << " ";
    }
}

int main()
{
    // Cac chuc nang
    PS p, p1, p2;
    PS ans;
    PS *arr;
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
            arr = new PS[n];
            input(arr, n);
            ans = max(arr, n);
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
