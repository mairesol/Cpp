#include <iostream>
#include <string>

using namespace std;

int menu();
bool menu_yet = false;

class NodeAuthor
{
public:
    string ten;
    string noi_cong_tac;
    string quoc_gia;
    NodeAuthor *next;

    NodeAuthor(string = "", string = "", string = "");
};

class ListAuthor
{
public:
    NodeAuthor *head;
    NodeAuthor *tail;

    ListAuthor();
    ~ListAuthor();
    ListAuthor &operator=(const ListAuthor &);
    bool empty();
    void insert_tail(NodeAuthor *);

    NodeAuthor *search_ten(string);
    NodeAuthor *search_noi_cong_tac(string);
    void clear();

    void input();
    void output();
};

class NodePaper
{
public:
    unsigned int ma_bai_bao;
    string ten;
    unsigned int nam_sx;
    ListAuthor danh_sach_tac_gia;
    NodePaper *next;

    NodePaper(unsigned int, string, unsigned int, ListAuthor);
};

class ListPaper
{
public:
    NodePaper *head;
    NodePaper *tail;

    ListPaper();
    ~ListPaper();
    bool empty();
    void insert_tail(NodePaper *);
    void remove_head();
    void remove_after(NodePaper *);

    void remove_all_noi_cong_tac(string);
    void search_all_author(string);
    void sort_nam_sx();
    void clear();

    void input();
    void output();
};

int main()
{
    ListPaper L;
    string s;
    int choice;
    bool flag = true;
    while (flag)
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            cout << "Chuong trinh ngung hoat dong.\n";
            flag = false;
            break;
        case 1:
            L.input();
            L.output();
            break;
        case 2:
            cout << "\nNhap ten tac gia: ";
            getline(cin, s);
            L.search_all_author(s);
            break;
        case 3:
            L.sort_nam_sx();
            L.output();
            break;
        case 4:
            cout << "\nNhap noi cong tac: ";
            getline(cin, s);
            L.remove_all_noi_cong_tac(s);
            break;
        case 5:
            ::menu_yet = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }
    return 0;
}
// ------------------------------------Author----------------------------------- //
NodeAuthor::NodeAuthor(string t, string n, string q) : ten(t), noi_cong_tac(n), quoc_gia(q){};

ListAuthor::ListAuthor()
{
    head = tail = NULL;
}
ListAuthor::~ListAuthor()
{
    clear();
}
bool ListAuthor ::empty()
{
    return (head == NULL);
}
void ListAuthor ::clear()
{
    NodeAuthor *p;
    while (!empty())
    {
        p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
}
NodeAuthor *ListAuthor::search_ten(string s)
{
    NodeAuthor *p = head;
    while (p != NULL && p->ten != s)
        p = p->next;
    return p;
}
NodeAuthor *ListAuthor::search_noi_cong_tac(string s)
{
    NodeAuthor *p = head;
    while (p != NULL && p->noi_cong_tac != s)
        p = p->next;
    return p;
}

ListAuthor &ListAuthor::operator=(const ListAuthor &obj)
{
    clear();
    NodeAuthor *p;
    NodeAuthor *q = obj.head;
    while (q != NULL)
    {
        p = new NodeAuthor(q->ten, q->noi_cong_tac, q->quoc_gia);
        insert_tail(p);
        q = q->next;
    }
    return *this;
}
void ListAuthor ::insert_tail(NodeAuthor *p)
{
    if (empty())
        head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
}
void ListAuthor::input()
{
    int n;
    string ten, noi_cong_tac, quoc_gia;
    cout << "\nNhap so tac gia: ";
    cin >> n;
    clear();
    cin.ignore(256, '\n');
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin tac gia thu " << i + 1 << ": ";
        cout << "\nTen: ";
        getline(cin, ten);
        cout << "\nNoi cong tac: ";
        getline(cin, noi_cong_tac);
        cout << "\nQuoc gia: ";
        getline(cin, quoc_gia);

        NodeAuthor *p = new NodeAuthor(ten, noi_cong_tac, quoc_gia);
        if (p != NULL)
            insert_tail(p);
    }
}
void ListAuthor::output()
{
    NodeAuthor *p = head;
    while (p != NULL)
    {
        cout << p->ten << " ";
        p = p->next;
    }
}

// ------------------------------------Paper----------------------------------- //
NodePaper::NodePaper(unsigned int m, string t, unsigned int n, ListAuthor d)
{
    ma_bai_bao = m;
    ten = t;
    nam_sx = n;
    danh_sach_tac_gia = d;
}

