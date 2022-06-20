/*Theloume n stelnoyme dedomena stis alles diergasies.*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define Size 100

MPI_Status status;
MPI_Request request;

int main(int argc, char *argv[])
{
int chunk= -1, destination= -1, d1[Size], d2[Size], i= 0, j= 0, size= 0, pr= 0, rank= 0, sour= -1, sum= 0, sum1= 0;

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

pr= size;
ch= Size/ pr;

if(rank== 0)
{
  for(i= 0; i< Size; ++i)
    d1[i]= i+1;

  for(destination= 1; destination< pr; ++destination)
  {/*Edw xrhsimopoieitai h Scatter. Stelnei ta dedomena.*/
    MPI_Scatter(&j, 1, MPI_INT, &j, 1, MPI_INT, 0, MPI_COMM_WORLD);/*Kanei aoe send.*/
    MPI_Scatter(&d1[j], ch, MPI_INT, &d2[j], ch, MPI_INT, 0, MPI_COMM_WORLD);/*Kanei aoe send.*/
    j= j+ ch;
  }

  for(i= 1; i< pr; ++i)
  {
    sour= i;
    MPI_Gather(&sum, 1, MPI_INT, &sum, 1, MPI_INT, 0, MPI_COMM_WORLD);/*Syllegei ta dedomena.*/
    sum1= sum1 + sum;/*Ypologizei to synolo.*/
    printf("Received %d: Sum= %d.\n", sour, sum);
  }

  printf("Sum= %d.\n", sum1);

  }
  else if(rank> 0)
  {
    MPI_Gather(&j, 1, MPI_INT, &j, 1, MPI_INT, 0, MPI_COMM_WORLD);/*Syllegei ta dedomena.*/
    MPI_Gather(&d1[j], ch, MPI_INT, &d2[j], ch, MPI_INT, 0, MPI_COMM_WORLD);/*Syllegei ta dedomena.*/

    for(i= j; i< j+ ch; ++i)
    sum= sum+ d2[i];

    MPI_Scatter(&sum, 1, MPI_INT, &sum, 1, MPI_INT, 0, MPI_COMM_WORLD);
  }

MPI_Finalize();
return 0;
}
