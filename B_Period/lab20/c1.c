#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

int processors, threads, MaxThreads, InParallel, DynamicThreadsEnabled, NestedParallelismSupported;/*Dhlwsh metablhtwn.*/

#pragma omp parallel
{
  processors= omp_get_num_procs();/*Etsi pernoume ton ari8mo twn epeksergastwn.*/
  threads= omp_get_num_threads();/*Etsi pernoume ton ari8mo twn threads.*/
  Max_Threads= omp_get_max_threads();/*Etsi pernoume ton ari8mo twn megistwn threads.*/
  InParallel= omp_in_parallel();/*Etsi pernoume ton ari8mo twn parallhlwn.*/
  DynamicThreadsEnabled= omp_get_dynamic();/*Etsi pernoume ton ari8mo twn dynamikwn threads.*/
  NestedParallelismSupported= omp_get_nested();/*Etsi pernoume twn parallhlwn.*/
}

printf("Number of processors= %d.\n", processors);
printf("Number of threads= %d.\n", threads);
printf("Number of max simultaneous threads= %d.\n", MaxTreads);
printf("In parallel= %d.\n", InParallel);
printf("Dymanic threads enabled= %d.\n", DynamicThreadsEnabled);
printf("Nested parallelism supported= %d.\n", NestedParallelismSupported);

return 0;
}
/*gcc -fopenmp c1.c -o c1*/