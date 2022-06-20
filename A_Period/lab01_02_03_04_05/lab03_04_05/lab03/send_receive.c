/*Xrhsimopoioymai mia if gia na steiloyme kai na lavoume mhnyma.*/
#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
int rank,size,error,name_length;;
char b[3], processor_name[MPI_MAX_PROCESSOR_NAME];

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
strcpy(b, "xx");

if(rank== 0)/*Stelnei to mhnyma xx kai to kanei receive meta.*/
{
MPI_Send(&b, sizeof(b), MPI_CHAR, 0, 0, MPI_COMM_WORLD);
MPI_Recv(&b, sizeof(b), MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
printf("Send %s : Receive %s.\n", b, b);
}
else if(rank== 1)
{/*Kanei ta panw anapoda.*/
MPI_Send(&b, sizeof(b), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
MPI_Recv(&b, sizeof(b), MPI_CHAR, 1, 0, MPI_COMM_WORLD, &status);
printf("Send %s : Receive %s.\n", b, b);
}
else
{
printf("Nothing to do at node %s.\n", processor_name);
}

MPI_Finalize();
return 0;
}
