#include <stdio.h>
#include "linked_list.h"
#include "circular_linked_list.h"
#include "doubly_linked_list.h"
#include "array_stack.h"
#include "list_stack.h"
#include "array_queue.h"
#include "circular_array_queue.h"

int main()
{

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// array queue tests
/*
    ArrayQueue arr_que = {};
    arr_que_init(&arr_que, 2);

    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        arr_que_enque(&arr_que, i * 10 + 10);
        printf("front: %d\trear:%d\tcount: %d\tsize: %d\n", arr_que_front(&arr_que), arr_que_rear(&arr_que), arr_que.count, arr_que.size);
    }

    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < 12; i++)
    {
        printf("dequed: %d\t", arr_que_deque(&arr_que));
        printf("front: %d\trear:%d\tcount: %d\tsize: %d\n", arr_que_front(&arr_que), arr_que_rear(&arr_que), arr_que.count, arr_que.size);
    }

    arr_que_free(&arr_que);
*/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// circular array queue tests

    CircularArrayQueue cir_arr_que = {};
    cir_arr_que_init(&cir_arr_que, 2);
    
    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < 20; i++)
    {
        cir_arr_que_enque(&cir_arr_que, i * 10 + 10);
        printf("front: %d\trear: %d\tsize: %d\n", cir_arr_que_front(&cir_arr_que), cir_arr_que_rear(&cir_arr_que), cir_arr_que.size);
    }

    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < 15; i++)
    {
        printf("dequed: %d\tfront: %d\trear: %d\tsize: %d\n", cir_arr_que_deque(&cir_arr_que), cir_arr_que_front(&cir_arr_que), cir_arr_que_rear(&cir_arr_que), cir_arr_que.size);
    }

    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < 2; i++)
    {
        cir_arr_que_enque(&cir_arr_que, i * 10 + 10);
        printf("front: %d\trear: %d\tsize: %d\n", cir_arr_que_front(&cir_arr_que), cir_arr_que_rear(&cir_arr_que), cir_arr_que.size);
    }

    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("dequed: %d\tfront: %d\trear: %d\tsize: %d\n", cir_arr_que_deque(&cir_arr_que), cir_arr_que_front(&cir_arr_que), cir_arr_que_rear(&cir_arr_que), cir_arr_que.size);
    }
    return 0;


}

