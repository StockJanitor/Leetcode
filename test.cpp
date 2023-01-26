#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // int nums = new int[5]; // Create array

    int nums[5]= {5,6,7,8,9};
    int j = 0;
    for(int i = 0; i<5;i++)
    {   
        cout << "newline"<<endl;
        cout << j << endl;
        cout << nums[j++] << endl;
        cout << j << endl;
    }
}