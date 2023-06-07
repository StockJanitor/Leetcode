/*
Stack

LIFO - last in first out
ADT - Abstract data type

*/

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size; // current size of storing variable
    int top;  // top/last of storing variable
    int *S;
};

void Create(struct Stack *st)
{
    printf("Enter Size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack s)
{
    // display from the top, reduce 1 by 1 till 0
    for (int i = s.top; i >= 0; i--)
    {
        printf("%d ", s.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        // increase top, then assign x to new indexx
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
int main()
{
    struct Stack st;
    Create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    Display(st);

    return 0;
}
