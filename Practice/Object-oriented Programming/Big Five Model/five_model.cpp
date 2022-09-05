#include <iostream>
#include <string>

#include "five_model.h"

using namespace std;

// Personality
Personality::Personality(int a) : gia_tri(a){};
Personality::~Personality(){};

int Personality::MucChiSo()
{
    if (gia_tri >= ChiSoCao)
        return 1;
    if (gia_tri <= ChiSoThap)
        return -1;
    return 0;
}

// Openness
Openness::Openness(int a) : Personality(a){};
Openness::~Openness(){};

void Openness::DacDiem()
{
    cout << "\nSan sang trai nghiem(O) ";
    switch (MucChiSo())
    {
    case -1:
        cout << "Nguoi co diem thap o yeu to nay thuong kha bao thu, kho tiep nhan nhung y tuong moi, la. Ho thich su on dinh, quen thuoc va thuc te.";
        break;
    case 0:
        cout << "Khong xac dinh ro.";
        break;
    case 1:
        cout << "Nguoi co diem cao o yeu to nay thuong la nguoi thich nhung y tuong moi, thich hieu biet nhieu linh vuc nhung dong thoi cung thich tu do, khong thich bi rang buoc...";
        break;

    default:
        break;
    }
}

// Coscientiounes
Coscientiouness::Coscientiouness(int a) : Personality(a){};
Coscientiouness::~Coscientiouness(){};

void Coscientiouness::DacDiem()
{
    cout << "\nTu chu tan tam(C) ";
    switch (MucChiSo())
    {
    case -1:
        cout << "Nguoi co diem thap o yeu to nay thuong de bo cuoc, kha nang chiu ap luc, tuan thu ki luat cua to chuc kem.";
        break;
    case 0:
        cout << "Khong xac dinh ro.";
        break;
    case 1:
        cout << "Nguoi co diem cao o yeu to nay thuong la nguoi cham chi, co kha nang chiu ap luc tot. Ho thuong la nguoi gan bo, trung thanh voi to chuc.";
        break;

    default:
        break;
    }
}

// Extraversion
Extraversion::Extraversion(int a) : Personality(a){};
Extraversion::~Extraversion(){};

void Extraversion::DacDiem()
{
    cout << "\nHuong ngoai(E) ";
    switch (MucChiSo())
    {
    case -1:
        cout << "Nguoi co diem thap o yeu to nay thuong ngai giao tiep, khong thich su noi bat, thich duoc lam viec doc lap.";
        break;
    case 0:
        cout << "Khong xac dinh ro.";
        break;
    case 1:
        cout << "Nguoi co diem cao o yeu to nay thuong la nguoi nhiet tinh, nang dong, giao tiep tot, thich the hien ban than.";
        break;

    default:
        break;
    }
}

// Agreeableness
Agreeableness::Agreeableness(int a) : Personality(a){};
Agreeableness::~Agreeableness(){};

void Agreeableness::DacDiem()
{
    cout << "\nHoa dong de chiu(A) ";
    switch (MucChiSo())
    {
    case -1:
        cout << "Nguoi co diem thap thuong dat loi ich cua ban than len tren, it dong cam, chia se voi dong nghiep, co tinh canh tranh cao.";
        break;
    case 0:
        cout << "Khong xac dinh ro.";
        break;
    case 1:
        cout << "Nguoi co diem cao o yeu to nay thuong than thien, coi mo, dong cam voi moi nguoi nhung nhieu khi \"thieu chinh kien\".";
        break;

    default:
        break;
    }
}

// Neuroticism
Neuroticism::Neuroticism(int a) : Personality(a){};
Neuroticism::~Neuroticism(){};

void Neuroticism::DacDiem()
{
    cout << "\nBat on cam xuc(N) ";
    switch (MucChiSo())
    {
    case -1:
        cout << "Nguoi co diem thap o yeu to nay thuong kiem soat duoc cam xuc, ung pho voi cang thang tot, it bi ben ngoai anh huong den tam trang cua ban than.";
        break;
    case 0:
        cout << "Khong xac dinh ro.";
        break;
    case 1:
        cout << "Nguoi co diem cao o yeu to nay thuong co cac cam xuc tieu cuc nhu: lo lang, buc boi, tu ti, yeu duoi va kha nang chiu ap luc kem.";
        break;

    default:
        break;
    }
}

// Person
void Person::nhap()
{
    l.clear();
    l.resize(5);
    int O, C, E, A, N;
    cin >> O >> C >> E >> A >> N;
    l[0] = new Openness(O);
    l[1] = new Coscientiouness(C);
    l[2] = new Extraversion(E);
    l[3] = new Agreeableness(A);
    l[4] = new Neuroticism(N);
}
void Person::tinh_cach()
{
    cout << "\nTinh cach:";
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
        l[i]->DacDiem();
    }
}
bool Person::luu_y()
{
    return ((l[1]->MucChiSo() == -1) || (l[4]->MucChiSo() == 1));
}