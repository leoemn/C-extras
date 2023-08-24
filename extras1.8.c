/*Create a program that simulates a basic text editor's undo functionality 
using a stack of strings and pointers.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Define structure for nodes of stack.
typedef struct node
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
void push(stack *NewStack, char *str);
char *peek(stack *Newstack);
void pop(stack *Newstack);
void FreeStack(stack* NewStack);

int main(void)
{
    
    stack *NewStack = CreateStack();

    push(NewStack, "First String");
    push(NewStack, "Second string");
    push(NewStack, "Third String");

    printf("Without UNDO: %s", peek(NewStack));
    pop(NewStack);
    printf("\nAfter UNDO: %s", peek(NewStack));

    FreeStack(NewStack);
}

stack *CreateStack()
{
    //Allocating memory for the stack using malloc.
    stack *NewStake = malloc(sizeof(stack));

    //Checking memory allocation was successfull.
    if (!NewStake)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    NewStake -> top = NULL;
    return NewStake;
}

void push(stack *NewStack, char *str)
{
    //Allocating memory for new node using malloc.
    node *NewNode = malloc(sizeof(node));

    //Checking memory allocation was successfull.
    if (!NewNode)
    {
        printf("Memory allocation is failed");
        exit(1);
    }

    NewNode -> str = strdup(str);
    NewNode -> next = NewStack -> top;
    NewStack -> top = NewNode;
}

char *peek(stack *NewStack)
{
    //Check if the stack is empty.
    if (NewStack -> top == NULL)
    {
        printf("Srack is empty");
        return NULL;
    }
    
    return NewStack -> top -> str;
}

void pop(stack *Newstack)
{
    //Check if the stack is empty.
    if (Newstack -> top == NULL)
    {
        printf("Nothing to UNDO");
        return;
    }
    node *temp = Newstack->top;
    Newstack->top = Newstack->top->next;

    // Freeing the string and node.
    free(temp->str); 
    free(temp);      
}

void FreeStack(stack* NewStack) 
{
    // Loop through the stack and free all nodes.
    while (NewStack->top) 
    {
        node* temp = NewStack->top;
        NewStack->top = NewStack->top->next;

        // Freeing the string and node.
        free(temp->str); 
        free(temp);      
    }
    // Freeing the stack itself.
    free(NewStack); 
}
