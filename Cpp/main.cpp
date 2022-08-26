#include <stdio.h>
#include "singly_linked_list.h"

int main(){

    node_t *head = NULL;
    node_t *emptyhead = NULL;
    node_t *head1 = NULL;

    printf("Testing PUSH\n");
    printf("\tTest 0: PUSH 2 to empty list...\n");
    push(&head, 2);
    printf("\t\tHead value is %d\n", head->val);
    printf("\t\t...Success\n");
    printf("\tTest 1: PUSH 3 to non-empty list...\n");
    push(&head, 3);
    printf("\t\tHead value is %d\n", head->val);
    printf("\t\t...Success\n");   
    printf("\tTest 2: PUSH 12 to non-empty list...\n");
    push(&head, 12);
    printf("\t\tHead value is %d\n", head->val);
    printf("\t\t...Success\n");  
    printf("\tTest 3: PUSH 29 to non-empty list...\n");
    push(&head, 29);
    printf("\t\tHead value is %d\n", head->val);
    printf("\t\t...Success\n");  
    printf("\tTest 4: PUSH 100 to non-empty list...\n");
    push(&head, 100);
    printf("\t\tHead value is %d\n", head->val);
    printf("\t\t...Success\n");
    printf("\n");


    printf("Testing TRAVERSE\n");
    printf("\tTraversing empty list: ");
    traverse(head1);
    printf("\t\t...success\n");
    printf("\tTraversing non-empty list: ");
    traverse(head);
    printf("\t\t...Success\n");
    printf("\n");
    
    printf("Testing DELETE\n");
    printf("\tTest 0: DELETE 77 (node not in list)...\n");
    delete_node(&head, 77);
    printf("\t\t...Success\n");
    printf("\tTest 1: Deleting head node...");
    delete_node(&head, 100);
    printf("\t\t");
    traverse(head);
    printf("\t\t...Success\n");
    printf("\tTest 2: Deleting tail node...");
    delete_node(&head, 2);
    printf("\t\t");
    traverse(head);
    printf("\t\t...Success\n");
    printf("\tTest 3: Deleting middle node...");
    delete_node(&head, 12);
    printf("\t\t");    
    traverse(head);
    printf("\t\t...Success\n");
    printf("\n");


    printf("Testing APPEND\n");
    printf("\tTest 0: Appending 3 to empty list: ");
    append_node(&head1, 3);
    traverse(head1);
    printf("\t\t...success\n");
    printf("\tTest 1: Appending 4 non-empty list: ");
    append_node(&head, 4);
    traverse(head);
    printf("\t\t...success\n");
    printf("\tTest 2: Appending 14 non-empty list: ");
    append_node(&head, 14);
    traverse(head);
    printf("\t\t...success\n");
    printf("\n");

    printf("Testing SEARCH\n");
    printf("\tTest 0: Search for -12 (element not in list)\n");
    int found = search(head, -12);
    (found) ? printf("\t\tFound element\n") : printf("\t\tNot found\n");
    printf("\t\t...Success\n");
    printf("\tTest 1: Search for 14 (element in list)\n");
    found = search(head, 14);
    (found) ? printf("\t\tFound element\n") : printf("\t\tNot found\n");
    printf("\t\t...Success\n");
    printf("\n");

    printf("Testing INSERT BEFORE\n");
    printf("\tTest 0: Insert 10 before 22 in empty list\n");
    insert_before(&emptyhead, 22, 10);
    printf("\t\t...success\n");
    printf("\tTest 1: Insert 10 before 3 (head) in non-empty list: ");
    insert_before(&head, 10, 3);
    traverse(head);
    printf("\t\t...success\n");

    printf("\tTest 2: Insert 111 before 29 (tail) in non-empty list: ");
    insert_before(&head, 111, 29);
    traverse(head);
    printf("\t\t...success\n");


    printf("\tTest 3: Insert 50 before 3 (middle) in non-empty list: ");
    insert_before(&head, 50, 3);
    traverse(head);
    printf("\t\t...success\n");
    printf("\n");


    printf("Testing INSERT AFTER\n");
    printf("\tTest 0: insert 8 after 11 (non-existing element): ");
    insert_after(head, 8, 11);
    traverse(head);
    printf("\t\t...success\n");
    printf("\tTest 1: insert 22 after 10 (head element): ");
    insert_after(head, 22, 10);
    traverse(head);
    printf("\t\t...success\n");
    printf("\tTest 2: insert 77 after 29 (tail element): ");
    insert_after(head, 77, 29);
    traverse(head);
    printf("\t\t...success\n");
    printf("\tTest 3: insert 33 after 4 (middle element): ");
    insert_after(head, 33, 4);
    traverse(head);
    printf("\t\t...success\n");
    printf("\n");


    printf("Testing SORT\n");
    printf("\tTest 0: sorting empty list\n");
    sort(emptyhead);
    printf("\t\t...success\n");
    printf("\tTest 1: sorting non-empty list: ");
    sort(head);
    traverse(head);
    printf("\t\t...success\n");
    printf("\n");

    printf("Testing REVERSE\n");
    printf("\tTest 0: reversing empty list: \n");
    reverse(&emptyhead);
    printf("\t\t...success\n");
    printf("\tTest 1: reversing non-empty list: ");
    reverse(&head);
    traverse(head);
    printf("\t\t...success\n");
    printf("\n");

    printf("Testing HAS CYCLE\n");
    node_t *cycle = new node_t;
    cycle->val = 10;
    node_t *cycle2 = new node_t;
    cycle->next = cycle2;
    cycle2->val = 22;
    cycle2->next = cycle;
    printf("\tTest 0: Testing on linked list of 2 elements that contains a cycle\n");
    int cyc = hasCycle(cycle);
    (cyc) ? printf("\t\tHas Cycle\n") : printf("\t\tNo Cycle\n");
    printf("\t\t...success\n");
    printf("\tTest 1: Testing on linked list without a cycle\n");
    cyc = hasCycle(head);
    (cyc) ? printf("\t\tHas Cycle\n") : printf("\t\tNo Cycle\n");
    printf("\t\t...success\n");

    delete cycle;
    delete cycle2;
    delete_list(&head);
    delete_list(&head1);
    return 0;
}
