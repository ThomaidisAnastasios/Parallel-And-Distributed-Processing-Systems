#include <stdio.h>
#define steps 1000000/*Prosdiorismos steps.*/

int main(int argc, char *argv[])
{
int i;/*Dhlwsh metablhtwn.*/
double step, x, summary, pi= 0;

step= 1.0/ steps;

for(i=0; i<steps; i++)
{
  x= (i+ 0.5)* step;
  summary= summary+ 4.0/ (1.0+ x* x);
}

pi= step* summary;
printf("steps= %d, pi= %f.\n", steps, pi);
return 0;
}
/*gcc -fopenmp lab-openmpi-pi_serial.c -o lab-openmpi-pi_serial*/
