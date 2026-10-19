#pragma once

typedef struct ListQueue
{
    int data;
    struct ListQueue* next;

} ListQueue;

void list_que_enque(ListQueue** front_ref, ListQueue** rear_ref, int x);
int list_que_deque(ListQueue** front_ref, ListQueue** rear_ref);

