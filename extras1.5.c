/*Create a program that sorts an array of integers in ascending order using the selection sort 
algorithm and pointers.*/

#include <stdio.h>

// Function prototype.
void SortArray(int *a, int length);

int main(void)
{
    int a[] = {2, 5, 1, 15, 3, 4, 25};
    int length = sizeof(a) / sizeof(a[0]);

    SortArray(a, length);

    return 0;
}

void SortArray(int *a, int length)
{
    int *min_ptr, *tmp_ptr;

    for (int *i = a; i < a + length - 1; i++)
    {
        min_ptr = i;
        for (int *j = i + 1; j < a + length; j++)
        {
            if (*min_ptr > *j)
            {
                min_ptr = j;
            }
        }
        
        int tmp = *i;
        *i = *min_ptr;
        *min_ptr = tmp;
    }

    for (int *i = a; i < a + length; i++)
    {
        printf("%d ", *i);
    }
}
