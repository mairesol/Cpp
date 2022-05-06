#include <iostream>

using namespace std;

class TNode
{
public:
    char value;
    TNode *left;
    TNode *right;
    TNode *next = NULL;
    TNode(char c)
    {
        value = c;
        left = NULL;
        right = NULL;
    }
    TNode()
    {
        left = NULL;
        right = NULL;
    }
    friend class Stack;
    friend class expression_tree;
};
class Stack
{
    TNode *head = NULL;

public:
    void push(TNode *);
    TNode *pop();
    friend class expression_tree;
};
class expression_tree
{
public:
    void inorder(TNode *x)
    {
        // cout<<"Tree in InOrder Traversal is: "<<endl;
        if (x == NULL)
            return;
        else
        {
            inorder(x->left);
            cout << x->value << "  ";
            inorder(x->right);
        }
    }
};

void Stack::push(TNode *x)
{
    if (head == NULL)
    {
        head = x;
    }
    // We are inserting here nodes at the top of the stack [following LIFO principle]
    else
    {
        x->next = head;
        head = x;
    }
}
TNode *Stack::pop()
{
    // Popping out the top most[ pointed with head] element
    TNode *p = head;
    head = head->next;
    return p;
}
int main()
{
    string s = "ABC*+D/";
    // If you  wish take input from user:
    // cout << "Insert Postorder Expression: " << endl;
    // cin >> s;
    Stack e;
    expression_tree a;
    TNode *x, *y, *z;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        // if read character is operator then popping two
        // other elements from stack and making a binary
        // tree
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            z = new TNode(s[i]);
            x = e.pop();
            y = e.pop();
            z->left = y;
            z->right = x;
            e.push(z);
        }
        else
        {
            z = new TNode(s[i]);
            e.push(z);
        }
    }
    cout << " The Inorder Traversal of Expression Tree: ";
    a.inorder(z);
    return 0;
}
