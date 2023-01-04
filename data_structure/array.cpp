#include <stdio.h>
#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;   // totla size
    int length; // current length
};

void Display(struct Array arr)
{
    int i;
    printf("elements are\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d", arr.A[i]);
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    // index msut be less than or equal to current length
    if (index >= 0 && index <= arr->length)
    {
        // loop from back, as long as i > index, assign wtih previous value
        for (int i = arr->length; i > index; i--)
        {
            // assign current with previous value
            arr->A[i] = arr->A[i - 1];
        }
        // index value is = x, assign after all other variables are moved
        arr->A[index] = x;

        // upon insert, length increases by 1
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    printf("%d\n", Delete(&arr, 3));
    Display(arr);

    return 0;
}