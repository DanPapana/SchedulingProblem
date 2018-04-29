#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct task {
      char name[20];
      int start_time;
      int end_time;
};

void Counting_sort(int *n, int array[]) {
  int i;
  for (i=0; i<*n; i++) {
    printf("%d ", &array[i]);
  }
}

int main()
{
int i; //iterators
int n=3; //max number of tasks

struct task t[5];
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
Counting_sort(&n, t[i].end_time);
}

return 0;
}

