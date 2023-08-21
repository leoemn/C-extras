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

    concate(a, b, length);
}
char *concate(char *a, char *b, int length)
{
    char *c = malloc(sizeof(char));
    for(int i = 0 ; i < length ; i++)
    {
        
    }
}
