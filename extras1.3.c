/*Implement a function that takes an array of integers and its size as parameters and returns the sum of
its elements using pointers.*/

#include<stdio.h>
#include<stdlib.h>

//Functions prototype.
int SumOfElements(int *a, int length);

int main(void)
{   
    int a[] = {1,2,3,4,5};
    //Calculating the size of an array 
    int length = sizeof(a) / sizeof(a[0]);

    int sum = SumOfElements(a, length);

    printf("sum of the elements is: %d", sum);
    return 0;
}

int SumOfElements(int *a, int length)
{
    //Performing pointer arithmetic, gives pointer to an element which is after the last element.
    int *end = a + length;
    int sum = 0;

    while (a < end)
    {
        sum = sum + *a;
        //Moving pointer to the next element in the array
        a++;
    }
    return sum;
}
