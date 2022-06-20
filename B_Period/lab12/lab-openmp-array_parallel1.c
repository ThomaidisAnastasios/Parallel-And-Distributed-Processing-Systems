#include <omp.h>
#include <stdio.h>

#define size 100/*Prosdiorismos size.*/

int main(int argc, char *argv[])
{
int a[size], i, s= 0;/*Dhlwsh metablhtwn.*/

#pragma omp parallel for
  for(i= 0; i< size; ++i)
  {
    a[i]= i;

    #pragma omp critical
      s= s+ a[i];
  }

printf("Summary= %d.\n", s);

return 0;
}
/*gcc -fopenmp lab-openmp-array_parallel1.c -o lab-openmp-array_parallel1*/