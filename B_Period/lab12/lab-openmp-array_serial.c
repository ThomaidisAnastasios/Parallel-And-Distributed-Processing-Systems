#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define size 100/*Prosdiorismos size.*/

int main(int argc, char *argv[])
{
int a[size], i, s= 0;/*Dhlwsh metablhtwn.*/

for(i= 0; i< size; ++i)
{
  a[i]= i;
  s= s+ a[i];
}

printf("Summary= %d.\n", s);

return 0;
}
/*gcc -fopenmp lab-openmp-array_serial.c -o lab-openmp-array_serial*/
