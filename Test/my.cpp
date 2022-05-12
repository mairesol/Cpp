#include <iostream>

using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;
};

TNode *createTNode(int d)
{
    TNode *p = new TNode;
    if (p == NULL)
        return NULL;
    p->data = d;
    p->left = p->right = NULL;
    return p;
}

void storeSorted(TNode *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->data;
        storeSorted(root->right, arr, i);
    }
}

TNode *insert(TNode *node, int x)
{
    if (node == NULL)
        return createTNode(x);

    if (x <= node->data)
        node->left = insert(node->left, x);
    else if (x > node->data)
        node->right = insert(node->right, x);

    return node;
}

void tree_sort(int arr[], int n)
{
    struct TNode *root = NULL;
    int i;
    for (i = 0; i < n; i++)
        root = insert(root, arr[i]);

    i = 0;
    storeSorted(root, arr, i);
}
int main()
{
    int arr[] = {5, 4, 7, 2, 11, 99, 12, 4, 26, 14, 99, 30, 101, 64, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    tree_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}