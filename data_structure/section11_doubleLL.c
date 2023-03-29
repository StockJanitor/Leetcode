#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node*t, *last;
    int i;
    first =(struct Node *)malloc(sizeof(struct Node));

    first->data = A[0];
    first ->prev = first->next = NULL;
    last = first;

    
}


int main()
{


    return 0;
}