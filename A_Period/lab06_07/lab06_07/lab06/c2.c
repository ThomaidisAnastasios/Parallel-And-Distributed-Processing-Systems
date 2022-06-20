/*C1 me MPI_Scatter.*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
char name[BUFSIZ];
int i, j, len= -1, N= atoi(argv[1]), pc= -1, range[N], rank= -1, size= -1, Ndiv= N/size, lr[Ndiv];
float pi= 0.0, W= 1.0/ N, typos[size];

MPI_Status status;
pc= MPI_Init(&argc, &argv);

if(pc== 1)
{
  MPI_Abort(MPI_COMM_WORLD, 1);/*Check.*/
  return 0;
}

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Get_processor_name(name, &len);

if(size< 2)
{
  printf("Must have at least 2 processes.\n");
  MPI_Abort(MPI_COMM_WORLD, 1);
  return 0;
}

if(rank== 0)
  for(i= 0 ; i< N; i++)
    range[i]= i;
/*Pali me Scatter stelnoyme.*/
MPI_Scatter(range, Ndiv, MPI_INT, lr, Ndiv, MPI_INT, 0, MPI_COMM_WORLD);/*Kanei aoe send.*/
typos[rank]=0.0;

for(j= 0; j< Ndiv; j++)
{
  i= lr[j];
 
 typos[rank]= typos[rank]+ 4* W/ (1+ (i+ 0.5)* (i+ 0.5)* W* W);/*Typos gia na vroyme to rank.*/
}

if(rank== 0)
{
  pi= typos[0];
  for(i= 1; i< size; ++i)
  {
    MPI_Recv(typos[i], 1, MPI_FLOAT, i, 0, MPI_COMM_WORLD, &status);
    pi= pi+ typos[i];/*Briskoume p.*/
    printf("pi= %f.\n",pi);/*Typwnei to pi.*/
  }
}
else if(rank> 0)
{
  printf("Rank= %d: Sending= %f\n",rank
  typos[rank]);/*Stelnei ta rank.*/
  MPI_Send(typos[rank], 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
}

MPI_Finalize();
if(rank== 0 )
  printf("Result %f.\n",pi);/*Typwnei to teliko pi.*/

return 0;
}

