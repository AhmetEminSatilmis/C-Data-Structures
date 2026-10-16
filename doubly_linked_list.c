#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"


void doubly_display(DoublyNode* r)
{
    printf("\n-----------------------------------\n");
    if (r == NULL)
    {
        printf("Linked list is empty");
        return;
    }
    
    while (r != NULL)
    {
        printf("%d\t", r->data);
        r = r->next;
    }
}

DoublyNode* doubly_insert(DoublyNode* r, int x)
{
    DoublyNode* temp = (DoublyNode*) malloc (sizeof(DoublyNode));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if (r == NULL)
    {
        return temp;
    }

    DoublyNode* iter = r;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    
    iter->next = temp;
    temp->prev = iter;
    temp->next = NULL;
    return r;
}

DoublyNode* doubly_insert_sorted(DoublyNode* r, int x)
{
    DoublyNode* temp = (DoublyNode*) malloc (sizeof(DoublyNode));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if (r == NULL)
    {
        return temp;
    }

    if (x < r->data)
    {
        temp->next = r;
        r->prev = temp;
        return temp;
    }

    DoublyNode* iter = r;
    while (iter->next != NULL && iter->next->data < x)
    {
        iter = iter->next;
    }

    if (iter->next != NULL)
    {
        iter->next->prev = temp;
    }
    temp->next = iter->next;
    temp->prev = iter;
    iter->next = temp;
    return r;
}

DoublyNode* doubly_delete(DoublyNode* r, int x)
{
    if (r == NULL)
    {
        printf("Linked lists is empty");
        return NULL;
    }

    DoublyNode* temp = r;
    if (r->data == x)
    {
        r->next->prev = NULL;
        r = r->next;
        free(temp);
        return r;
    }

    while (temp->next != NULL && temp->next->data != x)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("\n%d - Does not exist in the linked list", x);
        return r;
    }

    if (temp->next->next != NULL)
    {   
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
        return r;
    }

    free(temp->next);
    temp->next = NULL;
    return r;
}
