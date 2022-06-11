#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

bool isSquare(double);
int menu();

struct TNode
{
    double data;
    TNode *left;
    TNode *right;
};

typedef TNode *Tree;
void createTree(Tree &);
void insert(Tree &, double);
void output_LRN(Tree);
int depth(Tree, double);
void output_LNR_in_level(Tree, Tree, double);
void output_LNR_square(Tree);

int main()
{
    Tree t;
    createTree(t);
    double n;
    cout << "\nNhap so node: ";
    cin >> n;

    double x;
    for (double i = 0; i < n; i++)
    {
        cin >> x;
        insert(t, x);
    }

    bool flag = true;
    int choice;
    while (flag)
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            flag = false;
            cout << "\nKet thuc chuong trinh!";
            break;
        case 1:
            output_LRN(t);
            cout << endl;
            break;
        case 2:
            cout << "\nNhap k: ";
            cin >> x;
            output_LNR_in_level(t, t, x);
            cout << endl;
            break;
        case 3:
            output_LNR_square(t);
            cout << endl;
            break;
        default:
            cout << "\nKhong hop le ";
            break;
        }
    }
    return 0;
}
bool isSquare(double x)
{
    double y = sqrt(x);
    int z = sqrt(x);
    return (y == z);
}

// Tree
void createTree(Tree &t)
{
    t = NULL;
}
void insert(Tree &t, double x)
{
    if (t != NULL)
    {
        if (x == t->data)
            return;
        if (x < t->data)
            insert(t->left, x);
        else
            insert(t->right, x);
    }
    else
    {
        t = new TNode;
        if (t == NULL)
            return;
        t->data = x;
        t->left = t->right = NULL;
    }
}
void output_LRN(Tree t)
{
    if (t != NULL)
    {
        output_LRN(t->left);
        output_LRN(t->right);
        cout << t->data << " ";
    }
}
int depth(Tree t, double x)
{
    int count = 0;
    while (t != NULL)
    {
        if (x == t->data)
            return count;
        if (x < t->data)
            t = t->left;
        else
            t = t->right;
        count++;
    }
    return -1;
}

void output_LNR_in_level(Tree t, Tree node, double d)
{
    if (node != NULL)
    {
        output_LNR_in_level(t, node->left, d);
        if (depth(t, node->data) == d)
            cout << node->data << " ";
        output_LNR_in_level(t, node->right, d);
    }
}
void output_LNR_square(Tree t)
{
    if (t != NULL)
    {
        output_LNR_square(t->left);
        if (isSquare(t->data))
            cout << t->data << " ";
        output_LNR_square(t->right);
    }
}

// Menu
int menu()
{
    cout << "\n\nChon chuc nang: ";
    cout << "\n0. Thoat chuong trinh.";
    cout << "\n1. In theo phep duyet LRN.";
    cout << "\n2. In tat cac node o muc k.";
    cout << "\n3. In ra tat ca cac so chinh phuong.";

    int choice;
    cout << "\nLua chon: ";
    cin >> choice;
    return choice;
}