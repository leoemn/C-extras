/*Create a program that sorts an array of integers in ascending order using the selection sort 
algorithm and pointers.*/

#include<stdio.h>
#include<stdlib.h>

//Functions prototype.
void SortArray(int *a, int length);

int main(void)
{
    int a[] = {2, 5, 1, 15, 3, 4, 25};
    int length = sizeof(a) / sizeof(a[0]);

    SortArray(a, length);
}
void SortArray(int *a, int length)
{
    int *end = a + length;
    int max;
    while (a < end)
    {
        max = *a;
    }
    
}