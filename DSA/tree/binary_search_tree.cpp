#include <iostream>

using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;
};
TNode *createTNode(int);

typedef TNode *Tree;
void createTree(Tree &);
int insertNode(Tree &, int);
void remove(Tree &, int);

int main()
{
    return 0;
}

TNode *createTNode(int d)
{
    TNode *p = new TNode;
    if (p == NULL)
        return NULL;
    p->data = d;
    p->left = p->right = NULL;
    return p;
}

void createTree(Tree &t)
{
    t = NULL;
}
int insert(Tree &t, int x)
{
    if (t != NULL)
    {
        if (x == t->data)
            return 0;
        if (x < t->data)
            insert(t->left, x);
        insert(t->right, x);
    }
    else
    {
        t = new TNode;
        if (t == NULL)
            return -1;
        t->data = x;
        t->left = t->right = NULL;
        return 1;
    }
}

TNode *search(Tree t, int x)
{
    if (t != NULL)
    {
        if (x == t->data)
            return t;
        if (x < t->data)
            return search(t->left, x);
        return search(t->right, x);
    }
    return NULL;
}

void remove(Tree &t, int x)
{
    if (t != NULL)
    {
        if (x < t->data)
            remove(t->left, x);
        else if (x > t->data)
            remove(t->right, x);
        else
        {
            TNode *pHuy = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            else
                SearchStandFor(pHuy, t->right);
            delete pHuy;
        }
    }
}
void SearchStandFor(Tree &pHuy, Tree &pTM) // Nút có khoá nhỏ nhất (trái nhất) bên cây con phải node cần xóa
{
    if (pTM->left != NULL)
        SearchStandFor(pHuy, pTM->left);
    else
    {
        pHuy->data = pTM->data;
        pHuy = pTM;
        pTM = pTM->right;
    }
}