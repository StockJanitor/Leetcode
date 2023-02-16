#include <stdio.h>
#include <iostream>
using namespace std;

struct Matrix
{
    // LowerTri matrix value
    int A[10];

    // dimension of matrix
    int n;
};
void Set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            // if same, they are in LowerTri value, print it
            if (i == j)
                printf("%d ", m.A[i]);
            // else print 0
            else
                printf("0 ");
        }
        printf("\n");
    }
}

class LowerTri
{
    private:
        // list pointer
        int *A;
        // dimension of matrix
        int n;
    
    public:
        LowerTri()
        {
            n = 2;
            A=new int[2*(2+1)/2];
        }
        LowerTri(int n)
        {
            this->n=n;
            A=new int[n*(n+1)/2];
        }
        ~LowerTri()
        {
            delete []A;
        }
        void Set(int i,int j,int x);
        int Get(int i,int j);
        void Display();
        int GetDimension(){return n;};

};
void LowerTri::Set(int i, int j,int x)
{
    if(i>=j)
        A[i*(i-1)/2+j-1]=x;

}
int LowerTri::Get(int i, int j)
{
    if (i>=j)
        return A[i*(i-1)/2+j-1];
    return 0;
}
void LowerTri::Display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            // if same, they are in LowerTri value, print it
            if (i >= j)
                printf("%d ", A[i*(i-1)/2+j-1]);
            // else print 0
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    int d;
    cout << "Enter Dimensions ";
    cin >> d;

    LowerTri lm(d);

    int x;
    cout << "Enter All Elements ";
    for (int i=1; i<=d;i++)
    {
        for (int j=1;j<=d;j++)
        {
            cin >> x;
            lm.Set(i,j,x);
        }
    }
    lm.Display();

    return 0;
}