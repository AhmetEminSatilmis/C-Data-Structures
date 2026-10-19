#include <stdio.h>
#include <stdlib.h>
#include "list_queue.h"


void list_que_enque(ListQueue** front_ref, ListQueue** rear_ref, int x)
{
    if (front_ref == NULL || rear_ref == NULL)
    {
        printf("Null Reference Error");
        return;
    }

    ListQueue* new_node = (ListQueue*) malloc(sizeof(ListQueue));
    new_node->data = x;
    new_node->next = NULL;

    if (*front_ref == NULL)
    {
        *front_ref = new_node;
        *rear_ref = new_node;
        return;
    }

    (*rear_ref)->next = new_node;
    *rear_ref = new_node;
}

int list_que_deque(ListQueue** front_ref, ListQueue** rear_ref)
{
    if (front_ref == NULL || rear_ref == NULL)
    {
        printf("Null Reference Error");
        return -1;
    }

    if (*front_ref == NULL)
    {
        printf("Queue is empty\t");
        return -1;
    }

    ListQueue* temp = *front_ref;
    *front_ref = temp->next;
    int x = temp->data;
    free(temp);

    if (*front_ref == NULL)
    {
        *rear_ref = NULL;
    }
    return x;
}

