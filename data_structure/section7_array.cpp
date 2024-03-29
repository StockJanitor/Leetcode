/*
array 
linear search takes O(n)
binary search takes O(log n) 
- starts in the middle and then break down into parts, famous for log n time

*/

#include <stdio.h>
#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;   // totla size
    int length; // current length
};

////////////////////////////////////////////// Swap //////////////////////////////////////////////
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

////////////////////////////////////////////// Display //////////////////////////////////////////////
void Display(struct Array arr)
{
    int i;
    printf("elements are\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

////////////////////////////////////////////// Append //////////////////////////////////////////////
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

////////////////////////////////////////////// Insert //////////////////////////////////////////////
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

////////////////////////////////////////////// Delete //////////////////////////////////////////////
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

////////////////////////////////////////////// Get //////////////////////////////////////////////
int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

////////////////////////////////////////////// Set //////////////////////////////////////////////
void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

////////////////////////////////////////////// Max //////////////////////////////////////////////
int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

////////////////////////////////////////////// Min //////////////////////////////////////////////
int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

////////////////////////////////////////////// Sum //////////////////////////////////////////////
int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

////////////////////////////////////////////// Avg //////////////////////////////////////////////
float Avg(struct Array arr)
{
    // float avg = Sum(arr)/arr.length;  // <--- this doesnt convert sum to float, must convert before divide
    return (float)Sum(arr) / arr.length;
}

////////////////////////////////////////////// Reverse //////////////////////////////////////////////
void Reverse(struct Array *arr)
{
    int *B = new int[arr->length];
    for (int i = arr->length - 1, j = 0; i >= 0; j++, i--)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}
void Reverse2(struct Array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        Swap(&arr->A[i], &arr->A[j]);
    }
}

////////////////////////////////////////////// Sorted //////////////////////////////////////////////
void InsertSort(struct Array *arr, int x)
{

    int i = arr->length - 1;
    if (arr->length == arr->size)
    {
        return;
    }
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

////////////////////////////////////////////// Rearrange //////////////////////////////////////////////
void Rearrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}

////////////////////////////////////////////// Merge Arrays //////////////////////////////////////////////
// returning a pointer
struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    // assign pointer to return later
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // while i and j are in length
    while (i < arr1->length && j < arr2->length)
    {
        // if arr1 is smaller,
        if (arr1->A[i] < arr2->A[j])
        {
            // 1st assign to A[k], then increment k; same applies for i
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

////////////////////////////////////////////// Union Arrays //////////////////////////////////////////////
struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    // assign pointer to return later
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // while i and j are in length
    while (i < arr1->length && j < arr2->length)
    {
        // if arr1 is smaller, assign smaller
        if (arr1->A[i] < arr2->A[j])
        {
            // 1st assign to A[k], then increment k; same applies for i
            arr3->A[k++] = arr1->A[i++];
        }
        // if arr2 is smaller, assign smaller
        else if (arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        // if equal assign either, then increase both
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    // if there is any remainder, just add to arr3
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

////////////////////////////////////////////// Intersection Arrays //////////////////////////////////////////////
struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    // assign pointer to return later
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // while i and j are in length
    while (i < arr1->length && j < arr2->length)
    {
        // if arr1 is smaller, assign smaller
        if (arr1->A[i] < arr2->A[j])
        {
            // 1st assign to A[k], then increment k; same applies for i
            i++;
        }
        // if arr2 is smaller, assign smaller
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        // if equal assign either, then increase both
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

////////////////////////////////////////////// Difference Arrays //////////////////////////////////////////////
struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    // assign pointer to return later
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // while i and j are in length
    while (i < arr1->length && j < arr2->length)
    {
        // if arr1 is smaller, assign smaller
        if (arr1->A[i] < arr2->A[j])
        {
            // 1st assign to A[k], then increment k; same applies for i
            arr3->A[k++] = arr1->A[i++];
        }
        // if arr2 is smaller, assign smaller
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        // if equal assign either, then increase both
        else
        {
            i++;
            j++;
        }
    }

    // if there is any remainder, just add to arr3
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    // struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    // struct Array arr2 = {{3, 6, 7, 15, 20}, 10, 5};
    // struct Array *arr3;
    int A[5] = {2, 3, 4, 5, 6};
    int *ptr = A;
    // printf("%d\n", isSorted(arr));
    printf("%d", *ptr);

    // Set(&arr, 4,5);
    // Rearrange(&arr);

    // arr3 = Difference(&arr1, &arr2);

    // Display(*arr3);

    return 0;
}