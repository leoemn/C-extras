/*Implement a function to delete all occurrences of a specific value from a linked list.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void DelOccurrences(node **head_ref, int del);
void PrintList(node *list);
void FreeNodes(node *list);

int main(void)
{
    int n;
    printf("Enter the number of elemets you want in the list: ");
    scanf("%d",&n);

    node *list = NULL;

    for (int i = 0 ; i < n ; i++)
    {
        int number;
        printf("enter the element: ");
        scanf("%d", &number);

        node *NewNode = malloc(sizeof(node));

        NewNode -> data = number;
        NewNode -> next = list;
        list = NewNode;
    }

    printf("List before deleting any element: ");
    PrintList(list);

    int del;
    printf("\nenter the element you want to delet: ");
    scanf("%d", &del);

    DelOccurrences(&list, del);
    
    printf("List after deleting the element: ");
    PrintList(list);

    FreeNodes(list);
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

void DelOccurrences(node **head_ref, int del)
{
    node *temp = *head_ref;
    node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == del)
        {
            node *to_delete = temp;

            if (temp == *head_ref)
            {
                *head_ref = temp->next;
                prev = NULL;
            }
            else
            {
                prev->next = temp->next;
            }

            temp = temp->next;
            free(to_delete);
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

void FreeNodes(node *list)
{
    while(list)
    {
        node *NextNode = list -> next;
        free(list);
        list = NextNode;
    }
}