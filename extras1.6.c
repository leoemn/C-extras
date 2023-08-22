/*Implement a function that concatenates two strings (char arrays) and returns the result. 
Use dynamic memory allocation for the concatenated string.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Functions prototype
char *concate(char *a, char* b, int length);

int main(void)
{
    char *a = "Hello";
    char *b = "World";
    int length = strlen(a) + strlen(b);

    char *c = concate(a, b, length);
    
    //Printing concated string.
    printf("%s", c);

    //free allocated memory.
    free(c);

    return 0;
}
char *concate(char *a, char *b, int length)
{
    //Allocating memory using malloc.
    char *c = malloc(sizeof(char) + length + 2);

    //Checking if memory allocation was successful.
    if (c == NULL)
    {
        printf("Memory Allocation Failed");
        return NULL;
    }

    //Pointer to track current position in string.
    char *tmp = c;

    //Copying first string in c
    while (*a)
    {
        *tmp = *a;
        a++;
        tmp++; 
    }

    //Adding space between both string.
    *tmp = ' ';
    tmp++;

    //Concating second string in c
    while (*b)
    {
        *tmp = *b;
        b++;
        tmp++;
    }

    //Adding null terminator to end the string.
    *tmp = '\0';
    return c;
}
