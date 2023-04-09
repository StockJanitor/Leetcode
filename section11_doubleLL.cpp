#include <iostream>
using namespace std;

class Node
{
    public:
        Node * prev;
        int data;
        Node * next;

};

class DoublyLinkedList
{
    private:
        Node*head;
    public:
        DoublyLinkedList(); // constructor
        DoublyLinkedList(int A[], int n);
        ~DoublyLinkedList();
        void display();
        int length();
        void insert(int index, int x);
        int remove(int index);
        void reverse();
};

DoublyLinkedList::DoublyLinkedList()
{
    head = new Node;
    head->prev = nullptr;
    head->data = 0;
    head->next = nullptr;
}

DoublyLinkedList::DoublyLinkedList(int *A, int n )
{
    head = new Node;
    head->data = A[0];
    head->next = nullptr;
    head->prev = nullptr;
    Node *tail = head;

    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;

        // t->prev is head
        t->prev = tail;
        t->data = A[i];

        // head->next assign to t->next;
        t->next = tail->next;

        // head->next becomes t
        tail->next = t;

        // t is now tail
        tail = t;
        
        // head next becomes t, tail becomes t, t->next is nullptr
    }
}

void DoublyLinkedList::display()
{
    Node *p = head;
    while (p!=nullptr)
    {
        cout << p->data<< flush;
        p=p->next;
        if (p != nullptr)
        {
            cout << " <-> " << flush;
        }
    }
    cout << endl;
}
