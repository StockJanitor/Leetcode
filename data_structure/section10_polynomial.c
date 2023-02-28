#include <stdio.h>

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
    scanf("%d",p->n);
    p->terms =(struct Term*)malloc(p->n*sizeof(struct Term));

}

int main()
{
    return 0;
}