#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

///Gets the head of the node and initializes it
void init(Node **head) {
    *head = NULL;
}

/** Gets a link to the previous first node and the data for the node you want to add
and adds it at the beginning. It then returns the address of the just-added function */
Node* push_beginning(Node *list, Task *info) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->info = *info;
    new_node->next = list;
    list = new_node;
    return list;
}

/** Gets the head of the node as the first value, then iterates through
all the nodes, printing all of their information */
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

///Gets two nodes as values and swaps their data
void swap(Node *a, Node *b) {
    Task temp;
    temp = a->info;
    a->info = b->info;
    b->info = temp;
}

///Prints out the information of a desired node in a fancy way
void print_node(Node *head) {
    if (head != NULL) {
        printf("\n==============================");
        printf("\nActivity: %s", head->info.name);
        printf("\nStarting time: %d:00", head->info.start_time);
        printf("\nEnding time:   %d:00", head->info.end_time);
    }
}

/** Sorts the nodes based on their ending times. The "iterator" node holds the
value of the current node, while the "parent" node holds the value of the previous one.
It then returns the values, starting from the previous node*/
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

/** Starting from the head of the list, prints out the first element and then iterates
through all the other elements, with the parent node left slightly behind.
It then prints out the node that has a starting time with a value bigger
than that of the previously printed node's ending time*/
Node *greedy(Node *head) {
    Node *parent = (Node*)malloc(sizeof(Node));
    Node *iterator = (Node*)malloc(sizeof(Node));
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

/**Starting from the head node it iterates through all elements, trying to find
the one with the shortest starting and ending time. It then swaps the found node
with the value of the current iterator, so it won't be found again. It now checks
whether it would be a good fit for the problem's solution. In order to find this out,
it compares the value of its ending time with the rest of the nodes. If there are no
such values and if it fits (its starting time has a bigger value than the previously
printed node's ending time), its value is printed out using the "print_node" function*/
Node *dynamic(Node *head) {
    Node *parent = (Node*)malloc(sizeof(Node));
    Node *min = (Node*)malloc(sizeof(Node));
    Node *iterator = head;
    Node *iterator_1 = head;
    Node *iterator_min = head;
///TF is an integer, with values 0 and 1, checking whether the minimum nodes fits the required criteria
    int TF = 0;
    printf("\n------ DYNAMICAL ------");
    while (iterator != NULL) {
        iterator_min = iterator;
        min = iterator;
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

/**This function passes through elements, deleting them and freeing the memory.
It returns NULL for dramatic effect*/
Node *free_list(Node *head) {
    Node *iterator = head;
    Node *parent = head;
    while (iterator != NULL) {
        parent = iterator;
        free(parent);
    }
    return NULL;
}

/** The program picks a random number from 1 to 20 and then returns a string assigned to that value*/
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
    default:
        return "Baking bacon pancakes";
    }
}

