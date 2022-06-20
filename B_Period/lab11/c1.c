/*c1 tou 11. Nhmata gia ypologismo ginomenoy dianysmatwn me amoibaio apokleismo.*/
/*Mad dinetai sxedon olos o kwdikas. Syndyasmos c1 kai c2.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define NUMTHRDS 4
#define VECLEN 100

/*Koino struct.*/
typedef struct
{
int veclen;
double *a, *b, sum;
dotstr.veclen= VECLEN;
dotstr.a= a;
dotstr.b= b;
dotstr.sum= 0;

} DOTDATA;

DOTDATA dotstr;
pthread_t threads[NUMTHRDS];/*Orismos pinaka isos me ta threads.*/
pthread_mutex_t mutexsum;/*Orismos metablhthtw mutexsum san pthread_mutex_t.*/

int main(int argc, char *argv[])
{/*Dhlwsh metablhtwn.*/
void *status;
double *a, *b;
int i, t, error, *taskids[NUMTHRDS];
pthread_mutexattr_t attr1;
pthread_attr_t attr2;

pthread_mutex_init(&mutexsum, &attr1);/*Arxikopoihsh me mutex_init.*/
pthread_attr_init(&attr2);
pthread_attr_setdetachstate(&attr2, PTHREAD_CREATE_JOINABLE);/*Attribute se join.*/

/*Assign storage and initialize values.*/
a= (double *) malloc(NUMTHRDS* VECLEN* sizeof(double));
b= (double *) malloc(NUMTHRDS* VECLEN* sizeof(double));

for(i= 0; i< (VECLEN * NUMTHRDS); ++i)
{/*Arxikopoihsh twn a kai b.*/
  a[i]= 1.0;
  b[i]= 2* a[i];
}

for(t= 0; t< NUMTHRDS; ++t)/*Apo 0 mexri kai to NUTHRDS.*/
{
  taskids[t]= (int *) malloc(sizeof(int));
  *taskids[t]= t;

  if(error= pthread_create(&threads[t], &attr2, compute_multiplication, (void *) taskids[t]))
  {
    printf("Error: Creating thread: %d failed.\n", t + 1);
    exit(1);/*Katastrefoume to mutex.*/
  }
}

pthread_attr_destroy(&attr2);

for(t= 0; t< NUMTHRDS; ++t)/*Apo 0 mexri kai to NUTHRDS.*/
{
  if(error= pthread_join(threads[t], &status))
  {
  printf("Error: Joining thread: %d failed.\n", t + 1);
  exit(1);/*Katastrefoume to mutex.*/
  }
  else
    printf("Joined thread: %d with: %ld.\n", t + 1, (long) status);
}

printf("Sum: %f.\n", dotstr.sum);

/*Eleytheronoyme tis metavlhtes.*/
free(a);
free(b);
pthread_mutex_destroy(&mutexsum);

return 0;
}

void compute_multiplication(void *t)
{
pthread_t id;
int i, sum= 0, ct;

ct= *(int *)t;
id= pthread_self();
/*Ypologismos toy sum gia olo to euros.*/
/*To euros ksekinaei apo to dotstr.veclen kai teleiwnei sto dotstr.veclen) +dotstr.veclen*/
for(i=ct* dotstr.veclen; i< (ct* dotstr.veclen) +dotstr.veclen; ++i)
{
  sum= sum+ (a[i]* b[i]);/*Emfanish Enhmervtikoy mhnymatos.*/
  printf("Current thread= %d counted from: %d to: %d and sum= %d.\n", id, ct* dotstr.veclen, (ct* dotstr.veclen) + dotstr.veclen, sum);
}	

pthread_mutex_lock(&mutexsum);/*Kleidwnoume to sum gia na topothethsoyme timh. Epeidh h struct einai koinh.*/
dotstr.sum+= sum;/*Enhmerwsh athroismatos.*/
pthread_mutex_unlock(&mutexsum);/*Ksekleidwnoyme to sum gia na einai diathesimo kai gia allo nhma.*/
printf("Current value %f.\n", dotstr.sum);
pthread_exit((void *) 0);
}