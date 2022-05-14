#include <iostream>

using namespace std;

// 47 43 51 42 46 49 64 44 58 66 45 57 60  69 52 63 97 55 68 42 0
bool menu_yet = false;
int menu();

struct TNode
{
    unsigned int key;
    TNode *left;
    TNode *right;
};
typedef TNode *Tree;
void createTree(Tree &t);
void insert(Tree &, int x);
void clear(Tree &);
void output_LNR(Tree);
void output_LRN(Tree);
void output_NLR(Tree);
void output_NRL(Tree);
void output_RNL(Tree);
void output_RLN(Tree);

int main()
{
    int n, x;
    Tree t;
    createTree(t);

    int choice;
    bool flag = true;
    while (flag)
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            clear(t);
            cout << "\nNhap cac gia tri nguyen duong (neu nhap so khong duong thi dung): ";
            while (true)
            {
                cin >> x;
                if (x <= 0)
                    break;
                insert(t, x);
            }
            cout << "\nLNR: ";
            output_LNR(t);
            cout << "\nLRN: ";
            output_LRN(t);
            cout << "\nNLR: ";
            output_NLR(t);
            cout << "\nNRL: ";
            output_NRL(t);
            cout << "\nRNL: ";
            output_RNL(t);
            cout << "\nRLN: ";
            output_RLN(t);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;

        case 15:
            ::menu_yet = false;
            break;
        case 16:
            cout << "Chuong trinh ngung hoat dong.\n";
            flag = false;
            break;
        default:
            cout << "Lua chon khong dung, vui long nhap lai.";
            break;
        }
    }

    return 0;
}
// ------------------------------------tree------------------------------------ //
void createTree(Tree &t)
{
    t = NULL;
}
void insert(Tree &t, int x)
{
    if (t != NULL)
    {
        if (x == t->key)
            return;
        if (x < t->key)
            insert(t->left, x);
        else
            insert(t->right, x);
    }
    else
    {
        t = new TNode;
        if (t == NULL)
            return;
        t->key = x;
        t->left = t->right = NULL;
    }
}
void clear(Tree &t)
{
    if (t != NULL)
    {
        clear(t->left);
        clear(t->right);
        delete t;
        t = NULL;
    }
}
void output_LNR(Tree t)
{
    if (t != NULL)
    {
        output_LNR(t->left);
        cout << t->key << " ";
        output_LNR(t->right);
    }
}
void output_LRN(Tree t)
{
    if (t != NULL)
    {
        output_LRN(t->left);
        output_LRN(t->right);
        cout << t->key << " ";
    }
}
void output_NLR(Tree t)
{
    if (t != NULL)
    {
        cout << t->key << " ";
        output_NLR(t->left);
        output_NLR(t->right);
    }
}
void output_NRL(Tree t)
{
    if (t != NULL)
    {
        cout << t->key << " ";
        output_NRL(t->right);
        output_NRL(t->left);
    }
}
void output_RNL(Tree t)
{
    if (t != NULL)
    {
        output_RNL(t->right);
        cout << t->key << " ";
        output_RNL(t->left);
    }
}
void output_RLN(Tree t)
{
    if (t != NULL)
    {
        output_RLN(t->right);
        output_RLN(t->left);
        cout << t->key << " ";
    }
}
// ------------------------------------tree------------------------------------ //

// ------------------------------------menu------------------------------------ //
int menu()
{
    int choice;
    if (!::menu_yet)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon cac chuc nang sau:";
        cout << "\n 1. Nhap vao cay nhi phan tim kiem tu ban phim va thuc hien in ra cay theo cac thu tu: LNR, LRN, NLR, NRL, RNL, RLN.";
        cout << "\n 2. Tim mot node co khoa bang x tren cay. In ra man hinh thong bao co neu tim duoc, nguoc lai thong bao khong tim duoc.";
        cout << "\n 3. Xoa mot node co khoa bang x tren cay. In ra man hinh xoa thanh cong hoac khong thanh cong.";
        cout << "\n 4. In ra tong so node trong mot cay.";
        cout << "\n 5. In ra so node co day du 2 cay con.";
        cout << "\n 6. In ra so node co 1 cay con.";
        cout << "\n 7. In ra so node chi co 1 cay con phai.";
        cout << "\n 8. In ra so node la trong cay.";
        cout << "\n 9. In ra chieu cao cua cay.";
        cout << "\n 10. In ra cac node co gia tri chan.";
        cout << "\n 11. In ra so cac node co gia tri lon hon x duoc nhap tu ban phim.";
        cout << "\n 12. In ra gia tri cua node co gia tri lon nhat trong cay.";
        cout << "\n 13. In ra gia tri cua node co gia tri nho nhat cua cay con phai cua cay.";
        cout << "\n 14. In ra cac node tren tung muc cua cay.";
        cout << "\n 15. Xem lai menu.";
        cout << "\n 16. Thoat chuong trinh.";
        cout << "\n ================================";
        ::menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
// ------------------------------------menu------------------------------------ //