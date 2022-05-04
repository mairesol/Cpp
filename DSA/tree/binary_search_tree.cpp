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
        if(
    }
}