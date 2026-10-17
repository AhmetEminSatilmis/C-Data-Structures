#include <stdio.h>
#include <stdlib.h>
#include "array_queue.h"
#include <string.h>


void arr_que_init(ArrayQueue* arr_que, int size)
{
    arr_que->arr = (int*) malloc(sizeof(int) * size);
    arr_que->size = size;
    arr_que->front = -1;
    arr_que->rear = -1;
}

void arr_que_enque(ArrayQueue* arr_que, int x)
{
    if (arr_que->rear + 1 >= arr_que->size)
    {
        if (arr_que->front == 0)
        {
            arr_que->size *= 2;
            arr_que->arr = (int*) realloc(arr_que->arr, sizeof(int) * arr_que->size);
        }
        else
        {
            memmove(arr_que->arr, arr_que->arr + arr_que->front, arr_que->rear - arr_que->front + 1);
            arr_que->rear = arr_que->rear - arr_que->front;
            arr_que->front = 0;
        }
    }

    arr_que->front = (arr_que->front == -1) ? (0) : (arr_que->front);
    arr_que->arr[++arr_que->rear] = x; 
}

int arr_que_deque(ArrayQueue* arr_que)
{
    if (arr_que->front == -1)
    {
        printf("Queue is empty");
        return -1;
    }

    int x = arr_que->arr[arr_que->front++];
    int count = arr_que->rear - arr_que->front + 1;

    if (count == 0)
    {
        arr_que->front = -1;
        arr_que->rear = -1;
        return x;
    }

    if (count <= arr_que->size / 4)
    {
        arr_que->size /= 2;
        if (arr_que->front > 0)
        {
            int* temp_arr = (int*) malloc(sizeof(int) * arr_que->size);
            memcpy(temp_arr, arr_que->arr + arr_que->front, sizeof(int) * count);
            arr_que->front = 0;

            arr_que->rear = count - 1;
            free(arr_que->arr);
            arr_que->arr = temp_arr;
        }

        else
        {
            arr_que->arr = (int*) realloc(arr_que->arr, sizeof(int) * arr_que->size);
        }
    }
    return x;
}        

int arr_que_front(const ArrayQueue* arr_que)
{
    if (arr_que->front == -1)
    {
        return -1;
    }
    return arr_que->arr[arr_que->front];

}

int arr_que_rear(const ArrayQueue* arr_que)
{
    if (arr_que->rear == -1)
    {
        return -1;
    }
    return arr_que->arr[arr_que->rear];
}

void arr_que_free(ArrayQueue* arr_que)
{
    if (arr_que->arr != NULL)
    {
        free(arr_que->arr);
    }
}

