/*Prwto programma c1 sto lab 10 me threads.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 50

void *pHello(void *threadid);

int main()
{/*Dhlwnoyme pragmata.*/
pthread_t threads[NUM_THREADS];
int i, *threadid[NUM_THREADS];

for(i=0; i<NUM_THREADS; i++)/*Einai apo 0 mexri kai ton arithmo twn diergaseiwn.*/
{
  threadid[i]= (int *) malloc(sizeof(int));
  *threadid[i]= i;
  phello(threadid[i]);/*Pane sthn synarthsh.*/
}

return 0;
}

void *phello(void *threadid)
{
int id= *(int *)threadid;

printf("Hello World: Thread: %d.\n", (int)id+ 1);
fflush(NULL);/*Clear.*/

void pthread_exit(void *);
}
