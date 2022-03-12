#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *pNext;
};
typedef node NODE;
struct List
{
    node *pHead;
    node *pTail;
};
typedef List LIST;

void Init(LIST &);
int IsEmpty(LIST);
NODE *GetNode(int data);
void AddHead(LIST, NODE *);
void AddTail(LIST, NODE *);

void Input(LIST &);
void Output(LIST);
int main()
{

    return 0;
}

void init(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
int isEmpty(LIST l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}
NODE *GetNode(int data)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->data = data;
    p->pNext = NULL;
    return p;
}
void AddHead(LIST l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead == p;
        l.pTail == p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void AddTail(LIST l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead == p;
        l.pTail == p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void Input(LIST &l)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        NODE *p = GetNode(data);
        if (p != NULL)
            AddHead(l, p);
    }
}
void Output(LIST l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
}