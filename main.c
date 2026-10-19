#include <stdio.h>
#include "linked_list.h"
#include "circular_linked_list.h"
#include "doubly_linked_list.h"
#include "array_stack.h"
#include "list_stack.h"
#include "array_queue.h"
#include "circular_array_queue.h"
#include "list_queue.h"
#include "binary_search_tree.h"


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
        printf("front: %d\trear: %d\tsize: %d\n", arr_que_front(&arr_que), arr_que_rear(&arr_que), arr_que.size);
    }

    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < 12; i++)
    {
        printf("dequed: %d\t", arr_que_deque(&arr_que));
        printf("front: %d\trear: %d\tsize: %d\n", arr_que_front(&arr_que), arr_que_rear(&arr_que), arr_que.size);
    }

    arr_que_free(&arr_que);

*/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// circular array queue tests
/*
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
*/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// list queue tests


/*
    ListQueue* front = NULL;
    ListQueue* rear = NULL;
    
    printf("\n-------------------------------------------------------------\n");
    for (int i = 0; i < 20; i++)
    {
        list_que_enque(&front, &rear, i * 10 + 10);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", list_que_deque(&front, &rear));
    }

    for (int i = 0; i < 10; i++)
    {
        list_que_enque(&front, &rear, i * 100 + 10);
    }

    for (int i = 0; i < 22; i++)
    {
        printf("%d\t", list_que_deque(&front, &rear));
    }

    for (int i = 0; i < 10; i++)
    {
        list_que_enque(&front, &rear, i * 100 + 10);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", list_que_deque(&front, &rear));
    }
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// binary search tree tests

    BstNode* root = NULL;
    root = bst_insert(root, 50);
    bst_insert(root, 40);
    bst_insert(root, 30);
    bst_insert(root, 45);
    bst_insert(root, 55);
    bst_insert(root, 52);
    bst_insert(root, 60);

    printf("\n--------------------------------------------------------\n");
    bst_inorder(root);

    printf("\n--------------------------------------------------------\n");
    bst_preorder(root);

    printf("\n--------------------------------------------------------\n");
    bst_postorder(root);
    
    printf("\n--------------------------------------------------------\n");
    BstNode* node = bst_search(root, 40);

    if (node != NULL)
    {
        printf("%d\t", node->data);
    }
    else
    {
        printf("Couldnt find");
    }














    return 0;

}

