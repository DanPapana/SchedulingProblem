#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
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

///adds a node
Node* push_beginning(Node *list, Task *info) {
    Node *new_node = malloc(sizeof(Node));
    new_node->info = *info;
    new_node->next = list;
    list = new_node;
    return list;
}

///prints all the nodes in a mediocre fashion
void print_info(Node *head) {
    Node *iterator;
    iterator = head;
    printf("\nTODAY'S ACTIVITIES ARE:\n");
    while (iterator != NULL) {
        printf("\nActivity: %s\n", iterator->info.name);
        printf("Starting time: %d:00\n", iterator->info.start_time);
        printf("Ending time:   %d:00\n", iterator->info.end_time);
        iterator = iterator->next;
    }
}

///swaps the information within nodes
void swap(Node *a, Node *b) {
    Task temp;
    temp = a->info;
    a->info = b->info;
    b->info = temp;
}

///prints a node, duh
void print_node(Node *head) {
    if (head != NULL) {
        printf("\n==============================");
        printf("\nActivity: %s", head->info.name);
        printf("\nStarting time: %d:00", head->info.start_time);
        printf("\nEnding time:   %d:00", head->info.end_time);
    }
}

//A shameless bubble sort
Node *sort_end(Node *head) {
    Node *parent = head;
    Node *iterator = head;
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

/// Too greedy. Skips through elements.
Node *greedy(Node *head) {
    Node *parent = malloc(sizeof(Node));
    Node *iterator = malloc(sizeof(Node));
    parent = head;
    iterator = head->next;
    printf("\n-------- GREEDY ---------");
    print_node(parent);
    while (iterator != NULL) {
        while (iterator != parent) {
            if (parent->info.end_time <= iterator->info.start_time) {
                print_node(iterator);
            }
            parent = parent->next;
        }
        iterator = iterator->next;
    }
}

/// A modified selection sort. May I still call it backtrack?
Node *backtrack(Node *head) {
    Node *parent = malloc(sizeof(Node));
    Node *min = malloc(sizeof(Node));
    Node *iterator = head;
    Node *iterator_1 = head;
    Node *iterator_min = head;

    int TF = 0;
    printf("\n------ BACKTRACKING ------");
    while (iterator != NULL) {
        iterator_min = iterator;
        min = iterator;
/// This one would be classified as a fancier selection sort
        while (iterator_min != NULL) {
            if (iterator_min->info.start_time == min->info.start_time)	 {
                if (iterator_min->info.end_time < min->info.end_time) {
                    min = iterator_min;
                }
            }
            else if (iterator_min->info.start_time < min->info.start_time) 	{
                min = iterator_min;
            }
            iterator_min = iterator_min->next;
        }
        if (min->info.start_time < iterator->info.start_time) {
            swap(iterator, min);
        }
/// Iterator is now min, don't get too confused
        iterator_1 = iterator;
        TF = 0;
/// If TF = 1 the node doesn't fit the criteria
        while (iterator_1 != NULL) {
            if (iterator_1->info.end_time < iterator->info.end_time) {
                TF = 1;
            }
            if (parent->info.end_time > iterator->info.start_time) {
                TF = 1;
            }
            iterator_1 = iterator_1->next;
        }
        if (TF == 0) {
            print_node(iterator);
            parent = iterator;
        }
        iterator = iterator->next;
    }
}

/// This function is not giving anything away, quite the contrary
Node *free_list(Node *head) {
    Node *iterator = head;
    Node *parent = head;
    while (iterator != NULL) {
        parent = iterator;
        free(parent);
    }
    return NULL;
}

/// A list of activities with a STRING of humor
char* activities(int choice) {
    switch(choice) {
    case 1:
        return "Running";
    case 2:
        return "Reading";
    case 3:
        return "Swimming";
    case 4:
        return "Drinking a cup of tea";
    case 5:
        return "Napping";
    case 6:
        return "Drinking a glass of water";
    case 7:
        return "Drinking a cup of coffee";
    case 8:
        return "Drinking a pint of beer";
    case 9:
        return "Watching YouTube videos";
    case 10:
        return "Hiking";
    case 11:
        return "Procrastinating";
    case 12:
        return "Running out of ideas";
    case 13:
        return "Taking these names seriously";
    case 14:
        return "Cooking";
    case 15:
        return "Praying to the all-mighty";
    case 16:
        return "Drinking a glass of milk";
    case 17:
        return "Wrongly thinking I'm somewhat funny";
    case 18:
        return "Freaking out";
    case 19:
        return "Studying";
    case 20:
        return "Eating";
    }
}

int main()
{
    int choice;
    int iterator = 0;
    int no_activities;
    int r_start = 25; //random starting time
    int r_end = 25; //random ending time
    int s_range = 0; //starting range
    int f_range = 25; //finishing range
    int activity;
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
        backtrack(head);
        head = sort_end(head);
        head = greedy(head);
    } else if (choice % 2 == 0) {
        print_info(head);
        backtrack(head);
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

