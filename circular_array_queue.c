#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_array_queue.h"


void cir_arr_que_init(CircularArrayQueue* cir_arr_que, int size)
{
    cir_arr_que->arr = (int*) malloc(sizeof(int) * size);
    cir_arr_que->size = size;
    cir_arr_que->front = -1;
    cir_arr_que->rear = -1;
}

void cir_arr_que_enque(CircularArrayQueue* cir_arr_que, int x)
{
    cir_arr_que->rear = (cir_arr_que->rear + 1) % cir_arr_que->size;
    if (cir_arr_que->rear == cir_arr_que->front)
    {
        cir_arr_que->arr = (int*) realloc(cir_arr_que->arr, sizeof(int) * cir_arr_que->size * 2);
        for (int i = 0; i < cir_arr_que->front; i++)
        {
            cir_arr_que->arr[i + cir_arr_que->size] = cir_arr_que->arr[i];
        }
            
        cir_arr_que->rear = cir_arr_que->front + cir_arr_que->size;
        cir_arr_que->size *= 2;
    }

    if (cir_arr_que->front == -1)
    {
        cir_arr_que->front++;
    }
    cir_arr_que->arr[cir_arr_que->rear] = x;
}

int cir_arr_que_deque(CircularArrayQueue* cir_arr_que)
{
    if (cir_arr_que->front == -1)
    {
        printf("Queue is empty");
        return -1;
    }

    int x = cir_arr_que->arr[cir_arr_que->front];
    if (cir_arr_que->front == cir_arr_que->rear)
    {
        cir_arr_que->front = -1;
        cir_arr_que->rear = -1;
        return x;
    }

    cir_arr_que->front = (cir_arr_que->front + 1) % cir_arr_que->size;
    int count = (cir_arr_que->front <= cir_arr_que->rear) ? (cir_arr_que->rear - cir_arr_que->front + 1) : (cir_arr_que->size - cir_arr_que->front + cir_arr_que->rear+ 1);

    if (count <= cir_arr_que->size / 4)
    {
        int* temp_arr = (int*) malloc (sizeof(int) * cir_arr_que->size / 2);
        if (cir_arr_que->rear >= cir_arr_que->front)
        {
            memcpy(temp_arr, cir_arr_que->arr + cir_arr_que->front, sizeof(int) * count);
        }
        else
        {
            memcpy(temp_arr, cir_arr_que->arr + cir_arr_que->front, sizeof(int) * (cir_arr_que->size - cir_arr_que->front));
            memcpy(temp_arr + cir_arr_que->size - cir_arr_que->front, cir_arr_que->arr, sizeof(int) * (cir_arr_que->rear + 1));   
        }

        free(cir_arr_que->arr);
        cir_arr_que->arr = temp_arr;
        cir_arr_que->front = 0;
        cir_arr_que->rear = count - 1;
        cir_arr_que->size /= 2;
    }
    return x;
}

int cir_arr_que_front(const CircularArrayQueue* cir_arr_que)
{
    if (cir_arr_que->front == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    return cir_arr_que->arr[cir_arr_que->front];
}

int cir_arr_que_rear(const CircularArrayQueue* cir_arr_que)
{
    if (cir_arr_que->rear == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    return cir_arr_que->arr[cir_arr_que->rear];
}

void cir_arr_que_free(CircularArrayQueue* cir_arr_que)
{
    if (cir_arr_que->arr != NULL)
    {
        free(cir_arr_que->arr);
    }
}





















