#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Task;
struct Node;

Node *push_beginning(Node *list, Task *info);
void print_info(Node *head);
void swap(Node *a, Node *b);
void print_node(Node *head);
Node *sort_end(Node *head);
Node *greedy(Node *head);
Node *backtrack(Node *head);
Node *free_list(Node *head);
char* activities(int choice);

#endif
