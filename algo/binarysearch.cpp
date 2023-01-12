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

int BinarySearch(struct Array arr, int key)
{
    // left, mid and right of array
    int low, mid, high;
    low = 0;
    high = arr.length - 1;

    while (low <= high)
    {
        // returns floor value
        mid = (low + high) / 2;

        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    // if not found
    return -1;
}

int RSBinSearch(int a[], int l, int h, int key)
{
    int mid = (l + h) / 2;
    if (l <= h)
    {
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return RSBinSearch(a, l, mid - 1, key);
        }
        else
        {
            return RSBinSearch(a, mid + 1, h, key);
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    int arr1[5] = {2, 3, 4, 5, 6};
    printf("%d\n", RSBinSearch(arr1, 0, arr.length, 5));
    Display(arr);
    return 0;
}