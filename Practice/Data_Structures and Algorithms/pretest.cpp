#include <iostream>

using namespace std;

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
void output_RNL(Tree);
int searchParent(Tree, int, int);
int depth(Tree, int);
void output_level_LNR(Tree, Tree);
int degree(Tree);
void output_degree_RNL_in_level(Tree, Tree, int);

int main()
{
    int n, x;
    Tree t;
    createTree(t);

    // 20 33 10 35 25 13 11 -5
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
            clear(t);
            cout << "\nNhap cac gia tri nguyen duong: ";
            while (true)
            {
                cin >> x;
                if (x <= 0)
                    break;
                insert(t, x);
            }
            cout << "\nXuat cay: ";
            output_RNL(t);
            break;
        case 2:
            cout << "Nhap x: ";
            cin >> x;
            cout << "\nCha cua x: " << searchParent(t, x, 1);
            break;
        case 3:
            cout << "\nXuat muc: ";
            output_level_LNR(t, t);
            break;
        case 4:
            cout << "\nNhap L: ";
            cin >> x;
            cout << "\nXuat bac cua cac node co muc L + 1: ";
            output_degree_RNL_in_level(t, t, x + 1);
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

// ------------------------------------Tree------------------------------------ //

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
void output_RNL(Tree t)
{
    if (t != NULL)
    {
        output_RNL(t->right);
        cout << t->key << " ";
        output_RNL(t->left);
    }
}
int searchParent(Tree t, int x, int parent)
{
    if (t != NULL)
    {
        if (x == t->key)
            return parent;
        if (x < t->key)
            return searchParent(t->left, x, t->key);
        return searchParent(t->right, x, t->key);
    }
    return 0;
}

int depth(Tree t, int x)
{
    int count = 0;
    while (t != NULL)
    {
        if (x == t->key)
            return count;
        if (x < t->key)
            t = t->left;
        else
            t = t->right;
        count++;
    }
    return -1;
}
void output_level_LNR(Tree t, Tree node)
{
    if (node != NULL)
    {
        output_level_LNR(t, node->left);
        cout << depth(t, node->key) << " ";
        output_level_LNR(t, node->right);
    }
}
int degree(Tree t)
{
    return (t->left != NULL) + (t->right != NULL);
}
void output_degree_RNL_in_level(Tree t, Tree node, int d)
{
    if (node != NULL)
    {
        output_degree_RNL_in_level(t, node->right, d);
        if (depth(t, node->key) == d)
            cout << degree(node) << " ";
        output_degree_RNL_in_level(t, node->left, d);
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

// ------------------------------------menu------------------------------------ //
int menu()
{
    int choice;
    if (!::menu_yet)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon cac chuc nang sau:";
        cout << "\n 0. Thoat chuong trinh.";
        cout << "\n 1. Xay dung cay tu day so nguyen duong, ket thuc khi nhan vao mot so khac nguyen duong. Xuat ket qua cua cay theo thu tu giam dan.";
        cout << "\n 2. In ra node cha cua node co khoa x.";
        cout << "\n 3. Xuat ra muc cua cac node trong cay tuong ung voi gia tri node tang dan.";
        cout << "\n 4. Xuat ra bac cua cac node co muc L + 1 theo thu tu giam dan cua gia tri node.";
        cout << "\n 5. Xem lai menu.";
        cout << "\n ================================";
        ::menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}