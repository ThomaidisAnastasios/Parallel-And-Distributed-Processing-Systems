#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int i, threads;/*Dhlwsh metablhtwn.*/
double a[50], b[50], c[50], d[50];

#pragma omp parallel
{
  for(i= 0; i< 50; ++i)/*Ayto to dinei mesa.*/
  {
    a[i]= i* 1.5;
    b[i]= i+ 22.35;
    c[i]= d[i]= 0.0;
  }
  
  threads= omp_get_num_threads();
}

printf("Threads created= %d.\n", threads);

#pragma omp parallel sections
{
  #pragma omp section
  {
    threads= omp_get_num_threads();
    printf("1 %d number of threads.\n", threads);/*Ari8mos thread pinaka 1.*/
    printf("C: .\n");

    for(i= 0; i< 50; ++i)
    {
      c[i]= a[i] + b[i];/*Pinakas c.*/
      printf("c[%d]= %f.\n", i, c[i]);/*Emfanizei ton pinaka c.*/
    }
  }

  #pragma omp section
  {
    threads= omp_get_num_threads();
    printf("2 %d number of threads.\n", threads);/*Ari8mos thread pinaka 2.*/
    printf("D: .\n");

    for(i= 0; i< 50; ++i)
    {
      d[i]= a[i]* b[i];/*Pinakas d.*/
      printf("d[%d]= %f.\n", i, d[i]);/*Emfanizei ton pinaka d.*/
    }
  }
}

return 0;
}
/*gcc -fopenmp c2.c -o c2*/