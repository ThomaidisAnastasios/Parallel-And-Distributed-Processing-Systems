#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define size 100/*Dhlwsh size.*/

int main(int argc, char const *argv[])
{
double charge, summary;/*Dhlwsh Metablhtwn.*/
int i, j, a[size][size], b[size][size], c[size* size];

charge= omp_get_wtime();

for(i= 0; i< size; ++i)
  for(j= 0; j< size; ++j)
  {
    a[i][j]= i* j;
    b[i][j]= i* j;
  }

for(i= 0; i< size; ++i)
  for(j= 0; j< size; ++j)
    c[i* j]= a[i][j]* b[i][j];


summary= omp_get_wtime()- charge;

printf("Summary= %f sec.\n", summary);

return 0;
}
/*gcc -fopenmp lab-openmp-mul_matrix_serial.c -o lab-openmp-mul_matrix_serial*/
