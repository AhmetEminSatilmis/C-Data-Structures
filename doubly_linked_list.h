#pragma once


typedef struct DoublyNode
{
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
} DoublyNode;

void doubly_display(DoublyNode* r);
DoublyNode* doubly_insert(DoublyNode* r, int x);
DoublyNode* doubly_insert_sorted(DoublyNode* r, int x);
DoublyNode* doubly_delete(DoublyNode* r, int x);
