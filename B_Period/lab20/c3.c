#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100/*Prosdiorismos N.*/

float a[N], b[N], summary;

float calc()
{
int i, tid;/*Dhlwsh metablhtwn.*/

tid= omp_get_thread_num();

#pragma omp for reduction(+:summary)
  for(i= 0; i< N; ++i)
  {
    summary= summary+ (a[i]* b[i]);
    printf("tid= %d  i= %d\n", tid, i);
  }
}

int main(int argc, char *argv[])
{
int i;
float summary;

for(i= 0; i <N; ++i)
{
  a[i]= b[i]= 1.0 * i;
  summary= 0.0;
}

#pragma omp parallel
summary= calc();

printf("summary = %f\n", summary);

return 0;
}
/*gcc -fopenmp c3.c -o c3*/