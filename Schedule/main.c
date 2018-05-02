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

Node *greedy(Node *head) {
     Node *parent = head;				
     Node *iterator = head;			
     printf("\nTHE LIST OF TODAY'S ACTIVITIES:\n");	
     print_node(iterator);
          while (iterator != NULL) {	
               while (iterator != parent) {					     		
                     if (parent->info.end_time <= iterator->info.start_time) {													
                           print_node(iterator);				     				
                     } 	
                     parent = parent->next;
               }
                iterator = iterator->next;				}		
}

Node *free_list(Node *head) {
      Node *iterator = *head;
      Node *parent;
      while (iterator != NULL) {
            parent = iterator;
            free(parent);
      }
      return NULL;
}

char* activities(int choice) {
      switch(choice) {	
            case 1: return "Running";								
            case 2: return "Reading"							
            case 3: return "Swimming";								
            case 4: return "Drinking a cup of tea";	
            case 5: return "Napping";	
            case 6: return "Drinking a glass of water";
            case 7: return "Drinking a cup of coffee";
            case 8: return "Drinking a pint of beer";		
            case 9: return "Drinking a shot of tequila";
            case 10: return "Hiking";	
            case 11: return "Procrastinating";
            case 12: return "Running out of ideas";
            case 13: return "Taking these activity names seriously";						
            case 14: return "Cooking";
            case 15: return "Praying to the all-mighty";
            case 16: return "Drinking a glass of milk";
            case 17: return "Wrongly thinking that I'm somewhat funny";
            case 18: return "Freaking out";
            case 19: return "Studying";
            case 20: return "Eating";
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
