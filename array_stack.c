#include <stdio.h>
#include <stdlib.h>
#include "array_stack.h"
#include <string.h>

void arr_stack_init(ArrayStack* arr_stack, int s)
{
    arr_stack->arr = (int*) malloc(sizeof(int) * s);
    arr_stack->size = s;
    arr_stack->top = -1;
}

void arr_stack_free(ArrayStack* arr_stack)
{
    free(arr_stack->arr);
}

int arr_stack_peek(ArrayStack* arr_stack)
{
    if (arr_stack->top == -1)
    {
        printf("Array stack is empty");
        return -1;
    }

    return arr_stack->arr[arr_stack->top];
}

void arr_stack_push(ArrayStack* arr_stack, int x)
{
    if (arr_stack->size <= arr_stack->top + 1)
    {
        arr_stack->size *= 2;
        arr_stack->arr = (int*) realloc(arr_stack->arr, sizeof(int) * arr_stack->size);
    }

    arr_stack->arr[++arr_stack->top] = x;
}
    
int arr_stack_pop(ArrayStack* arr_stack)
{
    if (arr_stack->top == -1)
    {
        printf("Array stack is empty");
        return -1;
    }

    if (arr_stack->top + 1 <= arr_stack->size / 4)
    {
        int new_size = arr_stack->size / 2;
        memset(arr_stack->arr + new_size, 0, sizeof(int) * (arr_stack->size - new_size));

        arr_stack->arr = (int*) realloc(arr_stack->arr, sizeof(int) * new_size);
        arr_stack->size = new_size;
    }

    return arr_stack->arr[arr_stack->top--];




}
