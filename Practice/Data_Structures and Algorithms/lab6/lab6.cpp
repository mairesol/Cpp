#include <iostream>
#include <queue>

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
void output_LNR(Tree);
void output_LRN(Tree);
void output_NLR(Tree);
void output_NRL(Tree);
void output_RNL(Tree);
void output_RLN(Tree);
TNode *search(Tree, int);
int remove(Tree &, int);
void searchStandFor(Tree &, Tree &);
int numberNode(Tree);
int numberNode_2_child(Tree);
int numberNode_1_child(Tree);
int numberNode_1_child_right(Tree);
int numberLeafNode(Tree);
int height(Tree);
void printNodeEven(Tree);
void printNodeGreaterThan(Tree, int);
int max(Tree);
int min(Tree);
void printLevelOrder(Tree);
int depth(Tree, int);

int main()
{
    int n, x, y;
    Tree t, ans;
    createTree(t);

    // 96 35 98 2 70 1 24 40 76 7 27 39 47 72 83 3 17 25 32 43 51 71 82 90 5 14 22 26 31 42 46 49 64 86 93 12 44 58 66 85 87 92 95 9 45 57 60 69 89 52 63 67 55 68 0
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
            cout << "\nNhap x: ";
            cin >> x;
            ans = search(t, x);
            if (ans == NULL)
                cout << "\nKhong tim thay x.";
            else
                cout << "\nTim thay x.";
            break;
        case 3:
            cout << "\nNhap x: ";
            cin >> x;
            x = remove(t, x);
            if (x == -1)
                cout << "\nXoa khong thanh cong.";
            else
            {
                cout << "\nXoa thanh cong.";
                cout << "\nCay sau khi xoa x (LNR): ";
                output_LNR(t);
            }
            break;
        case 4:
            cout << "\nSo node: " << numberNode(t);
            break;
        case 5:
            cout << "\nSo node co day du 2 cay con: " << numberNode_2_child(t);
            break;
        case 6:
            cout << "\nSo node co 1 cay con: " << numberNode_1_child(t);
            break;
        case 7:
            cout << "\nSo node chi co 1 cay con phai: " << numberNode_1_child_right(t);
            break;
        case 8:
            cout << "\nSo node la: " << numberLeafNode(t);
            break;
        case 9:
            cout << "\nChieu cao: " << height(t);
            break;
        case 10:
            cout << "\nCac node co gia tri chan: ";
            printNodeEven(t);
            break;
        case 11:
            cout << "\nNhap x: ";
            cin >> x;
            cout << "\nCac node co gia tri lon hon x: ";
            printNodeGreaterThan(t, x);
            break;
        case 12:
            cout << "\nNode co gia tri lon nhat: " << max(t);
            break;
        case 13:
            cout << "\nNode co gia tri nho nhat cua cay con phai: " << min(t->right);
            break;
        case 14:
            cout << "\nCac node tren tung muc: \n";
            printLevelOrder(t);
            break;
        case 15:
            cout << "\nNhap x: ";
            cin >> x;
            cout << "\nDo dai duong di tu goc den node co gia tri x: " << depth(t, x);
            break;
        case 16:
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
TNode *search(Tree t, int x)
{
    if (t != NULL)
    {
        if (x == t->key)
            return t;
        if (x < t->key)
            return search(t->left, x);
        return search(t->right, x);
    }
    return NULL;
}
int remove(Tree &t, int x)
{
    if (t != NULL)
    {
        if (x < t->key)
            return remove(t->left, x);
        else if (x > t->key)
            return remove(t->right, x);
        else
        {
            TNode *pDelete = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            else
                searchStandFor(pDelete, t->right);
            delete pDelete;
        }
        return 1;
    }
    return -1;
}
void searchStandFor(Tree &pDelete, Tree &pStand) // Nút có khoá nhỏ nhất (trái nhất) bên cây con phải node cần xóa
{
    if (pStand->left != NULL)
        searchStandFor(pDelete, pStand->left);
    else
    {
        pDelete->key = pStand->key;
        pDelete = pStand;
        pStand = pStand->right;
    }
}
int numberNode(Tree t)
{
    if (t == NULL)
        return 0;
    return 1 + numberNode(t->left) + numberNode(t->right);
}
int numberNode_2_child(Tree t)
{
    if (t == NULL)
        return 0;
    if (t->left != NULL && t->right != NULL)
        return 1 + numberNode_2_child(t->left) + numberNode_2_child(t->right);
    return numberNode_2_child(t->left) + numberNode_2_child(t->right);
}
int numberNode_1_child(Tree t)
{
    if (t == NULL)
        return 0;
    if ((t->left != NULL && t->right == NULL) || (t->left == NULL && t->right != NULL))
        return 1 + numberNode_1_child(t->left) + numberNode_1_child(t->right);
    return numberNode_1_child(t->left) + numberNode_1_child(t->right);
}
int numberNode_1_child_right(Tree t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right != NULL)
        return 1 + numberNode_1_child_right(t->right);
    return numberNode_1_child_right(t->left) + numberNode_1_child_right(t->right);
}
int numberLeafNode(Tree t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right == NULL)
        return 1;
    return numberLeafNode(t->left) + numberLeafNode(t->right);
}
int height(Tree t)
{
    if (t == NULL)
        return 0;
    return 1 + max(height(t->left), height(t->right));
}
void printNodeEven(Tree t)
{
    if (t != NULL)
    {
        printNodeEven(t->left);
        if (t->key % 2 == 0)
            cout << t->key << " ";
        printNodeEven(t->right);
    }
}
void printNodeGreaterThan(Tree t, int x)
{
    while ((t != NULL) && (t->key <= x))
        t = t->right;
    if (t != NULL)
    {
        printNodeGreaterThan(t->left, x);
        cout << t->key << " ";
        output_LNR(t->right);
    }
}
int max(Tree t)
{
    if (t != NULL)
    {
        while (t->right != NULL)
            t = t->right;
        return t->key;
    }
    return -1;
}
int min(Tree t)
{
    if (t != NULL)
    {
        while (t->left != NULL)
            t = t->left;
        return t->key;
    }
    return -1;
}
void printLevelOrder(Tree t)
{
    if (t == NULL)
        return;
    queue<TNode *> q;
    q.push(t);
    while (!q.empty())
    {
        int count = q.size();
        while (count > 0)
        {
            TNode *p = q.front();
            q.pop();
            cout << p->key << " ";
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
            count--;
        }
        cout << endl;
    }
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
// ------------------------------------Tree------------------------------------ //

// ------------------------------------menu------------------------------------ //
int menu()
{
    int choice;
    if (!::menu_yet)
    {
        cout << "\n ================================";
        cout << "\n Vui long chon cac chuc nang sau:";
        cout << "\n 0. Thoat chuong trinh.";
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
        cout << "\n 13. In ra gia tri cua node co gia tri nho nhat trong cay con phai cua cay.";
        cout << "\n 14. In ra cac node tren tung muc trong cay.";
        cout << "\n 15. Cho biet do dai duong di tu goc den node co gia tri x nhap tu ban phim.";
        cout << "\n 16. Xem lai menu.";
        cout << "\n ================================";
        ::menu_yet = true;
    }
    cout << "\n Lua chon: ";
    cin >> choice;
    return choice;
}
// ------------------------------------menu------------------------------------ //