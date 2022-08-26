typedef struct node {
    int val;
    struct node *next;
} node_t;

void push(node_t **head, int val);
void append_node(node_t **head, int val);
void insert_before(node_t **head, int val, int key);
void insert_after(node_t *head, int val, int key);
void delete_node(node_t **head, int val);
void traverse(node_t *head);
int search(node_t *head, int key);
void sort(node_t *head);
int hasCycle(node_t *head);
void reverse(node_t **head);
void delete_list(node_t **head);