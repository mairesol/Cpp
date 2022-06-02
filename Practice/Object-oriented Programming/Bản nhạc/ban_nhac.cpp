#include <iostream>
#include <string>

#include "ban_nhac.h"

using namespace std;

NotNhac::NotNhac(string a, string b) : cao_do(a), truong_do(b){};
NotNhac::~NotNhac(){};
char NotNhac::get_cao_do()
{
    if (cao_do == "do")
        return 'C';
    if (cao_do == "re")
        return 'D';
    if (cao_do == "mi")
        return 'E';
    if (cao_do == "fa")
        return 'F';
    if (cao_do == "sol")
        return 'G';
    if (cao_do == "la")
        return 'A';
    if (cao_do == "si")
        return 'B';
    return 0;
}
double NotNhac::get_truong_do()
{
    if (truong_do == "tron")
        return 4;
    if (truong_do == "trang")
        return 2;
    if (truong_do == "den")
        return 1;
    if (truong_do == "moc don")
        return 0.5;
    if (truong_do == "moc doi")
        return 0.25;
    if (truong_do == "moc tam")
        return 0.125;
    if (truong_do == "moc tu")
        return 0.0625;
    return 0;
}
ostream &operator<<(ostream &os, const NotNhac &obj)
{
    os << obj.cao_do << " " << obj.truong_do;
    return os;
}

DauLang::DauLang(string a) : NotNhac("dau lang", a){};
DauLang::~DauLang(){};
char DauLang::get_cao_do()
{
    return 'Z';
}

void BanNhac::nhap()
{
    cout << "\nTen: ";
    getline(cin, ten);
    cout << "\nTac gia: ";
    getline(cin, tac_gia);
    cout << "\nNam sang tac: ";
    cin >> nam_sang_tac;

    int n;
    cout << "\nSo not nhac: ";
    cin >> n;

    NotNhac *p;
    string a, b;
    char c;
    double d;
    bool flag;
    for (int i = 1; i <= n; i++)
    {
        cout << "\nNot thu " << i << ": ";
        flag = true;
        while (flag)
        {
            flag = false;
            cout << "\nCao do: ";
            cin >> c;
            switch (c)
            {
            case 'C':
            case 'c':
                a = "do";
                break;
            case 'D':
            case 'd':
                a = "re";
                break;
            case 'E':
            case 'e':
                a = "mi";
                break;
            case 'F':
            case 'f':
                a = "fa";
                break;
            case 'G':
            case 'g':
                a = "sol";
                break;
            case 'A':
            case 'a':
                a = "la";
                break;
            case 'B':
            case 'b':
                a = "si";
                break;
            case 'Z':
            case 'z':
                a = "dau lang";
                break;
            default:
                cout << "\n----Khong hop le----\n";
                flag = true;
                break;
            }
        }
        flag = true;
        while (flag)
        {
            flag = false;
            cout << "\nTruong do: ";
            cin >> d;
            if (d == 4)
                b = "tron";
            else if (d == 2)
                b = "trang";
            else if (d == 1)
                b = "den";
            else if (d == 0.5)
                b = "moc don";
            else if (d == 0.25)
                b = "moc doi";
            else if (d == 0.125)
                b = "moc tam";
            else if (d == 0.0625)
                b = "moc tu";
            else
            {
                cout << "\n----Khong hop le----\n";
                flag = true;
            }
        }

        if (a == "dau lang")
            p = new DauLang(b);
        else
            p = new NotNhac(a, b);

        ban_nhac.push_back(p);
    }
}
BanNhac::~BanNhac()
{
    for (int i = 0; i < ban_nhac.size(); i++)
        delete ban_nhac[i];
    ban_nhac.resize(0);
}
void BanNhac::xuat()
{
    cout << endl;
    cout << ten << " " << tac_gia << " " << nam_sang_tac;
    cout << "\nCac not nhac: ";
    for (int i = 0; i < ban_nhac.size() - 1; i++)
        cout << *ban_nhac[i] << ", ";
    cout << *ban_nhac[ban_nhac.size() - 1] << "." << endl;
}

int BanNhac::so_dau_lang_den()
{
    int count = 0;
    for (int i = 0; i < ban_nhac.size(); i++)
        if (ban_nhac[i]->get_cao_do() == 'Z' && ban_nhac[i]->get_truong_do() == 1)
            count++;

    return count;
}
NotNhac BanNhac::cao_do_lon_nhat()
{
    int max = bac_cao_do(ban_nhac[0]);
    NotNhac *p_max = ban_nhac[0];
    for (int i = 1; i < ban_nhac.size(); i++)
    {
        if (bac_cao_do(ban_nhac[i]) > max)
        {
            max = bac_cao_do(ban_nhac[i]);
            p_max = ban_nhac[i];
        }
    }
    return *p_max;
}

int bac_cao_do(NotNhac *p)
{
    char c = p->get_cao_do();
    switch (c)
    {
    case 'C':
        return 1;
        break;
    case 'D':
        return 2;
        break;
    case 'E':
        return 3;
        break;
    case 'F':
        return 4;
        break;
    case 'G':
        return 5;
        break;
    case 'A':
        return 6;
        break;
    case 'B':
        return 7;
        break;
    case 'Z':
        return 0;
        break;
    default:
        break;
    }
    return -1;
}