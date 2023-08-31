/*Create a program that checks if a linked list is a palindrome (reads the same forwards and backwards).*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
}node;

int IsPalindrome(node *linkH, node *linkT);
void FreeNodes(node *listH);

int main(void)
{
    int n;
    printf("Enter the number of elements you want in the list: ");
    scanf("%d", &n);

    node *linkH = NULL;
    node *linkT = NULL;

    for (int i = 0 ; i < n ; i++)
    {
        int number;
        printf("Enter the element: ");
        scanf("%d", &number);

        node *NeWNode = malloc(sizeof(node));

        NeWNode -> data = number;                                                    
        NeWNode->next = NULL;
        NeWNode->previous = NULL;

        if (linkH == NULL) 
        {
            linkH = NeWNode;
            linkT = NeWNode;
        }
        else 
        {
            linkT->next = NeWNode;
            NeWNode->previous = linkT;
            linkT = NeWNode;
        }
    }

    // Call the isPalindrome function and print the result
    if (IsPalindrome(linkH, linkT)) 
    {
        printf("The linked list is a palindrome.\n");
    } 
    else 
    {
        printf("The linked list is not a palindrome.\n");
    }

    FreeNodes(linkH);
    return 0;
}

int IsPalindrome(node *linkH, node *linkT) 
{
    while (linkH != NULL && linkT != NULL) 
    {
        if (linkH -> data != linkT -> data) 
        {
            return 0; // Not a palindrome
        }
        linkH = linkH -> next;
        linkT = linkT -> previous;
    }
    return 1; // Palindrome
}

void FreeNodes(node *listH)
{
    while(listH)
    {
        node *NextNode = listH -> next;
        free(listH);
        listH = NextNode;
    }
}