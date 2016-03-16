#include <stdlib.h>
#include <stdio.h>

typedef struct _List {
    struct _List *next;
    int value;
} List;

int count1(List *head)
{
    int i = 0;
    List *count2;
    count2 = head;
    while (count2 != NULL) {
        i++;
        count2 = count2->next;
    }
    return i;
}

List *mergesort(List *head)
{
    int k = count1(head);
    List *left;
    List *right;
    List *tmp1;
    List *tmp2;

    if (k > 1) {
        left = head;
        right = head;
        int i = 0;
        for (; i < k/2 ; i++) {
            tmp1 = right;
            right = right->next;
        }
        tmp1->next = NULL;
        left = mergesort(left);
        right = mergesort(right);
    } else {
        left = head;
        right = NULL;
    }

    tmp1 = (List *) malloc (sizeof(List));
    tmp2 = tmp1;

    while (left != NULL && right != NULL) {
        if (left->value < right->value) {
            tmp2->next = left;
            tmp2 = tmp2->next;
            left = left->next;
            tmp2->next = NULL;
        } else {
            tmp2->next = right;
            tmp2 = tmp2->next;
            right = right->next;
            tmp2->next = NULL;
        }
    }

    if (left != NULL) {
        tmp2->next = left;
    } else {
        tmp2->next = right;
    }

    tmp1 = tmp1->next;

    return tmp1;
}
