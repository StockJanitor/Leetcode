#include <stdio.h>
#include <stdlib.h>
// #include <iostream>

// using namespace std;

struct Element
{
    int i; // first dimension
    int j; // second dimension
    int x; // value itself
};

struct Sparse
{
    int m;   // rows
    int n;   // columns
    int num; // number of non-zero elements
    struct Element *ele;
};

void create(struct Sparse *s)
{
    printf("Enter dimensions ");
    scanf("%d%d", &s->m, &s->n);
    printf("Number of non-zero ");
    scanf("%d", &s->num);

    // create array size of s->num
    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

    printf("Enter non-zero Elements ");
    // get each dimension and value
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}

void display(struct Sparse s)
{
    int i, j, k = 0;
    // each row
    for (i = 0; i < s.m; i++)
    {
        // each column
        for (j = 0; j < s.n; j++)
        {
            // if there is value in element[i][j], print the element, increment k
            if (i == s.ele[k].i && j == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
            }
            // else it is 0
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    // allocation of heap
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    // size of s1+s2
    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));
    while (i < s1->num && j < s2->num)
    {
        // if row is smaller
        if (s1->ele[i].i < s2->ele[j].i)
        { // ele[k] assign s1 ele[i]
            sum->ele[k++] = s1->ele[i++];
        }
        else if (s1->ele[i].i > s2->ele[j].i)
        { // ele[k] assign s2 ele
            sum->ele[k++] = s2->ele[j++];
        }
        // rows will be same, then we compare columns
        else
        {
            // check which column smaller
            if (s1->ele[i].j < s2->ele[j].j)
            {
                sum->ele[k++] = s1->ele[i++];
            }
            else if (s1->ele[i].j > s2->ele[j].j)
            {
                sum->ele[k++] = s2->ele[j++];
            }
            else
            {
                // if row and column is same, we add them
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
    {
        sum->ele[k++] = s1->ele[i];
    }
    for (; j < s2->num; j++)
    {
        sum->ele[k++] = s2->ele[j];
    }

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
}
int main()
{
    struct Sparse s;
    create(&s);
    display(s);
    return 0;
}