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

int numberNode(Tree);
int numberLeafNode(Tree);

int main()
{
    return 0;
}

TNode *createTNode(int d)
{
    TNode *p = new TNode;
    if (p == NULL)
        return NULL;
    else
    {
        p->data = d;
        p->left = p->right = NULL;
    }
}

void createTree(Tree &t)
{
    t = NULL;
}
int insertNode(Tree &t, int x)
{
    if (t != NULL)
    {
        if (x == t->data)
            return 0;
        if (x < t->data)
            insertNode(t->left, x);
        insertNode(t->right, x);
    }
    else
    {
        t = new TNode;
        if(
    }
}