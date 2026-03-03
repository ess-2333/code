#include <stdio.h>
#include <stdlib.h>

// typedef struct Tree{
//     int value;
//     struct Tree *left;
//     struct Tree *right;
// }BiTree, *BiNode;

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* createListNode(int val) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main(){

}