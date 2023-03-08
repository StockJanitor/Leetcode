#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    // create first Node in heap
    first = (struct Node *)malloc(sizeof(struct Node));
    // assign 1st data
    first->data = A[0];
    // next is NULL
    first->next = NULL;
    // last is first node now
    last = first;

    for (i = 1; i < n; i++)
    {
        // create t in heap as Node
        t = (struct Node *)malloc(sizeof(struct Node));
        // assign current data
        t->data = A[i];
        t->next = NULL;

        // current last's next will be t,
        last->next = t;
        // we over write current last to t
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int count(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return 0;
    else
        x = count(p->next);
    return x + 1;
}

int sum(struct Node *p)
{
    int total = 0;
    if (p == 0)
        return 0;
    else
        total = sum(p->next);
    return total + p->data;
}

void rec_display(struct Node *p)
{
    if (p != NULL)
    {
        rec_display(p->next);
        printf("%d ", p->data);
    }
}

int rec_max(struct Node *p)
{
    int max = 0;

    if (p == 0)
    {
        return 0;
    }

    max = rec_max(p->next);
    if (max > p->data)
    {
        return max;
    }
    else
    {
        return p->data;
    }
}

struct Node *search(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return search(p->next, key);
}

struct Node *transposition_search(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            // if data is what we look for,
            // next Node into previous, q, node
            q->next = p->next;

            // store p->next to first
            p->next = first;

            // save p as frist
            first = p;
        }
        // store previous node as q
        q = p;
        // next node as p
        p = p->next;
    }
}

void insert(struct Node *p, int index, int value)
{
    // check index
    if (index < 0 || index > count(p))
    {
        return;
    }
    // if within index, create node
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    int i;
    // if index 0
    if (index == 0)
    {
        // current first becomes after t
        t->next = first;
        // first becomes t
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            // current become the next node
            p = p->next;
        }

        // t->next points to after p
        // p->next points to t
        // so t is inserted after p and before p->next
        t->next = p->next;
        p->next = t;
    }
}

void insert_sort(struct Node *p, int value)
{
    struct Node *q = NULL, *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        // if p exists and data is less than value, we keep going
        while (p && p->data < value)
        {
            // q assign p, and p becomes next
            q = p;
            p = p->next;

            // this will stop if value becomes greater than p->data, so the q will be previous node, and p will be next node that has larger data
        }
        if (p == first)
        {
            // if p is the first node, we insert data into left of it
            t->next = first;
            first = t;
        }
        else
        {
            // current q->next will be after t
            t->next = q->next;
            // q->next will be t
            q->next = t;
        }
    }
}
int main()
{

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    Display(first);

    insert_sort(first, 15);
    Display(first);

    return 0;
}