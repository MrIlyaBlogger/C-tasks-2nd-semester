#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} List;

int size(List* head) {
    int s = 0;
    if (head == NULL) {
        return 0;
    }
    while (head != NULL) {
        s++;
        head = head->next;
    }
    return s;
}

bool compare(List *head1, List *head2) {
    if (size(head1) != size(head2)) {
        return false;
    }
    while (head1 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}