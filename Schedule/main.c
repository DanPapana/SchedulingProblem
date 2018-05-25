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

Node* push_beginning(Node *list, Task *info) {
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
        printf("\nActivity:    %s\n", iterator->info.name);
        printf("Starting time: %d:00\n", iterator->info.start_time);
        printf("Ending time:   %d:00\n", iterator->info.end_time);
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
        printf("\nActivity:      %s", head->info.name);
        printf("\nStarting time: %d:00", head->info.start_time);
        printf("\nEnding time:   %d:00\n", head->info.end_time);
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
    Node *iterator = head->next;
    printf("\n*********************************************");
    printf("\nTHE LIST OF TODAY'S ACTIVITIES:\n");
    printf("**********************************************");
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

Node *find_min(Node *head) {
    Node *iterator = head;
    Node *min = head;
    while (iterator->next != NULL) {

        if (iterator->info.start_time == min->info.start_time) {
            if (iterator->info.end_time < min->info.end_time) {
                min = iterator;
            }
        } else {
            if (iterator->info.start_time < min->info.start_time) {
                min = iterator;
            }
        }
        iterator = iterator->next;
    }
    return min;
}

Node *backtrack(Node *head) {
    Node *solution = malloc(sizeof(Node));
    Node *min;
    Node *parent = head;
    Node *iterator_1 = head;
    Node *iterator_2 = head;

    while (iterator_1->next != NULL) {
        min = find_min(head);
        while (iterator_2->next != NULL) {
            iterator_2 = iterator_2->next;
            if (min->info.end_time <= iterator_2->info.end_time) {
                parent->next = solution;
                parent = parent->next;
                solution->next = min;
                solution = solution->next;
                print_node(solution);
            }
            else
            {
                solution = parent;
            }
        }
        iterator_1 = iterator_1->next;
    }
   // print_node(solution);
   // return solution;
}

Node *free_list(Node *head) {
    Node *iterator = head;
    Node *parent;
    while (iterator != NULL) {
        parent = iterator;
        free(parent);
    }
    return NULL;
}

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
        return "Taking these activity names seriously";
    case 14:
        return "Cooking";
    case 15:
        return "Praying to the all-mighty";
    case 16:
        return "Drinking a glass of milk";
    case 17:
        return "Wrongly thinking that I'm somewhat funny";
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
    int i = 0;
    int n = 2;
    int r_start; //random starting time
    int r_end; //random ending time
    int s_range = 0; //starting range
    int f_range = 25; //finishing range
    int activity;
    /*
    printf("n = ");
    scanf("%d", &n);
    */
    Node *head;
    init(&head);

    Task *new_task = (Task*)malloc(sizeof(Task));

    //I have introduced some values which would trigger the while loop
    while (s_range >= f_range || s_range <= 0 || f_range > 24) {
        printf("\nInsert the working hours (1 to 24):");
        printf("\nStarting time: ");
        scanf("%d", &s_range);
        printf("Ending time: ");
        scanf("%d", &f_range);
    }

    while (i < n) {
        while (r_start >= r_end || r_end > 24 || r_start == new_task->start_time) {
            srand((unsigned)time(NULL));
            // r_start = s_range + rand()/(RAND_MAX/(f_range - s_range +1) + 1);
            // r_end = s_range + rand()/(RAND_MAX/(f_range - s_range +1) + 1);
            r_start = s_range + rand() % (f_range - s_range);
            r_end = r_start + rand() % (f_range - s_range);
        }
        activity = 1 + rand() % 20;
        new_task->start_time = r_start;
        new_task->end_time = r_end;
        new_task->name = activities(activity);
        head = push_beginning(head, new_task);
        i++;
    }
    //head = sort_end(head);
    print_info(head);
    printf("B E H O L D");
    head = backtrack(head);
    //head = greedy(head);
    head = free_list(head);
    return 0;
}
