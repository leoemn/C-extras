/*Write a program to merge two sorted linked lists into a single sorted list.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int main(void)
{
    node *link1 = NULL;
    node *link2 = NULL;

    //Creating first linked lists with 5 elements in it.
    for (int i = 0 ; i < 5 ; i++)
    {
        int number;
        printf("Enter the element: ");
        scanf("%d", &number);

        node *NewNode = malloc(sizeof(node));

        NewNode -> data = number;
        NewNode -> next = link1;
        link1 = NewNode;
    }
    
    for (int i = 0 ; i < 5 ; i++)

}
