/*To antergammeno ths c5 toy lab6.*/
/*To pC e;inai o elegxos gia parallhlopoihsh, ari8mos diergasewn.*/
#include <mpi.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define N 5/*Pare 5.*/

int main(int argc, char *argv[])
{
char name[BUFSIZ];
int array[10][N], i, j, mn[N], n[N], rank, size, len, pC;

MPI_Status status;
srand(time(NULL));
pC= MPI_Init(&argc ,&argv);

if(pC== 1)/*elegxos*/
{
  printf("Error.\n");
  MPI_Abort(MPI_COMM_WORLD, 1);
}

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Get_processor_name(name, &len);

if(rank== 0)
{
  printf("Rank= %d.\n", rank);

  for(i= 0; i< 10; ++i)/*0 me 10.*/
    {
      for (j= 0; j< N; ++j)/*0 me N.*/
      {
        array[i][j]= 0;
        array[i][j]= rng();/*Pane sthn random.*/
        printf("Rank= %d: array[%d][%d]= %d.\n", rank, i, j, array[i][j]);
      }
  }

  for(i= 0; i< N; ++i)
  {
    int number= i +1;
    printf("give a number for %d/ %d.", number, N);/*Dwse noymero.*/
    scanf("%d", &n[i]);/*Pare noymero.*/
  }
}

for(i= 0; i< 10; ++i)
{
  mn[i]= 0;

  for(j= 0; j< N; ++j)/*0 me N.*/
    mn[i]= mn[i]+ array[i][j]* n[j];/*kane prakseis.*/
}

for(i= 0; i< 10; ++i)/*0 me 10.*/
  for(j= 0; j< N; ++j)/*0 me N.*/
    printf("Array %d: %d= %d.\n", i+ 1, j+ 1, array[i][j]);/*Pinakas.*/

for(i= 0; i< N; ++i)
  printf("multi number %d= %d.\n", i+ 1, mv[i]);/*Pollaplasiasmeno noymero.*/

MPI_Finalize();
return 0;
}

int rng()
{
  return rand()%100;/*Vgale random.*/
}
