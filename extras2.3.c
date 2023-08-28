/*Write a function that takes a linked list as input and returns its middle element.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

//Functions prototype.
node *MiddleElement(node *list);
void PrintList(node *list);
void FreeNodes(node *list);

int main(void)
{
    int n;
    printf("Enter the number of elements you want in the list: ");
    scanf("%d", &n);

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
    node *ME = MiddleElement(list);
    PrintList(list);
    printf("\nMiddle Element is: %d", ME -> data);
    FreeNodes(list);
}

node *MiddleElement(node *list)
{
    
    node *fast = list;
    node *slow = list;
    while(slow != NULL && fast-> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
        
        if (fast == NULL || slow == NULL)
        {
            break;
        }
    }

    return slow;
}

void PrintList(node *list)
{
    node *temp = list;
    printf("LIST: ");
    while (temp)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    
}

void FreeNodes(node *list)
{
    while (list)
    {
        node *NextNode = list -> next;
        free(list);
        list = NextNode;
    }
    
}