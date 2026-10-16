#include <stdio.h>
#include <stdlib.h>
#include "array_queue.h"
#include <string.h>


void arr_que_init(ArrayQueue* arr_que, int size)
{
    arr_que->arr = (int*) malloc(sizeof(int) * size);
    arr_que->size = size;
    arr_que->count = 0;
}

void arr_que_enque(ArrayQueue* arr_que, int x)
{
    if (arr_que->count >= arr_que->size)
    {
        arr_que->size *= 2;
        arr_que->arr = (int*) realloc(arr_que->arr, sizeof(int) * arr_que->size);
    }

    arr_que->arr[arr_que->count++] = x; 
}

int arr_que_deque(ArrayQueue* arr_que)
{
    if (arr_que->count == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }

    if (arr_que->count <= arr_que->size / 4)
    {
        int new_size = arr_que->size / 2;
        memset(arr_que->arr + new_size, 0, sizeof(int) * (arr_que->size - new_size));

        arr_que->arr = (int*) realloc(arr_que->arr, sizeof(int) * new_size);
        arr_que->size = new_size;
    }

    int x = arr_que->arr[0];
    for (int i = 0; i < arr_que->count - 1; i++)
    {
        arr_que->arr[i] = arr_que->arr[i + 1];
    }
    arr_que->arr[--arr_que->count] = 0;
    return x;
}

int arr_que_front(const ArrayQueue* arr_que)
{
    return arr_que->arr[0];
}

int arr_que_rear(const ArrayQueue* arr_que)
{
    return arr_que->arr[arr_que->count - 1];
}

void arr_que_free(ArrayQueue* arr_que)
{
    if (arr_que->arr != NULL)
    {
        free(arr_que->arr);
    }
}

