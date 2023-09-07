/*Create a program to reverse a doubly linked list.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

// Function prototypes
node *ReverseDoublyLinkedList(node *list);
void PrintDoublyLinkedList(node *list);
void FreeDoublyLinkedList(node *list);

int main(void)
{
    int n;
    printf("Enter the number of elements you want in the doubly linked list: ");
    scanf("%d", &n);

    node *list = NULL;
    node *tail = NULL;

    for (int i = 0 ; i < n ; i++) 
    {
        int number;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &number);

        node *NewNode = malloc(sizeof(node));

        NewNode->data = number;
        NewNode->prev = tail;
        NewNode->next = NULL;

        if (list == NULL) {
            list = NewNode;
        } else {
            tail->next = NewNode;
        }

        tail = NewNode;
    }

    printf("\nOriginal Doubly Linked List: ");
    PrintDoublyLinkedList(list);

    // Reverse the doubly linked list
    list = ReverseDoublyLinkedList(list);

    printf("\nReversed Doubly Linked List: ");
    PrintDoublyLinkedList(list);

    FreeDoublyLinkedList(list);

    return 0;
}

node *ReverseDoublyLinkedList(node *list)
{
    node *current = list;
    node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        list = temp->prev;
    }

    return list;
}

void PrintDoublyLinkedList(node *list)
{
    node *temp = list;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void FreeDoublyLinkedList(node *list)
{
    while (list)
    {
        node *NextNode = list->next;
        free(list);
        list = NextNode;
    }
}
