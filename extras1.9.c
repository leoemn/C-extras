/*Implement a function to find the second largest element in an integer array using pointers.*/

#include<stdio.h>
#include<limits.h>

//Function prototype.
int SecondLargest(int *arr, int n);

int main(void) 
{
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int Second = SecondLargest(arr, n);

    if (Second != INT_MIN) 
    {
        printf("The second largest element is %d\n", Second);
    } 
    else 
    {
        printf("There is no second largest element\n");
    }

    return 0;
}

int SecondLargest(int *arr, int n) 
{
    //Checks if array has more than two numbers. 
    if (n < 2) 
    {
        printf("Invalid input. Array size should be at least 2.");
        return INT_MIN;
    }

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) 
    {
        if (*(arr + i) > first) 
        {
            second = first;
            first = *(arr + i);
        }
        else if (*(arr + i) > second && *(arr + i) != first) 
        {
            second = *(arr + i);
        }
    }

    if (second == first) 
    {
        // No second largest element present in the array
        return INT_MIN;  
    }

    return second;
}
