#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct schedule {
      char *name;
      int start_time;
      int end_time;
} Task;

typedef struct list {
    Task info;
    struct list *next;
} Node;

void init(Node **head) {
      *head = NULL;
}

void push_beginning(Node *head, Task *info) {
    Node *new_node = malloc(sizeof(Node));
    new_node->info = *info;
    new_node->next = list;
    list = new_node;
    return list;
}

void print_info(Node *head) {
    Node *iterator;
    iterator = head;	
    printf("\nTODAY'S ACTIVITIES ARE:\n");
    while (iterator != NULL) {
        printf("\nActivity: %s\n", iterator->info.name);
        printf("Starting time: %d:00\n", iterator->info.start_time);
        printf("Ending time: %d:00\n", iterator->info.end_time);
        iterator = iterator->next;
    }
}

void swap(Node *a, Node *b) {		
      Task temp;	
      temp = a->info;	
      a->info = b->info;	
      b->info = temp;
}

void print_node(Node *head) {		
      if (head != NULL) {					
            printf("\n==============================");			
            printf("\nActivity: %s", head->info.name);			
            printf("\nStarting time: %d:00", head->info.start_time);			
            printf("\nEnding time: %d:00", head->info.end_time);  	
      }
}

//A shameless bubble sort
Node *sort_end(Node *head) {				
      Node *parent = head;				
      Node *iterator = head->next;			  
      while (iterator != NULL) {
            while (iterator != parent) {		
                  if ((iterator->info.end_time < parent->info.end_time)) {
                        swap(iterator, parent);	
                  }
                  parent = parent->next;
             }
             parent = head;            	
             iterator = iterator->next;	
      }			
      return parent;
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
