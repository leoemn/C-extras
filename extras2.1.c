/*Implement a simple linked list with a function to insert an element at the beginning.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

//Functions prototype
void PrintList(node *list);
void FreeNode(node *list);

int main(void)
{
    int n;
    printf("Enter the number of element: ");
    scanf("%d", &n);

    node * list = NULL;

    for (int i = 0 ; i < n ; i++)
    {
        int number;
        printf("enter an element: ");
        scanf("%d", &number);

        node *NewNode = malloc(sizeof(node));
        NewNode -> data = number;
        NewNode -> next = list;
        list = NewNode;
    }
    PrintList(list);
    FreeNode(list);
}
void PrintList(node *list)
{
    node *temp = list;
    while (temp)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}
void FreeNode(node *list)
{
    
    while (list)
    {
        node *NextNode = list -> next;
        free(list);
        list = NextNode;  
    }
    
}

