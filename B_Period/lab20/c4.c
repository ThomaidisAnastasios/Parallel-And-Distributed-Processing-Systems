#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1048/*Prosdiorismos N.*/

double a[N][N];

int main(int argc, char *argv[])
{
int nthreads, tid, i, j;/*Dhlwsh metablhtwn.*/

#pragma omp parallel shared(nthreads) private(i, j, tid, a)
{
  tid= omp_get_thread_num();
  
  if(tid== 0)
  {
    nthreads= omp_get_num_threads();
	printf("Number of threads= %d.\n", nthreads);
  }
  
  printf("Thread %d starting.\n", tid);

  for(i= 0; i< N; ++i)
    for (j= 0; j< N; ++j)
	  a[i][j]= tid+ i+ j;

  printf("Thread %d done. Last element= %f.\n", tid, a[N - 1][N - 1]);
}

return 0;
}
/*gcc -fopenmp c3.c -o c3*/