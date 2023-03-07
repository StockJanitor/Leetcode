#include <stdio.h>
#include <stdlib.h>
struct Term
{
    int coeff;
    int exp;
};
struct Poly
{
    int n; // size of numbers
    struct Term *terms;
};

void create(struct Poly *p)
{
    int i;

    printf("Numbers of terms");
    scanf("%d", &p->n);
    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    printf("Enter terms \n");
    // enter each coeff and exp
    for (i = 0; i < p->n; i++)
    {
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void display(struct Poly p)
{
    int i;
    for (i = 0; i < p.n; i++)
    {
        printf("%dx%d+", p.terms[i].coeff, p.terms[i].exp);
    }
    printf("\n");
}




int main()
{
    struct Poly p1;
    create(&p1);
    display(p1);
    return 0;
}