/*Arithmitikh sxesh.*/
#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
int rank, size, error, name_length;
char b0[3], processor_name[MPI_MAX_PROCESSOR_NAME];

MPI_Status status;
error= MPI_Init(&argc, &argv);
MPI_Get_processor_name(processor_name, &name_length);

if(error!= MPI_SUCCESS)
{
printf("Error.\n");
printf("Processor name %s.\n", processor_name);

MPI_Abort(MPI_COMM_WORLD, error);
}

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
strcpy(b0, "xx");

if(rank== 0)
{/*Stelnei to mhnyma sto 0 sto epomeno rank.*/
  MPI_Send(&b0, sizeof(b0), MPI_CHAR, (rank+1), 0, MPI_COMM_WORLD);
  MPI_Recv(&b0, sizeof(b0), MPI_CHAR, (rank+1), 0, MPI_COMM_WORLD, &status);
  printf("Rank %d %s Send %s :Receive %s.\n", rank, processor_name, b0, b0);
}
else if(rank == 1)
{/*Stelnei to mhnyma sto 0 sto proeigoumeno rank.*/
  MPI_Send(&b0, sizeof(b0), MPI_CHAR, (rank-1), 0, MPI_COMM_WORLD);
  MPI_Recv(&b0, sizeof(b0), MPI_CHAR, (rank-1), 0, MPI_COMM_WORLD, &status);
  printf("Rank %d %s Send %s :Receive %s.\n", rank, processor_name, b0, b0);
}
else
  printf("Nothing to do at node %s.\n", processor_name);

MPI_Finalize();
return 0;
}
