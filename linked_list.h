#pragma once


typedef struct ListNode
{
    struct ListNode* next;
    int data;
} ListNode;


void list_display(ListNode* r);
ListNode* list_insert(ListNode* r, int x);
ListNode* list_insert_sorted(ListNode* r, int x);
ListNode* list_delete(ListNode* r, int x);
