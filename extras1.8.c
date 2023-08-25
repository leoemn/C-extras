/*Create a program that simulates a basic text editor's undo functionality 
using a stack of strings and pointers.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Define structure for nodes of stack.
typedef struct  node
{
    char *str;
    struct node *next;
}node;

//Define structure for stack itself.
typedef struct
{
    node *top;
}stack;

//Functions prototype.
stack *CreateStack();
void push(stack *MyStack, char *str);
char *peek(stack *MyStack);
void pop(stack *MyStack);
void FreeStack(stack *MyStack);

int main(void)
{
    stack *MyStack = CreateStack();

    //Push some strings in our stack.
    push(MyStack, "First String");
    push(MyStack, "Second String");
    push(MyStack, "Third String");

    printf("without UNDO: %s", peek(MyStack));

    pop(MyStack);

    printf("\nAfter UNDO: %s", peek(MyStack));

    FreeStack(MyStack);

    return 0;
}

stack *CreateStack()
{
    //Allocating memory for the stack using malloc.
    stack *MyStack = malloc(sizeof(stack));

    //Checking memory allocation was successfull.
    if (!MyStack)
    {
        printf("Memory Allocation failed");
        return NULL;
    }
    MyStack -> top = NULL;
    return MyStack;
}

void push(stack *MyStack, char *str)
{
    //Allocating memory for new node using malloc.
    node *NewNode = malloc(sizeof(node));

    //Checking memory allocation was successfull.
    if (!NewNode)
    {
        printf("Memory Allocation failed");
        return;
    }
    NewNode -> str = strdup(str);
    NewNode -> next = MyStack -> top;
    MyStack -> top = NewNode;
}

char *peek(stack *MyStack)
{
    //Check if the stack is empty.
    if (!MyStack -> top)
    {
        printf("Stack is empty");
        return NULL;
    }
    return MyStack -> top -> str;
}

void pop(stack *MyStack)
{
    //Check if the stack is empty.
    if (!MyStack -> top)
    {
        printf("Stack is already empty, Nothing to POP");
        return;
    }
    node *temp = MyStack -> top;
    MyStack -> top = MyStack -> top -> next;

    // Freeing the string and node.
    free(temp -> str);
    free(temp);
}

void FreeStack(stack *MyStack)
{
    // Loop through the stack and free all nodes.
    while (MyStack -> top)
    {
        node *temp = MyStack -> top;
        MyStack -> top = MyStack -> top -> next;

        // Freeing the string and node.
        free(temp -> str);
        free(temp);
    }
    // Freeing the stack itself.
    free(MyStack);
}

