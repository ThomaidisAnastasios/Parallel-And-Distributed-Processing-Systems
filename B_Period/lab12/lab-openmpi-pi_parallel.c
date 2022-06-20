#include <omp.h>
#include <stdio.h>

#define steps 1000000/*Prosdiorismos steps.*/

int main(int argc, char *argv[])
{
int i;/*Dhlwsh metablhtwn.*/
double step, x, sum, pi= 0;

step= 1.0/ steps;

#pragma omp parallel for private(x) reduction(+:sum)

for(i=0; i<steps; i++)
{
  x= (i+ 0.5)* step;
  sum= sum+ 4.0/ (1.0+ x* x);
}

pi= step* sum;
printf("Steps= %d, pi= %f.\n", steps, pi);
return 0;
}
