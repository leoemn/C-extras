/*Create a program that dynamically allocates memory for an array of `n` integers,
where `n` is user-input. Populate the array with user-input values and display them.*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n;
    printf("Enter size of an array: ");
    scanf("%d", &n);

    //Dynamically allocating memory using malloc.
    int *a = malloc(sizeof(int) * n);

    //Checking if memory is successfully allocated.
    if (a == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    //Input values from the user.
    for (int i = 0 ; i < n ; i++)
    {
        printf("Enter an element for element: ");
        scanf("%d", &a[i]);
    }

    //Printing the values.
    for (int i = 0 ; i < n ; i++)
    {
        printf("%d ", a[i]);
    }

    //Free the allocated values.
    free(a);
    return 0;
}