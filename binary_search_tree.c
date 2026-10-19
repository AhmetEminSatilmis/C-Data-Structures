#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"


BstNode* bst_insert(BstNode* node, int x)
{
    if (node == NULL)
    {
        BstNode* temp = (BstNode*) malloc(sizeof(BstNode));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = x;
        return temp;
    }

    if (x > node->data)
    {
        node->right = bst_insert(node->right, x);
    }

    else
    {
        node->left = bst_insert(node->left, x);
    }
    return node;
}

void bst_inorder(BstNode* node)
{
    if (node == NULL)
    {
        return;
    }

    bst_inorder(node->left);
    printf("%d\t", node->data);
    bst_inorder(node->right);
}

void bst_preorder(BstNode* node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d\t", node->data);
    bst_preorder(node->left);
    bst_preorder(node->right);
}

void bst_postorder(BstNode* node)
{
    if (node == NULL)
    {
        return;
    }

    bst_postorder(node->left);
    bst_postorder(node->right);
    printf("%d\t", node->data);
}

BstNode* bst_search(BstNode* node, int x)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->data == x)
    {
        return node;
    }

    if (node->data < x)
    {
        return bst_search(node->right, x);
    }

    else
    {
        return bst_search(node->left, x);
    }
}


























        
