#pragma once


typedef struct
{
    int* arr;
    int top;
    int size;
} ArrayStack;

void arr_stack_init(ArrayStack* arr_stack, int s);
void arr_stack_free(ArrayStack* arr_stack);
int arr_stack_peek(ArrayStack* arr_stack);
void arr_stack_push(ArrayStack* arr_stack, int x);
int arr_stack_pop(ArrayStack* arr_stack);