ListPaper::ListPaper()
{
    head = tail = NULL;
}
ListPaper::~ListPaper()
{
    clear();
}
bool ListPaper ::empty()
{
    return (head == NULL);
}

void ListPaper ::insert_tail(NodePaper *p)
{
    if (empty())
        head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
}
void ListPaper ::remove_head()
{
    if (!empty())
    {
        NodePaper *p = head;
        head = head->next;
        delete p;
        if (empty())
            tail = NULL;
    }
}
void ListPaper ::remove_after(NodePaper *q)
{
    if (q != NULL)
    {
        NodePaper *p = q->next;
        if (p != NULL)
        {
            q->next = p->next;
            if (p == tail)
                tail = q;
            delete p;
        }
    }
}

void ListPaper ::search_all_author(string s)
{
    NodePaper *p = head;
    while (p != NULL)
    {
        if (p->danh_sach_tac_gia.search_ten(s) != NULL)
            cout << p->ten << " ";
        p = p->next;
    }
}
void ListPaper ::remove_all_noi_cong_tac(string s)
{
    NodePaper *p = head, *q = NULL;
    while (true)
    {
        while (p != NULL && p->danh_sach_tac_gia.search_noi_cong_tac(s) == NULL)
        {
            q = p;
            p = p->next;
        }
        if (p == NULL)
            return;
        if (q != NULL)
            remove_after(q);
        else
            remove_head();

        p = q->next;
    }
}

void ListPaper ::clear()
{
    NodePaper *p;
    while (!empty())
    {
        p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
}

void ListPaper ::sort_nam_sx()
{
    NodePaper *min;
    NodePaper *temp;
    NodePaper *pre_p = NULL, *pre_min = NULL;
    for (NodePaper *p = head; p != tail; p = p->next)
    {
        min = p;
        pre_min = pre_p;
        for (NodePaper *q = p->next; q != NULL; q = q->next)
        {
            if (q->nam_sx < min->nam_sx)
            {
                min = q;
                pre_min = temp;
            }
            temp = q;
        }

        pre_p->next = min;
        pre_min->next = p;

        temp = min->next;
        min->next = p->next;
        p->next = temp;

        pre_p = p;
    }
}
void ListPaper::input()
{
    int n;
    unsigned int ma_bai_bao, nam_sx;
    string ten;
    ListAuthor danh_sach_tac_gia;
    cout << "\nNhap so bai bao: ";
    cin >> n;
    clear();
    for (int i = 0; i < n; i++)
    {
        cout << "\n\nNhap thong tin bai bao thu " << i + 1 << ": ";
        cout << "\nMa bai bao: ";
        cin >> ma_bai_bao;
        cin.ignore(256, '\n');
        cout << "\nTen bai bao: ";
        getline(cin, ten);
        cout << "\nNam san xuat: ";
        cin >> nam_sx;
        cout << "\nDanh sach tac gia: ";
        danh_sach_tac_gia.input();
        NodePaper *p = new NodePaper(ma_bai_bao, ten, nam_sx, danh_sach_tac_gia);
        if (p != NULL)
            insert_tail(p);
    }
}
void ListPaper::output()
{
    cout << "\nThong tin cac bai bao: ";
    int i = 1;
    NodePaper *p = head;
    while (p != NULL)
    {

        cout << "\n\nBai bao thu " << i << ": ";
        cout << endl
             << p->ma_bai_bao << "\t" << p->ten << "\t" << p->nam_sx;
        cout << "\nDanh sach tac gia: ";
        p->danh_sach_tac_gia.output();

        i++;
        p = p->next;
    }
}
// ------------------------------------menu------------------------------------ //
int menu()
{
    int choice;
    if (!::menu_yet)
    {
        cout << "\n\n ================================";
        cout << "\n Vui long chon cac chuc nang sau:";
        cout << "\n 0. Thoat chuong trinh.";
        cout << "\n 1. Nhap vao danh sach n bai bao tu ban phim va xuat ra danh sach vua nhap.";
        cout << "\n 2. Tim cac bai bao cua tac gia co ten la X viet, duoc nhap tu ban phim.";
        cout << "\n 3. Sap xep cac bai bao theo nam xuat ban va in ra sau khi sap xep.";
        cout << "\n 4. Xoa tat ca cac paper do tac gia co noi cong tac X duoc nhap vao tu ban phim.";
        cout << "\n 5. Xem lai menu.";
        cout << "\n ================================";
        ::menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
