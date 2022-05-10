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

// Stores inorder traversal of the BST
// in arr[]
void storeSorted(TNode *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->data;
        storeSorted(root->right, arr, i);
    }
}

/* A utility function to insert a new
   TNode with given key in BST */
TNode *insert(TNode *node, int x)
{
    /* If the tree is empty, return a new TNode */
    if (node == NULL)
        return createTNode(x);

    /* Otherwise, recur down the tree */
    if (x < node->data)
        node->left = insert(node->left, x);
    else if (x > node->data)
        node->right = insert(node->right, x);

    /* return the (unchanged) TNode pointer */
    return node;
}

// This function sorts arr[0..n-1] using Tree Sort
void tree_sort(int arr[], int n)
{
    struct TNode *root = NULL;

    // Construct the BST
    root = insert(root, arr[0]);
    for (int i = 1; i < n; i++)
        root = insert(root, arr[i]);

    // Store inorder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}
int main()
{
    // create input array
    int arr[] = {5, 4, 7, 2, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    tree_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}