/*Script 4 me threads mesa apo main se void.*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 4

void *compthread(void *t);

int main()
{
int t, e, *tasksid[NUM_THREADS];
void *status;
pthread_t threads[NUM_THREADS];

pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

for(t= 0; t< NUM_THREADS; t++)/*Einai apo 0 mexri kai ton arithmo twn diergaseiwn.*/
{
  tasksid[t]= (int *) malloc(sizeof(int));/*Pare tis diergasies.*/
  *tasksid[t]= t;
  printf("Thread make Number: %d.\n", t);
  if(e= pthread_create(&tasks[t], &attr, compthread, (void *)tasksid[t]))
  {
    printf("Failed to create thread: %d.\n", t+ 1);
    exit(1);/*Apetyxe.*/
  }
}

pthread_attr_destroy(&attr);
for(t= 0; t< NUM_THREADS; t++)/*Einai apo 0 mexri kai ton arithmo twn diergaseiwn.*/
{
  if(e= pthread_join(tasks[t], &status))
  {
    printf("Failed to join thread: %d.\n", t+ 1);
    exit(1);/*Pali apetyxe.*/
  }
  else
    printf("Joined thread: %d with status: %d.\n", t, (long)status);
}

return 0;
}

void *compthread(void *t)
{
int i, tasksid= *(int *)t;
double r= 0.0;
pthread_t id;
id= pthread_self();

printf("Thread: %d started.\n", tasksid);
for(i=0; i< 1000; i++)
 r+= sin(i)* tan(i);/*Pare to result.*/

printf("Threads: %d Finished. Result: %f. ID: %d.\n", tasksid, r, (unsigned)id);
void pthread_exit(void *);

}
