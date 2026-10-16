#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void list_display(ListNode* r)
{
    printf("\n------------------------------\n");
    if (r == NULL)
    {
        printf("\nLinked list is empty");
        return;
    }

    while (r != NULL)
    {
        printf("%d\t", r->data); 
        r = r->next;
    }
} 

ListNode* list_insert(ListNode* r, int x)
{
    ListNode* temp = (ListNode*) malloc(sizeof(ListNode));
    temp->data = x;
    temp->next = NULL;

    if (r == NULL)
    {
        return temp;
    }

    ListNode* iter = r;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = temp;
    return r;
}
    


ListNode* list_insert_sorted(ListNode* r, int x)
{
    ListNode* temp = (ListNode*) malloc(sizeof(ListNode));
    temp->data = x;

    if (r == NULL)
    {
        temp->next = NULL;
        return temp;
    }

    if (x < r->data)
    {
        temp->next = r;
        return temp;
    }

    ListNode* iter = r;
    while (iter->next != NULL && iter->next->data < x)
    {
        iter = iter->next;
    }

    temp->next = iter->next;
    iter->next = temp;
    return r;
}

ListNode* list_delete(ListNode* r, int x)
{
    if (r == NULL)
    {
        printf("\nLinked list is empty");
        return r;
    }

    ListNode* temp = r;
    if (x == r->data)
    {
        r = r->next;
        free(temp);
        return r;
    }

    ListNode* iter = r;
    while (iter->next != NULL && iter->next->data != x)
    {
        iter = iter->next;
    }

    if (iter->next == NULL)
    {
        printf("\n%d - Does not exist in the linked list", x);
        return r;
    }
    temp = iter->next;
    iter->next = temp->next;
    free(temp);
    return r;
}

