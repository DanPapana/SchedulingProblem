#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task {
      char name[20];
      int start_time;
      int end_time;
};
//As you could have probably guessed by now, WE have no idea how these pointers work.
void Counting_sort(int array[]) {
    int i=0;
    int j;
    int count[10];
    for (j=0; j<(strlen(&array)); j++) {
        count[j] = &array[i];
    }


    for (j=0; j<(strlen(&array)); j++) {
        printf("= %d =", count[j]);
    }
}

int main()
{
int i; //iterators
int n=2; //max number of tasks

struct task t[n];
for (i=1; i<=n; i++) {
     printf("Activity no. %d: ", i);
     scanf("%s", t[i].name);
     printf("Start time: ");
     scanf("%d", &t[i].start_time);
     printf("End time: ");
     scanf("%d", &t[i].end_time);
}
//Greedy implementation
//First we must sort the activities based on their ending times
//We will use a Counting Sort for this matter, since we're only dealing with numbers
for (i=1; i<=n; i++) {
Counting_sort(t[i].end_time);
}

return 0;
}
