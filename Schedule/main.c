#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct schedule {
      char name[20];
      int start_time;
      int end_time;
} task;

typedef struct list {
    struct schedule task;
    struct list *next;
} Node;

void push_beginning(Node *head, task *new_task) {
    Node *new_node = malloc(sizeof(struct list));
    new_node->task = *new_task;
    new_node->next = head->next;
    head->next = new_node;
}

void print_info(Node *head) {
    Node *iterator;
    iterator = head;
    while (iterator->next!=NULL) {
        printf("%s ", iterator->task.name);
        printf("%d ", iterator->task.start_time);
        printf("%d ", iterator->task.end_time);
        iterator = iterator->next;
    }
}

int main()
{
    int i=1;
    int n=3;
    //printf("n = ");
    //scanf("%d", &n);

    Node **head = (Node**)malloc(sizeof(struct list));
    //a node for the activities (schedule)
    task *new_task = (task*)malloc(sizeof(struct schedule));
    //an actual node
    Node *new_node = (Node*)malloc(sizeof(struct list));
    // adding elements
    push_beginning(new_node, new_task);

    //for (i=1; i<=n; i++) {

        printf("Activity no. %d: ", i);
        scanf("%s", new_task->name);
        printf("Start time: ");
        scanf("%d", &new_task->start_time);
        printf("End time: ");
        scanf("%d", &new_task->end_time);
    //}

    print_info(new_node);

    free(head);
return 0;
}
