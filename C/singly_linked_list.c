#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

void push(node_t **head, int val) {
    node_t *newnode = malloc(sizeof(node_t));
    newnode->val = val;
    newnode->next = *head;
    *head = newnode;
}

void append_node(node_t **head, int val) {
    if (*head == NULL) {
        // make new head
        node_t *newnode = malloc(sizeof(node_t));
        newnode->val = val;
        newnode->next = NULL;
        *head = newnode;
        return;
    }
    node_t *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    node_t *newnode = malloc(sizeof(node_t));
    newnode->val = val;
    newnode->next = NULL;
    curr->next = newnode;
    return;
}

void insert_before(node_t **head, int val, int key) {
    if (*head == NULL) return;
    // if insert before head
    if ((*head)->val == key) {
        node_t *newnode = malloc(sizeof(node_t));
        newnode->val = val;
        newnode->next = *head;
        *head = newnode;
        return;
    }
    // find node with desired key
    node_t *curr = *head, *prev;
    while (curr && curr->val != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) return; // key not found;
    // insert node at desired position
    printf("KEY FOUND\n");
    node_t* newnode = malloc(sizeof(node_t));
  //  printf("%d\n", newnode == NULL);
    newnode->val = val;
    newnode->next = curr;
    prev->next = newnode;
    return;
}

void insert_after(node_t *head, int val, int key) {
    if (head == NULL) return;
    node_t *curr = head;
    while (curr && curr->val != key) {
        curr = curr->next;
    }
    if (curr == NULL) return;  // key not found
    node_t *newnode = malloc(sizeof(node_t));
    newnode->val = val;
    newnode->next = curr->next;
    curr->next = newnode;
    return;
}

void delete_node(node_t **head, int val) {
    if (*head == NULL) return;
    node_t *curr = *head, *prev;
    // key is head node
    if (curr->val == val) {
        *head = curr->next;
        free(curr);
        return;
    }
    // find key
    while (curr != NULL && curr->val != val) {
        prev = curr;
        curr = curr->next;
    }
    // if key is not present
    if (curr == NULL) return;
    //remove the node;
    prev->next = curr->next;
    free(curr);
    return;
}

void traverse(node_t *head) {
    node_t *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int search(node_t *head, int key) {
    if (head == NULL) return 0;
    node_t *curr = head;
    while (curr != NULL && curr->val != key) {
        curr = curr->next;
    }
    if (curr == NULL) return 0;
    return 1;
}

void sort(node_t *head) {
    // uses bubble sort
    if (head == NULL) return;
    node_t *curr = head, *idx = NULL;
    int temp;
    while (curr != NULL) {
        //idx points to node next to current
        idx = curr->next;
        while (idx != NULL) {
            if (curr->val > idx->val) {
                temp = curr->val;
                curr->val = idx->val;
                idx->val = temp;
            }
            idx = idx->next;
        }
        curr = curr->next;
    }
}

int hasCycle(node_t *head) {
    if (head == NULL) return 0;
    node_t *slow = head, *fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 1;
}

void reverse(node_t **head) {
    node_t *prev = NULL, *curr = *head, *tmp;
    while (curr != NULL) {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    *head = prev;
}

void delete_list(node_t **head) {
    node_t* temp = NULL;
    node_t* curr = *head;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

