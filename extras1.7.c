/*Write a program to find the frequency of each character in a given string using a dynamically 
allocated array of counters.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Functions prototype.
int *InitializeCounterArray(int size);
void CountFrequncy(int *counter, const char *str);
void PrintFrequency(int *counter, int size);

//Global Variable
int size = 256; //To use extended ASCII

int main(void)
{
    //Assuming user will not enter longer string. 
    char input[256];
    printf("Enter a string: ");

    //Using fgets to take input from the user.
    fgets(input, sizeof(input), stdin);

    //Removing newline character added by fgets.
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
    }

    int *counter = InitializeCounterArray(size);

    CountFrequncy(counter, input);

    printf("Printing frequency");
    PrintFrequency(counter, size);

    //Free allocated memory
    free(counter);
}

int *InitializeCounterArray(int size)
{
    int *counter = calloc(size, sizeof(int));
    if (counter == NULL)
    {
        printf("memory allocation FAILED");
        return NULL;
    }
    return counter;
}

void CountFrequncy(int *counter, const char *str)
{
    while (*str)
    {
        //Using the character as the index and incrementing its counter
        counter[(int)*str]++;
        str++;
    }
}

void PrintFrequency(int *counter, int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        if (counter[i] > 0)
        {
            printf("frequeny of %c is %d\n", i, counter[i]);
        }
    }
}
