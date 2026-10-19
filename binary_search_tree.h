#pragma once


typedef struct BstNode
{
    struct BstNode* left;
    struct BstNode* right;
    int data;

} BstNode;

BstNode* bst_insert(BstNode* node, int x);
void bst_inorder(BstNode* node);
void bst_preorder(BstNode* node);
void bst_postorder(BstNode* node);
BstNode* bst_search(BstNode* node, int x);

