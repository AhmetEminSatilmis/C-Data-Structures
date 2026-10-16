#pragma once


typedef struct ListStack ListStack;

void list_stack_push(ListStack** head_ref, int x);
int list_stack_pop(ListStack** head_ref);
int list_stack_peek(ListStack* head);
void list_stack_display(ListStack* head);
