#include <stdio.h>
#include <stdlib.h>
#include "list_stack.h"

typedef struct ListStack
{
    int data;
    struct ListStack* next;

} ListStack;

void list_stack_push(ListStack** head_ref, int x)
{
    if (head_ref == NULL)
    {
        printf("Null Reference Error");
        exit(1);
    }

    ListStack* temp = (ListStack*) malloc(sizeof(ListStack));
    temp->data = x;
    temp->next = *head_ref;
    *head_ref = temp;
}

int list_stack_pop(ListStack** head_ref)
{
    if (head_ref == NULL)
    {
        printf("Null Reference Error");
        exit(1); 
    }
    if (*head_ref == NULL)
    {
        printf("Stack is empty");
        return -1;
    }

    int x = (*head_ref)->data;
    ListStack* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
    return x;
}
        
int list_stack_peek(ListStack* head)
{
    if (head == NULL)
    {
        printf("Stack is empty");
        return -1;
    }
    return head->data;
}

void list_stack_display(ListStack* head)
{
    printf("\n--------------------------------------\n");
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
}
        



        


