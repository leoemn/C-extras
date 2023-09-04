#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* SortList(node *link1, node *link2);
void PrintList(node *head);
void InsertSorted(node **head, int data);

int main(void)
{
    node *link1 = NULL;
    node *link2 = NULL;

    //Creating linked lists with 5 elements in it.
    for (int i = 0 ; i < 5 ; i++)
    {
        int number1, number2;
        printf("Enter the element for first linked list: ");
        scanf("%d", &number1);
        InsertSorted(&link1, number1);

        printf("Enter the element for second linked list: ");
        scanf("%d", &number2);
        InsertSorted(&link2, number2);
    }

    node *MergedList = SortList(link1, link2);
    printf("Merged and Sorted List: \n");
    PrintList(MergedList);

    // Freeing up allocated memory
    while (MergedList != NULL)
    {
        node *temp = MergedList;
        MergedList = MergedList->next;
        free(temp);
    }

    return 0;
}

void InsertSorted(node **head, int data)
{
    node *NewNode = malloc(sizeof(node));
    NewNode->data = data;
    NewNode->next = NULL;

    if (*head == NULL || (*head)->data >= NewNode->data)
    {
        NewNode->next = *head;
        *head = NewNode;
    }
    else
    {
        node *current = *head;
        while (current->next != NULL && current->next->data < NewNode->data)
        {
            current = current->next;
        }
        NewNode->next = current->next;
        current->next = NewNode;
    }
}

node* SortList(node *link1, node *link2)
{
    node *merged = NULL, **lastPtr = &merged;

    while (link1 && link2)
    {
        if (link1->data < link2->data)
        {
            *lastPtr = link1;
            link1 = link1->next;
        }
        else
        {
            *lastPtr = link2;
            link2 = link2->next;
        }
        lastPtr = &((*lastPtr)->next);
    }

    if (link1) 
        *lastPtr = link1;
    else 
        *lastPtr = link2;

    return merged;
}

void PrintList(node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
