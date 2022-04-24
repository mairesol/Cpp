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
void NLR(Tree); // pre - oder
void LNR(Tree); // in - oder
void LRN(Tree); // post - oder
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
void NLR(Tree root)
{
    if (root != NULL)
    {
        // <Xử lý root>;
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Tree root)
{
    if (root != NULL)
    {
        LNR(root->left);
        // <Xử lý root>;
        LNR(root->right);
    }
}
void LRN(Tree root)
{
    if (root != NULL)
    {
        LRN(root->left);
        LRN(root->right);
        // <Xử lý root>;
    }
}
int numberNode(Tree root)
{
    if (root = NULL)
        return 0;
    return 1 + numberNode(root->left) + numberNode(root->right);
}
int numberLeftNode(Tree root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return numberLeafNode(root->left) + numberLeafNode(root->right);
}