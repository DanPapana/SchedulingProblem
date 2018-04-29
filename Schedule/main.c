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

void print_info(Node *head) {
    Node *iterator;
    iterator = head;
    while (iterator->next!=NULL) {
        //printf("%s", iterator->task.name);
        printf("%d", iterator->task.start_time);
        printf("%d", iterator->task.end_time);
        iterator = iterator->next;
    }
}

int main()
{
    int i=1;
    int n=3;
    char str[20];
    int num;
    //printf("n = ");
    //scanf("%d", &n);
    task *new_element = malloc(sizeof(struct schedule));
    Node *head = malloc(sizeof(struct list));
    head->next = NULL;

    //for (i=1; i<=n; i++) {
     //printf("Activity: ");
     //scanf("%s", str);
     printf("Start time: ");
     scanf("%d", &num);
     printf("End time: ");
     scanf("%d", &new_element->end_time);
    //}

    new_element->start_time = num;
    //printf("%d", new_element->start_time);
    print_info(head);
//Greedy implementation
//First we must sort the activities based on their ending times
//We will use a Counting Sort for this matter, since we're only dealing with numbers

    free(head);
return 0;
}
