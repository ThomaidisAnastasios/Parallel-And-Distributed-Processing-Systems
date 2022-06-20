/*Metrame ta dedomena poy lhfthikan.*/
#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
int rank,size,error,name_length;
char b0[5],b1[5],processor_name[MPI_MAX_PROCESSOR_NAME];

MPI_Status status;
error= MPI_Init(&argc, &argv);
MPI_Get_processor_name(processor_name, &name_length);

if(error!= MPI_SUCCESS)/*Koitaei an exei error sthn arxikopoihsh.*/
{
printf("Error.\n");
printf("Processor name %s.\n", processor_name);

MPI_Abort(MPI_COMM_WORLD, error);
}

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
strcpy(b0, "xx");

if(rank == 0)
  {/*Stelnei sto 0.*/
  strcpy(b0, "xx*");
  MPI_Send(&b0, sizeof(b0), MPI_CHAR, 0, 0, MPI_COMM_WORLD);
  MPI_Recv(&b0, sizeof(b0), MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
  printf("Send %s : Receive %s.\n", b0, b0);
  }
 else if(rank == 1)/*Twra stelnei kai pairnei to mhnyma.*/
  {/*Stelnei sto 1.*/
  MPI_Send(&b1, sizeof(b0), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
  MPI_Recv(&b1, sizeof(b0), MPI_CHAR, 1, 0, MPI_COMM_WORLD, &status);
  strcpy(b1, b0);
if(b0 == "xx")
  strcpy(b1,"xx+");/*Prosthetei to +.*/
else
  {
strcpy(b1,"xx*+");/*Prosthetei to *+.*/
  }
  MPI_Send(&b1, sizeof(b1), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
  MPI_Recv(&b1, sizeof(b1), MPI_CHAR, 1, 0, MPI_COMM_WORLD, &status);
  printf("Send %s : Receive %s.\n", b1, b1);
  }
else
  printf("Nothing to do at node %s.\n", processor_name);

MPI_Finalize();
return 0;
}
