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

void push_beginning(Node *first_node, task *new_task) {
    Node **head = (Node**)malloc(sizeof(struct list));
    first_node->task = *new_task;
    first_node->next = *head;
    *head = first_node;
}

void print_info(Node *head) {
    Node *iterator;
    iterator = head;
    while (iterator->next!=NULL) {
        printf("%s", iterator->task.name);
        printf("%d", iterator->task.start_time);
        printf("%d", iterator->task.end_time);
        iterator = iterator->next;
    }
}

int main()
{
    int i;
    int n=3;
    //printf("n = ");
    //scanf("%d", &n);

    //a node for the activities (schedule)
    task *new_task = (task*)malloc(sizeof(struct schedule));
    //an actual node
    Node *first_node = (Node*)malloc(sizeof(struct list));
   // adding elements
    push_beginning(first_node, new_task);

    //for (i=1; i<=n; i++) {
/*    head->next = NULL;
        printf("Activity no. %d: ", i);
        scanf("%s", new_node->name);
        printf("Start time: ");
        scanf("%d", &new_node->start_time);
        printf("End time: ");
        scanf("%d", &new_node->end_time);
    //}
*/
    print_info(first_node);

    free(first_node);
return 0;
}
