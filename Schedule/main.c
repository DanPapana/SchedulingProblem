#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

int main()
{
    int choice;
    int iterator = 0;
    int no_activities;
    int r_start = 25; ///<random starting time
    int r_end = 25; ///<random ending time
    int s_range = 0; ///<starting range
    int f_range = 25; ///<finishing range
    int activity; ///<activity choice
    Node *head;
    init(&head);
    Task *new_task = (Task*)malloc(sizeof(Task));
    printf("\nOdd for greedy, even for the other one, 0 for both: ");
    scanf("%d", &choice);
    printf("\nInsert the number of activities: ");
    scanf("%d", &no_activities);

    ///I have introduced some values which would trigger the while loop
    while (s_range >= f_range || s_range < 1 || f_range > 24) {
        printf("\nInsert the working hours (1 to 24):");
        printf("\nStarting time: ");
        scanf("%d", &s_range);
        printf("Ending time: ");
        scanf("%d", &f_range);
    }

/**It iterates while the number of iterations is lower than the total number of activities (no_activities).
It then checks if the randomized values are not equal, not bigger than 24 and not smaller than 1.
If they are, it randomizes again. If both randomized numbers fit the criteria, it assigns the smaller
number to the starting time and the bigger number to the ending time. The activity is also randomly generated,
via a number from 1 to 20 as mentioned earlier */
    while (iterator < no_activities) {
        while (r_start == r_end || r_start == new_task->start_time || r_end == new_task->start_time || r_start < 1 || r_end < 1 || r_start > 24 || r_end > 24) {
            srand((unsigned)time(NULL));
            r_start = s_range + rand() % f_range;
            r_end = s_range + rand() %	f_range;
        }
        activity = 1 + rand() % 20;
        if (r_start < r_end) {
            new_task->start_time = r_start;
            new_task->end_time = r_end;
        } 	else {
            new_task->start_time = r_end;
            new_task->end_time = r_start;
        }
        new_task->name = activities(activity);
        head = push_beginning(head, new_task);
        iterator++;
    }
    if (choice == 0) {
        print_info(head);
        dynamic(head);
        head = sort_end(head);
        head = greedy(head);
    } else if (choice % 2 == 0) {
        print_info(head);
        dynamic(head);
    } else	{
        printf("\n_________GREEDY__________\n");
        head = sort_end(head);
        print_info(head);
        head = greedy(head);
    }
    printf("\n********************************\n");
    head = free_list(head);
    free(new_task);
    return 0;
}
