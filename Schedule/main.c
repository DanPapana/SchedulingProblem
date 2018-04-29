#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Counting_sort(int n, int array[]) {
  int i;
  for (i=1; i <= 2; i++) {
    printf("%d, ", array[i]);
  }
}

struct task {
      char name[20];
      int start_time;
      int end_time;
};

int main()
{
int i, j; //iterators
int n=2; //max number of tasks

struct task t[10];
for (i=1; i<=n; i++) {
     printf("\nActivity no. %d: ", i);
     scanf("%s", t[i].name);
     printf("\nStart time: ");
     scanf("%d", &t[i].start_time);
     printf("\nEnd time: ");
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

