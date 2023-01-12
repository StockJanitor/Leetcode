#include <stdio.h>
#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;   // totla size
    int length; // current length
};

////////////////////////////////////////////// Display //////////////////////////////////////////////
void Display(struct Array arr)
{
    int i;
    printf("elements are\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d", arr.A[i]);
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
    if (index >= 0 && index <arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

////////////////////////////////////////////// Set //////////////////////////////////////////////
void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <arr->length)
    {
        arr->A[index] = x;
    }
}

////////////////////////////////////////////// Max //////////////////////////////////////////////
int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i <arr.length;i++)
    {
        if (arr.A[i]>max)
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
    for (int i = 1; i <arr.length;i++)
    {
        if (arr.A[i]<min)
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
    for (int i = 0; i<arr.length;i++)
    {
        sum += arr.A[i];
    }
    return sum;

}

////////////////////////////////////////////// Avg //////////////////////////////////////////////
float Avg(struct Array arr)
{
    // float avg = Sum(arr)/arr.length;  // <--- this doesnt convert sum to float, must convert before divide
    return (float)Sum(arr)/arr.length;
}




int main()
{
    struct Array arr = {{2, 3, 4, 5, 50}, 10, 5};
    int A[5] = {2,3,4,5,6};
    printf("%f\n", Avg(arr));
    // Set(&arr, 4,5);
    Display(arr);

    return 0;
}