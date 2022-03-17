#include <iostream>

using namespace std;

struct node
{
    int data;
    node *pNext;
};
typedef node NODE;
struct List
{
    node *pHead;
    node *pTail;
};
typedef List LIST;

void init(LIST &);
int isEmpty(LIST);
NODE *getNode(int);
void addHead(LIST, NODE *);
void addTail(LIST, NODE *);
void input(LIST &);
void output(LIST);
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
NODE *getNode(int data)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->data = data;
    p->pNext = NULL;
    return p;
}
void addHead(LIST l, NODE *p)
{
    if (isEmpty(l))
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void addTail(LIST l, NODE *p)
{
    if (isEmpty(l))
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void input(LIST &l)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        NODE *p = getNode(data);
        if (p != NULL)
            addHead(l, p);
    }
}
void output(LIST l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
}