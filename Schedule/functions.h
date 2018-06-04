#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
    char *name;
    int start_time;
    int end_time;
} Task;
///<This is a structure inside of a structure
typedef struct list {
    Task info;
    struct list *next;
} Node;

void init(Node **head);
Node *push_beginning(Node *list, Task *info);
void print_info(Node *head);
void swap(Node *node_a, Node *node_b);
void print_node(Node *head);
Node *sort_end(Node *head);
Node *greedy(Node *head);
Node *dynamic(Node *head);
Node *free_list(Node *head);
char* activities(int choice);

#endif
