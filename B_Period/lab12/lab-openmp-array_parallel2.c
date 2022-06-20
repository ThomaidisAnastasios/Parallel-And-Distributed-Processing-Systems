#include <omp.h>
#include <stdio.h>

#define size 100/*Prosdiorismos size.*/

int main(int argc, char *argv[])
{
int a[size], i, s= 0;/*Dhlwsh metablhtwn.*/

#pragma omp parallel for reduction(+:s)
  for(i= 0; i< size; ++i)
  {
    a[i]= i;
    s= s+ a[i];
  }

printf("Summary= %d.\n", s);

return 0;
}

