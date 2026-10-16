#pragma once


typedef struct CircularNode
{
    struct CircularNode* next;
    int data;
} CircularNode;

void circular_display(CircularNode* r);
CircularNode* circular_insert(CircularNode* r, int x);
CircularNode* circular_insert_sorted(CircularNode* r, int x);
CircularNode* circular_delete(CircularNode* r, int x);
