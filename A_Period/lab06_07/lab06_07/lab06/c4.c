#include <mpi.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define N 5/*Thelei pente.*/

int main(int argc, char *argv[])
{
int array[10][N], i, j, number, mn[N], n[N];

srand(time(NULL));/*Random.*/
init_ar(array);

for(i= 0; i< N; ++i)
{
  int number= i +1;
  printf("Give an integer number for %d/ %d.", number, N);
  scanf("%d", &n[i]);/*Pare noumero.*/
}

for(i= 0; i< 10; ++i)
{
  mn[i]= 0;

  for(j= 0; j< N; ++j)
    mn[i]= mn[i]+ array[i][j]* n[j];/*Ypologismos toy pinaka.*/
}

for(i= 0; i< 10; ++i)
  for(j= 0; j< N; ++j)
    printf("Array %d: %d= %d\n",i+ 1,j+ 1, array[i][j]);/*Pinakas.*/

for(i= 0; i < N; ++i)
  printf("multi number %d= %d.\n", i+ 1, mn[i]);/*Pollaplasiasmeno.*/

return 0;
}

void init_ar(int array[10][N])
{
int i, j;
FILE *fp;

fp= fopen("array.dat", "r");/*Open file an to vreis.*/

if(fp== NULL)
{
  printf("Cant find the array.dat file.\n");
  exit(EXIT_FAILURE);/*Elegxos gia to array.dat file.*/
}

for(i= 0; i< 10; ++i)
{
  for(j= 0; j< N; ++j)
  {
    array[i][j]= 0;
    fscanf(fp, "%d ", &array[i][j]);/*Anoikse thn f.*/
  }
}

fclose(fp);/*Kleise thn f.*/
}
