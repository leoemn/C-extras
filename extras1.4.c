/*Write a program that swaps the values of two arrays of integers using pointers,
keeping the arrays' sizes the same.*/

#include<stdio.h>
#include<stdlib.h>

//Function prototype.
void SwapArrays(int *a, int*b, int length);

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int length = sizeof(a) / sizeof(a[0]);
    
    printf("Printing both arrays without swapping values.\n");
    printf("a = ");
    for (int i = 0 ; i < length ; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nb = ");
    for (int i = 0 ; i < length ; i++)
    {
        printf("%d ", b[i]);
    }
    SwapArrays(a, b, length);
    return 0;
}

void SwapArrays(int *a, int*b, int length)
{
    int *end = a + length;
    int *i = a;
    int *j = b; 

    while (i < end)
    {
        int tmp = *i;
        *i = *j;
        *j = tmp;
        i++;
        j++;
    }

    printf("\nboth arrays after swapping values.");
    printf("\na = ");
    for (int i = 0 ; i < length ; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nb = ");
    for (int i = 0 ; i < length ; i++)
    {
        printf("%d ", b[i]);
    }
}