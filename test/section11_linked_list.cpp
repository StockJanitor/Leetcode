#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void display();
    void insert(int index, int x);
    int remove(int index);
    int length();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    // create new Node
    first = new Node;

    // assign first data
    first->data = A[0];

    // next is NULL
    first->next = NULL;

    // last = first
    last = first;

    for (i = 1; i < n; i++)
    {
        // create new Node and assign values
        t = new Node;
        t->data = A[i];
        t->next = NULL;

        // last->next should be t
        last->next = t;
        // last becomes t
        last = t;
    }
}

LinkedList::~LinkedList()
{
    // assign p as first
    Node *p = first;
    while (first)
    {
        // first becomes next
        first = first->next;

        // delete previous first, p
        delete p;

        // p then assign to first again
        p = first;
    }
}

void LinkedList::display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void LinkedList::insert(int index, int x)
{
    if (index < 0 || index > length())
    {
        return;
    }

    Node *t, *p = first;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
};
int LinkedList::remove(int index)
{
    Node *p, *q = NULL;
    int x = -1;
    if (index < 0 || index > length())
    {
        return -1;
    }
    if (index == 0)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
};
int LinkedList::length()
{
    Node *p = first;
    int x = 0;
    while (p)
    {
        x += 1;
        p = p->next;
    }
    return x;
};

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    LinkedList test(A, 5);
    test.display();
    return 0;
}