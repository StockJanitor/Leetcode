#include <iostream>

using namespace std;

int partition(int numbers[], int i, int k)
{
    int l, h, midpoint, pivot, temp;
    bool done;

    // get midpoint
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];

    done = false;
    l = i;
    h = k;

    // swap nums < pivot to front, nums > pivot to back
    while (!done)
    {

        // finding the num thats larger than pivot
        while (numbers[l] < pivot)
        {
            l++;
        }

        // finding the num thats smaller than pivot
        while (pivot < numbers[h])
        {
            h--;
        }

        // if index larger or equal to h
        if (l >= h)
        {
            // sorting is done
            done = true;
        }
        else
        {
            // swap the numbers at l with h
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
            l++;
            h--;
        }

    }
    // return the last index, so we can specify partitions
    return h;
}

void quicksort(int numbers[], int i, int k)
{
    // if 1 element or less just return;
    if (i >= k)
    {
        return;
    }
    // get the middle index
    int j = partition(numbers, i, k);

    // partition front part
    quicksort(numbers, i, j);

    // partition backpart
    quicksort(numbers, j + 1, k);
}
int main()
{

    return 0;
}