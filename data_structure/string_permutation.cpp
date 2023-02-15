#include <stdio.h>
#include <iostream>
using namespace std;

void perm(char s[], int k)
{
    static int A[10] = {0};
    static char Res[10];

    int i;
    if (s[k] == '\0')
    {
        Res[k] = '\0';
        printf(Res);
        printf("\n");
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    char B[] = "abc";
    perm(B, 0);
    return 0;
}