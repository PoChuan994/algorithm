/* Refered from https://www.geeksforgeeks.org/merge-sort-for-linked-list/ */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
}Node;

Node *insert(int value)
{
    Node *new = malloc(sizeof(Node));
    new->val = value;
    new->next = NULL;
    return new;
}

void display(Node *head)
{
    Node *curr = head;
    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

Node *split(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *second = slow->next;
    slow->next = NULL;
    return second;
}

Node *merge(Node *first, Node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->val <= second->val) {
        first->next = merge(first->next, second);
        return first;
    } else {
        second->next = merge(first, second->next);
    }
}

Node *merge_sort(Node *head)
{
    if (!head || !head->next)
        return head;

    /* split the list into two havles */
    head = merge_sort(head);
    Node *second = merge_sort(second);

    return merge(head, second);
}

int main ()
{
    Node *head = insert(52);
    head->next = insert(28);
    head->next->next = insert(64);
    head->next->next->next = insert(43);
    head->next->next->next->next = insert(82);
    head->next->next->next->next->next = insert(16);

    printf("The origin list is \n");
    display(head);
    merge_sort(head);
    printf("The sorted list is \n");
    display(head);

    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
