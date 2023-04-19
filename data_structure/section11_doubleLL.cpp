#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;

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

DoublyLinkedList::DoublyLinkedList(int *A, int n)
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
    while (p != nullptr)
    {
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr)
        {
            cout << " <-> " << flush;
        }
    }
    cout << endl;
}

int DoublyLinkedList::length()
{
    int len = 0;
    Node *p = head;
    while (p != nullptr)
    {
        len++;
        p = p->next;
    }
    return len;
}

void DoublyLinkedList::insert(int index, int x)
{
    if (index < 0 || index > length())
    {
        return;
    }

    // create a head pointer
    Node *p = head;

    // initialize new Node
    Node *t = new Node;
    t->data = x;

    if (index == 0)
    {
        // prev is null
        t->prev = nullptr;
        // head becomes after t
        t->next = head;
        // head prev is t
        head->prev = t;
        // head becomes t
        head = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        // t prev becomes p
        t->prev = p;
        t->next = p->next;

        // the previous of next node, should become t
        if (p->next)
        {
            p->next->prev = t;
        }

        p->next = t;
    }
}

int DoublyLinkedList::remove(int index)
{
    int x = -1;
    Node *p = head;

    if (index < 0 || index > length())
    {
        return x;
    }

    if (index == 1)
    {
        // head become next
        head = head->next;
        if (head)
        {
            // if head exists, prev becomes nullptr
            head->prev = nullptr;
        }
        // x becomes the data
        x = p->data;
        // delete p
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        // previous next becomes current node next
        p->prev->next = p->next;
        if (p->next)
        {
            // the previous of next node becomes current node previous
            p->next->prev = p->prev;
        }

        x = p->data;
        delete p;
    }
    return x;
}

void DoublyLinkedList::reverse()
{
    Node *p = head;
    Node *temp;
    while (p != nullptr)
    {
        // assign next to temp
        temp = p->next;
        // next become previous
        p->next = p->prev;
        p->prev = temp;

        // move the next node, which is prev after above assignment
        p = p->prev;

        // just in case this is the last node, we need check nullptr and switch position
        if (p->next == nullptr)
        {
            p->next = p->prev;
            p->prev = nullptr;

            // head becomes p
            head = p;
            break;
        }
    }
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node *p = head;
    while (head)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

int main()
{

    int A[]{1, 3, 5, 7, 9};

    DoublyLinkedList dll(A, sizeof(A) / sizeof(A[0]));
    cout << "Length: " << dll.length() << endl;

    dll.insert(0, 11);
    dll.insert(6, 13);
    dll.display();

    dll.remove(1);
    dll.remove(6);
    dll.display();

    dll.reverse();
    dll.display();

    return 0;
}