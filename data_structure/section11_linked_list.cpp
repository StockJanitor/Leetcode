#include <iostream>

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
    first->next =NULL;

    // last = first
    last = first;

    for(i=1;i<n;i++)
    {
        // create new Node and assign values
        t = new Node;
        t->data=A[i];
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
    while(first)
    {
        // first becomes next
        first = first->next;

        // delete previous first, p
        delete p;

        // p then assign to first again
        p=first;
    }
}
int main()
{
    return 0;
}