#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Day
{
private:
    int date, month, year;

public:
    Day(int = 0, int = 0, int = 0);
    ~Day() {}
    friend istream &operator>>(istream &, Day &);
    friend ostream &operator<<(ostream &, const Day &);
};
class Candidate
{
private:
    int ma;
    string ten;
    Day ngaysinh;
    double diem_toan, diem_van, diem_anh;

public:
    Candidate(int = 0, string = "", Day = Day(0, 0, 0), double = 0, double = 0, double = 0);
    ~Candidate() {}

    double tong_diem();
    void nhap();
    void xuat();
};
class TestCandidate
{
    vector<Candidate> list;

public:
    void nhap();
    void xuat_lon_hon_15();
};

int main()
{
    TestCandidate l;
    l.nhap();
    l.xuat_lon_hon_15();
    return 0;
}
Day::Day(int d, int m, int y)
{
    date = d;
    month = m;
    year = y;
}
istream &operator>>(istream &is, Day &obj)
{
    is >> obj.date >> obj.month >> obj.year;
    return is;
}
ostream &operator<<(ostream &os, const Day &obj)
{
    os << obj.date << "/" << obj.month << "/" << obj.year;
    return os;
}
Candidate::Candidate(int m, string t, Day n, double dt, double dv, double da)
{
    ma = m;
    ten = t;
    ngaysinh = n;
    diem_toan = dt;
    diem_van = dv;
    diem_anh = da;
}
double Candidate::tong_diem()
{
    return diem_toan + diem_van + diem_anh;
}
void Candidate::nhap()
{
    cout << "Nhap ma: ";
    cin >> ma;
    cin.ignore(256, '\n');
    cout << "Nhap ten: ";
    getline(cin, ten);
    cout << "Nhap ngay sinh: ";
    cin >> ngaysinh;
    cout << "Nhap diem toan: ";
    cin >> diem_toan;
    cout << "Nhap diem van: ";
    cin >> diem_van;
    cout << "Nhap diem anh: ";
    cin >> diem_anh;
}
void Candidate::xuat()
{
    cout << ma << "\t" << ten << "\t" << ngaysinh << "\t"
         << diem_toan << "\t" << diem_van << "\t" << diem_anh;
}

void TestCandidate::nhap()
{
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;
    list.resize(n);
    for (int i = 0; i != n; i++)
    {
        cout << "Nhap thi sinh thu " << i + 1 << " :\n";
        list[i].nhap();
    }
}
void TestCandidate::xuat_lon_hon_15()
{
    cout << "Danh sach thi sinh co tong diem lon hon 15: " << endl;
    bool flag = false;
    for (int i = 0; i != list.size(); i++)
    {
        if (list[i].tong_diem() > 15.0)
        {
            flag = true;
            list[i].xuat();
            cout << endl;
        }
    }
    if (flag == false)
        cout << "Khong co thi sinh nao thoa man.\n";
}