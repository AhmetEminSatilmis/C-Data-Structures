#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

void circular_display(CircularNode* r)
{
    printf("\n------------------------------\n");
    if (r == NULL)
    {
        printf("\nLinked list is empty");
        return;
    }

    printf("%d\t", r->data);
    CircularNode* iter = r->next;

    while (iter != r)
    {
        printf("%d\t", iter->data); 
        iter = iter->next;
    }
} 

CircularNode* circular_insert(CircularNode* r, int x)
{

    if (r == NULL)
    {
        r = (CircularNode*) malloc(sizeof(CircularNode));
        r->next = r;
        r->data = x;
        return r;
    }

    CircularNode* iter = r;
    while (iter->next != r)
    {
        iter = iter->next;
    }
    iter->next = (CircularNode*) malloc(sizeof(CircularNode));
    iter->next->data = x;
    iter->next->next = r;
    return r;
}
    
CircularNode* circular_insert_sorted(CircularNode* r, int x)
{
    if (r == NULL)
    {
        r = (CircularNode*) malloc(sizeof(CircularNode));
        r->next = r;
        r->data = x;
        return r;
    }

    CircularNode* iter = r; 
    if (x < r->data)
    {
        while (iter->next != r)
        {
            iter = iter->next;
        }
        
        iter->next = (CircularNode*) malloc(sizeof(CircularNode));
        iter->next->data = x;
        iter->next->next = r;
        return iter->next;
    }

    while (iter->next != r && iter->next->data < x)
    {
        iter = iter->next;
    }
    CircularNode* temp = (CircularNode*) malloc(sizeof(CircularNode));
    temp->data = x;
    temp->next = iter->next;
    iter->next = temp;
    return r;
}

CircularNode* circular_delete(CircularNode* r, int x)
{
    if (r == NULL)
    {
        printf("\nLinked list is empty");
        return r;
    }

    CircularNode* iter = r;
    if (x == r->data)
    {
        while (iter->next != r)
        {
            iter = iter->next;
        }
        iter->next = r->next;
        free(r);
        return iter->next;
    }

    while (iter->next != r && iter->next->data != x)
    {
        iter = iter->next;
    }

    if (iter->next == r)
    {
        printf("\n%d - Does not exist in the linked list", x);
        return r;
    }

    CircularNode* temp = iter->next;
    iter->next = temp->next;
    free(temp);
    return r;
}
