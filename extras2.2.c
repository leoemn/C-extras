/*Create a program to count the number of nodes in a linked list.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

//Functions prototype
int CountNode(node *list);
void FreeNode(node *list);

int main(void)
{
    int n;
    printf("enter the number of element: ");
    scanf("%d", &n);
    
    node *list = NULL;
    
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
    int count = CountNode(list);
    printf("Number of nodes in this linked list is: %d", count);
    FreeNode(list);
}

int CountNode(node *list)
{
    int count = 0;
    node *temp = list;
    while(temp)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
        count++;
    }

    return count;
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