/*
Stack
last in first out

*/
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter Size");
    // setting the size of stack
    scanf("%d", &st->size);

    // set the top to -1
    st->top = -1;

    // initialize the stack
    st->S = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}