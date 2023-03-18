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
int length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

void display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
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

    // check if index is valid
    if (index < 0)
    {
        return;
    }
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
    // else if index is not 0, insert at index
    else
    {
        // find previous node
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        // t->next will be previous node->next
        t->next = p->next;
        // previous node->next will be t
        p->next = t;
    }
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    display(Head);
    insert(Head, 3, 10);
    display(Head);
    return 0;
}