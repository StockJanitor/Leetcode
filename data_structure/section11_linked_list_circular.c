#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    // allocate in heap
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        // creating new node
        t = (struct Node *)malloc(sizeof(struct Node));

        // assign data at i
        t->data = A[i];

        // which points to the head,
        t->next = last->next;

        // last is still the head, so head->next is t
        last->next = t;

        // last becomes t
        last = t;
    }
}

void display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
}
void display_recursive(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        display_recursive(h->next);
    }
    flag = 0;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    // check if index is 0
    if (index == 0)
    {
        // initialize new node
        t = (struct Node *)malloc(sizeof(struct Node));
        // assign data
        t->data = x;

        // if head is NULL then itself is head and last
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        // else, t will be last->next, t->next will be head, and t becomes head
        else
        {
            while (p->next != Head)
            {
                p = p->next;
                p->next = t;
                t->next = Head;
                Head = t;
            }
        }
    }
    // else if index is not 0,
    else
    {
    }
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    display_recursive(Head);
    return 0;
}