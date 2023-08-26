/*Write a program to find the common elements between two arrays of integers using pointers 
and dynamic memory allocation.*/

#include<stdio.h>
#include<stdlib.h>

//Function prototype.
int *CommonElement(int *arr1, int *arr2, int length1, int length2, int *count);

int main(void)
{
    //Initializing arrays.
    int arr1[] = {1, 51, 25, 57, 6, 58, 44};
    int arr2[] = {4, 36, 44, 77, 57, 18, 43, 51, 66};

    //getting length of arrays.
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    int length2 = sizeof(arr2) / sizeof(arr2[0]);

    //Variable to store count of common elements.
    int count = 0;

    int *arr3 = CommonElement(arr1, arr2, length1, length2, &count);

    for (int i = 0 ; i < count ; i++)
    {
        printf("%d ", *(arr3 + i));
    }

    free(arr3);
}


int *CommonElement(int *arr1, int *arr2, int length1, int length2, int *count)
{
    for (int i = 0 ; i < length1 ; i++)
    {
        for (int j = 0 ; j < length2 ; j++)
        {
            if (*(arr1 + i) == *(arr2 + j))
            {
                (*count)++;
                break;
            }
        }
    }
    //Allocating dynamic memory using malloc 
    int *arr3 = malloc(sizeof(int) * (*count));

    //Checking if memory allocation was successful.
    if (!arr3)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    int k = 0;
    
    for (int i = 0 ; i < length1 ; i++)
    {
        for (int j = 0 ; j < length2 ; j++)
        {
            if (*(arr1 + i) == *(arr2 + j))
            {
                *(arr3 + k) = *(arr1 + i);
                k++;
                break;  
            }
        }
    }

    return arr3;
}
