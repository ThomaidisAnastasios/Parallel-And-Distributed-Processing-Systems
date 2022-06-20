/*C4 mono me synarthseis arxikopoihshs OpenMPI.*/
#include <mpi.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define N 5

int main(int argc, char *argv[])
{
int array[10][N], i, j, number, mn[N], n[N];

MPI_Init(&argc, &argv);
srand(time(NULL));
rn(array);/*Ftiakse thn random.*/

for(i= 0; i< 10; ++i)
  for(j= 0; j< N; ++j)
  {
    array[i][j]= 0;
	  array[i][j]= rn();
  }

for(i= 0; i< N; ++i)
{
  int number= i +1;
  printf("Give a number for %d/ %d.", number, N);/*Dwse noymero.*/
  scanf("%d", &n[i]);/*Pare noymero.*/
}

for(i= 0; i< 10; ++i)
{
  mn[i]= 0;

  for(j= 0; j< N; ++j)
    mn[i]= mn[i]+ array[i][j]* n[j];/*Pollaplasiasmos. Ypologismos pinakwn.*/
}

for(i= 0; i< 10; ++i)
  for(j= 0; j< N; ++j)
    printf("Array %d: %d= %d.\n", i+ 1, j+ 1, array[i][j]);

for(i= 0; i< N; ++i)
  printf("Multi number %d= %d.\n", i+ 1, mn[i]);/*Pollaplasiasmeno noumero.*/

MPI_Finalize();
return 0;
}

int rn()
{
  return rand()%100;/*Tyxaiothta.*/
}
