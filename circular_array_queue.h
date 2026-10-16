#pragma once


typedef struct CircularArrayQueue
{
    int* arr;
    int size;
    int front;
    int rear;
} CircularArrayQueue;

void cir_arr_que_init(CircularArrayQueue* cir_arr_que, int size);
void cir_arr_que_enque(CircularArrayQueue* cir_arr_que, int x);
int cir_arr_que_deque(CircularArrayQueue* cir_arr_que);
int cir_arr_que_front(const CircularArrayQueue* cir_arr_que);
int cir_arr_que_rear(const CircularArrayQueue* cir_arr_que);
void cir_arr_que_free(CircularArrayQueue* cir_arr_que);
