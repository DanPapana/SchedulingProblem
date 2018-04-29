#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct schedule {
      char name[20];
      int start_time;
      int end_time;
} Task;

typedef struct list {
    struct schedule task;
    struct list *next;
} Node;

int main()
{
    int i=1;
    int n=2;
    //printf("n = ");
    //scanf("%d", &n);
    Task *new_info = malloc(sizeof(struct schedule));
    Node *head = malloc(sizeof(struct list));
    head->next = NULL;
    for (i=1; i<=n; i++) {
     printf("Activity no. %d: ", i);
     scanf("%s", new_info->name);
     printf("Start time: ");
     scanf("%d", &new_info->start_time);
     printf("End time: ");
     scanf("%d", &new_info->end_time);
    }




    printf("%s", new_info->name);
    printf("%d", new_info->start_time);
    printf("%d", new_info->end_time);
//Greedy implementation
//First we must sort the activities based on their ending times
//We will use a Counting Sort for this matter, since we're only dealing with numbers

return 0;
}
