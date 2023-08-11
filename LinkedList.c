#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

//Function Prototype.
void FreeLinkedList(node *list);

int main(void)
{
    node *list = NULL;

    for (int i = 0 ; i <= 4 ; i++)
    {
        int number;
        scanf("%d", &number);
        node *newnode = malloc(sizeof(node));
        newnode -> data = number;
        newnode -> next = list;
        list = newnode;
    }

    node *tmp = list;
    while (tmp != NULL)
    {
        printf("%d ", tmp -> data);
        tmp = tmp -> next;
    }

   FreeLinkedList(list);
}
void FreeLinkedList(node *list)
{
    while (list != NULL)
    {
        node *nextNode = list->next;
        free(list); // Free the current node
        list = nextNode;
    }
}
