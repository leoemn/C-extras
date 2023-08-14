/*Write a program that allocates memory for a single integer using `malloc` and sets its value to 44. 
Print the value.*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *a = malloc(sizeof(int));

    //Check if memory is succesfully allocated
    if (a == NULL)
    {
        printf("memory allocation failed");
        return 1;
    }

    *a = 44;
    printf("%d", *a);
    free(a); //Free the allocated memory
}
