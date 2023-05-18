#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;

} *poly = NULL;

void create()
{
    struct Node *t, *last = NULL;
    int num, i;

    printf("Enter number of terms");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp\n");

    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly == NULL)
        {

            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%dx%d +", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    create();
    Display(poly);
    return 0;
}