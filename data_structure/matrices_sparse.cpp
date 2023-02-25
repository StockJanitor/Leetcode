#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

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
struct Sparse * add (struct Sparse*s1, struct Sparse *s2)
{
    struct Sparse *sum;
    sum= (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele=

}
int main()
{
    struct Sparse s;
    create(&s);
    display(s);
    return 0;
}